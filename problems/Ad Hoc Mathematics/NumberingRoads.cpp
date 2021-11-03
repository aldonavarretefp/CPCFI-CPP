#include <stdio.h>

int main() {

	int n=1;
	int R, N;
	int res;

	while (scanf("%d %d", &R, &N), R>0) {

		printf("Case %d: ", n);
		n++;

		res = (R-1)/N;
		if(res<27){
			printf("%d\n", res);
		} else {
			printf("impossible\n");
		}


	}

	return 0;
}