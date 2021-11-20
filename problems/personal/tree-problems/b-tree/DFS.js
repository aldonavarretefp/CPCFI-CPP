/**     DFS Traversal O(n)
 * Se implementa una pila
 * en este caso se puede iterativamente y recursivamente.
 */
//         a
//     b       c
//   d   e       f

class Node {
    constructor (value){
        this.val = value;
        this.left = null;
        this.right = null;
    }
}

const DFSIterative = (root) => {
    if(root === null ) return [];
    const stack = [root];
    const values = [];
    while(stack.length > 0){
        const curr = stack.pop();
        values.push(curr.val);

        if(curr.right) stack.push(curr.right );
        if(curr.left) stack.push(curr.left);
    }
    return values;

}
const DFSRecursive = (root) => {
    if (root === null) return [];
    const leftValues =  DFSRecursive(root.left);
    const rightValues = DFSRecursive(root.right);

    return [root.val,...leftValues,...rightValues];

}







const a = new Node("a");
const b = new Node("b");
const c = new Node("c");
const d = new Node("d");
const e = new Node("e");
const f = new Node("f");

a.left  = b;
a.right = c;
b.left  = d;
b.right = e;
c.right = f; 

console.log(DFSIterative(a));