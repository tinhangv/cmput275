#include <stdio.h> // Important for input and output with scanf/printf
#include <math.h> // You may use functions from math.h though they are not neccessary

int main(){
	// declare your variables
	int n ;
	int m ;
	// read the input
	scanf("%d",&n);
	scanf("%d",&m);
	// solve, good luck!
	double exp = log((double)m)/log((double)n);
	//printf("%f\n",exp);
	//printf("%f\n", exp - (int)exp);
	if(fabs(exp - (int)exp) < 1e-9){
		printf("GOOD\n");
	}else{
		printf("BAD\n");
	}
	return 0;
    
}
