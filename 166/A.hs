import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

solve x
 | a /= b && a /= c && a /= d  && b /= c && b /= d && c /= d = x
 | otherwise = solve (x+1)
  where
   a = x`mod`10
   b = x`div`10 `mod` 10
   c = x`div`100 `mod` 10
   d = x`div`1000 `mod` 10

main= getLine >>= print. (\x -> solve (x+1)). (\x -> read x::Int).head. words

