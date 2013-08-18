main = getLine >>= print. (\[n, k] -> max 0 (3*n - k)). map read. words

