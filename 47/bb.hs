import Data.List

main :: IO()
main = do
--	line <- getLine
	getLine >>= print . sum .  map ((\x -> x*x). toInteger . length) .  group . sort 
