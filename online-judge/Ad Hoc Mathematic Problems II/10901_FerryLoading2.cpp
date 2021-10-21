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

template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};
void solve(){
    int n,t,m;
    int tActual = 0, izq_der = 0;
    vector<pair<int,string>> carros;
    iterable_queue<int> cd,ci;
    SCD(n);SCD(t);SCD(m);

    FO(i,m){
        int tCarro;
        string lugarLlegada;
        SCD(tCarro);
        cin>>lugarLlegada;
        carros.PB(make_pair(tCarro,lugarLlegada));
    }

    
    int i = 0;
    do{
        // cout << carros[i].first << ", " << carros[i].second << endl;
        printf("=====\n");
        debug(carros);
        debug(izq_der);
        debug(carros[i].second.c_str()[0]);
        debug(carros[i].first);
        debug(tActual);
        debug(cd);
        debug(ci);
        if(!izq_der){ //Izq
            //Descarga izquierda 
            if((int)cd.size()==0){ //Amanas
                cout<< "Ya no hay pasajeros en la derecha" <<endl;
            }else{
                for(auto it=cd.begin(); it!=cd.end();++it){
                    int tEntrega = carros[i].first + abs(tActual-*it);
                    debug(tEntrega);
                    cd.pop();
                    printf("%d\n", tEntrega);
                }
                
                
            }
            if(carros[i].second[0] == 'l' )cd.push(carros[i].first);
            else ci.push(carros[i].first);
            tActual += t; izq_der++;
        }else{ 
            if((int)cd.size()==0){ //Amanas
                cout<< "Ya no hay pasajeros en la derecha" <<endl;
            }
            else{
                for(auto it=cd.begin(); it!=cd.end();++it){
                    int tEntrega = carros[i].first + abs(tActual-carros[i].first);
                    cd.pop();
                    printf("%d\n", tEntrega);
                }
                
            }
            if(carros[i].second[0] == 'l' )cd.push(carros[i].first);
            else ci.push(carros[i].first);
            tActual += t; izq_der--;
            
        }
        i++
    }while((int)ci.size() != 0 && (int)cd.size() != 0);

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
    int T = 1;
    // SCD(T);
    FO(tc,T)
        solve();
    return 0;
}