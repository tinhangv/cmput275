#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int q;
	scanf("%d %d", &n,&q);
	int *sums = malloc(sizeof(int)*(n+1));
	int *output = malloc(sizeof(int)*q);

	sums[0] = 0;
	for(size_t i=0; i<n; ++i){
		int newCalls;
		scanf(" %d", &newCalls);
		sums[i+1] = sums[i] + newCalls;
	}

	for(size_t i=0; i<q; ++i){
		int s,t;
		scanf("%d %d", &s,&t);
		
		output[i] = sums[t]-sums[s-1];
	}
	
	for(size_t i=0; i<q; ++i){
		printf("%d\n",output[i]);
	}

	free(output);
	free(sums);
	return 0;
}