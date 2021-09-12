#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int counter = 0,maximo = 1 ;
    char letra='A';
    cin>>str;
    for(char c: str){
        if(c==letra){
            counter++;
            maximo = max(counter,maximo); // Maximo va cambiando
        }else{
            letra = c;
            counter=1;
        }
    }
    cout<<maximo;

    return 0;
}
