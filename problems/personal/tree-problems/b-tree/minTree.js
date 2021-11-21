//         a
//     b       c
//   d   e       f
/**  BFS TRAVERSAL SUM
 * Recuerda que en este algoritmo se emplea una queue, 
 * La complejidad es O(n), porque vemos cada uno de los nodos.
 */


 class Node{
    constructor(value){
        this.val = value;
        this.left = null;
        this. right = null;
    }
}

const minBFS = (root) => {
    if(root === null) return -1;
    const values = [];
    const queue = [root];
    let min = 10e9;

    while(queue.length > 0){

        const curr = queue.shift();

        values.push(curr.val);
        min = Math.min(min,curr.val);
        
        if(curr.left!== null) queue.push(curr.left);

        if(curr.right!== null) queue.push(curr.right);
    }
    return min;

}
const minDFSRecursive = (root) => {
    if(root === null) return 10e9;
    return Math.min(root.val, minDFSRecursive(root.left) ,minDFSRecursive(root.right));
}

const a = new Node(3);
const b = new Node(11);
const c = new Node(4);
const d = new Node(4);
const e = new Node(2);
const f = new Node(1);

a.left  = b;
a.right = c;
b.left  = d;
b.right = e;
c.right = f; 

console.log(minBFS(a));
console.log(minDFSRecursive(a));

