errorMsg = "Error occurred"

int = 0
pair = 1
lt = 2
gt = 3
comma = 4

nextToken :: [String] -> (String, [String])
nextToken [] = ("", [""])
nextToken (x:xs)
 | x == "int"  = (x, xs)
 | x == "pair" = ("pair<" ++ token1 ++ "," ++ token2 ++ ">", rem2)
  where
  	(token1, rem1) = nextToken xs
	(token2, rem2) = nextToken rem1

solve :: [String] -> String
solve ["int"] = "int"
solve ("int": _) = errorMsg
solve (_:xs) = if null rem2 then "pair<" ++ token1 ++ "," ++ token2 ++ ">" else errorMsg
 where
  	(token1, rem1) = nextToken xs
	(token2, rem2) = nextToken rem1

main = getContents >>= print. map (\(x:_) -> if x == 'p' then pair else int ). tail. words
--main = getContents >>= print. solve. tail. words
