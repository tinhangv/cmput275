#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    while(1){
        //initialize command, target, int
        char command = '\0', targ = '\0';;
        int i;
        //read command
        scanf("%c", &command);

        if(command == 'a'){
            scanf(" %c %d",&targ, &i);
            //add i to set x or y
            printf("*%c, %c, %d\n", command, targ, i);

        }else if(command == 'r'){
            scanf(" %c %d",&targ, &i);
            //remove i from set x or y
            printf("*%c, %c, %d\n", command, targ, i);

        }else if(command == 'p'){
            scanf(" %c",&targ);
            //print set
            printf("*%c, %c\n", command, targ);

        }else if(command == 'u'){
            //print union
            printf("*%c\n",command);

        }else if(command == 'i'){
            //print intersection
            printf("*%c\n",command);

        }else if(command == 'q'){
            printf("*%c\n",command);
            //terminate
            //free(x.arr);
            //free(y.arr);
            return 0;
        }
    }
}