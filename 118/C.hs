import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

_mod :: Integer
_mod = (10^9+7)

pow _ 0 = 1
pow a n 
 | odd n = (tmp * a) `mod` _mod 
 | otherwise = tmp
 where
 	tmp1 = pow a (n `div` 2)
	tmp = (tmp1 * tmp1) `mod` _mod

main :: IO ()
main = do
	getLine >>= print . (`mod` _mod). (\x -> x*(x+1) `div` 2). (pow 2). (\x -> read x )
