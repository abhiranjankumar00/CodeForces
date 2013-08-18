import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

main :: IO ()
main = do
	line <- getLine
	let
		[n, rt, rp] = map (\x -> read x :: Integer) . words $ line
	putStrLn $ show $ 1*rp*n
	putStrLn $ show $ pi * fromIntegral ( 1*(rt - rp))
	if process n rt rp then
		putStrLn "YES"
	else
		putStrLn "NO"
	where
		process n rt rp = if n == 1 then
					rp <= rt	
					else
					rt >= 2*rp && fromIntegral (2*rp*n) <= pi * fromIntegral (2*(rt - rp))
