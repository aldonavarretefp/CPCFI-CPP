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


/**************************************/
/******** User-defined Function *******/
/**************************************/
void llenaMapa(map<int,PII,greater<int>> &mymap){
    int level, x,y;
    SCD(level);
    SCD(x);
    SCD(y);
    // Inserting the elements
    mymap.insert(make_pair(level,make_pair(x,y)));   
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
    freopen("platforme.in","r",stdin);
    int T; SCD(T);
    map<int,PII,std::greater<int>> m;
    vector<int y, vector<int,int> ,std:greater<int> > v;
    FO(tc,T)
        llenaMapa(m);
    vector<int y, vector<int,int> ,std:greater<int> >
    map<int, PII> :: iterator it; 
    for (it=m.begin() ; it!=m.end() ; it++) 
        cout << "(" << (*it).first << "=> "<< (*it).second.first << " "<< (*it).second.second << ")" << endl; 
    FO(i,2){
        for (it=m.begin() ; it!=m.end() ; it++){
            map<int, PII> :: iterator secondIterator = it; secondIterator++;//Me muevo al siguiente
            int x = it->second.first;
            int y = it->second.second;
            int x2 = secondIterator->second.first;
            int y2 = secondIterator->second.second;
            if(<x)
            printf("%d %d %d %d\n",x,y,x2,y2);

        }           
    }
    return 0;
}