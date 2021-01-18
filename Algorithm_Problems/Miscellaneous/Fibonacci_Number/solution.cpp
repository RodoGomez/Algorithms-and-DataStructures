#include<iostream>
#include<vector>

#define l long long int

l calculate_Fn(std::vector<l> &ftable, int n);

int main(){

	int n {};
	std::cin >> n;

	std::vector<l> ftable(n + 1);

	l Fn = calculate_Fn(ftable, n);
	
	std::cout << Fn << std::endl;

	return 0;
}


/*
 * This algorithm generates a table of the Fibonacci numbers and just return the last element
 * which is the Fn required.
*/

l calculate_Fn(std::vector<l> &ftable, int n){

	if(n <= 1){
		return n;					// F(n) = n when n == 0 OR n == 1
	}

	ftable[0] = 0;						// When n > 1 you need to initialize the first to elements of the table.
	ftable[1] = 1;

	for(int i{2}; i <= n; i++){				// F(n) = F(n-1) + F(n-2)
		ftable[i] = ftable[i-1] + ftable[i-2];
	}

	return ftable[n];
}
