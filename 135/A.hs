import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	_n <- getLine
	st <- getLine
	let
		n = (\x -> read x :: Int). head. words $ _n
	print n
	putStrLn st
