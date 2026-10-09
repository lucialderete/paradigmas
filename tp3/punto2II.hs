--a. contar recibe una lista y cuenta la cantidad de elementos que contiene.
contar :: [Int] -> Int
contar [] = 0
contar (x:xs) = 1 + contar xs

--b. sumaDeElementos recibe una lista numérica y calcula la suma de sus elementos.
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching

sumaDeElementos :: [Int] -> Int
sumaDeElementos [] = 0
sumaDeElementos (x:xs) = x + sumaDeElementos xs

sumaDeElementos :: [Int] -> Int
sumaDeElementos (xs)
    | xs == [] = 0
    | otherwise = head xs + sumaDeElementos(tail xs)



--c. filtrarLista1 recibe una lista y un elemento y elimina de la lista todas las ocurrencias de ese
elemento.
--i. Realice una versión con Guards
--ii. Realice una versión con Pattern Matching
--iii. Realice una versión con List Comprehension

filtrarLista1 :: [Int] -> [Int]
    | xs == [] 


