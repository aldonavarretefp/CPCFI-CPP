//https://codeforces.com/problemset/problem/20/C
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

using ll = long long;

#define x first
#define y second

template <typename T>
struct Dijkstra {

	int node,edge;
	vector< vector< pair<int,T> > > adj;
	vector< T > level;
	vector<int> parent;

	Dijkstra(int _node, int _edge) : node(_node), edge(_edge) {
		vector<int>(node+1).swap(parent);
		vector<T>(node+1, numeric_limits<T>::max()).swap(level);
		vector< vector< pair<int,T> > > (node+1).swap(adj);
	}

	void add_edge(int u, int v, T w) {
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	void traverse(int src) {

		level[src] = 0;
		set< pair<T,int> > s {{0,src}};
		parent[src] = -1;

		while(not s.empty()) {
			auto it = *s.begin();
			int cur_node = it.y;
			T cur_level = it.x;
			s.erase(s.begin());

			for(auto u : adj[cur_node]) {
				if(level[u.x] - u.y > cur_level) {
					level[u.x] = cur_level + u.y;
					parent[u.x] = cur_node; 
					s.insert({level[u.x],u.x});
				}
			}
		}
	}

	void print_path(int x) {

		if(level[x] == numeric_limits<T>::max()) {
			cout<<"-1\n";
			return;
		}

		if(x == -1){
			return;
		}

		print_path(parent[x]);
		cout<<x<<" ";

	}

};

void solve(){
    int n, m;
    cin>>n>>m;
    Dijkstra<ll> d(n,m);
    FO(i, m){
        int u,v,w;
        cin>>u>>v>>w;
        d.add_edge(u,v,w);
    }
    d.traverse(1);
	d.print_path(n);
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
    
    if(getenv("CP_IO")){setIO();}
    fastIO;
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}