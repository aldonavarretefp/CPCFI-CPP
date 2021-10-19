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

void print_queue(deque<int> q)
{
  cout<<"[ ";
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop_front();
  }
  cout<<"]";
  printf("\n");
}
int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end())
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
        return index ;
    }
    else {
        // If the element is not
        // present in the vector
        return -1 ;
    }
}
void solve(){
    int k;
    int flagStack =0, flagQueue=0,flagPriority=0;
    while(scanf("%d", &k) !=EOF){
        cout<< "======\n";
        deque<int> structure;
        VI queries;
        while(k--){
            
            int command,number;SCD(command); SCD(number);

            if(command ==1) structure.push_back(number);

            else{ 
                //Si es el de atras entonces podría ser una pila
                // debug(number);
                queries.PB(number);
                
                // print_queue(structure);
                // if(number == structure.back()){

                //     int elActual = structure.back(); debug(elActual);
                //     structure.pop_back();

                //     int elqueLessigue = structure.back();

                //     if(elqueLessigue>elActual){ //deja de ser de prioridad
                //         flagStack =1;
                //         break;
                //     }
                //     if(structure.empty()){
                //         cout<< "Not sure\n";
                //         break;
                //     }
                // };
                // if(number == structure.front()){

                //     int elActual = structure.front();
                //     structure.pop_front();
                //     print_queue(structure);
                //     int elqueLessigue = structure.front();
                //     if(elqueLessigue>elActual){ //deja de ser de prioridad
                //         flagQueue =1;
                //         break;
                //     }
                //     if(structure.empty()){
                //         cout<< "Not sure\n";
                //         break;
                //     }
                // };
                

                // debug(idx);
            }
            
            
        }
        debug(queries);
        print_queue(structure);
        for(int el: queries){
            deque<int>::iterator it = find(structure.begin(), structure.end(), el);
            if(it!=structure.end())
            {  
                if(el==structure.back()){
                    cout<< "pos stack\n";
                    int actual = structure.back();
                    structure.pop_back();
                    if(structure.empty()){
                        cout<< "Not sure\n";
                        break;
                    }
                    int siguiente = structure.back();
                    debug(actual); debug(siguiente);
                    if(siguiente>actual){
                        cout<< "stack\n";
                        break;
                    }
                }else{
                    cout<< "pos queue\n";
                    int actual = structure.back();
                    structure.pop_front();
                    debug(actual); 
                    if(structure.empty()){
                        cout<< "Not sure\n";
                        break;
                    }
                    int siguiente = structure.front();
                    debug(siguiente);
                    if(siguiente>actual){
                        cout<< "queue\n";
                        break;
                    }
                }
                
            
            }else{
                cout<< "impossible\n";
            }
        }
                
    }
}

void setIO(){
  string file = __FILE__;
  file = string(file.begin(),file.end()-3);
  string input_file = file + "in";
  string output_file = file + "out";
  freopen(input_file.c_str(), "r",stdin);
//   freopen(output_file.c_str(),"w",stdout);
  
}

/********** Main()  function **********/
int main()
{
    
    if(getenv("CP_IO")){setIO();}
    solve();
    return 0;
}