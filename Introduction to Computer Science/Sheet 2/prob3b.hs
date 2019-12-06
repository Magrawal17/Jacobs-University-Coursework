isLeapYear :: Integer -> Bool
isLeapYear x | ((x `mod` 400) == 0) = True 
isLeapYear x | ((x `mod` 100) == 0) = False 
isLeapYear x | ((x `mod` 4) == 0) = True 
isLeapYear x | otherwise = False
