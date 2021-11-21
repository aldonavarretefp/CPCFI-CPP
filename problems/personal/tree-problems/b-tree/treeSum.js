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

const sumBFS = (root) => {
    if(root === null) return -1;
    const values = [];
    const queue = [root];
    let globalSum = 0;

    while(queue.length > 0){

        const curr = queue.shift();

        values.push(curr.val);
        globalSum += curr.val;
        
        if(curr.left!== null) queue.push(curr.left);

        if(curr.right!== null) queue.push(curr.right);
    }
    return globalSum;

}
const sumDFSRecursive = (root) => {
    if(root === null) return 0;
    return root.val + sumDFSRecursive(root.left) + sumDFSRecursive(root.right);
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

console.log(sumBFS(a));
console.log(sumDFSRecursive(a));

