#include <cstdio>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,caso;
    string str;

    scanf("%d",&n);

    while (n--)
    {
        // scanf("%s\n",&str);
        cin >> str;

        if(str == "1"|| str == "4" || str == "78")
            caso = 0;
        else if(str[str.length()-2] == '3'  && str[str.length()-1] == '5'  && str.length() > 1 )
            caso = 1;
        else if(str[0] == '9'  && str[str.length()-1] == '4'  && str.length() > 1 )
            caso = 2;
        else if(str[0] == '1' &&  str[1] == '9' &&  str[2] == '0'  && str.length() > 1)
            caso = 3;

        printf("%c",(caso==0)?'+':(caso==1)?'-':(caso==2)?'*':'?');
        printf("\n");
    }


    

    return 0;
}