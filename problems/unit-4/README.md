# Dynamic Problems Description
## Edit Distance (Bottom - Up porque partimos de los casos en donde hay un empty string en cualquiera de los dos)
Dado dos palabras hay que dar el número minimo de costo de cambios que hay que hacer para formar la otra cadena. Las operaciones admitidas eran 
<ul>
  <li>Add ()</li>
  <li>Replace ()</li>
  <li>Remove (izquierda)</li>
</ul>
Y al final agregamos +1 debido al movimiento que nos encontramos, si dos letras en el mismo indice, pues solo concidera el menor procedimiento de la letra anterior.<br><p align="center"><img src="./CSES_1639-EditDistance/img.png"/></p>

## Rectangle cutting (Bottom - Up)
Dado dos numeros, que son el tamaño de la matriz. Debes de dar el <b>mínimo</b> número de cortes de tal forma que te queden puros cuadrados. <i> Cabe recalcar que un cuadrado puede ser de nxm si son las mismas (P.e. 5x5). Por lo tanto hay 0 formas porque ya es un cuadrado.</i><br>
De igual manera nota que la matriz entonces tiene una diagonal con ceros y la triangular inferior es la misma que la triangular superior. Eso se verifica en el codigo.
<br><p align="center">![Table](./CSES_1744-RectangleCutting/table.png)</p>

## MoneySums
Dado un conjunto de números debemos obtener todas las posibles sumas de dichos numeros ordenados, es por eso que se utiliza un set.<br>
Al final, los numeros que tengan un 1 son las sumas posibles que se pueden obtener usando las monedas. Notas: Se itera por cada moneda.
<br><p align="center"> ![Exp](./CSES_1745-MoneySums/img.png) </p>

## Book Shop (0/1 Snapsack problem)
<p align="center"><img src="./CSES_1158-BookShop/IMG_4014.jpg"/></p>
<p align="center"><img src="./CSES_1158-BookShop/IMG_4016.jpg"/></p>
