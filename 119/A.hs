main = getLine >>= print . maximum. (\[n, a, b, c] -> [ (na+ nb+ (n - na*a - nb*b) `div` c) | na <- [0..n], nb <- [0..n], (n - na*a - nb*b) `mod` c == 0, (n - na*a - nb*b) `div` c >= 0]). map read . words