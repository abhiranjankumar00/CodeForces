import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = getLine >>= print. maximum. (\x -> if x>=0 then [x] else map (*(-1))[-x, (-x)`div`10, (-x)`div`100 * 10 + (-x)`mod`10]). (\x -> read x :: Integer). head. words
