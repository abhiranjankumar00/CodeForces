import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	nn <- getLine
	inp <- getContents
	let
		n = read nn :: Int
		arr1 = map (\x -> map(\x -> read x :: Int). words $ x). lines $ inp
		arr2 = transpose arr1
		s = sum [if sum (arr1 !! i) < sum (arr2 !! j) then 1 else 0 | i <- [0..n-1], j <- [0..n-1]]
	print s
