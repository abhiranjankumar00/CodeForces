module Main where
---------------------Import--------------------------- {{{
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import System.IO
import Data.Ratio                                   -- x = 5%6
import Data.Bits                                    -- (.&.), (.|.), shiftL...
import Text.Printf                                  -- printf "%0.6f" (1.0)
import qualified Data.ByteString.Char8 as BS-- }}}

---------------------Input---------------------------- {{{
getInteger = (\(Just (x,_)) -> x). BS.readInteger
getInt = (\(Just (x,_)) -> x). BS.readInt

getIntArray = readIntArray
getIntegerArray = readIntegerArray

readIntArray input = 
  case x of
    Just (a, xs) -> a : readIntArray xs
    Nothing -> []
  where
   x = BS.readInt. BS.dropWhile isSpace $ input 

readIntegerArray input = 
  case x of
    Nothing -> []
    Just (y, ys) -> y : readIntegerArray ys
  where
    x = BS.readInteger. BS.dropWhile isSpace $ input
------------------------------------------------------ }}}

main :: IO ()
main = BS.getContents >>= (\(cnt, arr) -> print cnt >> (putStrLn. intercalate " ". map show$ arr)). solve. tail. readIntArray 

solve arr = 
  let
    len = length arr
    (a, b) = part. sort. addIndex 0 $ arr
    cnt = (length. nubBy (\(x, _) (y,_) -> x==y) $ a) * (length. nubBy (\(x, _) (y,_) -> x==y) $ b)
    sol = [ if any (\(x, id) -> id ==i ) a then 1 else 2| i <- [0..len-1]]
  in
    (cnt, sol)

part [] = ([], [])
part (x:y:xs) =
  let 
    (a, b) = part xs
  in
    (x:a, y:b)

addIndex :: Int -> [Int] -> [(Int, Int)]
addIndex _ [] = []
addIndex id (x:xs) = (x,id):addIndex (id+1) xs
