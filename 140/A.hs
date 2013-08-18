import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	a <- getLine
	b <- getLine
	c <- getLine
	let
		[xa, ya] = map (\x -> read x :: Integer). words $ a
		[xb, yb] = map (\x -> read x :: Integer). words$  b
		[xc, yc] = map (\x -> read x :: Integer). words$  c
		x1 = xb - xa
		y1 = yb - ya
		x2 = xb - xc
		y2 = yb - yc
	if x1*y2 == y1*x2 then
		putStrLn "TOWARDS"
		else if x1*y2 - y1*x2 < 0 then
			putStrLn "LEFT"
			else
				putStrLn "RIGHT"
