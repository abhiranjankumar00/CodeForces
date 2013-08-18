main = do
	_ <- getLine
	content <- getLine
	let
--		arr = map (\x -> read x :: Int). words $ content
		solve _ [] = 0
		solve lst (a: as) = max (lst - a) 0 + solve a as
	print $ solve 0 $ map read. words $ content

