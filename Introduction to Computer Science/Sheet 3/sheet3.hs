--3.3.A

isPrime :: Int -> Bool
isPrime x = check x (x `div` 2)

check :: Int -> Int -> Bool
check a b
 |b <= 0 = False
 |b == 1 = True
 |a `mod` b == 0 = False
 |otherwise = check a (b-1)

--3.3.B

converttoint :: [String] -> [Int]
converttoint z = [read y| y <- z] -- converting each string to an Integer

converttostring :: Int -> [String]
converttostring e = circle (show e)

rotate:: Int ->[a] ->[a]
rotate _ [] = []
rotate 0 a = a
rotate n a = rotate (n-1) (drop 1 a ++[head a] )   

circle :: [a] -> [[a]]
circle z = [rotate x z | x <- [0,1..length(z)-1]]

isCircPrime :: Int -> Bool-- checking if the given integer is a circular prime or not
isCircPrime i 
 | i < 0 = False
 | length ([y |y <- (converttoint (converttostring i)), isPrime y]) == length (converttoint (converttostring i)) = True
 | otherwise = False


