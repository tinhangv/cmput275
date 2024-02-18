#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntSet{
    int *arr;
    size_t len, cap;
};

void addVal(struct IntSet *p, int val){
    //double array capacity if max reached
    if(p->len == p->cap){
        int *newArr = malloc(p->cap*sizeof(int)*2);
        for(size_t i=0; i<p->len; ++i) newArr[i] = p->arr[i];
        free(p->arr);
        p->arr = newArr;
        p->cap = p->cap*2;
    }

    //insert value to correct place
    for(size_t i=0 ; i< (p->len); ++i){
        if(p->arr[i] == val) return;
        else if ((p->arr[i]) > val) {
            //shift all elements right of arr[i]
            for(size_t j=(p->len); j>i; --j) p->arr[j] = p->arr[j-1];
            p->arr[i]=val;
            ++(p->len);
            return;
        }
    }
    p->arr[(p->len)++] = val;
    return;
}

void removeVal(struct IntSet *p, int val){
    for(size_t i=0; i< (p->len); ++i) if((p->arr[i])==val){
        for(size_t j=i; j<(p->len)-1; ++j) p->arr[j] = p->arr[j+1];
        --(p->len);
        return;
    }
}

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

void printArray(int arr[], size_t len) {
    if(len>0){
        for (unsigned int i = 0; i < len; ++i) {
            printf("%d", arr[i]);
            if(i < len-1) printf(" ");
        }
        printf("\n");
    }
}

void printUnion(int x[], size_t xLen, int y[], size_t yLen){
    size_t i=0, j=0;
    struct IntArray setUnion;
    setUnion.arr = malloc(sizeof(int)*4);
    setUnion.len=0;
    setUnion.cap=4;

    while(i<xLen && j<yLen){
        if(x[i]==y[j]){
            push(&setUnion,x[i]);
            ++i; ++j;
        }else if(x[i]<y[j]){
            push(&setUnion,x[i]);
            ++i;
        }else if(x[i]>y[j]){
            push(&setUnion,y[j]);
            ++j;
        }
    }
    while(i<xLen){
        push(&setUnion,x[i]);
        ++i;
    }
    while(j<yLen){
        push(&setUnion,y[j]);
        ++j;
    }
    printArray(setUnion.arr, setUnion.len);
}

void printIntersection(int x[], size_t xLen, int y[], size_t yLen){
    size_t yStart = 0;
    struct IntArray setInter;
    setInter.arr = malloc(sizeof(int)*4);
    setInter.len=0;
    setInter.cap=4;
    for(size_t i=0; i<xLen; ++i){
        for(size_t j=yStart; j<yLen; ++j){
            if(x[i]==y[j]){
                yStart = j;
                push(&setInter,x[i]);
            }
        }
    }
    printArray(setInter.arr, setInter.len);
}

int main(){
    //initialize two dynamic arrays with capacity 4
    struct IntSet x;
    x.arr = malloc(sizeof(int)*4);
    x.len=0;
    x.cap=4;
    struct IntSet y;
    y.arr = malloc(sizeof(int)*4);
    y.len=0;
    y.cap=4;

    while(1){
        //initialize command, target, int
        char command = '\0', targ = '\0';;
        int i;
        //read command
        scanf("%c", &command);

        if(command == 'a'){ //add i to set x or y
            scanf(" %c %d",&targ, &i);
            if(targ=='x') addVal(&x, i);
            else if(targ=='y') addVal(&y, i);

        }else if(command == 'r'){ //remove i from set x or y
            scanf(" %c %d",&targ, &i);
            if(targ=='x') removeVal(&x, i);
            else if(targ=='y') removeVal(&y, i);

        }else if(command == 'p'){ //print set
            scanf(" %c",&targ);
            if(targ == 'x') printArray(x.arr, x.len);
            else if (targ == 'y') printArray(y.arr,y.len);

        }else if(command == 'u'){  //print union
            printUnion(x.arr, x.len, y.arr, y.len);

        }else if(command == 'i'){ //print intersection 
            printIntersection(x.arr, x.len, y.arr, y.len);

        }else if(command == 'q'){ //terminate
            free(x.arr);
            free(y.arr);
            return 0;
        }
    }
}