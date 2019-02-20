#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
	if(argc!=2){
		printf("error\n");
		return 0;
	}
	int mynumber;
	mynumber=atoi(argv[1]);
	
	int i;	
 int count;
	
	if(mynumber==1){
		printf("no\n");
		return 0;
	}
	
	if(mynumber==2){
		printf("yes\n");
		return 0;
	}

	for(i=2;i< mynumber; i++){
		if(mynumber % i ==0){
			count =1;
      break;
		}
	}
	if (count ==0){
   printf("yes\n");
 }else{
	printf("no\n");
	}
  
  return 0;
}
