import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

solve :: [[Integer]] -> Integer -> String
solve [] _ = "YES"
solve (x:xs) curPow
 | curPow > a = solve xs (curPow + b)
 | otherwise = "NO"
 	where
		a = head x
		b = last x

main :: IO ()
main = do 
	line1 <- getLine
	contents <- getContents
	let
		[s, n] = map (\x -> read x :: Integer). words $ line1
		arr = sort.map (\x -> map (\x -> read x :: Integer). words $ x). lines $ contents
--	print s
--	print arr
	putStrLn$ solve  arr s

