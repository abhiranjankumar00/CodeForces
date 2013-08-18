solve :: String -> IO()
solve x = mapM_ putStr (if not $null rem then ["Error occurred"] else  token1)
 where
	(token, rem) = nextToken x
	token1 = map (\x -> if x == 'i' then "int" else if x == 'p' then "pair" else [x]) token

nextToken :: String -> (String, String)
nextToken [] = ("", "-")
nextToken (p:ps)
 | p == 'i'  = ("i", ps)
 | otherwise = ("p<" ++ token1 ++ "," ++ token2 ++ ">", rem2)
  where
  	(token1, rem1) = nextToken ps
	(token2, rem2) = nextToken rem1


main = getContents >>= solve. map (\(p:_) -> p). words. tail

