--recibe un numero natural y cuenta los digitos
contarDigitos :: Int -> Int
contarDigitos 0 = 0
contarDigitos n = (n mod 10) + contarDigitos(div n 10)

--b recibe un numero natural y calcula el producto de sus digitos
productoDeDigitos :: Int -> Int
productoDeDigitos 0 = 0
productoDeDigitos n = (n mod 10) * productoDeDigitos(div n 10)

--c recibe un numero natural y determina si tiene algun numero igual a 0
tieneCeros :: Int -> Bool
tieneCeros 0 = True
tieneCeros n 
    | n < 10 = n ==0
    | n `mod` 10 == 0 = True
    | otherwise = tieneCeros(div n 10)

--d. encontrarMenor recibe un número natural y encuentra el dígito de menor valor
encontrarMenor :: Int -> Int
encontrarMenor natural  
    | n < 10 = n
    | otherwise = encontrarMenor(div n 10)
        let digito = n `mod` 10
            menorResto = encontrarMenor(n `div` 10)

        let if digito < menorResto
            then digito
            else menorResto

--e. crearLista recibe un número natural n y crea una lista con los n números naturales
crearLista 0 = []
crearLista n = crearLista (n - 1) ++ [n]

-f divisiónEntera: recibe dos números naturales y realiza la división entera entre dichos
números mediante restas sucesivas.
divisiónEntera :: Int -> Int
divisiónEntera n d
    | n < d =0

divisiónEntera n d
    | n >= d = 1 + divisiónEntera(n - d) d

