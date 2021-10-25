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
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
struct UnionFind {
	vector<int> parent;
	vector<bool> cycle;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), cycle(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) {
			cycle[x] = true;
			return false;
		}
		if (cycle[x] || cycle[y])cycle[x] = cycle[y] = true;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	bool has_cycle(int x) { return cycle[root(x)]; }
};

void solve(){ 

    // // read letters as numbers
    UnionFind UF(26);
    string line; 
    VI queries;
    SETI queriesSet;
    while(getline(cin, line), line[0]!= '*'){
        int n1 = line[1],n2 = line[3]; //debug(n1); debug(n2);
        queries.PB(n1-'A');
        queries.PB(n2-'A');
        queriesSet.insert(n1-'A');
        queriesSet.insert(n2-'A');
        // cout<<n1-65<<" "<<n2-65<<endl;    
        // UF.unite(n1-65, n2-65);
        // debug(UF.size);
    }

    // A,B,C,D,E,F,G,H...
    for(int i = 0; i<(int)queries.size(); i+=2){
        UF2.unite(queries[i], queries[i+1]); debug(queries[i]);debug(queries[i+1]);
        debug(UF2.size);
        debug(i); debug(queries.size());
    }
    

    
    set<int> trees;
    for (auto elem : queriesSet){
        trees.insert(UF2.root(elem));
        // std::cout << elem << " , ";
    }
    // cout<<endl;
    
    debug(trees);
    int acorns = 0;
    for (int i = 0; i < 26; i++){
        char c;
        cin>>c;
        char comma;
        SCC(comma);
        debug(c);
        int number = c - 'A'; debug(number);
        if(binary_search(trees.begin(),trees.end(),UF2.root(number)) && number<=max){
            
        }else{
            acorns++;
        }
        if (comma == '\n') break; // , (comma)
    }
    printf("There are %d tree(s) and %d acorn(s).\n",
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
int main()
{
    
    if(getenv("CP_IO")){setIO();}
    int T;
    SCD(T); getchar();
    FO(tc,T)
        solve();
    return 0;
}