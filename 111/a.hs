import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

f :: Int -> [Int] -> Int
f s [] = 0
f s xxs@(x:xs) 
 | s > foldl (+) 0 xxs = 0
 | otherwise = 1 + (f (s+x) xs)

main :: IO ()
main = do
	nn <- getLine
	line <- getLine
	let
		n = read nn :: Int
		arr = reverse.sort. map (\x -> read x :: Int).words $ line
	print $ f 0 arr
