import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

process :: Int -> [Int] -> Int
process d [] = 0
process d [a] = 0
process d (a: as) = (d - a) + (process d as)

main :: IO ()
main = do
	line <- getLine
	_ <- getLine
	arr1 <- getLine
	let
		d = read line:: Int
		a = map (\x -> read x :: Int).words $ arr1
	print $ process d a
