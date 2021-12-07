/*
When you encrypt a string S, you start with an initially-empty resulting string R and append characters to it as follows:
Append the middle character of S (if S has even length, then we define the middle character as the left-most of the two central characters)
Append the encrypted version of the substring of S that's to the left of the middle character (if non-empty)
Append the encrypted version of the substring of S that's to the right of the middle character (if non-empty) 
*/

const helper = (s,i,j) => {
    if(i>j) return "";
    if(i==j) return s[i];
    let mid = Math.floor((i+j)/2);
    return  s[mid] + helper(s,i,mid-1) + helper(s,mid+1,j);
}

const s = "abcd";
console.log(helper(s,0,s.length-1));