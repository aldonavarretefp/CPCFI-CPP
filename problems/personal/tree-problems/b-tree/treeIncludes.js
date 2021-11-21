//         a
//     b       c
//   d   e       f
/**  BFS TRAVERSAL
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

const treeIncludes = (root,value) => {
    if(root === null) return false;
    const queue = [root];

    while(queue.length > 0){

        const curr = queue.shift();
        if (curr.val === value) return true;
        
        if(curr.left!== null) queue.push(curr.left);

        if(curr.right!== null) queue.push(curr.right);
    }
    return false;

}

const treeIncludesRecursive = (root,value) => {
    if(root === null) return false;
    if(root.val === value) return true;
    return treeIncludesRecursive(root.left,value) || treeIncludesRecursive(root.right,value);
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

console.log(treeIncludes(a,"g")); // false
console.log(treeIncludesRecursive(a,"e")); //true

