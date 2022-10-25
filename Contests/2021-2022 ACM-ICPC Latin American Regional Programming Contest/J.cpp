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


typedef int64 dtype;

struct line {
    dtype a, b, c;
};

struct point {
    dtype x, y;
    point() { x = y = 0.0; }
    point(dtype _x, dtype _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS); 
    }
};

void pointsToLine(point p1, point p2, line & l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); // (y1-y2) / (x1 - x2)
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y; 
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool intersect(line l1, line l2, point & p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}


struct vec {
    dtype x, y;
    vec(dtype _x, dtype _y) : x(_x), y(_y) {}
};

dtype dist (point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

dtype norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

dtype dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, dtype s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

dtype distToLine(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    dtype u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

dtype distToLineSegment(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ap) / norm_sq(ab);
    if (u < 0.0) {
        c = {a.x, a.y};
        return dist(p, a);
    }
    if (u > 1.0) {
        c = {b.x, b.y};
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

// counter clockwsie test
double cross(vec a, vec b) {
    return a.x*b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    vec pq = toVec(p,q);
    vec pr = toVec(p,r);
    return cross(pq, pr) > 0;
}

bool collinear(point p, point q, point r) {
    vec pq = toVec(p, q);
    vec pr = toVec(p, r);
    return fabs(cross(pq, pr)) < EPS;
}

void solve(){
    //check if the pair of points are at the border of the grid, and check if two pairs of points intersect

    int64 w,h;
    cin>>w>>h;
    int64 n;
    cin>>n;
    vector<line> lines;
    FO(i,n){
        
        int64 x0,y1,x1,y2;
        cin>>x0>>y1>>x1>>y2;
        point p1(x0,y1),p2(x1,y2);
        //if BOTH points are at the border of the grid, then create a line
        line l;
        //check if p1 is in the borders
        if(p1.x == 0 || p1.x == w || p1.y == 0 || p1.y == h){
            if(p2.x == 0 || p2.x == w || p2.y == 0 || p2.y == h){
                debug(p1.x,p1.y);
                debug(p2.x,p2.y);
                pointsToLine(p1,p2,l);
                lines.PB(l);
            }
        }
    }
    //print vector
    debug(lines.size());    
    if(lines.size()<=1){
        cout<<"Y"<<endl;
        return;
    }else{
        //check if any of the lines intersect, if so, then print 'N'
        //else print 'Y'
        bool intersection = false;
        FO(i,lines.size()){
            line l1 = lines[i];
            FO(j,lines.size()){
                if(i!=j){
                    line l2 = lines[j];
                    point p;
                    if(intersect(l1,l2,p)){
                        intersection = true;
                        break;
                    }
                }
            }
            if(intersection){
                break;
            }
        }
        if(intersection){
            cout<<"N"<<endl;
        }else{
            cout<<"Y"<<endl;
        }


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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}