import Data.Char

data Counts = Counts { ls :: Int
                     , ws :: Int
                     , cs :: Int
                     } deriving Show
{-

data Counts  = Counts Int Int Int


-}
              
skipSpaces :: Counts -> String -> (Counts, String)
skipSpaces counts []         = (counts, [])
skipSpaces counts (x:xs) | x == '\n' = (counts {ls = ls counts + 1, cs = cs counts + 1}, xs)
                         | isSpace x = (counts {cs = cs counts + 1}, xs)
                         | otherwise = (counts, (x:xs))
                                           
skipWord :: String -> (Int, String)
skipWord (x:xs) | not $ isSpace x = let (c,str) = skipWord xs
                                      in (c+1,str)
                | otherwise = (0,(x:xs))
skipWord []     = (0,[])

wc :: String -> Counts
wc = wc' $ Counts 0 0 0
wc' c [] = c
wc' c xs = let (c', str) = skipSpaces c xs
               (n, str') = skipWord str
               newc      = c' { cs = cs c' + n, ws = ws c' + 1}
               in wc' newc str'
               

main :: IO ()
main = do input <- getContents
          print $ wc input
                  