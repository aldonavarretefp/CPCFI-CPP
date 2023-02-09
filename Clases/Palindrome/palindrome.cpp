
#include <bits/stdc++.h>
#include <iostream>
#include <map>

/* Cuando un numero es par su salida de operación %2 sale cero*/
using namespace std;
int main()
{
    string str;
    map<char,string> mapa;
    cin>>str;
    //Guardando numero de instancias
    for (char c: str){
        if(mapa.count(c)) mapa[c] += c;
        else mapa[c] = c;
    }
    string impar,primeraMitad,segundaMitad;
    for(auto &x:mapa){
        //cout<<x.first<< " , "<< x.second<<endl;
        if(x.second.length()%2 == 1 && impar != ""){ // impar
            cout<<"NO SOLUTION";
            return 0;

        }else if ( x.second.length() % 2 == 1 ){
            impar = x.second;
        }else{
            primeraMitad += x.second.substr(0,x.second.length()/2);
            segundaMitad = x.second.substr(0,x.second.length()/2)+segundaMitad;
        }
    }
    cout<< primeraMitad + impar + segundaMitad;


    return 0;

}
