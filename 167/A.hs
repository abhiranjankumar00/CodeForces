import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	content <- getContents
	let
		(nn:arr) = map (\x -> read x ::Int).words $ content
		sum = foldl (+) 0 arr
		n = nn+1
		solution = length.filter (/= 1) $ [ x `mod` n | x <- [sum+1..sum+5] ]
	print solution

