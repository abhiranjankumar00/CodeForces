errorMsg = "Error occurred"

int = 0
pair = 1
lt = 2
gt = 3
comma = 4

nextToken :: String -> (String, String)
nextToken [] = ("-", "-")
nextToken "-" = ("-", "-")
nextToken (x:xs)
 | x == 'i' = ("i", xs)
 | x == 'p' = ("p<" ++ token1 ++ "," ++ token2 ++ ">", rem2)
  where
  	(token1, rem1) = nextToken xs
	(token2, rem2) = nextToken rem1

solve :: String -> [String]
solve ['i'] = ["int"]
solve ('i': _) = [errorMsg]
solve (_:xs) = if null rem2 then map mm ("p<" ++ token1 ++ "," ++ token2 ++ ">") else [errorMsg]
 where
  	(token1, rem1) = nextToken xs
	(token2, rem2) = nextToken rem1
	mm 'p' = "pair"
	mm '<' = "<"
	mm '>' = ">"
	mm ',' = ","
	mm 'i' = "int"

main = getContents >>= putStrLn. concat. solve. map (\(x:_) -> x). tail. words
--main = getContents >>= print. solve. tail. words
