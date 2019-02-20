#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "count.h"

int count;


struct node *insert(struct node *head, int deci){
  if (head == NULL){ //head empty
    head = malloc (sizeof(struct node));
    head->data = deci;
    head->next = NULL;
    count ++;
    return head;
  } else {
    struct node *ptr = head;
    while (ptr != NULL){
      if (ptr->data == deci){ //duplicate
        return head;
      }
      ptr = ptr->next;
    }
    
    struct node *tmp = head;
    while (tmp->next != NULL){
      tmp = tmp->next;
    } // tmp = last node
    
    struct node *newnode;
    newnode = malloc (sizeof (struct node));
    newnode->data = deci;
    tmp->next = newnode;
    newnode->next = NULL;
    count++;
    return head;
  }
}
  

int main (int argc, char **argv){

  struct node *head = NULL;
  /*struct node *hashTable[1000];*/
  
  if (argc != 2){
    printf("error\n");
    return 0;
  }

	FILE *fp = fopen(argv[1], "r");
 
  if (fp == 0){ //if there's no file
		printf("error\n");
		return 0;
   }
   
     fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) // empty file
    {
        printf("0\n");
        return 0;
    }
    
    int hashsize = 1000;

do{
 if ((count/hashsize) >= 0.75){
   hashsize = hashsize *2;
   head = NULL;
   count =0;
 }
 struct node *hashTable[hashsize];
 
 fp = fopen(argv[1], "r");
 
  int i;
  for (i=0; i<1000; i++){
    hashTable[i] = NULL;
  }
  
  int hexnum;
  struct node *tmp;
  
  while (fscanf(fp, "%x\n", &hexnum) == 1){ 
    int key;
    if (hexnum >=0){
      key = (hexnum % 1000);
    }else{
      key = -(hexnum %1000);
    }
    
    if (hashTable[key] == NULL){
      hashTable[key] = insert(head, hexnum);
    }else{
      tmp = hashTable[key];
      hashTable[key] = insert(tmp, hexnum);
    }
  }
  
 }while ((count/hashsize) >= 0.75);

  printf("%d\n",count);
  fclose (fp);
  
  return 0;
}