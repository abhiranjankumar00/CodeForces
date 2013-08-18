import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

_mod :: Int
_mod = 1000003

f :: Char -> Int
f '>' = 8
f '<' = 9
f '+' = 10
f '-' = 11
f '.' = 12
f ',' = 13
f '[' = 14
f ']' = 15
f _ = error "error"

main :: IO ()
main = interact (solve )

solve xs = show $ foldl (\acc x -> (acc*16 + (f x)) `mod` _mod) 0  xs

