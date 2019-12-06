import System.IO
import Data.Char
import Emoji

-- Peek into the content to decide whether we encode or decode.

convert :: String -> String
convert xs
 | null $ filter (\c -> isLetter c && isAscii c) xs = dec xs
 | otherwise = enc xs

main = do
contents <- getContents
putStrLn (convert (contents))
