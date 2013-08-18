main = getLine >>= print. foldl (+) 0 . (\[w, h] -> [ (w-x+1)*(h-y+1)| x <- [2, 4..w], y <- [2, 4..h]] ). map read. words
