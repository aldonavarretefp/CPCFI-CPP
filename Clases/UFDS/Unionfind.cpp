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
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  VI p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); 
    numSets = N; 
    rank.assign(N, 0);
    p.assign(N, 0); 
      for (int i = 0; i < N; i++) 
        p[i] = i; 
  }

  int findSet(int i) {
    return (p[i] == i)/*Soy mi propio padre?*/ ? i : (p[i] = findSet(p[i])); 
  }

  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j); 
  }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
      numSets--; 
      int x = findSet(i);
      int y = findSet(j);
    // rank is used to keep the tree short
      if (rank[x] > rank[y]) { 
          p[y] = x; 
          setSize[x] += setSize[y]; 
      }
      else{ 
        p[x] = y; 
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) 
          rank[y]++; 
      } 
    } 
  }
  int numDisjointSets() {
    return numSets; 
  }

  int sizeOfSet(int i) {
    return setSize[findSet(i)]; 
  }

};


int32 t,u,v;
int N,Q;
/**************************************/
/******** User-defined Function *******/
/**************************************/
void solve(UnionFind &UF){
    SCD(t);
    SCD(u);
    SCD(v);
    if(t==0) {UF.unionSet(u, v);}
    else{ //Print 1 or 0 if are connected
        printf("%d\n",UF.isSameSet(u,v)); // will return 1 (true)
    }

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

    SCD(N); SCD(Q);
    UnionFind UF(N);
    
    FO(tc,Q)
        solve(UF);
    return 0;
}