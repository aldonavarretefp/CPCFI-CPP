const canConstruct = (target, wordBank) => {
    const table = new Array(target.length + 1).fill(false);
    table[0] = true;
    for (let i = 0 ; i <= target.length ; i++ ){
        if(table[i] === true){
            for (let word of wordBank){
                // Lets check if match
                if (target.slice(i,i+word.length)===word)
                    table[i+word.length] = true;
            }
        }
    }
    return table[target.length];
}

console.log(canConstruct('abcdef',['ab','abc','cd','def','abcd']));  // true
console.log(canConstruct('skateboard',['bo','rd','ate','t','ska','sk','boar']));  // false



//Complexity:

// Time:
    //Table: m
    //WordBank: n
    //slicing words m
    //O(mˆ2*n)
// Space:
    //Table: m
    //O(m)
