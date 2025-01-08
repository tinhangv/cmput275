#include <stdio.h>

int main(){
	
	int n,t; //neighbours, time
	scanf("%d %d",&n,&t);
	//printf("n:%d t:%d\n",n,t);
	int times[24];
	for (size_t i=0;i<24;++i) times[i]=1;
	for(size_t i = 0; i<n; ++i){
		int s,e;
		scanf("%d %d",&s,&e);
		//printf("s:%d e:%d\n",s,e);
		if(e<s){
			for(size_t j=e;j<s;++j){
				times[j]=0;
			}
		}else if (e>s){
			for(size_t j=0;j<s;++j){
				times[j]=0;
				//printf("first %lu\n",j);
			}
			for(size_t j=e;j<=23;++j){
				times[j]=0;
				//printf("second %lu\n",j);
			}
		}
	}
	int hours = 0;
	for(size_t i=0; i<23;++i){
		hours += times[i];
		//printf("%d",times[i]);
	}
	//printf("\n");
	if(hours ==0) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	printf("%d\n",(t+hours-1)/hours);
	
	return 0;
}