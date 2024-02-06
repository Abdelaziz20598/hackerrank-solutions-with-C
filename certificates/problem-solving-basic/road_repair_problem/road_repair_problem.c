#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


typedef struct arr_type{
	int *arr;
	int length;

}arr_type;

arr_type arr_declare(void);

void arr_print(arr_type arr_struct);


int smallest_element(int arr[], int length);

int minGain(arr_type crew_id, arr_type job_id, int crew_id_count, int job_id_count);

int main(void){
	int min = 0;
	printf("please enter the length of crew and the crew ids\n");
	arr_type crew_id = arr_declare();
	int crew_id_count = crew_id.length;

	printf("u've entered the array:\n");
	arr_print(crew_id);


	printf("please enter the length of jobs and the jobs ids\n");
	arr_type job_id = arr_declare();
	int job_id_count = job_id.length;

	printf("u've entered the array:\n");
	arr_print(job_id);

	
	

	min = minGain(crew_id, job_id, crew_id_count, job_id_count);
	printf("the min is %d:\n", min);
	return 0;
}

arr_type arr_declare(void){
	arr_type arr1;
	printf("enter the lngth here: ");
	scanf("%d", &arr1.length);
	arr1.arr = (int *) malloc(sizeof(int) * (arr1.length));
	printf("please enter the elements of the array: \n");
	for(int i = 0; i < arr1.length; i++){
		scanf("%d", &arr1.arr[i]);
	}
	return arr1;
}

void arr_print(arr_type arr_struct1){

	printf("[");
	for(int i = 0; i < arr_struct1.length; i++){
		printf("%d, ", arr_struct1.arr[i]);
	}
	printf("]\n");

}


int smallest_element(int arr[], int length){
	int minx = 0;
	minx = arr[0];
	for(int k = 0; k < length; k++){
		if(arr[k] < minx){
			minx = arr[k];
		}
	}
	return minx;
}
int minGain(arr_type crew_id, arr_type job_id, int crew_id_count, int job_id_count){
	
	int diff_array[job_id_count];
	int diff = 0; 
	for(int i = 0; i < crew_id_count; i++){

		for(int j = 0; j < job_id_count; j++){
			
			if(crew_id.arr[i] != job_id.arr[j]){
				diff_array[j] = crew_id.arr[i] - job_id.arr[j];
				if(diff_array[j] < 0){
					diff_array[j] *= -1;
				}			
			}	
		}
		printf("the min is %d:\n", smallest_element(diff_array, job_id_count));
		diff +=  smallest_element(diff_array, job_id_count);
		printf("the diff is %d:\n", diff);
	}

	return diff;

}