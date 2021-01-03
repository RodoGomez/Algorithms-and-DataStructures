#include<stdio.h>
#include<stdlib.h>

#define ll_i long long int

static ll_i max_pair_product(ll_i *dataset, int n);

int main(){

	int n = 0, i = 0;
	scanf("%d", &n);	// Scanning the number of values in the data set

	// Allocating memory for storing n elements of long long int type
	ll_i *dataset = (ll_i*)malloc( (sizeof(ll_i) * n) );
	
	// If malloc returns null, exit the program
	if(!dataset){
		exit(-1);
	}
	// Scanning the dataset
	for(i = 0; i < n; i++){
		scanf("%lli", &dataset[i]);
	}

	ll_i result = max_pair_product(dataset, n-1);

	printf("%lli\n",result);

	// Freeing the allocated memory
	free(dataset);

	return 0;
}

/*
 * This algorithm find the largest and the second largest element in an array and 
 * move them to the last and one before the last position in the array respectivly
 * so finally it returns the product of the last two elements in the array.
*/

static ll_i max_pair_product(ll_i *dataset, int n){

	int i = 0, index = 0;
	ll_i temp = 0;

	for(i = 1; i <= n; i++){
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[n];
	dataset[n] = dataset[index];
	dataset[index] = temp;

	index = 0;

	for(i = 1; i < n; i++){
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[n-1];
	dataset[n-1] = dataset[index];
	dataset[index] = temp;

	return dataset[n] * dataset[n-1];
}