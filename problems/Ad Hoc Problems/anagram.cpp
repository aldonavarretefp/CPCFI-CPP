#include <cstdio>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

bool comparacion(char A, char B){

	char a = tolower(A);
	char b = tolower(B);
	if( a == b ){ //Si son iguales compara a sus mayusculas
        if(A<B) return true;
        else return false;
    }
    if(a<b) return true;
    else return false;
}
int main() {
    int k;
    char str[100];

    scanf("%i",&k);
    while(k--){
        scanf("%s",&str);
        int n = strlen(str);
        std::sort (str,str+n,comparacion);

        // std::cout << "The 3! possible permutations with 3 elements:\n";
        //next permutations c++
         do {
            std::cout << str<<'\n';
        } while ( std::next_permutation(str,str+n,comparacion) );
    }
        
    return 0;
}