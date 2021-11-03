#include<stdio.h>
int main(){
    
	int nCasos;
    int max;
    int instancias[10];
	scanf("%d",&nCasos);	
	for(size_t i=1;i<=nCasos;i++){
        char website[10][100];
		for(size_t j=0;j<10;j++)
			scanf("%s%d",website[j],&instancias[j]);
		for(size_t j=max=0;j<10;j++)
			if(instancias[j]>max)
				max=instancias[j];
		printf("Case #%d:\n",i); 
		for(size_t j=0;j<10;j++)
			if(instancias[j]==max) //Solo los iguales
				printf("%s\n",website[j]);
	}
	return 0;
}