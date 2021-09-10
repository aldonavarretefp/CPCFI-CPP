#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n;
    cin>>n;
    while(n--){ //Bajando lineas
        ll r,c;
        cin>>r >>c;
        ll z = max(r,c);
        ll vExtremo = (z-1)*(z-1);
        if(z%2 == 0){
            // maximos izq
            cout<<vExtremo-(c-1)<<endl;
        }else{
            //Par, maximos arriba
            cout<<vExtremo-(r-1)<<endl;
        }

    }



    return 0;
}
