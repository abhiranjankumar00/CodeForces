import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio

main :: IO ()
main = getLine >>= putStrLn. intersperse ('+') .sort. filter (/='+')

