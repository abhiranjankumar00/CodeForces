import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

f :: Int -> Int -> Int -> Int -> Int
f 0 0 0 0 = 0
f a1 a2 a3 a4
 | a4 > 0 = a4 + f a1 a2 a3 0
 | a1 > 0 && a3 > 0 =
 	let
		mn = min a1 a3
	in
		mn + f (a1 - mn) a2 (a3 - mn) a4 
 | a3 > 0 = a3 + f a1 a2 0 a4
 | a2 > 1 = (a2 `div` 2) + f a1 (a2 `mod` 2) a3 a4
 | a2 == 1 && a1 >= 2 = 1 + f (a1 - 2) 0 a3 a4
 | a2 <= 1 && a1 <= 2 = 1
 | a1 > 0 = a1 `div` 4 + (if a1 `mod` 4 > 0 then 1 else 0)
 | otherwise = error "hi, how are you!!!"

main :: IO ()
main = do
	_ <- getLine
	line <- getLine
	let
		arr = map (\x -> read x :: Int) . words $ line
		a1 = length . filter (== 1) $ arr
		a2 = length . filter (== 2) $ arr
		a3 = length . filter (== 3) $ arr
		a4 = length . filter (== 4) $ arr
	print $ f a1 a2 a3 a4

