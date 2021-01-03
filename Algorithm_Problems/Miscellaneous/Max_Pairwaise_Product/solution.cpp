#include<iostream>
#include<vector>
// Solution using std::vector


int64_t max_pair_product(std::vector<int64_t> &dataset); 

int main(){

	int n {};
	std::cin >> n;

	std::vector<int64_t> dataset(n);

	for(int i{}; i < n; i++){
		std::cin >> dataset[i];
	} 

	int64_t result = max_pair_product(dataset);

	std::cout << result << std::endl;

	return 0;
}

int64_t max_pair_product(std::vector<int64_t> &dataset){
	
	int index {}, i {};
	int64_t temp {};

	for(i = 0; i < dataset.size(); i++){
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[dataset.size() - 1] ;
	dataset[dataset.size() - 1] = dataset[index];
	dataset[index] = temp;

	index = 0;

	for(i = 0; i < dataset.size() - 1; i++){
		if(dataset[index] < dataset[i]){
			index = i;
		}
	}

	temp = dataset[dataset.size() - 2] ;
	dataset[dataset.size() - 2] = dataset[index];
	dataset[index] = temp;	

	return dataset[dataset.size() - 1] * dataset[dataset.size() - 2];	
} 