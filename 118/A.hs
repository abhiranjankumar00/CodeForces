main = getContents >>= print. p. words
	where 
		p [[], []]= []
		p [(x:xs), []] = (x, ' '): p xs []
		p [[], (x:xs)] = (' ', x): p [] xs
		p [(x:xs) (y:ys)] = if x == y then p xs ys else (x, y): p xs ys

--import Data.List
--import qualified Data.Map as Map
--import qualified Data.Set as Set
--import Data.Char

--process :: [Char] -> [Char] -> [(Char, Char)]
--process [] [] = []
--process [] (x: xs) = (' ' , x) : process [] xs
--process (x: xs) [] = (x, ' ') : process xs []
--process (x:xs) (y:ys)
-- | x == y = process xs ys
-- | otherwise = (x, y) : process xs ys

--main :: IO ()
--main = do
--	w1 <- getLine
--	w2 <- getLine
--	let
--		arr = process w1 w2
--	if length arr == 2 && fst (arr !! 0) == snd (arr !! 1) && snd (arr!!0) == fst (arr!!1) then
--		putStrLn "YES"
--		else
--			putStrLn "NO"
	
