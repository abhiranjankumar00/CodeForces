import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

findLeft x = length. takeWhile (== '.') $ x

main :: IO ()
main = do 
	line <- getLine
	let 
		[m, n] = map (\x -> read x :: Int). words$ line
	arr' <- getContents
	let
		arr = lines arr'
		tarr = transpose arr
		left =  minimum. map findLeft $ arr
		top  = minimum. map findLeft $ tarr
		right = n - (minimum. map findLeft. map reverse $arr)
		bot =  m -  (minimum. map findLeft. map reverse $ tarr)
--	mapM_ print arr
--	putStrLn ""
--	mapM_ print tarr
--	putStrLn ""
--	putStrLn $ "left  = " ++ show left	
--	putStrLn $ "top   = " ++ show top
--	putStrLn $ "right = " ++ show right
--	putStrLn $ "bot   = " ++ show bot
--	putStrLn ""
	mapM_ putStrLn. map (drop left). map (take right). drop top. take bot $ arr
