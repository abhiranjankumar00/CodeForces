main :: IO()
main = do
	a <- getLine
	let	m = words a
		p = read (m !! 0) :: Int
		q = read (m !! 1) :: Int
	--print p
	--print q
	print $ process p q 0


process :: Int -> Int -> Int -> Int
process _ 0 _ = 0
process a b c 
 | odd a 	= process a (b-1) (1-c) + half + c
 | otherwise	= half + process a (b-1) 0
 	where half = (a `div` 2)
