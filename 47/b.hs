import qualified Data.Map as Map

main :: IO()
main = do
	line <- getLine
	let	x = foldl (\acc x -> add x acc) [] line
		y = foldl (\acc (a, b) -> acc + (b*b)) 0 x
	print $ y

add :: Char -> [(Char, Integer)] -> [(Char, Integer)]
add ch [] = [(ch, 1)]
add ch ( (a, b) : xs  ) 
 | a == ch = (a, b+1) : xs
 | otherwise = (a, b) : add ch xs
