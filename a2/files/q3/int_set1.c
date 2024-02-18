#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data, inX, inY;
    struct Node *next;
};

struct xySet{
    struct Node *head;
    size_t len;
};

//create a new set a return the pointer to it
struct xySet *createSet(){
    struct xySet *ret = malloc(sizeof(struct xySet));
    ret->len=0;
    ret->head=NULL;
}

void append(struct xySet *s, int val, int xy){ //xy: 0 for x
    //create a new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    (xy == 0) ? (newNode->inX = 1): (newNode->inY = 1);

    //if empty set or val less than smallest element
    if (s->len == 0 || s->head->data < val){
        //point new node to first element
        newNode->next = s->head;
        //point head to newNode
        s->head = newNode;
        s-> len++;
        return;
    }
    //if val greater than last element
    
    //loop through set
    struct Node *cur = s->head->next;
    //while(cur != NULL)
}

void printSet(struct xySet *s, int xy){
    struct Node *cur = s-> head;
    for (size_t i=0; i< s->len; ++i, cur = cur->next){
        if(xy==0 && cur->inX ==1) printf("%d ", cur->data);
        else if(cur->inY == 1) printf("%d", cur-> data);
    }
    printf("\n");
}

int main(){
    struct xySet *s = createSet();
    append(s, 9, 0);
    printSet(s, 0);

    while(1){
        //read command, target, int
        char command = '\0', targ = '\0';;
        int i;
        scanf("%c %c %d", &command, &targ, &i);
        printf("%c, %c, %d\n", command, targ, i);
        
        if(command == 'a'){
            //add i to set x or y
        }else if(command == 'r'){
            //remove i from set x or y
        }else if(command = 'p'){
            //print set
        }else if(command = 'u'){
            //print union
        }else if(command = 'i'){
            //print intersection
        }else if(command = 'q'){
            //terminate
            // free(x.arr);
            // free(y.arr);
            return 0;
        }
    }
    
}