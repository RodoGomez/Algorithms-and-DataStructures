#include<iostream>
#include<vector>
// Solution using std::vector


int64_t max_pair_product(std::vector<int64_t> &dataset); 

int main(){

	int n {};
	std::cin >> n;

	std::vector<int64_t> dataset(n);		// Declaring a vector of n elements.

	for(int i{}; i < n; i++){
		std::cin >> dataset[i];
	} 

	int64_t result = max_pair_product(dataset);

	std::cout << result << std::endl;

	return 0;
}

/*
 * This algorithm find the largest and the second largest element in an array and 
 * move them to the last and one before the last position in the array respectivly
 * so finally it returns the product of the last two elements in the array.
 *
 * Note that this algorithm has a complexity of O(n) -even when we go through the array twice- and it could be improved 
 * using any other kind of sorting algorithm, but by the moment this algorithm was developed using this approach.
 * This algorithm could be improved having a complexity of log(n).
*/

int64_t max_pair_product(std::vector<int64_t> &dataset){
	
	int index {}, i {};
	int64_t temp {};

	for(i = 0; i < dataset.size(); i++){			// Finding the greatest element in the dataset.
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[dataset.size() - 1] ;			// Moving the greatest element in the dataset to the last position in the dataset.
	dataset[dataset.size() - 1] = dataset[index];
	dataset[index] = temp;

	index = 0;

	for(i = 0; i < dataset.size() - 1; i++){		// Finding the 2nd greatest element in the dataset.
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[dataset.size() - 2] ;			// Moving the 2nd greatest element to one position before the last one.
	dataset[dataset.size() - 2] = dataset[index];
	dataset[index] = temp;	

	return dataset[dataset.size() - 1] * dataset[dataset.size() - 2];	// Return the product of the greatest element times the 2nd greatest element.
} 
