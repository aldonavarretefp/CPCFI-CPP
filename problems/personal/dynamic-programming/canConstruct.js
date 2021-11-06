const canConstruct = (target,wordBank, memo = {}) => {
    if(target in memo) return memo[target];
    if(target.length === 0) return true;

    
    for (let word of wordBank){
        if(target.indexOf(word) === 0){ //'abc' in 'abcdef'
            const suffx = target.slice(word.length); //suffix = 'def'
            if(canConstruct(suffx,wordBank, memo)){
                memo[target] = true;
                return true;
            }}
    }
    memo[target] = false;
    return false;
}

console.log(canConstruct('abcdef',['ab','abc','cd','def','abcd']));
console.log(canConstruct('skateboard',['bo','rd','ate','t','ska','sk','boar']));
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef',[
    'e',
    'ee',
    'eeee',
    'eeeeeeee',
    'eeeeeeeeee',
    'eeeeeeeeeeeeeeeeee'
]));

// Problem:
// Given a string and a dictionary of words
// find if it is possible to form a target string
// by using the words in the word bank.

// Brute force:
// The height of the tree is the length of the target string
// you do it n times
// and if you need to search the 'slice' of the target string
// so you multiply by m
// Time: O(n^m * m)
// We need extra espace to store de suffix m times.
// Space: O(mˆ2)



