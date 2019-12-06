
module Emoji where

import Data.Char

enc :: String -> String
enc "" = ""
enc x
 | isUpper(head x) = [chr (ord(head x) + 127935)] ++ enc(tail x)
 | isLower(head x) = [chr (ord(head x) + 128415)] ++ enc(tail x)
 | otherwise = x

dec :: String -> String
dec ""=""
dec x 
 | (ord (head x) >= 128512 && ord (head x) <= 128537) = [chr ((ord (head x)) + 97 - 128512)]++ dec (tail x)
 | (ord (head x) >= 128000 && ord (head x) <= 128025) = [chr ((ord (head x)) + 65 - 128000)]++ dec (tail x)
 | otherwise = x


