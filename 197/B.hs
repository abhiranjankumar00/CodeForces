import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		[n, m] = map (\x->read x::Integer). words $ line1
		arr = map (\x->x-1). map (\x->read x::Integer). words $ line2
		solve _ [] = 0
		solve p (x:xs) = ((x-p)`mod`n + n)`mod`n + (solve x xs)
	print$ solve 0 arr
