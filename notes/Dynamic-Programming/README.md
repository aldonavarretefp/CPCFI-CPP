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


