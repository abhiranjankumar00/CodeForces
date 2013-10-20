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

parse [] = []
parse (x:y:xxs) = (x, y): parse xxs

main :: IO ()
main =  BS.getContents >>= print. solve. parse. tail. readIntArray

--solve :: [(Int, Int)] -> Bool
solve arr = 
  let
    (xs, ys) = foldl' (\(acx, acy) (x, y) -> (acx+x, acy+y)) (0, 0) arr
    p1 = not. null. filter (\(x, y) -> even (xs - x + y) && even (ys - y+x) ) $ arr
  in
    if even xs && even ys
      then 0
      else if p1
        then 1
        else (-1)
