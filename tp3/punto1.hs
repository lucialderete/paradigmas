misterio1 x
    | x <= 0 = 0
    | x == 1 = 1
    | otherwise = 2*x + misterio1 (x - 1) - 1

misterio2 0 = 0
misterio2 n = (mod n 10) + misterio2 (div n 10)