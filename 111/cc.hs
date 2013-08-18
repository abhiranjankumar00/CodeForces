import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

idx 0 (x : xs) = x
idx n (x: xs) = idx (n-1) xs

main :: IO ()
main = do
	line1 <- getLine
	let
		[n, kk] = map (\x -> read x :: Integer) . words $ line1
		k = kk-1
	line2 <- getLine
	let
		arr =  sort. map (\x -> read x:: Integer). words $ line2
	putStrLn $ show (idx (k `div` n) arr) ++ " " ++ show (idx (k `mod` n) arr)
