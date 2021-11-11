const canSum = (targetSum,numbers) => {
    
    const table = Array(targetSum+1).fill(false);
    table[0] = true;
    for(let i = 0 ; i<= targetSum; i++){
        if(table[i]){ // If current sum is true
            for(let num of numbers){
                table[i+num] = true;                
            }
                
        }
    }
    return table[targetSum];
}

console.log(canSum(7,[2,3])); // true
console.log(canSum(7,[5,3,4,7])); // true
console.log(canSum(7,[4,2])); // false
console.log(canSum(8,[2,3,5])); // true
console.log(canSum(10,[1,2,3,4,5,6,7,8,9,10]));
console.log(canSum(10,[1,2,3,4,5,6,7,8,9,10,11]));

// Complexity:
// Time: O(m*n)
// Space: O(m)