class Node{
    constructor(value){
        this.val = value;
        this.left = null;
        this. right = null;
    }
}
let COUNT = 10;
function print2D(root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
function print2DUtil(root,space)
{
    // Base case
    if (root == null)
        return;
   
    // Increase distance between levels
    space += COUNT;
   
    // Process right child first
    print2DUtil(root.right, space);
   
    // Print current node after space
    // count
    process.stdout.write("\n");
    for (let i = COUNT; i < space; i++)
        process.stdout.write("  ");
    process.stdout.write(root.val + "\n");
   
    // Process left child
    print2DUtil(root.left, space);
}

const printLevels = (root)=>{
    if(!root) return;
    const queue = [root];
    let level = 0;
    while (queue.length > 0){
        let qsize = queue.length;
        process.stdout.write(`Level ${level}:`);
        for(let i = 0; i < qsize; i++){
            const curr = queue.shift();
            process.stdout.write(` ${curr.val}`);
            if(curr.left)
                queue.push(curr.left);
            if(curr.right)
                queue.push(curr.right);
        }
        process.stdout.write(`\n`);
        level++;
        
    }
}
const insert = (root,val) =>{
    if(!root)
        return new Node(val);

    if (val <= root.val){
        root.left = insert(root.left,val);
    }else{
        root.right = insert(root.right,val);
    }
    return root;
}

const preorder = (root) =>{
    if(!root)
        return;
    process.stdout.write(`${root.val}   `);
    preorder(root.left);
    preorder(root.right);
}

const root = insert(null,9); // La primera vez se modifica la raiz.
    insert(root,10);
    insert(root,2);
    insert(root,3);
    insert(root,1);
    insert(root,8);

/**
 *    1
 *  2   3
 * 4 5  
 */

printLevels(root);
print2D(root);
console.log('\n\n');
preorder(root);

