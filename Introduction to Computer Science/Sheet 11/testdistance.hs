                                                   
--Problem 11.3 B

{- |
Module: testdistance.hs
-}

module Main where

    import Distance
    import Test.HUnit

    Test1 = Lists { x = "", y = ""}
    Test2 = Lists { x = "", y = "back"}
    Test3 = Lists { x = "book", y = ""}
    Test4 = Lists { x = "book", y = "back"}
    Test5 = Lists { x = "principal", y = "gigantic"}
    
    
    tests = TestList [ TestCase (0 @=? (Distance.ed Test1))
                      ,TestCase (4 @=? (Distance.ed Test2))
                      ,TestCase (4 @=? (Distance.ed Test3))
                      ,TestCase (2 @=? (Distance.ed Test4))
                      ,TestCase (8 @=? (Distance.ed Test5)) ]
    
    main = runTestTT tests
    
