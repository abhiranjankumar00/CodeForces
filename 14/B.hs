solve _ _ [] = True
solve d add ((a, b) : xs) 
 | (d + add) >= min a b && (d + add) <= max a b = solve d add xs
 | otherwise = False



main = do
	line <- getLine
	arr' <- getContents
	let
		[n, x] = map (\x -> read x :: Integer ). words $ line
		arr = map (\x -> let [a, b] = map (\y -> read y :: Integer ). words $ x in (a, b)  ). lines $ arr'
		ans 1001 = -1
		ans d
		 | solve x d arr = d
		 | solve x (-d) arr = d
		 | otherwise = ans (d+1)
--	print x
--	print arr
	print $ ans 0
