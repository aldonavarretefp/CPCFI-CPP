

const binarySearchRec = (arr, key,l,r) => {
    if( l > r) return -1;
    let mid = Math.floor(l + (r-l)/2);
    if(key == arr[mid]) return mid;
    if(key<arr[mid]) return binarySearchRec(arr,key,l,mid-1);
    else return binarySearchRec(arr,key,mid+1,r);
}
const binarySearchIter = (arr,key) => {
    let l = 0 ;
    let r = arr.length-1;
    while(l <= r){
        let mid = Math.floor(l + (r-l)/2);
        if( key == arr[mid])
            return mid;
        if(key<arr[mid])
            r = mid-1;
        else
            l = mid + 1;
    }
    return -1;
}
const peakElementIdx = (arr) => {
    let l = 0 ;
    let r = arr.length-1;
    while(l < r){
        let mid = Math.floor(l + (r-l)/2);
        if(arr[mid] < arr[mid+1])
            l = mid + 1;
        else
            r = mid;
    }
    return arr[l];
}
const findMinInShifted = (arr) => {
    let l = 0; 
    let r = arr.length-1;
    while( l < r){
        let mid = Math.floor(l + (r-l)/2);
        if(arr[mid] > arr[r]){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    return arr[l];
}

const findIndexInShited = (arr,target) =>{
    //arr = [ 11,12,6,7,8,9,10]; target 10
    /*                       lr */
    let l = 0;
    let r = arr.length-1;
    while(l <= r ) {
        let mid = Math.floor(l + (r-l)/2);
        if(arr[mid] == target)
            return mid;
        if(arr[l] < arr[mid]){ //search left if target there
            if(arr[l] <= target && target < arr[mid])
                r = mid-1;
            else
                l = mid+1;
        }else{
            if(arr[mid] < target && target <= arr[r])
                l = mid+1;
            else
                r = mid-1;
        }
    }
    // if(l <= arr.length-1 && arr[l] == target)
    //     return l;
    return -1;
}

//Sorted array
//           0  1  2  3  4  5  6  7  8  9
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// Binary search recursive
console.log(binarySearchRec(arr, 4,0,arr.length-1)); // 3
console.log(binarySearchRec(arr, 9,0,arr.length-1)); // 8
console.log(binarySearchRec(arr, 1,0,arr.length-1)); // 0
console.log();
//Binary search iterative
console.log(binarySearchIter(arr, 4)); // 3
console.log(binarySearchIter(arr, 9)); // 8
console.log(binarySearchIter(arr, 1)); // 0
console.log();

//Peak element
arr = [ 10, 20, 1000,999,998,997,996,995];
console.log(peakElementIdx(arr)); // 1000
console.log();

//Find min in shifted arr
arr = [ 11,12,6,7,8,9,10];

console.log(findMinInShifted(arr)); // 6
console.log();

arr = [ 11,12,6,7,8,9,10];
console.log(findIndexInShited(arr,11)) //2

