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
#define PD(t) printf("%d\n",t)
#define PF(t) printf("%f\n",t);
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 2*acos(0.0)
#define MOD 1000000007
#define read(type) readInt<type>()
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


/********** Main()  function **********/
int main()
{
    // freopen("input.txt", "r", stdin);
    int duracion,nMesesaDepreciar,nMes,i;
    float pago,prestamo,pDepreciacion,arrDepreciaciones[101],vActCarro,cDebida,pagoMensualPrestamo;
    while(true){
        // scanf("%i %f %f %i",&duracion,&pago,&prestamo,&nMesesaDepreciar);
        cin>>duracion>>pago>>prestamo>>nMesesaDepreciar;
        if(duracion <0)break;

        //LLenado arreglo de porcentaje de depreciaciones, dijeron que maximo 100 meses
        while(nMesesaDepreciar--){
            scanf("%i %f",&nMes,&pDepreciacion); 
            FOR(i,nMes,101,1)
                arrDepreciaciones[i] = pDepreciacion;
        }

        int mes=0;
        pagoMensualPrestamo = prestamo/duracion;

        vActCarro = (prestamo+pago)-((prestamo+pago)*arrDepreciaciones[0]); //Justo cuando sale de la agencia
        cDebida   = prestamo;

        while (vActCarro<cDebida)
        {
            mes++;
            cDebida -= pagoMensualPrestamo;
            vActCarro-= vActCarro*arrDepreciaciones[mes];

        }
        

        printf("%d ",mes);
        printf("%s\n",(mes!=1)?"months":"month");

    }
    return 0;
}