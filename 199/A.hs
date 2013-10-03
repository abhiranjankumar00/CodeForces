import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio
import qualified Data.ByteString.Char8 as BS

getInteger = (\(Just (x,_)) -> x). BS.readInteger
getInt = (\(Just (x,_)) -> x). BS.readInt

filter' func = foldl' (\acc x -> if func x then x:acc else acc) []
map' func = foldl' (\acc x -> func x: acc) []

solve [] = (0, 0, 0, 0, 0)
solve (x:xs)
  | x == 1 = (a+1, b, c, d, e)
  | x == 2 = (a, b+1, c, d, e)
  | x == 3 = (a, b, c+1, d, e)
  | x == 4 = (a, b, c, d+1, e)
  | x == 6 = (a, b, c, d, e+1)
  | otherwise = (0, 0, 0, 0, 0)
    where
      (a, b, c, d, e) = solve xs

solution (0, 0, 0, 0, 0) = []
solution (a, b, c, d, e) 
  | a > 0 && b > 0 && d > 0 = (1, 2, 4):solution (a-1, b-1, c, d-1, e)
  | a > 0 && b > 0 && e > 0 = (1, 2, 6) : solution (a-1, b-1, c, d, e-1)
  | a > 0 && c > 0 && e > 0 = (1, 3, 6) : solution (a-1, b, c-1, d, e-1)
  | otherwise = []

main :: IO ()
main = do
  _n <- BS.getLine
  _arr <- BS.getLine
  let
    n = getInt _n
    arr = solution. solve. map' getInt. BS.words $ _arr
  if length arr /= n`div` 3 then print (-1) else (mapM_ (\(a, b, c) -> putStrLn $ (show a) ++ " "++ (show b) ++ " " ++ (show c)) arr)
