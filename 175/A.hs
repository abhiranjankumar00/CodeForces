import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line <- getLine
	let
		[n, k] = map (\x -> read x :: Integer). words $ line
		--arr = if k == 0 then [(1::Integer)..n] else [(1::Integer)..(k-1)] ++ [k+1] ++ [k] ++ [k+2..n]
		arr = [k+1, k..1] ++ [k+2..n]
--	print n
--	print k
	mapM_ (\x -> putStr (show x  ++ " ")) $ arr
 
