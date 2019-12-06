{-r

circle :: [a] -> [[a]]
circle z = [rotate x z | x <- [0,1..length(z)-1

circle :: [a] -> [[a]]

circle z = [rotate x z | x <- [0,1..length(z)-1]]


rotate :: Int -> [a] -> [a]

rotate x y = if x > 0 then rotate (x-1) (tail y ++ take 1 y) else y-}



rotate:: Integer ->[a] ->[a]
rotate _ [] = []
rotate 0 a = a
rotate n a = rotate (n-1) (drop 1 a ++[head a] )   