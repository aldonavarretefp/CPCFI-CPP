# Dynamic Programming
Maximize, Minimize...
Observe if there is sub-structures.

## UVa 11450
Algunas posibles soluciones vistas anteriormente
<ul>
   <li>Greedy: Wrong Answer porque buscaria el mayor para cada categoría de prenda</li>
   <li>Complete Search: Time Limit Exceeded porque buscaría todas las posibles soluciones.</li>
   <li>Divide and Conquer: Impossible porque los subproblemas no son independientes.</li>
   <li>Top-Down DP: Correct Answer</li>
   <li>Bottom-Up DP: Correct Answer</li>
</ul>

### Top-Bottom DP
Se inicializa la tabla con valores dummies(-1,±INF). <br> 

### Bottom-Up DP
Se inicializa solo algunas casillas con el/los caso(s) base(s).


## Classical problems

### Max 1D Range Sum

### Max 2D Range Sum
Given a matrix find the submatrix such that its sum its the maximum one.

## Longest Increasing Subsequence (LIS)
They are not necesarily contiguous.



## 0/1 Snapsack 
Bag, value, weight, maximize the # of items


## Traveling SalesMan DP + Bitmasking
Tenemos 4 ciudades (vertices), y las aristas con costo las unen.<br>
Tienes que visitar todas las ciudades 1 única vez y regresar al punto de inicio. <br>
Además de tener el costo mínimo. <br>
En este problema solo hay 16 ciudades (o un número pequeño)<b> 1 <= n <= 16</b><br>
Aqui cambia un poco las cosas porque ahora a los conjuntos de donde tomamos las 
ciudades lo representaremos con numeros binarios. (bitmask) <br>
{A,B,C,D} = 1011 (Estamos tomando el conjunto {A,C,D}<br>
Complejidad: O(nˆ2 2^n) Como en el libro para instancias de 15 a 18.<br>
Haciendo la siguiente operación:<br>
x | (1<<i) Prender el bit a visited que corresponde a next. <br>

# Problemas NO CLASICOS

## UVa 10943 How do you add? (Range dp)
Dado un entero n y k digitos dispoible, cuantas formas hay de sumar ese 
número con K digitos.<br>
En complejidad, se vuelve factorial, porque ocupa distribución binomial.<br>
Estados.<br>
Transiciones.<br>

## Palos
Tienes un palo de l longitud y debes calcular el costo mínimo para hacer los 
cortes en las coordenadas o puntos especificados en un array. Este problema
se resuelve de forma recursiva.

