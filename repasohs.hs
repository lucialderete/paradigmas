contarPositivos :: [Int] -> Int
contarPositivos xs 
    | null xs = 0
    | head xs > 0 = contarPositivos(tail xs) + 1
    | otherwise = contarPositivos(tail xs)

productoLista :: [Int] -> Int
productoLista xs 
    | null xs = 1
    | otherwise = (head xs) * productoLista(tail xs)
    
contarElemento :: [Int] -> Int -> Int
contarElemento xs n
    | null xs = 0
    | head xs == n = 1 + contarElemento(tail xs) n
    | otherwise = contarElemento(tail xs) n


eliminarNegativosG :: [Int] -> [Int]
eliminarNegativosG xs
    | null xs  = []
    | head xs > 0 = head xs : eliminarNegativosG(tail xs)
    |otherwise = eliminarNegativosG(tail xs)

eliminarNegativosPM :: [Int] -> [Int]
eliminarNegativosPM [] = []
eliminarNegativosPM (x:xs)
    | x < 0 = eliminarNegativosPM xs
    | otherwise =  x : eliminarNegativosPM xs


todosPares :: [Int] -> Bool
todosPares xs
    | null xs = True
    | head xs `mod` 2 == 0 = todosPares( tail xs)
    | otherwise = False

todosParesPM :: [Int] -> Bool
todosParesPM [] = True
todosParesPM (x:xs) 
    | x `mod` 2 == 0 = todosParesPM xs
    |otherwise= False

quitarN :: [Int] -> Int -> [Int]
quitarN xs n
    | null xs = []
    | n <= 0 = xs
    | otherwise = quitarN (tail xs) (n-1)

quitarNPM :: [Int] -> Int -> [Int]
quitarNPM [] n = []
quitarNPM (x:xs) n
    | n <= 0 = x:xs
    | otherwise = quitarNPM xs (n-1)