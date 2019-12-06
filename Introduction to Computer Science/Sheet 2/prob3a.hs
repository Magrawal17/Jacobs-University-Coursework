isLeapYear :: Integer -> Bool
isLeapYear x = ((x `mod` 400) == 0)  || (((x `mod`4 ) == 0) && ( not ((x `mod` 100) == 0)))