#include <cstdio>
#include <bits/stdc++.h>
using namespace std;


int main(){
    double h=1,d,u,f,climbed;
    int day;
    bool aguanta;
    while(cin>> h>> u>>d>> f){        
        if(h==0)break;
        f*=u/100;
        day=0;
        climbed=0;

        
        while(true){
            day++;
            climbed+=u;
            u-=f;
            if (u < 0)u = 0;
            if (climbed > h) {
                aguanta = true; //acaba
                break;
            }
            climbed -= d;
            if (climbed < 0) {
                aguanta = false; //falla
                break;
            }
        };
        if(!aguanta)printf("failure on day %d\n", day);
        else printf("success on day %d\n", day);
    };
    return 0;
}