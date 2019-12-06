{- |
Module: testcases.hs
-}

module Main where

import Shape
--the shape module is defined in the file HW9P1.hs
import Test.HUnit
--Test.Hunit helps in creating testcases, defined in the haskell system be default,

pa = Point { x = 0, y = 0 }
pb = Point { x = 10, y = 10 }
pc = Point { x = 0, y = 20 }

box = Rectangle { p1 = pa, p2 = pb }
circle = Circle { m = pa, r = 10 }
triangle = Triangle { a = pa, b = pb, c = pc }

tests = TestList [ TestCase (100.0 @=? (Shape.area box))
    ,TestCase (314 @=? (floor (Shape.area circle)))
    ,TestCase (100.0 @=? (Shape.area triangle))
    ,TestCase (100.0 @=? (Shape.area $ Shape.bbox box))
    ,TestCase (400.0 @=? (Shape.area $ Shape.bbox circle))
    ,TestCase (200.0 @=? (Shape.area $ Shape.bbox triangle)) ]

main = runTestTT tests