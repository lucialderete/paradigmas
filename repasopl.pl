/* contar n elementos 
contar([], 0).
contar([X|Resto], N) :-
    contar(Resto, N1),
    N is N1 + 1.


% sumar elementos
sumar([], 0).
sumar([X|Resto], Total):-
    sumar(Resto, SumaResto),
    Total is X + SumaResto.


% eliminar ocurrencias
eliminar(X, [], []).

eliminar(X, [X|Resto], Resultado):-
    eliminar(X, Resto, Resultado).

eliminar(X, [Y|Resto], [Y | Resultado]):-
    X \= Y,
    eliminar(X, Resto, Resultado).


% invertir lista

invertir(Lista, Invertida) :-
    invertirAux(Lista, [], Invertida).

% caso base si la lista esta vacia
invertirAux([], Acumulador, Acumulador).

invertirAux([X | Resto], Acumulador, Resultado) :-
    invertirAux(Resto, [X | Acumulador], Resultado).

% contar digitos
contarDigitos(0, 1).
contarDigitos(Numero, Total):-
    Numero < 10,
    Total is 1.

contarDigitos(Numero, Total):-
    Numero >= 10,
    NuevoNum is Numero div 10,
    contarDigitos(NuevoNum, Suma),
    Total is Suma +1.

    
% producto de digitos
productoDigitos(0, 0).
productoDigitos(Numero, Producto):-
    Numero < 10,
    Producto is Numero.
productoDigitos(Numero, Producto):-
    Numero >= 10,
    NuevoNum is Numero div 10,
    UltimoD is Numero mod 10,
    productoDigitos(NuevoNum, Multiplica),
    Producto is Multiplica * UltimoD.
    */

/*
contarPares(0, 0).
contarPares(Numero, Cantidad):-
    Numero < 10,
    Numero mod 2 =:= 0,
    Cantidad is 1.

contarPares(Numero, Cantidad):-
    Numero < 10,
    Numero mod 2 =\= 0,
    Cantidad is 0.

contarPares(Numero, Cantidad):-
    Numero >= 10,
    UltimoDigito is Numero mod 10,
    NuevoN is Numero div 10,
    contarPares(NuevoN, Suma),
    UltimoD mod 2 =:= 0,
    Cantidad is Suma + 1.

contarPares(Numero, Cantidad):-
    Numero >= 10,
    UltimoDigito is Numero mod 10,
    NuevoN is Numero div 10,
    contarPares(NuevoN, Suma),
    UltimoD mod 2 =\= 0,
    Cantidad is Suma.

% encontrarMenor digito
menorDigito(Numero, Menor):-
    Numero < 10,
    Menor is Numero.

menorDigito(Numero, Menor):-
    Numero >= 10,
    UltimoD is Numero mod 10,
    RestoN is Numero div 10,
    menorDigito(RestoN, MenorResto),
    UltimoD < MenorResto,
    Menor is UltimoD.

menorDigito(Numero, Menor):-
    Numero >= 10,
    UltimoD is Numero mod 10,
    RestoN is Numero div 10,
    menorDigito(RestoN, MenorResto),
    UltimoD > MenorResto,
    Menor is MenorResto.
   

% sumar digitos
sumarDigitos(Numero, Suma):-
    Numero < 10,
    Suma is Numero.

sumarDigitos(Numero, Suma):-
    Numero >= 10,
    UltimoD is Numero mod 10,
    NuevoNum is Numero div 10,
    sumarDigitos(NuevoNum, Sumar),
    Suma is UltimoD + Sumar.

% contarMayores
% caso base, la lista esta vacia
cantidadMayores([], X, Cantidad):-
    Cantidad is 0.
% cuando la lista no esta vacia y H es MAYOR que X
cantidadMayores([H|Resto], X, Cantidad):-
    H > X,
    cantidadMayores(Resto, X, Suma),
    Cantidad is Suma + 1.
*/
% cuando la lista no esta vacia y H es menor que x
cantidadMayores([H|Resto], X, Cantidad):-
    H =< X,
    cantidadMayores(Resto, X, Cantidad).

% separar pares impares
% caso base, la lista esta vacia
separar([], [], []).

separar([H|Resto], [H|Pares], Impares):-
    H mod 2 =:= 0,
    separar(Resto, Pares, Impares).

separar([H|Resto], Pares, [H|Impares]):-
    H mod 2 =\= 0,
    separar(Resto, Pares, Impares).

% eliminar duplicados consecutivos
eliminarConsecutivos([], []). %caso base cuando la lista esta vacia
eliminarConsecutivos([X], [X]). %cuando la lista tiene un solo elemento
eliminarConsecutivos([H, H|Resto], ListaFinal):- %inicio de la lista es igual al que le sigue
    eliminarConsecutivos([H|Resto], ListaFinal).

eliminarConsecutivos([X, Y|Resto], [X|ListaFinal]):-%inicio de la lista es distinto al q le sigue
    X \= Y,
    eliminarConsecutivos([Y|Resto], ListaFinal).