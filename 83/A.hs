import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
--main = getContents >>= print. foldl (\acc (a, b) -> Map.insert a b acc) (Map.empty). map (\[a, b, c] -> (read a::Int,  (read b :: Int, read c :: Int))). map (\x -> words x). tail. lines

main = do
	line <- getLine
	content <- getContents 
	let
		[n, p] = map (\x->read x :: Int). words $line
		arr = map (\x -> (\[x, y, z] -> [read x :: Int, read y :: Int, read z ::Int]).words $ x).lines $content
		out1 = foldl (\acc [x, _, _] -> Set.insert x acc) Set.empty $ arr
		in1 = foldl (\acc [_, x, _] -> Set.insert x acc) Set.empty $ arr
	 	tracePath x d 
		 | Set.member x out1 =	
	print arr
	print $"out = " ++ show (out1)
	print $"in  = " ++ show in1
	print $ filter (\x -> Set.member x out1 && (not $ Set.member x in1)) [1..n]
