import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio
import qualified Data.ByteString.Char8 as BS

getInteger = (\(Just (x,_)) -> x). BS.readInteger
getInt = (\(Just (x,_)) -> x). BS.readInt

main :: IO ()
main = do
  line1 <- BS.getLine
  content <- BS.getContents
  let
    [n, m, ss, f] = map getInt. BS.words$ line1
    arr = map (map getInt). map BS.words. BS.lines $ content
    dir = if ss < f then 'R' else 'L'
    plus = if dir == 'L' then (-1) else 1
    solve :: Int -> [[Int]] -> Int -> [Char]
    solve s _ _
      | s == f = []
    solve s [] _ = dir : solve (s+plus) [] 0
    solve s xxs@([t, l, r]:xs) sc
      | sc < t = dir : solve (s+plus) xxs (sc+1)
      | sc > t = solve s xs sc
      | l-1 <= s && s <= r+1 = 'X' : solve s xxs (sc+1)
      | otherwise = dir : solve (s+plus) xxs (sc+1)

  print ss
  print f
  print arr
  print $solve ss arr 1
