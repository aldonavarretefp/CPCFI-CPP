//         5
//     11       3
//   4   2        1
/**  BFS MAX ROOT TO LEAF
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


const maxRootToLeafDFSRecursive = (root) => {
    if(root === null) return -Infinity;
    if(root.left === null && root.right === null) return root.val;
    return root.val + Math.max(maxRootToLeafDFSRecursive(root.left),maxRootToLeafDFSRecursive(root.right));
}

const a = new Node(5);
const b = new Node(11);
const c = new Node(3);
const d = new Node(4);
const e = new Node(2);
const f = new Node(1);

a.left  = b;
a.right = c;
b.left  = d;
b.right = e;
c.right = f; 


console.log(maxRootToLeafDFSRecursive(a));

