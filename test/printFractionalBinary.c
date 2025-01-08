#include <stdio.h>

// void printFractionalBinary(float num, float e){
//     float x=num; 
//     printf("0.");
//     float y=0;
//     float mult = 1/10;
//     while(((y-num)>=0 && (y-num)>=e || 
//             (num-y)>=0 && (num-y) >= e)){
//         x = x*2;
//         if(x>=1){
//             printf("1");
//             --x;
//             y += mult;
//             mult /= 10;
//         }else{
//             printf("0");
//         }
//     }
// }
void printFractionalBinary(float num, float e){
    printf("0.");
    float estimate = 0.0;
    float divisor = 2.0;
    while(estimate < num - e){
        float toAdd = 1/divisor;
        if(toAdd + estimate > num){
            printf("0");
        }else{
            printf("1");
            estimate += toAdd;
        }
        divisor *=2;
    }
}

int main(){
    printFractionalBinary(0.43,0.001);
}