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
main = BS.getContents >>= putStrLn. (["Bob", "Alice"]!!). fromIntegral .(`mod` 2).solve. tail. readIntegerArray
  where 
  solve xs = (maximum xs ) `div` g - fromIntegral (length xs)
    where
      g = gcd' xs
      gcd' :: [Integer] -> Integer
      gcd' (a:as) = foldl' (gcd) a as

