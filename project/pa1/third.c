#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "third.h"

node *head = NULL;
node *current = NULL;

void insert(struct node* newnode){
  struct node *ptr = head;
    while(ptr != NULL){
        if (newnode->data == ptr->data){
          return; // not inserting
        }
        ptr = ptr-> next;
    }
    
  if(head == NULL || (head->data > newnode->data)){
    newnode -> next = head;
    head = newnode;
  }else{
    current = head;
    while (current->next != NULL && current->next->data < newnode->data){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
  free(ptr);
}

struct node* createnewnode (int data){
  struct node* ptr = (struct node*) malloc(sizeof(struct node));
  ptr->data = data;
  ptr->next = NULL;
  
  return ptr;
  free(ptr);
}


struct node* delete(int data){

    node* current = head;
    node* prev = NULL;

    if(head == NULL){
        return NULL;
    }

    while(current-> data != data){
        if(current->next == NULL){
            return NULL;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    if(current == head){
        head = head->next;
    }
    else{
        prev-> next = current -> next;
    }
    return current;
}


void printList(){
    struct node *ptr = head;
    
    if (ptr == NULL){
      printf("\n");
      return;
    }
    
    while(ptr->next != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr-> next;
    }
    printf("%d\n", ptr->data);
}

int main (int argc, char **argv){
  if (argc != 2){
    printf("error\n");
    return 0;
  }

	FILE *fp = fopen(argv[1], "r");
 
  if (fp == 0){ //if there's no file
		printf("error\n");
		return 0;
   }
   
     fseek(fp, 0, SEEK_END); //empty file
    if (ftell(fp) == 0)
    {
        printf("\n");
        return 0;
    }
 
 fp = fopen(argv[1], "r");
 
   char a;
   int b;
   char *line = NULL;
   size_t n=0;
   
  
   while(getline(&line, &n, fp) != -1){
      sscanf(line, "%c %d\n", &a,&b);
      
      if (a=='i'){ 
        insert(createnewnode(b));
      }else if (a=='d'){
        delete(b);
      }else{
        printf("error\n");
        return 0;
      }
    }
  fclose (fp);
  
  printList();
  return 0;
}
	
	
