--5.3.A

toBase :: Int -> Int -> [Int]
toBase _ 0 = []
toBase b n = toBase b (n `div` b) ++ [n `mod` b]

--5.3.B

fromBase :: Int -> [Int] -> Int
fromBase _ [] = 0
fromBase b (x:xs) = x*(b^length xs) + fromBase b xs

--5.3.C

showBase :: Int -> Int -> String
showBase _ 0 = ""
showBase b n = listtostring(toBase b n)

listtostring :: [Int] -> String
listtostring []=""
listtostring (x:xs) = show(x) ++ listtostring(xs)

showBin :: Int -> String
showBin x= listtostring(toBase 2 x)

showOct :: Int -> String
showOct x= listtostring(toBase 8 x)

showHex :: Int -> String
showHex x= listtostring(toBase 16 x)

--5.3.D

readBase :: Int -> String -> Int
readBase b n =  (fromBase  (b) (stringtoint(n) ))

stringtoint :: String -> [Int]
stringtoint n = map (\x -> read [x]::Int) n

readBin :: String -> Int
readBin n =  (fromBase  (2) (stringtoint(n) ))

readOct :: String -> Int
readOct n =  (fromBase  (8) (stringtoint(n) ))

readHex :: String -> Int
readHex n =  (fromBase  (16) (stringtoint(n) ))