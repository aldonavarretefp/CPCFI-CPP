

const swap = (arr, i, j) => {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


const insert = (arr, val) => {
    console.log('element to insert: ', val);
    console.log('array: ', arr);
    let index = arr.length - 1;
    arr.push(val);

    while (index > 1){
        let fathexIdx = Math.floor((index-1)/2);
        if (arr[index] > arr[fathexIdx]){
            swap(arr, index, fathexIdx);
            index = fathexIdx;
        }
        else{
            break;
        }
    }

}


const heap = [-1];
heapsize = heap.length;

for(let i = 1; i < 5; i++){
    console.log("inserting:",i);
    insert(heap,i);
}
console.log(heap);
// 3
// 2 1
//