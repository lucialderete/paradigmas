import System.Win32 (COORD(yPos, xPos), SECURITY_ATTRIBUTES (nLength))
import Graphics.Win32 (fillRect)
-- a)  contarDigitos recibe un número natural y cuenta cuántos dígitos posee el mismo
contarDigitos n
    | n < 10 = 1
    | otherwise = 1 + contarDigitos (n `div` 10)

-- b. productoDeDigitos recibe un número natural y calcula el producto de sus dígitos.

productoDeDigitos n
    | n < 10  = n
    | otherwise = (n `mod` 10) * productoDeDigitos(n `div` 10)


-- c. tieneCeros recibe un número natural y determina si el número tiene algún dígito igual a 0.
tieneCeros n 
    | n < 10 = n == 0
    | otherwise = tieneCeros(n `div` 10) || (n `mod` 10 == 0)

-- d. encontrarMenor recibe un número natural y encuentra el dígito de menor valor
encontrarMenor n
    | n < 10 = n
    | otherwise =
        if n `mod` 10 < encontrarMenor(n `div` 10)
            then n `mod` 10
            else encontrarMenor(n `div` 10)

-- e. crearLista recibe un número natural n y crea una lista con los n números naturales.

crearLista n 
    | n == 0 = []
    | otherwise = crearLista(n-1) ++ [n]

-- f. divisiónEntera: recibe dos números naturales y realiza la división entera entre dichos números mediante restas sucesivas.

divisionEntera x y
    | x < y = 0
    | otherwise = divisionEntera(x-y) y + 1


-- punto2
-- a. contar recibe una lista y cuenta la cantidad de elementos que contiene

contar :: [a] -> Int
contar [] = 0
contar (xs) = 1 + contar (drop 1 xs)

-- b. sumaDeElementos recibe una lista numérica y calcula la suma de sus elementos.
-- i. Realice una versión con Guards
-- ii. Realice una versión con Pattern Matching
sumaElementosG :: [Int] -> Int
sumaElementosG xs 
    | null xs =0
    | otherwise = head xs +sumaElementosG (tail xs) 

sumaElementosPM :: [Int] -> Int
sumaElementosPM [] = 0
sumaElementosPM (x:xs) = x + sumaElementosPM xs

-- c.. filtrarLista1 recibe una lista y un elemento y elimina de la lista todas las ocurrencias de ese elemento
filtrarListaG xs y
    | null xs = []
    | head xs == y = filtrarListaG(tail xs) y
    | otherwise = head xs : filtrarListaG(tail xs) y

filtrarListaPM :: [Int] -> Int -> [Int]
filtrarListaPM [] y= []
filtrarListaPM (x:xs) y 
    | x == y = filtrarListaPM xs y
    | otherwise = x : filtrarListaPM xs y

filtrarListaLC :: [Int] -> Int -> [Int]
filtrarListaLC xs y = [x | x <- xs, x/=y]

-- d. invertirLista recibe una lista y devuelve la lista invertida.
invertirLista :: [Int] -> [Int]
invertirLista [] = []
invertirLista (x:xs) = invertirLista xs ++ [x]

-- e. subLista1 recibe una lista y un número natural n y retorna una lista con los primeros n elementos de la lista dada. No utilice take.
sublista :: [Int] -> Int -> [Int]
sublista xs y
    | y <= 0 = []
    | null xs = []
    |otherwise = head xs : sublista (tail xs) (y-1)

-- f. subLista2 recibe una lista y un número natural n y retorna una lista sin los primeros n elementos de la lista dada. No utilice drop.
sublista2 :: [Int] -> Int -> [Int]
sublista2 xs n
    | n <= 0 = xs
    | null xs = []
    | otherwise = sublista2(tail xs) (n-1)

-- g. intersección recibe dos listas y devuelve una nueva lista con los elementos que tienen en común las listas dadas
interseccion :: [Int] -> [Int] -> [Int]
interseccion [] y = []
interseccion (x:xs) y
    | x `elem`y = x : interseccion xs y
    | otherwise = interseccion xs y