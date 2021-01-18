// Solution in c
#include<stdio.h>
#include<stdlib.h>
#define l long int			// Using a long int data type since Fibonacci numbers grow fast.


static l calculate_Fn(l *ftable, int n);	

int main(){

	int n = 0;

	scanf("%d", &n);
	// Allocate memory for a table of n + 1 elements.
	l *ftable = (l*)malloc(sizeof(l) * n + 1);
	// If malloc returns null, exit the program.
	if(!ftable){
		exit(-1);
	}

	l Fn = calculate_Fn(ftable, n);

	printf("%li\n", Fn);
	// Freeing the allocated memory
	free(ftable);

	return 0;
}

/*
 * This algorithm generates a table of the Fibonacci numbers and just return the last element
 * which is the Fn required.
*/
static l calculate_Fn(l *ftable, int n){

	int i = 0;

	if(n <= 1){					// F(n) = n when n == 0 OR n == 1
		return n;
	}

	ftable[0] = 0;					// When n > 1 you need to initialize the first to elements of the table.
	ftable[1] = 1;

	for(i = 2; i <= n; i++){
		ftable[i] = ftable[i-1] + ftable[i-2];	// F(n) = F(n-1) + F(n-2)
	}

	return ftable[n];
}
