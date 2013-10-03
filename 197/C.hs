import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		n = read line2 :: Int
		opt = [ x+1 | x<-[0..9], line1!!x=='1']
		arr = solve 0 n [0, 0] [0,0]
		ans = if length arr == n then arr else []
		solve id m lst s
		 | m == 0 = []
		 | null y = []
		 | id == 0 = yy:(solve (1-id) (m-1) [yy, lst!!1] [s!!0+yy,s!!1])
		 | True = yy:(solve (1-id) (m-1) [lst!!0, yy] [s!!0, yy+s!!1])
		 	where
				y = filter (\k -> k /= lst!!(1-id) && k + s!!id > s!!(1-id)) opt
				yy = head y
	print arr
	putStrLn $ if null ans then "NO" else "YES"
	mapM_ (\x -> putStr ((show x) ++ " ")) $ ans
