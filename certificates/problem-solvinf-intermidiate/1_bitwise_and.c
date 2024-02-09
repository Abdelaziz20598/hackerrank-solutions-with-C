#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
bool isPow(int, int);

int main(){

	int count = 0;
	int x;
	printf("please enter the length of the array: ");
	scanf("%d", &x);

	int y[x];
	printf("please enter the elements: ");
	for(int i = 0; i < x; i++){
		scanf("%d", &y[i]);
	}
	//printf("%s", isPow(x, y)?"true":"false");
	for(int j = 0;  j< x; j++){

		for(int k = j+1; k < x; k++){
			printf("%d & %d\n", y[j], y[k]);
			if(isPow((y[j] & y[k]), 2)){
				count++;
				printf("count = %d\n", count);
			}
			else{continue;}
		}	
	}
	printf("%d", &count);
}

bool isPow(int x, int y){

	while(x % y == 0){
	x /= y;
	}
	
	return x == 1;
}