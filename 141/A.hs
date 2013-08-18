import Data.List

main =  getLine >>= print.(\x -> 4-length x). nub. sort. map (\x -> read x :: Integer). words

