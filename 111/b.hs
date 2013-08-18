import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

f :: [Char] -> [String]
f [] = []
f (x:xs) = (x: "") : (f xs)

g [] [] = True
g (x: xs) (y: ys) 
 | x > y = g xs ys
 | otherwise = False

main :: IO ()
main = do
	nn <- getLine
	line <- getLine
	let
		n = read nn :: Int
		tmp = map (\x -> read x :: Int). f $ line
		(xx, yy) = splitAt n tmp
		x = sort $ xx
		y = sort $ yy
	if (g x y) || (g y x) then
		putStrLn "YES"
		else
			putStrLn "NO"
