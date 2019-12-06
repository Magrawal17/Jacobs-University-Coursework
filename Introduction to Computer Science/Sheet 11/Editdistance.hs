--11.3 A


{- |
Module: Editdistance.hs
-}

module Distance where

data Lists=Lists{ x :: String, y :: String } deriving (Eq,Ord,Show) 

class Editdistance a where
    ed::a->Int
    
instance Editdistance Lists where
    ed (Lists "" "")    = 0 
    ed (Lists x  "")    = length x 
    ed (Lists "" y )    = length y
    ed (Lists (x:xs) (y:ys)) 
                             |  x == y     = ed (Lists xs ys)
                             |  otherwise  = 1 + minimum    [ ed (Lists (y:(x:xs)) (y:ys)),     --condition one   
                                                            ed (Lists xs (y:ys))        ,     --condition two
                                                            ed (Lists (y:xs) (y:ys))    ]     --condition three
 

 -- Haskell Part
A)

{- |
   Module: Distance.hs

-}

module Distance (ed) where

ed :: (Eq a) => [a] -> [a] -> Int
ed [] [] = 0
ed [] ys = length ys
ed xs [] = length xs
ed (x:xs) (y:ys)
  | x == y    = ed xs ys
  | otherwise = 1 + minimum [ed xs (y:ys),
                             ed (x:xs) ys,
                             ed xs ys]

😎


{- |
   Module: distancetest.hs
-}

module Main where

import Distance
import Test.HUnit
    
a =""
b =""
c ="hello"
d= "he"
e ="newt"
f="neiw"

tests = TestList [
        TestCase (assertEqual "Edit distance for empty"        0 (ed "" b)),
        TestCase (assertEqual "Check Edit distance for one string"        5 (ed c a)),
        TestCase (assertEqual "Check Edit distance for one string"        5 (ed a c)),
        TestCase (assertEqual "Check Edit distance for same string"       0 (ed c c)),
        TestCase (assertEqual "Check Edit distance for extended string"       3 (ed c d)),
        TestCase (assertEqual "Check Edit distance for same string"       2 (ed e f))
        ]
    
main = do
    runTestTT tests