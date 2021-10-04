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
 
// Data structure to store a graph edge
struct Edge {
    int source, dest, weight;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int x, int N)
    {
        // resize the vector to `3×N` elements of type `vector<int>`
        adjList.resize(3*N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            int v = edge.source;
            int u = edge.dest;
            int weight = edge.weight;
 
            // create two new vertices, `v+N` & `v+2×N`, if the edge's weight is `3x`.
            // Also, split edge `(v, u)` into `(v, v+N)`, `(v+N, v+2N)` & `(v+2N, u)`,
            // each having weight `x`.
            if (weight == 3*x)
            {
                adjList[v].push_back(v + N);
                adjList[v + N].push_back(v + 2*N);
                adjList[v + 2*N].push_back(u);
            }
 
            // create one new vertex `v+N` if the weight of the edge
            // is `2x`. Also, split edge `(v, u)` into `(v, v+N)`,
            // `(v+N, u)` each having weight `x`
            else if (weight == 2*x)
            {
                adjList[v].push_back(v + N);
                adjList[v + N].push_back(u);
            }
 
            // no splitting is needed if the edge weight is `1x`
            else {
                adjList[v].push_back(u);
            }
        }
    }
};
 
// Recursive function to print the path of a given vertex `v` from
// the source vertex
void printPath(vector<int> const &predecessor, int v, int &cost, int N)
{
    if (v < 0) {
        return;
    }
 
    printPath(predecessor, predecessor[v], cost, N);
    cost++;
 
    // only consider the original nodes present in the graph
    if (v < N) {
        cout << v << " ";
    }
}
 
// Perform BFS on the graph starting from vertex source
void BFS(Graph const &graph, int source, int dest, int N)
{
    // stores vertex is discovered in BFS traversal or not
    vector<bool> discovered(3*N, false);
 
    // mark the source vertex as discovered
    discovered[source] = true;
 
    // `predecessor[]` stores predecessor information. It is used
    // to trace a least-cost path from the destination back to the source.
    vector<int> predecessor(3*N, -1);
 
    // create a queue for doing BFS and enqueue source vertex
    queue<int> q;
    q.push(source);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        int curr = q.front();
        q.pop();
 
        // if destination vertex is reached
        if (curr == dest)
        {
            int cost = -1;
            cout << "The least-cost path between " << source << " and " <<
                dest << " is "; printPath(predecessor, dest, cost, N);
            cout << "having cost " << cost;
        }
 
        // do for every adjacent edge of the current vertex
        for (int v: graph.adjList[curr])
        {
            if (!discovered[v])
            {
                // mark it as discovered and enqueue it
                discovered[v] = true;
                q.push(v);
 
                // set `curr` as the predecessor of vertex `v`
                predecessor[v] = curr;
            }
        }
    }
}
 

void solve(){
    
}

void setIO(){
  string file = __FILE__;
  file = string(file.begin(),file.end()-3);
  string input_file = file + "in";
  string output_file = file + "out";
  freopen(input_file.c_str(), "r",stdin);
//   freopen(output_file.c_str(),"w",stdout);
  
}
int main()
{
    if(getenv("CP_IO")){setIO();}
    // int T;
    // SCD(T);
    // FO(tc,T)
    //     solve();
    // return 0;
    
    int x = 1;
    int n ;
    SCD(n);
    FO(i,n){

        int a,b,c;
        SCD(a);SCD(b);SCD(c);
    }

    // Llena a los nodos con sus respectivos pesos.
    vector<Edge> edges =
    {
        {0, 1, 3*x}, {0, 4, 1*x}, {1, 2, 1*x}, {1, 3, 3*x},
        {1, 4, 1*x}, {4, 2, 2*x}, {4, 3, 1*x}
    };
    

 
    int N = 3;    // total number of nodes in the graph

 
    // build a graph from the given edges
    Graph graph(edges, x, N);
 
    // given the source and destination vertex
    int source = 0, dest = 2;
 
    // Perform BFS traversal from the given source
    BFS(graph, source, dest, 5);
 
    return 0;
}
