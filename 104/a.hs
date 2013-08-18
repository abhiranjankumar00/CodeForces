import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	_n <- getLine
	line <- getLine
	let 
		n = read _n :: Int
		flag = all (\x -> x== '7' || x == '4' ) line
		(line1, line2) = splitAt (n `div` 2) line
	print $ show $ process line
	where
		process [] = []
		process (x : xs) = x : (process xs)
