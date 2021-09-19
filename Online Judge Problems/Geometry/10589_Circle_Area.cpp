#include <stdio.h>
#include <math.h>

int main() {
	
	int N, a, M;
	double x, y;
	double res;


	while(scanf("%d %d", &N, &a), N>0){
		res=0;
		M=0;
		for(int i=0; i<N; i++) {
			scanf("%lf %lf", &x, &y);

			if( sqrt(pow(x-0,2)+pow(y-0,2))<=a   &&  sqrt(pow(x-a,2)+pow(y-0,2))<=a  &&  sqrt(pow(x-a,2)+pow(y-a,2))<=a  &&  sqrt(pow(x-0,2)+pow(y-a,2))<=a  ){
				M++;
			}


		}
		
		res=(M*a*a)/(double)N;

		printf("%4.5lf\n", res);

	}	


	return 0;
}