import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

solve :: Int -> [Int] -> Int
solve _ [] = 0
solve mn (x:xs)
 | x > mn = length xs + 1
 | otherwise = solve (min mn x) xs

main :: IO ()
main = getContents >>= print. (\arr -> solve (head arr) arr). reverse. map read. tail. words
