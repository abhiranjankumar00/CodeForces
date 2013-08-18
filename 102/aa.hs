import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO()
main = do
	_line <- getContents
	let
		[r1, r2, c1, c2, d1, d2] = map (\x -> read x :: Integer) . concat . map (\x -> words $ x) . lines$ _line
		arr = [1..9]
		p = [(a, b, c, d) | a<-arr, b<-arr, c<-arr, d<-arr, a/=b, a/=c, a/=d, b/=c, b/=d, c/=d, a+b==r1, c+d==r2, a+c==c1, b+d==c2, a+d==d1, b+c==d2]
	process p
	where
		process [] = putStrLn "-1"
		process ((a, b, c, d) : xs) = putStrLn $ (show a) ++ " " ++ show b ++ "\n" ++ show c ++ " " ++ show d


main1 :: IO ()
main1 = do
	in_line <- getContents
	putStrLn in_line
	let
		line = (show (lines $ in_line))
	putStrLn line
	let
		word = map (\x -> map (\x -> read x :: Integer) . words $ x) $ lines in_line
		word1 = concat word
	putStrLn (show word1)
	let
		[r1, r2, c1, c2, d1, d2] = word1
	putStr (show r1 ++ " " ++ show r2 ++ "\n" ++ show c1 ++ " " ++ show c2)
