#include <stdio.h>

int main(){
    //read one int
    int n;
    scanf("%d", &n);
    //print every divisor
    printf("1");
    for (int i=2; i<=n; ++i){
        //printf("%d",n/i);
        if (n % i == 0) printf(" %d",i);
    }
    printf("\n");
    return 0;
}