import Data.List

main :: IO ()
main = getContents >>= putStrLn. intercalate " ". map show. (\[n, k, l, r, sall, sk] -> (getArr k sk) ++ (getArr (n-k) (sall - sk))). map read. words
  where
    getArr n s = 
      let
        mre = s`rem`n
        lss = n - mre
      in
        (replicate mre (s`div`n + 1)) ++ (replicate lss (s`div`n))

