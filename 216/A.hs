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
import qualified Data.Vector as V
import Control.Monad
import qualified Data.ByteString.Char8 as BS
-- }}}

main :: IO ()
main = do
  con <- getContents
  let
    [[n, m, k],arr] = map(map (read::String -> Int)). map words. lines $ con
    first = length. filter (==1) $arr
    second = length. filter (==2)$ arr
    
  print (m, first)
  print (first-m)
  print (k, second)
  print (second - k)
  print $ (max 0 (first -m)) + (max 0 (second - k))


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


