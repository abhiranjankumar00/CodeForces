import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

fstIdx :: Integer -> Integer -> Integer
fstIdx k n
 | k < n = 0
 | otherwise = 1 + fstIdx (k-n) n

sndIdx :: Integer -> Integer -> Integer
sndIdx k n = k `mod` n

idx :: Integer -> [a] -> a
idx 0 (x:xs) = x
idx n (x: xs) = idx (n-1) xs

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		[n, k] = map (\x -> read x :: Integer). words $ line1
		arr = sort. map (\x -> read x :: Int). words $ line2
		fid = fstIdx (k-1) n
		sid = sndIdx (k-1) n
		f = idx fid arr
		s = idx sid arr
--	print n 
--	print k
--	print arr
	putStrLn $ (show f) ++ " " ++ (show s)
