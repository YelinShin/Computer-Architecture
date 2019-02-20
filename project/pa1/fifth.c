#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 
   int row;
   int column;
   int c; //my row counter
   int d; //my column counter

   
   char *line = NULL;
   size_t n=0;


    getline(&line, &n, fp);
    sscanf(line, "%d %d\n", &row,&column); // getting first line

   int first[row][column];
   int second[row][column];
   int sum[row][column];
    
    do{
      for(c =0; c<row; c++){
        for(d=0; d<column; d++){
          fscanf(fp, "%d", &first[c][d]);
        }
      }
      
      getline(&line, &n, fp);
      
      for(c =0; c<row; c++){
        for(d=0; d<column; d++){
          fscanf(fp, "%d", &second[c][d]);
        }
      }
    } while(getline(&line, &n, fp) != -1);
 
    for(c =0; c<row; c++){
        for(d=0; d<column; d++){
          sum[c][d] = first[c][d] + second[c][d];
          printf("%d\t", sum[c][d]);
        }
        printf("\n");
    }
  
  fclose (fp);
  return 0;
}