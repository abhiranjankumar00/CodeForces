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
import System.Directory
import System.FilePath
-- }}}

main :: IO ()
main = BS.getContents >>= putStrLn. solve. readIntegerArray
  where
    solve [n, m, i, j, a, b] =
      let
        get (x1, y1) (x2, y2) =
          if (abs (x2-x1) `rem` a == 0) && (abs (y2-y1) `rem` b == 0) && even (abs(x2-x1)`div`a) == even (abs(y2-y1)`div`b) then
            max (abs(x2-x1)`div`a) (abs(y2-y1)`div`b)
            else 10^8
      in
        (\x -> if x < 10^8 then show 2 else "Poor Inna and pony!"). minimum $[get (i, j) (1, 1), get (i, j) (n, 1), get (i, j) (1, m), get (i, j) (n, m)]

---------------------Input---------------------------- {{{
getInteger = (\(Just (x_yzpqr,_)) -> x_yzpqr). BS.readInteger
getInt = (\(Just (x_yzpqr,_)) -> x_yzpqr). BS.readInt

getIntArray = readIntArray
getIntegerArray = readIntegerArray

readIntArray input_pqr =
    case x_yzpqr of
        Just (a_yzpqr, xs_pqr) -> a_yzpqr : readIntArray xs_pqr
        Nothing -> []
    where
        x_yzpqr = BS.readInt. BS.dropWhile isSpace $ input_pqr

readIntegerArray input_pqr =
    case x_yzpqr of
        Nothing -> []
        Just (y_zpqr, ys_pqr) -> y_zpqr : readIntegerArray ys_pqr
    where
        x_yzpqr = BS.readInteger. BS.dropWhile isSpace $ input_pqr
------------------------------------------------------ }}}

