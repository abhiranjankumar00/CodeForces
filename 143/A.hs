import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = getContents >>= print. length. filter (>= 2). map (\[x, y, z] -> x + y + z). map (map (\x -> read x :: Int)) . map words. tail. lines

