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
        console.log(curr.val);
        if(!curr.right && !curr.left) console.log('no children');

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

const DFSRecursive2 = (root) => {
    if (!root) return;

    console.log(root.val);

    if(root.left)  DFSRecursive2(root.left);
    if(root.right) DFSRecursive2(root.right);
}






const inorder = (root) => {
    if(root === null) return [];
    const leftValues =  inorder(root.left);
    const rightValues = inorder(root.right);
    return [...leftValues,root.val,...rightValues];
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
console.log(DFSRecursive(a));
console.log(inorder(a));
console.log(DFSRecursive2(a));