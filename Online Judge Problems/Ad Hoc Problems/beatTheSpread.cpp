#include <string>
#include <cstdio>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(int argc, char** argv){

    int k,s,d;
    int w, l; //winner, loser
    scanf("%i",&k);
    while(k--){
        scanf("%d %d",&s,&d);
        if(d>s){
            printf("impossible\n");
        }
        else{
            l = (s - d)/2;
			w = d + l;
			if(l + w == s && abs(w-l)==d) printf("%d %d\n", w, l);
			else printf("impossible\n");
        }
    }
    return 0;
}