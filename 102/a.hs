import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	rr <- getLine
	cc <- getLine
	dd <- getLine
	let
		[r1, r2] = process rr 
		[c1, c2] = process cc
		[d1, d2] = process dd
		p = [(a, b, c, d) | a <- [1..9], b <- [1..9], c <- [1..9], d <- [1..9], a /= b, a /= c, a /= d, b /= c, b /= d, c /= d, a+b == r1, c+d==r2, a+c==c1, b+d == c2, a+d==d1, b+c==d2]
	process1 p
	where
		process x = map (\x -> read x :: Integer) . words $ x

process1 :: [(Integer, Integer, Integer, Integer)] -> IO()
process1 [] = putStrLn "-1"
process1 ((a, b, c, d) : xs) = do
	putStrLn (show a ++ " " ++ show b )
	putStrLn (show c ++ " " ++ show d)
