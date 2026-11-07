progenitor(mufasa, simba).
progenitor(sarabi, simba).
progenitor(ahadi, mufasa).
progenitor(uru, mufasa).
progenitor(ahadi, scar).
progenitor(uru, scar).
masculino(mufasa).  
masculino(simba).  
masculino(ahadi).  
masculino(scar).
femenino(sarabi).   
femenino(uru).

% Formule una regla medio_hermanos(X, Y) que determine si dos individuos comparten exactamente un solo progenitor (no ambos). Evite que un individuo sea medio hermano de sí mismo.
medio_hermanos(X, Y) :-
    progenitor(Z, X),           % Comparten un progenitor común Z
    progenitor(Z, Y),
    X \= Y,                     % Evita que un individuo sea medio hermano de sí mismo
    \+ (progenitor(P, X), progenitor(P, Y), P \= Z). % Niega que exista OTRO progenitor común P diferente de Z

   