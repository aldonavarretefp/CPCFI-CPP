#include <string>
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include  <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    bool palindrome=true;
    while (true) {
        getline (cin,str);
        if(str == "DONE"){
            break;
        }

        str.erase(remove(str.begin(),str.end(),','),str.end());
        str.erase(remove(str.begin(),str.end(),'!'),str.end());
        str.erase(remove(str.begin(),str.end(),'?'),str.end());
        str.erase(remove(str.begin(),str.end(),'.'),str.end());
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        transform(str.begin(), str.end(), str.begin(),[](unsigned char c){ return tolower(c); });

        if( equal(str.begin(), str.begin() + str.size()/2, str.rbegin()) )
            std::cout << "You won't be eaten!\n";
        else
            std::cout << "Uh oh..\n";
        
    }
    return 0;
}