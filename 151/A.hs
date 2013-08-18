import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = getLine >>= mapM_ (\x -> putStr $ show x ++ " ")  .(\x -> if (x <= 2) then [-1] else [x, (x-1) ..1]). read. head.words

