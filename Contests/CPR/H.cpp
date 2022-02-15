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
    int n;
    cin >> n;
    vector<string> strings(n);
    for(int i = 0; i < n; i++){
        cin >> strings[i];
    }
    int minLen = INT_MAX;
    int imin = 0;
    
    for(int i = 0; i < n; i++){
        if(minLen > strings[i].length()){
            minLen = strings[i].length();
            imin = i;
        }
    }
    
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        string s1 = strings[imin];
        string s2 = strings[i];
        vector<vector<int>> dp(s1.length() + 1,vector<int>(s2.length() + 1,0));

        for(int j = 0; j <= s2.length(); j++){
            dp[0][j] = 0;
        }
        for(int j = 0; j <= s1.length(); j++){
            dp[j][0] = 0;
        }
        
        for(int j = 1; j <= s1.length(); j++ ){
            for(int k = 1; k <= s2.length(); k++){
                dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
                if(s1[j-1] == s2[k-1]){
                    dp[j][k]++;
                }
            }
        }

        res = min(res,dp[s1.length()][s2.length()]);
    
    }
    cout << res;
    


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}