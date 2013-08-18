main = getLine >>= print.  (\[a, b, c] -> (a*c - b*c) `div` b + if (a*c-b*c) `mod` b == 0 then 0 else 1). map read. words
