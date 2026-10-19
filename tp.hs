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

-- h. subLista2 recibe una lista numérica, un número entero x, un número natural n y retorna una lista con los primeros n elementos de la lista dada que sean mayores que x. Utilice Pattern Matching

sublista3 :: [Int] -> Int -> Int -> [Int]
sublista3 [] y n = []
sublista3 xs y n
    | n <= 0 = []
sublist3a (x:xs) y n
    | x > y = x:sublista3 xs y (n-1)
    |otherwise = sublista3 xs y n


-- i. verificar recibe un predicado p (un predicado es una función que devuelve un valor booleano) y una lista de elementos xs y devuelve True si todos los elementos de la lista satisfacen el predicado, caso contrario retorna False.
-- i. Realice una versión con Guards
-- ii. Realice una versión con Pattern Matching
-- iii. Realice una versión con List Comprehension

esPositivo :: Int -> Bool
esPositivo n = n > 0

verificar :: (a -> Bool) -> [a] -> Bool
verificar p xs
    | null xs = True
    | p (head xs) = verificar p (tail xs)
    | otherwise = False 

verificarPM :: (a -> Bool) -> [a] -> Bool
verificarPM p [] = True
verificarPM p (x:xs)
    | p x = verificarPM p xs
    | otherwise = False

verificarLC :: (a -> Bool) -> [a] -> Bool
verificarLC p xs = null[x | x <- xs, not (p x)]

-- j. filtrarLista2 recibe un predicado y una lista y devuelve la lista de elementos que satisfacen el predicado. La signatura de la función debería ser: filtrarLista2 :: (a -> Bool) -> [a] -> [a]
-- i. Realice una versión con Guards
-- ii. Realice una versión con Pattern Matching
-- iii. Realice una versión con List Comprehension

filtrarLista2 :: (a -> Bool) -> [a] -> [a]
filtrarLista2 p xs 
    | null xs = []
    | p (head xs) = head xs : filtrarLista2 p (tail xs)
    | otherwise = filtrarLista2 p (tail xs)

filtrarlista2PM :: (a -> Bool) -> [a] -> [a]
filtrarLista2PM p [] = []
filtrarlista2PM p (x:xs) 
    |p x = x : filtrarlista2PM p xs
    |otherwise = filtrarlista2PM p xs

filtrarlista2LC :: (a -> Bool) -> [a] -> [a]
filtrarlista2LC p xs = [x | x <- xs, p x]

-- k transformar recibe como parámetros una función f (de un argumento) y una lista y devuelve como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f. version con guards, pattern matching y list comprehension
transformar :: (a -> b) -> [a] -> [b]
transformar f xs
    | null xs = []
    | otherwise = f (head xs) : transformar f (tail xs)

transformarPM :: (a-> b) -> [a] -> [b]
transformarPM f [] = []
transformarPM f (x:xs) = f x : transformar f xs

transformarLC :: (a-> b) -> [a] -> [b]
transformarLC f xs= [f x | x <- xs]
