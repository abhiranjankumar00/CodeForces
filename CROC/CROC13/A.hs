import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	_ <- getLine
	line <- getLine
	let
		arr = map length. group. filter (/= 0). sort. map (\x -> read x :: Integer). words $ line
		sol :: Int -> [Int] -> Int
		sol x [] = x
		sol x (p:ps)
		 | p > 2 = (-1)
		 | p == 2 = sol (x+1) ps
		 | otherwise = sol x ps
	print $ sol 0 arr
