{- |
Module: Shape.hs
-}

module Shape where

data Point = Point { x :: Double, y :: Double } deriving (Show)

 -- Rectangles

data Rectangle = Rectangle { p1 :: Point, p2 :: Point } deriving (Show)

-- Circles

data Circle = Circle { m :: Point, r :: Double } deriving (Show)

-- Triangles

data Triangle = Triangle { a :: Point, b :: Point, c :: Point } deriving (Show)

--10.3 (a)


class Area ans where 
    area :: ans -> Double

instance Area Rectangle where
    area (Rectangle (Point x1 y1) (Point x2 y2)) = abs( (x2-x1) * (y2-y1) )

instance Area Circle where
    area (Circle _ r) = (3.14) * r * r

instance Area Triangle where
    area (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3)) = abs ( (x1*(y2-y3) + x2*(y1-y3)+ x3*(y1-y2) ) /2)

--10.3 (b)

class BoundingBox ans where 
    bbox:: ans -> Rectangle

instance BoundingBox Rectangle where
    bbox (Rectangle (Point x1 y1) (Point x2 y2)) = Rectangle (Point x1 y1) (Point x2 y2) 

instance BoundingBox Circle where
    bbox (Circle (Point a b) r) = Rectangle (Point (a+r) (b+r) ) (Point (a-r) (b-r))

instance BoundingBox Triangle where
    bbox (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3) ) = Rectangle (Point x1 x2) (Point x2 y3)

   

