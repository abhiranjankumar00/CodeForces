import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line1 <- getLine
	content <- getContents
	let
		[n, k] = map (\x -> read x :: Integer). words $ line1
		arr =  map (\[x, y] -> (read x :: Integer, read y :: Integer) ). map words. lines $ content
		solve [] = []
		solve ((f, t): xs)
		 | t > k = (f - t + k) : solve (xs)
		 | otherwise = f : solve (xs)
--	print content
--	print arr
	print $ maximum. solve $ arr
