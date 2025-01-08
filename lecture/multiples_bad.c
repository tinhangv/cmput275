#include <stdio.h>

int *multiples(int n){
	int arr[4];
	for (int i=0; i<4; ++i){
		arr[i] = (i+1)*n;
	}
}

int main(){
	int *fives = multiples(5);
	for(int i=0; i<4; ++i){
}
