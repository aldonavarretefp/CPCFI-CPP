const howSum = (targetSum, nums) => {
    const table = Array(targetSum + 1).fill(null);
    table[0] = [];

    for(let i = 0 ; i<= targetSum; i++){
        if (table[i] != null){
            for (let num of nums){
                table[i + num] = [...table[i], num];
            }
        }
    }
    return table[targetSum];
}

console.log(howSum(7, [2,3])); // [3,2,2]
console.log(howSum(7, [5,3,4])); // [4,3]
console.log(howSum(7, [2,4])); // null

// Complexity:
// Time: O(m*n*m) = O(m^2*n)
// Space: O(m)