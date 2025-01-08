#include <stdio.h> 
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	char *s = malloc(sizeof(char)*n); 
	scanf("%s",s);
	int l[26] = {0};

	for(size_t i=0; i<n; ++i){
    	++l[(int)s[i]-97];
    }
	int x =0;
	for(size_t i=0;i<26;++i){
		if(l[i]%2 ==1){
			x=1;
			l[i]--;
		}
	}
	for(size_t i=0;i<26;++i){
		if(l[i]>1){
			x += l[i];
		}
	}
	printf("%d\n",x);
	free(s);
	
	return 0;
}