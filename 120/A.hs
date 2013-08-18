main = getLine >>= putStrLn.p. map read. words
	where
		p [x, y]
		 | x == 0 && y == 0 = "0 0"
		 | x == 0 = "Impossible"
		 | y == 0 = show x ++ " " ++ show x
		 | y <= x = show (x) ++ " " ++ show (x + y-1)
		 | otherwise = show (x + y-x) ++ " " ++ show (x + y-1)
