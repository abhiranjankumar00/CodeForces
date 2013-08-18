main = getContents >>= putStrLn. unwords. map show. (\(s:as) -> let ss = s/(sum as) in if sum as == 0 then replicate 3 0 else map (*ss) as). map read. words
