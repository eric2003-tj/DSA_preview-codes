#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct Listnode{
    int data;
    struct Listnode *next;
}Node;
Node* genNode(int data,Node *next){
    Node *now = (Node*)malloc(sizeof(Node));
    now->data = data;
    now->next = next;
    return now;
}
void freeNode(Node* now){
  while(now!=NULL){
    Node *ss = now->next;
    free(now);
    now = ss;
  }
}
//#ifdef DEBUG
Node *insertLinkedList(Node *head,int data){
  Node *current = genNode(data,NULL);
  if(head == NULL){
    return current;
  }
  Node *ptr = head;
  Node *last = NULL;
  while(ptr != NULL && ptr->data < data){
    last = ptr;
    ptr = ptr->next;
  }
  if(last == NULL){
    current-> next = head;
    return current;
  }else{
    current->next = last->next;
    last->next = current;
    return head;
  }
}
//#endif
Node* removeNode(Node *head,int data){
     Node *current = head;
     Node *last = NULL;
     if(head->data == data){
        current = head->next;
        free(head);
        return current;
     }
     while(current->data != data){
        last = current;
        current = current->next;
     }
     if(current == NULL){
        printf("Not found!\n");
     }else{
        last->next = current->next;
        free(current);
     }
     return head;
}
int main(){
  Node *head = NULL;
  head = insertLinkedList(head,6);
  head = insertLinkedList(head,7);
  head = insertLinkedList(head,8);
  head = insertLinkedList(head,9);
  Node *current = head;
  while(current!=NULL){
    printf("%d\n",current->data);
    current = current->next;
  }
  head = removeNode(head,6);
  current = head;
  while(current!=NULL){
    printf("%d\n",current->data);
    current = current->next;
  }
}
