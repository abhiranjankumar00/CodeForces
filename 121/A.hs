import qualified Data.Set as Set
import Data.List

lst = takeWhile (<= 1000000000) $ [ x*(x+1) `div`2 | x <- [1..] ]
len = length lst - 1
arr = foldl' (\acc x -> Set.insert x acc) (Set.empty) lst

binary_search x low high 
 | low == high = lst !! low == x
 | otherwise =
 	let
		mid = (low + high) `div` 2
	in
		if (lst !! mid) >= x then
			binary_search x low mid 
			else
				binary_search x (mid+1) high 

solve x = (\x -> if x then "YES" else "NO").  any (==True). map (\y -> Set.member (x - y) arr) $ lst
solve' x = (\x -> if x then "YES" else "NO"). foldl' (\acc y -> acc || (Set.member (x-y) arr)) False $ lst

main = getLine >>= putStrLn. solve'. (\x -> read x :: Int). head. words 

