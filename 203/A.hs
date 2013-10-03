module Main where
---------------------Import--------------------------- {{{
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
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
main = do
  _ <- getLine
  a <- getLine
  b <- getLine
  let
    (mn1, mx1) = (\x -> (minimum x, maximum x)). map (read::String->Int). words $ a
    mn2 = minimum. map (read::String->Int). words$ b
    arr = filter (\k -> 2*mn1 <= k && mx1 <= k &&  k < mn2) [1..100]
  print $ if null arr then -1 else head arr

