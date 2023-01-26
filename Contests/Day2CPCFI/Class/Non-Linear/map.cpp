#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define PD(t) printf("%d",t)
#define PLD(t) printf("%ld",t)
#define PLLD(t) printf("%lld",t)
#define PC(t) printf("%c",c)
#define PS(t) printf("%s",t)
#define PF(t) printf("%f",t)
#define PLF(t) printf("%lf",t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FO(i, b) for(int  i = 0; i<b; i++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define read(type) readInt<type>()
#define TR(v,arr) for (auto& (v): (arr))
#define endl '\n'
#define fastIO cin.tie(0); cout.tie(0);
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef queue<int> QI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void solve(){
    int i;
 
    // Declaring maps
    map<int, int> M;
    unordered_map<int, int> UM;
    multimap<int, int> MM;
    unordered_multimap<int, int> UMM;
 
    // Inserting  pairs of key
    // and value
    for (i = 101; i <= 105; i++) {
 
        // Inserted the Key and
        // value twice
        M.insert(
            pair<int, int>(i - 100, i));
        UM.insert(
            pair<int, int>(i - 100, i));
        M.insert(
            pair<int, int>(i - 100, i));
        UM.insert(
            pair<int, int>(i - 100, i));
    }
    for (i = 101; i <= 105; i++) {
 
        // Inserted the key and
        // value twice
        MM.insert(
            pair<int, int>(i - 100, i));
        UMM.insert(
            pair<int, int>(i - 100, i));
        MM.insert(
            pair<int, int>(i - 100, i));
        UMM.insert(
            pair<int, int>(i - 100, i));
    }
 
    // Iterators for accessing
    map<int, int>::iterator Mitr;
    unordered_map<int, int>::iterator UMitr;
    multimap<int, int>::iterator MMitr;
    unordered_multimap<int, int>::iterator UMMitr;
 
    // Output
    cout << "In map" << endl;
    cout << "Key"
         << " "
         << "Value" << endl;
 
    for (Mitr = M.begin();
         Mitr != M.end();
         Mitr++) {
        cout << Mitr->first << "   "
             << Mitr->second
             << endl;
    }
 
    // Unsorted and is unordered output
    cout << "In unordered_map" << endl;
    cout << "Key"
         << " "
         << "Value" << endl;
    for (UMitr = UM.begin();
         UMitr != UM.end();
         UMitr++) {
        cout << UMitr->first
             << "   "
             << UMitr->second
             << endl;
    }
 
    // Sorted output
    cout << "In multimap" << endl;
    cout << "Key"
         << " "
         << "Value" << endl;
    for (MMitr = MM.begin();
         MMitr != MM.end();
         MMitr++) {
        cout << MMitr->first
             << "   "
             << MMitr->second
             << endl;
    }
 
    // Unsorted and is unordered
    // output
    cout << "In unordered_multimap"
         << endl;
    cout << "Key"
         << " "
         << "Value" << endl;
 
    for (UMMitr = UMM.begin();
         UMMitr != UMM.end();
         UMMitr++) {
        cout << UMMitr->first
             << "   " << UMMitr->second
             << endl;
    }
 
    cout << "The erase() function"
         << " erases respective key:"
         << endl;
    M.erase(1);
 
    cout << "Key"
         << " "
         << "Value" << endl;
 
    for (Mitr = M.begin();
         Mitr != M.end(); Mitr++) {
        cout << Mitr->first
             << "   " << Mitr->second
             << endl;
    }
 
    cout << "The find() function"
         << " finds the respective key:"
         << endl;
    if (M.find(1) != M.end()) {
        cout << "Found!" << endl;
    }
    else {
        cout << "Not Found!" << endl;
    }
 
    cout << "The clear() function "
         << "clears the map:" << endl;
    M.clear();
 
    // Returns the size of the map
    cout << "Now the size is :"
         << M.size();
}

void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r",stdin);
    freopen(output_file.c_str(),"w",stdout);
}

/********** Main()  function **********/
int32_t main(){
    
    // if(getenv("CP_IO")){setIO();}
    fastIO;
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}