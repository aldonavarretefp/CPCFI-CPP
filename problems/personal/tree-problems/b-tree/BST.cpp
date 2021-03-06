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
//Struct
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int v){ 
        data = v; 
        left = NULL;
        right = NULL;
    }
};
//Functions
struct Node * insert(Node * root,int value){
    if (!root) return new Node(value);
    if(value <= root->data ) root->left = insert(root->left, value);
    else                     root->right = insert(root->right, value);
    return root;
}
bool Search(Node * root,int k){
    if(!root) return false;
    if(root->data == k) return true;
    if(k <= root->data) return Search(root->left,k);
    else                return Search(root->right,k); 
    
}

int findMin(Node * root){
    Node * curr = root;
    while(curr->left != NULL) curr = curr->left;
    return curr->data;

}
int findMax(Node * root){
    Node * curr = root;
    while(curr->right != NULL) curr = curr->right;
    return curr->data;

}
int findHeight(Node * root){
    if(!root) return -1;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

//Traversals
void InOrder(Node * root){
    if(!root) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PreOrder(Node * root ){
    if(!root) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}
void PostOrder(Node * root ){
    if (!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
void BFS(Node * root ){
    if(!root) return;
    queue<Node *> q; q.push(root);
    while(!q.empty()){
        Node * curr = q.front(); q.pop(); 
        cout<<curr->data<<" ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}
void DFS(Node * root ){
    if(!root) return;
    stack<Node *> s; s.push(root);
    while(!s.empty()){
        Node * curr = s.top(); s.pop();
        cout<<curr->data<<" ";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}

void solve(){
    Node * root = NULL;
    root = insert(root,9); // La primera vez se modifica la raiz.
    insert(root,10);
    insert(root,2);
    insert(root,3);
    insert(root,1);
    insert(root,8);

    cout<<"InOrder: ";  InOrder(root);  cout<<endl;
    cout<<"PreOrder: "; PreOrder(root); cout<<endl;
    cout<<"PostOrder: ";PostOrder(root);cout<<endl;
    cout<<"BFS: ";BFS(root);cout<<endl;
    cout<<"DFS: ";DFS(root);cout<<endl;



    // Search
    int k = 8;
    cout<<k << (Search(root,k)? " se encuentra en el BST" : " no se encuentra en el BST")<<endl;

    //Min and Max;
    cout<< "Max: "<<findMax(root)<<endl;
    cout<< "Min: "<<findMin(root)<<endl;

    //Height of a BT
    cout<<"Height: "<< findHeight(root)<<endl;
}

/********** Main()  function **********/
int main(){
    
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}

/**
 *      9
 *    2  10
 *  1 3  8 
 */ 