#include <bits/stdc++.h>
using namespace std;

#define fastIO          cin.tie(0); cout.tie(0);
#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

const int num_primes = 1000000;
int primes[num_primes+1];
int sum[num_primes+1];

void solve() {
    int i,j;
    scanf("%d %d",&i,&j);
    printf("%d\n",sum[j]-sum[i-1]);
}

int main() {
    if (getenv("CP_IO")) { setIO(); }    

    for (int i = 0; i <= num_primes; i++) {
        primes[i] = 1;
    }

    for (int i = 2; i != int(sqrt(num_primes)); i++) {
        if (primes[i]){
            for (int j = 2; i * j <= num_primes; j++) {
                primes[i*j] = 0;
            }
        }
    }

    sum[0] = 0;
    for (int i = 1; i <= num_primes; i++) {
        sum[i] = sum[i-1] + primes[i];
    }

    int T;
    si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}
Contraer
c.cpp
2 KB
﻿
#include <bits/stdc++.h>
using namespace std;

#define fastIO          cin.tie(0); cout.tie(0);
#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

const int num_primes = 1000000;
int primes[num_primes+1];
int sum[num_primes+1];

void solve() {
    int i,j;
    scanf("%d %d",&i,&j);
    printf("%d\n",sum[j]-sum[i-1]);
}

int main() {
    if (getenv("CP_IO")) { setIO(); }    

    for (int i = 0; i <= num_primes; i++) {
        primes[i] = 1;
    }

    for (int i = 2; i != int(sqrt(num_primes)); i++) {
        if (primes[i]){
            for (int j = 2; i * j <= num_primes; j++) {
                primes[i*j] = 0;
            }
        }
    }

    sum[0] = 0;
    for (int i = 1; i <= num_primes; i++) {
        sum[i] = sum[i-1] + primes[i];
    }

    int T;
    si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}
c.cpp
2 KB