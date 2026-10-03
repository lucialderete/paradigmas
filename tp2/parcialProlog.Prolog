%parcial q me hizo gemini basado en el tp qsyo
%EJERCICIO 1: Base de Conocimiento y Lógica de Reglas

%Dado el siguiente fragmento de una base de conocimiento sobre un sistema de gestión de una biblioteca
%Consigna: Escriba la regla lector_avanzado(Usuario) en PROLOG. Un usuario es considerado "lector avanzado" si cumple TODAS las siguientes condiciones simultáneamente:
%Ha pedido prestados al menos dos libros distintos.
%Esos dos libros pertenecen a distinto género.
%La suma total de las páginas de esos dos libros es mayor a 1000.

% libro(Titulo, Genero, CantidadPaginas).
libro(el_quijote, novela, 863).
libro(cien_anios, novela, 417).
libro(breve_historia_tiempo, ciencia, 256).
libro(el_principito, infantil, 96).

% prestamo(NombreUsuario, TituloLibro).
prestamo(juan, el_quijote).
prestamo(juan, breve_historia_tiempo).
prestamo(maria, cien_anios).
prestamo(luis, el_principito).


lector_avanzado(Usuario):- 
    prestamo(Usuario, Libro1), 
    prestamo(Usuario, Libro2), 
    Libro1 \= Libro2,
    libro(Libro1, Genero1, Pagina1),
    libro(Libro2, Genero2, Pagina2),
    Genero1 \= Genero2,
    Suma is Pagina1 + Pagina2,
    Suma>1000.


%EJERCICIO 2: Recursividad y Filtrado con Múltiples Listas
%Consigna: Implemente la regla recursiva clasificar_edades(ListaEdades, Mayores, Menores) que reciba una lista de números enteros (representando edades) y la separe en dos listas resultantes:
%Mayores: debe contener las edades mayores o iguales a 18.
%Menores: debe contener las edades menores a 18.

%si la lista esta vacia
clasificar_edades([], [], []).

%si el primer elemento es mayor
clasificar_edades([Primero|Resto], [Primero|Mayores], [Menores]):-
    Primero >= 18,
    clasificar_edades(Resto, Mayores, Menores).

%el primer elemento es menor
clasificar_edades([Primero|Resto], Mayores, [Primero|Menores]):-
    Primero < 18,
    clasificar_edades(Resto, Mayores, Menores).


%EJERCICIO 3: Completamiento de Código 
%Se desea implementar una regla contar_ocurrencias(Elemento, Lista, Cantidad) que cuente cuántas veces aparece un elemento específico dentro de una lista.

%caso base
contar_ocurrencias(_, [], 0).

%el primer elemento es igual a X
contar_ocurrencias(X, [Primero|Resto], C):-
    Primero =:= X,
    contar_ocurrencias(X, Resto, Contar),
    C is Contar + 1.

%el primero no es igual a x
contar_ocurrencias(X, [Primero|Resto], C):-
    Primero \= X,
    contar_ocurrencias(X, Resto, C).

%%%%
% a) pedro, maria
% b) juan, ana
% c) juan, ana,
% d)juan

%1.2
%a) 
padreDe(X, Y):- progenitor(X, Y), masculino(X).
%b)
hermanaDe(X, Y):- progenitor(Z, X), progenitor(Z, Y), X\=Y, femenino(X)
%c) 
abueloDe(X, Y):- progenitor(X, Z), progenitor(Z, Y), masculino(X)
%d) 
tioDe(X, Y):- hermanoDe(X, Z), progenitor(Z, Y )

%2.
cantidadMayores([ ], _, 0).

cantidadMayores([Primero|Resto], X, Cantidad):-
       Primero > X,
       cantidadMayores(Resto, X, C),
       Cantidad is C + 1.

cantidadMayores([Primero|Resto], X, Cantidad):-
      Primero<X,
      cantidadMayores(Resto, X, Cantidad).

%b) 
separarParesImpares([ ], [ ], [ ]).
separarParesImpares([Primero|Resto], [Primero|Pares], Impares):-
     Primero mod 2 =:= 0,
     separarParesImpares(Resto, Pares, Impares).
separarParesImpares([Primero|Resto], Pares, [Primero|Impares]):-
    Primero mod 2 =\= 0,
     separarParesImpares(Resto, Pares, Impares).

%3)
sumarDigitos(N, N) :-
    N < 10.

sumarDigitos(N, Suma) :-
    N >= 10,
    Digito is N mod 10,
    Resto is N // 10,
    sumarDigitos(Resto, SumaResto),
    Suma is Digito + SumaResto.

%4) 
misterio([], 0).

misterio([Primero|Resto], R) :-
    misterio(Resto, S),
    R is S + 1.
%la regla misterio suma la cantidad de elementos que tiene la lista
%devuelve 4
%devuelve 0

%5) 
maximoPar([X], X) :-
    X mod 2 =:= 0.

maximoPar([Primero|Resto], Max) :-
    Primero mod 2 =\= 0,
    maximoPar(Resto, Max).

maximoPar([Primero|Resto], Max) :-
    Primero mod 2 =:= 0,
    maximoPar(Resto, MaxResto),
    Primero >= MaxResto,
    Max is Primero.

maximoPar([Primero|Resto], Max) :-
    Primero mod 2 =:= 0,
    maximoPar(Resto, MaxResto),
    Primero < MaxResto,
    Max is MaxResto.
