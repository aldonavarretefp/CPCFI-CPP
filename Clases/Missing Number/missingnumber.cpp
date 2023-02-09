#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    set <int> s;
    ll n,k,aux=1;
    cin>>n;
    for(int i =0 ; i< n ; i++){
        cin>>k;
        s.insert(k);
    }
    set<int >::iterator it ;
    for (it = s.begin() ; it != s.end() ; it++ )
    {
        //cout<<aux<<" ," <<*it<<endl;
        if(aux==*it) aux++;
        else{
            cout<<aux;
            return 0;
        }
    }

    if(aux<=n){
        cout<<n;
    }



    return 0;
}
