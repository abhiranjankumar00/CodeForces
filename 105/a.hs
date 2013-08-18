import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line <- getContents
	let
		[k, l, m, n, d] = map(\x -> read x :: Integer) . lines $ line
		sum1 = (d `div` k)+(d `div` l)+ (d `div` m)+ (d `div` n)
		diff1 = -(d `div` l*k)- (d `div` k*m)- (d `div` k*n)- (d `div` l*m)- (d `div` l*n)- (d `div` m*n)
		sum2 = (d `div` k*l*m)+ (d `div` l*m*n) + (d `div` k*m*n) + (d `div` l*k*n)
		diff2 = -(d `div` l*k*m*n)
	print sum1
	print diff1
	print sum2
	print diff2
