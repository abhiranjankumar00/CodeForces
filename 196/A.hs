import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let	
		[n, m] = map (\x -> read x::Int).words $ line1
		arr = sort. map (\x -> read x::Int). words $ line2
	print $ minimum [ arr!!(x+n-1)-arr!!x| x<-[0..(m-n)]]

