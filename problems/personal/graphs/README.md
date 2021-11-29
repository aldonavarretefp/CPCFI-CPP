# Graphs Notes.

## Number of Edges simple graph:  
(directed) 0 <= |E| <= n(n-1) (O sea para cada nodo, puede estar conectado con cualquier otro nodo)
<br>
(undirected) 0 <= |E| <= n(n-1)<b>/2</b><br>

### Grafo denso -> muchas aristas. (adjacency matrix)
### Grafo no denso (sparse-escaso) -> pocas aristas. (adjacency list)

<br>

## Paths simple graph:
<br>

### Walk: Un conjunto de aristas 
### Closed walk: Una secuencia de aristas que termina en un nodo mismo
### Path: Un walk en donde no repito nodos (y por lo tanto no aristas.)
### Trail: Un path en donde no repito aristas.

### Strongly connected Graph: 
Un grafo en donde todos los nodos estan conectados.
### Weakly connected Graph: 
Un grafo en donde al menos uno de los nodos esta conectado.

### Cycle: Una secuencia de aristas que termina en un nodo mismo.

### Acyclic Graph: Un grafo que no tiene ciclos.
Directed acyclic graph: DAG. (Find shortest path).
