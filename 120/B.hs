main = getContents >>= print.p. map read. words
	where
		p [x1, y1, r1, x2, y2, r2] 
		 | r1^2 < d && r2^2 < d && (r1 + r2)^2 >= d = 0
		 | (r1 + r2)^2 < d = (sqrt(fromIntegral d) - (fromIntegral r1) - (fromIntegral r2))/2.0 
		 | (r1 + r2)^2 >= d && (r1 - r2)^2 <= d = 0
		 | otherwise = (rr1 - dd - rr2)/2.0
		 where
		 	rr1 = fromIntegral $ max r1 r2
			rr2 = fromIntegral $ min r1 r2
			dd = sqrt $ fromIntegral d
			d = (x1 - x2)^2 + (y1 - y2)^2
