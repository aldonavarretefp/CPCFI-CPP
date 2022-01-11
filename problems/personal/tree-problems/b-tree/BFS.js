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

const BFS = (root) => {
    if(root === null) return;
    const values = [];
    const queue = [root];

    while(queue.length > 0){
        
        const curr = queue.shift();

        values.push(curr.val);
        
        if(curr.left!== null) queue.push(curr.left);

        if(curr.right!== null) queue.push(curr.right);
    }
    return values;

}
//Levels
const levels = (root) => {
    if(root === null) return;
    const queue = [root];
    let level = 0;
    while(queue.length > 0){
        const q_size = queue.length;
        process.stdout.write(`level ${level}: `);
        for(let i = 0; i < q_size; i++){
            const curr = queue.shift();
            process.stdout.write(`${curr.val} `);
            if(curr.left) 
                queue.push(curr.left);
            if(curr.right) 
                queue.push(curr.right); 
        }
        process.stdout.write('\n');
        level++;
    }
}
var result = [];
const bfsR = (root) =>{
    if(root==null) return [];
    const queue = [root];
    result.push(root.val);
    while(queue.length > 0){
      const qsize = queue.length;
      for(let i = 0 ; i < qsize ; i++){
        const curr = queue.shift();
        // console.log(curr.val);
        // console.log(curr.left," " ,curr.right);
        if(curr.left) 
          queue.push(curr.left);
        if(curr.right) 
          queue.push(curr.right);
      }
      if(queue.length > 0){
        let last = queue[queue.length-1];
        result.push(last.val);
      }
    }
  }

// const a = new Node("a");
// const b = new Node("b");
// const c = new Node("c");
// const d = new Node("d");
// const e = new Node("e");
// const f = new Node("f");

const a = new Node(1);
const b = new Node(2);
const c = new Node(3);
const d = new Node(4);
const e = new Node(5);

a.left  = b;
a.right = c;
b.left  = d;
b.right = e;
// c.right = f; 

// console.log(BFS(a));
// console.log(BFS(b));
console.log(levels(a));

bfsR(a);
console.log(result);

/**
 *    1
 *  2   3
 * 4 5  
 */