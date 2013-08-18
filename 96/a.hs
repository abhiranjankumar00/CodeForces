import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	getLine >>= putStrLn . f
		where	f [] = "NO"
			f ('H' : xs) = "YES"
			f ('Q' : xs) = "YES"
			f ('9' : xS) = "YES"
			f (_ : xs) = f xs

