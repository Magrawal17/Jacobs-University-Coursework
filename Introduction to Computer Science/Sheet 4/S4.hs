--4.3
--a)


isSpecialPrime :: Int -> Bool
isSpecialPrime n
 |elem n x == True = True
 |otherwise = False
  where 
   x= (filter isPrime (map(+1)(zipWith(+) (1:filter isPrime [1..n]) (filter isPrime[1..n]))))

isPrime :: Integer -> Bool
isPrime 2=True
isPrime x= length([a|a <- [2..(div x 2)] , (mod x a) ==0])==0)