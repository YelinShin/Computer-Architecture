#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fourth.h"


struct hashTable* hashArray[1000]; 

int hashCode(int key){
   return (key % 1000);
}

void insert(int ourdata){
  struct hashTable *item = (struct hashTable*) malloc (sizeof(struct hashTable));
  item->data = ourdata;
  
  int hashIndex = hashCode(ourdata);
   
    //check if it duplicate
    int i;
    
    for (i=hashIndex; i<=1000; i++){
      if (hashArray[i] == NULL){
        hashArray[i] = item;
        printf("inserted\n");
        return;
      }else{
        if(hashArray[i]->data == ourdata){
          printf("duplicate\n");
          return;
        }
      }
    }
    
   while (hashArray[hashIndex] != NULL){
     hashIndex = hashIndex+1;
   }
   
   hashArray[hashIndex] = item;
   printf("inserted\n");
   return;
}

void search(int ourdata){               
   //get the hash 
   int hashIndex = hashCode(ourdata);  
	
    int i;
    
    if (hashArray[hashIndex] == NULL){
      printf("absent\n");
      return;
    }
    
    for (i=hashIndex; i<=1000; i++){
      if (hashArray[i] == NULL){
        printf("absent\n");
        return;
      }
    
      if(ourdata == hashArray[i]->data){
        printf("present\n");
        return;
      }
    }
    printf("absent\n");
   return;        
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
        insert(b);
      }else if (a=='s'){
        search(b);
      }else{
        printf("error\n");
      }
    }
  fclose (fp);
  
  return 0;
}