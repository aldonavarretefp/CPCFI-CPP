#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie (0 );
    int nEntradas;
    cin>>nEntradas;
    for (int i=0; i<nEntradas; i++)
    {
        cin >> t;
        if (t % k == 0)
            cnt++;
    }
    return 0;
}
