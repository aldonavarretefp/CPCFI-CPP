#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x)
#define pll(x)          printf("%lld\n", x)
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file+"in";
    string output_file =file+"out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

void solve() {
    int c,b,maxGames=0;
    si(c);
    si(b);
    while(c--){
        int price,games;
        si(price);
        si(games);
        if(price <= b && games>maxGames)
            maxGames=games;
    }
    printf("%d\n",maxGames);
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T; si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}