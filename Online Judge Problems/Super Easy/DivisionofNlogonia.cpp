#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int k,n,m,x,y;
    while(k != 0){
        cin>>k;
        if(k==0)return 0;
        cin>>x>>y;
        for (size_t i = 0; i < k; i++)
        {
            cin>>n>>m;
            if(n==x || m==y) printf("divisa\n");
            // I Cuadrante (+,+) NE
            else if(n>x && m>y) printf("NE\n");
            // II Cuadrante (-,+) NO
            else if(n<x && m>y) printf("NO\n");
            // III Cuadrante (-,-) SO
            else if(n<x && m<y) printf("SO\n");
            // IV Cuadrante (+,-) SE
            else if(n>x && m<y) printf("SE\n");


        }
        
    };
    return 0;
}