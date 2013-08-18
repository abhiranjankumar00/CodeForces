import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line <- getLine
	let
		[k, b, n, t] = map (\x -> read x :: Double). words $ line
	print $ if (k < 1.1) then ceiling ((n*b-t)/b + 0) else solve k b n t

solve k b n t = max 0 $ ceiling $ n + ( (log (k-1+b) - log (k*t - t + b)) / log k)
