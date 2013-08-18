import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	name1 <- getLine
	name2 <- getLine
	namet <- getLine
	let
		name = sort namet
		newName = sort $ name1 ++ name2
	if name == newName then
		putStrLn "YES"
		else
			putStrLn "NO"
