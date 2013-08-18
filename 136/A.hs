main = getLine >>= mapM_ (\x -> putStr (show x ++ " ")). (\x -> x:[1..(x-1)]). (\x -> read x :: Int) . head. words
