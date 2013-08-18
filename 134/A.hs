import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		[n, k] = map (\x -> read x :: Int). words $ line1
		arr = map (\x -> read x :: Int). words $line2
		solve _ [] _ = []
		solve lst aas@(a:b:as) k 
		 | k == 0 = aas
		 | a -1> lst && a -1 > b = (a-1):  b : solve (b) as (k-1) 
		 | otherwise = a:b : solve b as k
----	print n
--	print k
--	print arr
	mapM_ (\x -> putStr $ show x ++ " ") $ head arr : solve (head arr) (tail arr) k
