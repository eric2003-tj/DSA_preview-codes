#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct poly{
   int power;
   int number;
   struct poly *next;
}Node;
Node *genListNode(int power,int data,Node* next){
   Node *newNode = (Node*)malloc(sizeof(Node));
   newNode->power = power;
   newNode->number = data;
   newNode->next = next;
   return newNode;
}
Node *insertNewNode(Node *head,Node *toInsert){
   head -> next = toInsert;
   return head;
}
Node *mergeVector(Node *head1,Node *head2){
    Node *result = genListNode(-1,0,NULL);
    Node *toReturn = result;
    while((head1!=NULL && head2!=NULL)){
        if(head1->power > head2->power){
            result = insertNewNode(result,head2);
            head2 = head2->next;
            result = result->next;
        }else if(head1->power < head2->power){
            result = insertNewNode(result,head1);
            head1 = head1->next;
            result = result->next;
        }else{
            Node* temp = genListNode(head1->power,head1->number+head2->number,NULL);
            result = insertNewNode(result,temp);
            head2 = head2->next;
            head1 = head1->next;
            result = result->next;
        }
    }
    if(head1 == NULL){
        while(head2!=NULL){
            result = insertNewNode(result,head2);
            head2 = head2->next;
            result = result->next;
        }
    }else if(head2 == NULL){
        while(head1!=NULL){
            result = insertNewNode(result,head1);
            head1 = head1->next;
            result = result->next;
        }
    }
    return toReturn;
}
int main(){
    Node *head1 = genListNode(0,5,NULL);
    Node *head2 = genListNode(1,3,NULL);
    Node *temp1 = genListNode(1,4,NULL);
    Node *temp2 = genListNode(2,6,NULL);
    Node *head;
    head1 = insertNewNode(head1,temp1);
    head2 = insertNewNode(head2,temp2);
    head = mergeVector(head1,head2);
     while(head!=NULL){
        printf("%d %d\n",head->power,head->number);
        head = head->next;
    }
}
