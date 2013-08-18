import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

_find n [] = "YES"
_find n (a:as)
 | n == a  || n == (7-a)= "NO"
 | otherwise = _find n as

main :: IO ()
main = do
	_ <- getLine
	_n <- getLine
	arrT <- getContents
	let
		n = read _n :: Int
		arr = map (\x -> read x :: Int).words $ arrT
	putStrLn  $_find n arr
