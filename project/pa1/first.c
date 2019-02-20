#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc!=2){
	printf("error\n");
  return 0;
	}
	int findnumber;
	findnumber = atoi(argv [1]);

	
	if(findnumber% 2 == 0){
		printf("even\n");
	return 0;	
} 
	else if(findnumber % 2 == 1){
		printf("odd\n");
	return 0;
	}
	else{
		printf("error\n"); // checking for not int number
	return 0;	
}
	
}
