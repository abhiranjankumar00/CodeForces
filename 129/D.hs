import Data.List

createArr [] = ([], [])
createArr (ps: xs) = 
	let
		[a, b] = map (\x -> read x :: Int).words $ ps
		(p, q) = createArr xs
	in
		if a == b then
			(a:p, q)
			else
				(a:p, b:q)
	
solve [] [] = []
solve (a:as) [] = (fst a, snd a, 0) : solve as []
solve [] (a:as) = (fst a, 0, snd a) : solve [] as
solve aas@((a, ap): as) bbs@((b, bp): bs)
 | a == b = (a, ap, bp) : solve as bs
 | a < b =  (a, ap, 0) : solve as bbs
 | b < a = (b, 0, bp) : solve aas bs

main :: IO ()
main = do
	m <- readLn :: IO Int
	content <- getContents
	let
		n = (m+1) `div` 2
		(p,q) = (\(p, q) -> ((map (\x -> (head x, length x)).group.sort$ p), map (\x -> (head x, length x)).group.sort$ q)). createArr. lines $ content
		inf = 10000000
		cal (a, c1, c2) n 
		 | c1 >= n = 0
		 | c1 + c2 >= n = n - c1
		 | otherwise = inf
		sol = ( \x -> if x == inf then -1 else x). minimum. map (\x -> cal x n) $ solve p q
	print sol
