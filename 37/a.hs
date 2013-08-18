import Data.List
main = getContents >>= putStrLn. (\x ->show (maximum.map length.group.sort $ x) ++ " " ++ show (length.nub $ x)). tail. words
