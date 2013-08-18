import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		[n, m] = map (\x -> read x :: Int) .words $line1
		arr = reverse. sort. map (\x -> read x :: Int) . words $ line2
		mn = arr !! (m-1)
	print . length. filter (\x -> x >= mn && x > 0) $ arr
