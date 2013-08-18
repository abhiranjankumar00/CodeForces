import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

process :: [(Integer, Integer)] -> Integer -> Integer -> Integer -> [Integer]
process [] t1 t2 k = []
process ((a, b): as) t1 t2 k = ( max (a*t1 + b*t2 - (a*t1*k `div` 100)) (a*t2 + b*t1 - (b*t1*k `div` 100)) ) : process (as) t1 t2 k

main :: IO ()
main = do
	line1 <- getLine
	let
		[n, tt1, tt2, k] = map (\x -> read x :: Integer).words $ line1
		t1 = tt1*100
		t2 = tt2*100
	content <- getContents
	let
	 	arr =  map (\x -> let [a, b] = words$ x in (read a :: Integer, read b :: Integer)). lines $ content
		arr1 = reverse. sortBy (\(a, b) (c, d) -> if b /= d then compare b  d else compare c a). zip [1..] $ process arr t1 t2 k
	mapM_ (\(x, y) -> putStrLn$ (show x) ++ " " ++ (show$ y `div` 100) ++ "." ++ appendZero (show $ y `mod` 100)) arr1
	where
		appendZero x 
		 | length x == 2 = x
		 | otherwise = appendZero ('0': x)
