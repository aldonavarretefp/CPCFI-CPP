#include <stdio.h>

int main() {

	int n,m,c;
	long long res;
	int altura, ancho;

while(scanf("%d %d %d", &n, &m, &c), n>0) {
		res=0;
		if(c) { //white
			
			altura=((n-8)/2)+1;    //n
			ancho=((m-8)/2)+1;	  //m
			res=altura*ancho;
			
			if(n>8 && m>8) {
				altura=((n-8-1)/2)+1;
				ancho=((m-8-1)/2)+1;
				res+=altura*ancho;
			}

		} else { //black
			if(n==8 && m==8){
				res=0;
			}else{
				altura=1+(n-8-1)/2;    //n
				ancho=1+(m-8)/2;	  //m
				res=altura*ancho;
				altura=1+(n-8)/2;
				ancho=1+(m-8-1)/2;
				res+=altura*ancho;
			}
			
		}

		printf("%lld\n", res);
	}


	return 0;
}