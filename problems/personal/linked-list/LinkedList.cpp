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

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
void printLinkedList (Node * headPointer){
    Node * temp = headPointer;
    cout<<"List :";
    while(headPointer != NULL){
        cout<<headPointer->data<<" ";
        headPointer=headPointer->next;
    }
    cout<<endl;
}
void insertAtBeggining(Node ** headPointer, int value){
    Node* temp = new Node(value);
    temp->next = *headPointer;
    *headPointer = temp;
}
void deleteAtIndex(Node ** headPointer, int index){
    Node * curr = *headPointer;
    if(index == 0){
        *headPointer = curr->next;
        free(curr);
    }else{
        int count = 0;
        while(count < index-2){
            curr = curr->next;
            count++;
        }
        Node * next = curr->next;
        curr->next = next->next;
        free(next);
    }
}
void insertAtIndex(Node ** headPointer, int index, int value){
    Node* temp = new Node(value);
    Node* curr = *headPointer;
    if(index == 0){
        temp->next = *headPointer;
        *headPointer = temp;
    }else{
        int count = 0;
        while(count < index - 1){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void reverseLinkedList(Node ** headPointer ){
    Node * curr = *headPointer;
    Node * prev = NULL;
    Node * next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //Curr now is null
    *headPointer = prev;
}
void reverseRecursive(Node ** headPointer, Node *p){
    if(p->next == NULL){
        *headPointer = p;
        return;
    }
    reverseRecursive(headPointer,p->next);
    Node* q = p->next; 
    q->next = p;
    p->next = NULL;
}
void printRecursive(Node* p){
    if(p == NULL) return;
    cout<<p->data<<" ";
    printRecursive(p->next);
}
void printReverseRecursive(Node* p) 
{ 
    // Base case 
    if (p == NULL) return; 
    // print the list after head node 
    printReverseRecursive(p->next); 
    // After everything else is printed, print head 
    cout << p->data << " "; 
} 


void solve(){
    Node* head = NULL;
    int n=5;
    FO(i,n){
        insertAtBeggining(&head,i+1);

    }
    printLinkedList(head);

    reverseLinkedList(&head);
    printLinkedList(head);
    // deleteAtIndex(&head,0);
    // deleteAtIndex(&head,20);
    cout<<"Recursive: ";
    printRecursive(head);
    cout<<endl;
    cout<<"Recursive Reversed(print): ";
    printReverseRecursive(head);
    cout<<endl;
    cout<< "Reverse recursive: ";
    reverseRecursive(&head,head);
    printLinkedList(head);
    
    

    
    

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
    
    // if(getenv("CP_IO")){setIO();}
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    FO(tc,T)
        solve();
    return 0;
}