isValidLine [x0, y0, x1, y1] 
 | x0 == x1 || y0 == y1 = True
 | otherwise = False

isParallel l1@[x0, y0, x1, y1]  l2@[p0, q0, p1, q1] 
 | isValidLine l1 == False = False
 | isValidLine l2 == False = False
 | min x0 x1 == min p0 p1 && max x0 x1 == max p0 p1 && x1 - x0 /= 0 = True
 | min y0 y1 == min q0 q1 && max y0 y1 == max q0 q1 && y1 - y0 /= 0 = True
 | otherwise = False

isRect l1 l2 l3 l4
 | isParallel l1 l2 == False = False
 | isParallel l3 l4 == False = False
 | l1!!0 == l1!!2 && min (l1!!1) (l1!!3) == min (l2!!1) (l2!!3) && max (l1!!1) (l1!!3) == max (l2!!1) (l2!!3) = True
 | l1!!1 == l1!!3 && min (l1!!0) (l1!!2) == min (l2!!0) (l2!!2) && max (l1!!0) (l1!!2) == max (l2!!0) (l2!!2) = True
 | l3!!0 == l3!!2 && min (l3!!1) (l3!!3) == min (l4!!1) (l4!!3) && max (l3!!1) (l3!!3) == max (l4!!1) (l4!!3) = True
 | l3!!1 == l3!!3 && min (l3!!0) (l3!!2) == min (l4!!0) (l4!!2) && max (l3!!0) (l3!!2) == max (l4!!0) (l4!!2) = True
 | otherwise = False



solve [l1, l2, l3, l4] 
 | isRect l1 l2 l3 l4 = "YES"
 | isRect l1 l3 l2 l3 = "YES"
 | otherwise = "NO"

main = getContents >>= putStrLn. solve. map (\x -> map (\y -> read y :: Integer) x). map words. lines
