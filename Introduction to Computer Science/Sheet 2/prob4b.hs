

circle :: [char] -> [[char]]
circle [] = [[]]
circle a = rotate (length a) a 

rotate::Integer -> [a] -> [[a]]
rotate _ [] = [[]]
rotate 0 a = [a]
rotate n a = rotate (n-1) (drop 1 a ++[head a] ) 

circulate :: Int -> [a] -> [[a]]
circulate n string
 | (n == 1 ) = [string]
 | otherwise = [string] ++ (circulate (n-1) (rotate 1 string))