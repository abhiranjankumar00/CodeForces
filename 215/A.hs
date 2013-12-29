-- {{{
module Main where
---------------------Import-------------------------
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import System.IO
import Data.Ratio                                   -- x = 5%6
import Data.Bits                                    -- (.&.), (.|.), shiftL...
import Text.Printf                                  -- printf "%0.6f" (1.0)
import Control.Monad
import qualified Data.ByteString.Char8 as BS
-- }}}

main :: IO ()
main = do 
  line1 <- BS.getLine
  line2 <- BS.getLine
  line3 <- BS.getLine
  let
    [n, d] = getIntArray line1
    arr = (sort. getIntArray$ line2) ++ (repeat (-d))
    [m] = getIntArray line3
  print. sum. take m $ arr


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


