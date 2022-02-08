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
void solve(){
    //Check if number is divisible by 2 3 4 and 5
    string num;
    cin>>num;
    int n=num.size();
    int nums[7]={0,0,0,0,0,0,0};
    
    int last_digit = num[n-1]-'0';
    if (n==1 && last_digit==4) {
        nums[4]=1;
    }else{
        int last_last_digit = num[n-2]-'0'; 
        int combined = last_last_digit*10+last_digit;
        if (combined%4==0) {
            nums[4]=1;
        }
    }
    //if number is divisible by 2 
    if(last_digit%2==0){
        nums[2]=1;
    }

    //if number is divisible by 3 its digits sum is divisible by 3
    int sum=0;
    for (size_t digit = 0; digit < n; digit++){
        sum += num[digit]-'0';
    }
    if(sum%3==0){
        nums[3]=1;
    }
    
    //if number is divisible by 5 its last digit is either 0 or 5
    if(last_digit==0 || last_digit==5){
        nums[5]=1;
    }
    //if 2 and 3 are divisors then 6 is divisor
    if(nums[2]==1 && nums[3]==1){
        nums[6]=1;
    }
    //iterating over all the numbers
    //If all cells are zeros, just print -1
    bool flag=false;
    int count=0;
    for (size_t i = 0; i < 6; i++){
        if(nums[i]==1){
            if(count > 0){
                cout<<" ";
            }
            cout<<i;
            flag=true;
            count++;
        }
        
    }
    if(nums[6]==1){
        cout<<" ";
        cout<<6;
        flag=true;
    }

    if(!flag){
        cout<<-1;
    }
    cout<<endl;



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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    FO(tc,T)
        solve();
    return 0;
}