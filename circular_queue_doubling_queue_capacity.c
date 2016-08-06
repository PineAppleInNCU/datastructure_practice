#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 /* maximum queue size */
//global variance
typedef struct{
    int key;
    /* other fields */
}element;
typedef enum {
         true = 1 ==1 ,
         false =1 ==0
}bool;



element queue[MAX_QUEUE_SIZE];
int rear=-1;
int front=-1;
//global variance//
//function
bool IsEmpty();
bool IsFull();
void queueFull();
void addq(element);
element deleteq();
//function//


main(){

/*//copy test
    int a[3];
    int b[3];

    a[0]=1;
    a[1]=2;
    a[2]=3;
    int i=0;
    for(i=0;i<3;i++){
        printf("%d\n",a[i]);
    }

    copy(a,a+3,b);

    for(i=0;i<3;i++){
        printf("%d\n",b[i]);
    }
//copy test//
//test >> there isn't any function called copy  */

    element test;
    test.key=1;

    addq(test);
    deleteq();
    printf("front:%d\n",front);
    printf("rear:%d\n",rear);

}
bool IsEmpty(){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}
bool IsFull(){
    if(rear==MAX_QUEUE_SIZE-1){
        return true;
    }
    else{
        return false;
    }
}
void queueFull(){
    fprintf(stderr,"The queue is full!");
    exit(EXIT_FAILURE);

}
void addq(element item){
    /* add an item to the queue */
    rear=(rear+1)%MAX_QUEUE_SIZE;//make it circular
    if(rear==MAX_QUEUE_SIZE-1){
        queueFull();/* print error and exit */
    }
    queue[rear]=item;
}
element deleteq(){
    /* remove element at the front of the queue */
    if(front==rear){
        printf("the queue is empty!!");/* return an error key */
        exit(EXIT_FAILURE);
    }
    front=(front+1)%MAX_QUEUE_SIZE;
    return queue[front];
}
