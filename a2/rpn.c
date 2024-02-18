#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntArray{
    int *arr;
    size_t len, cap;
};
void push(struct IntArray *p, int val){
    //double array capacity if max reached
    if(p->len == p->cap){
        int *newArr = malloc(p->cap*sizeof(int)*2);
        for(size_t i=0; i<p->len; ++i) newArr[i] = p->arr[i];
        free(p->arr);
        p->arr = newArr;
        p->cap = p->cap*2;
    }
    //push value to end of array
    p->arr[(p->len)++] = val;
}
void pop(struct IntArray *p){
    //decrement length count by 1, effectively removing the last element
    --p->len;
}

// void printArray(int arr[], unsigned int len) {
//   printf("print array:");
//   for (unsigned int i = 0; i < len; ++i) {
//     printf("%d", arr[i]);
//   }
//   printf("\n");
// }

int main(){
    //initialize a dynamic array with capacity 4
    struct IntArray ia;
    ia.arr = malloc(sizeof(int)*4);
    ia.len=0;
    ia.cap=4;

    //read inputs
    while (!feof(stdin)) {

        int x;
        //if is int
        if (1 == scanf("%d", &x)) {
            push(&ia, x);
            //printArray(ia.arr,ia.len);
        }else{ 
            //if is char
            char operation = '\0';
            scanf(" %c", &operation);
            //printf("(%c)\n",operation);
            if(operation == 'p' || operation == 's' || operation == '*' || operation == '/'){
                int a=ia.arr[ia.len-2], b=ia.arr[ia.len-1];
                pop(&ia);pop(&ia);
                if(operation == 'p') push(&ia,a+b);
                else if(operation == 's') push(&ia,a-b);
                else if(operation == '*') push(&ia,a*b);
                else if(operation == '/') push(&ia,a/b);
                //printArray(ia.arr,ia.len);
            }
        }
    }

    printf("%d\n", ia.arr[0]);
    free(ia.arr);

    return 0;
}