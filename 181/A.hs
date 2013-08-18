import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	_ <- getLine
	line <- getLine
	let
		arr = map read. words $ line
		pos = filter (> 0) arr
		neg = filter (<0) arr
		zero = filter (==0) arr
		[arr1, arr2, arr3] = if length neg >= 3 then  [[neg!!0], [neg!!1, neg!!2], (drop 3 neg) ++ (pos) ++ zero]  else [[neg!!0], [pos!!0], (drop 1 pos) ++ (drop 1 neg) ++ zero]
	putStr $ (show (length arr1)) ++ " "
	mapM_ (\x -> putStr $ (show x) ++ " ") arr1
	putStrLn ""
	putStr $ (show (length arr2)) ++ " "
	mapM_ (\x -> putStr $ (show x) ++ " ") arr2
	putStrLn ""
	putStr $ (show (length arr3)) ++ " "
	mapM_ (\x -> putStr $ (show x) ++ " ") arr3
