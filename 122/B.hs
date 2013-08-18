main = getContents >>= mapM_ print.map solve. map (\x -> read x :: Integer). tail. words
 where
  solve x
   | even x = 4*x + 1
   | x `mod` 4 == 3 = x+1
   | otherwise = 2*x+1
