import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

findMax n = findMax' 3 n
 where
  findMax' k n 
	 | (k+1)*(k)*(k-1) `div` 6 > n = k
	 | otherwise 			 = findMax' (k+1) n

solve 0 = []
solve n = 
	let
		k = findMax n
	in
		[k]++ (solve (n - ((k+1)*k*(k+1))`div`6) )

--main :: IO ()
--main = do

