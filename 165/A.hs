import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = getContents >>= mapM_ putStrLn. map (\x -> if 360 `mod` (180-x) == 0 then "YES" else "NO"). map (\x -> read x :: Int). tail. words 

