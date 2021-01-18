# Fibonacci Number. 

## Problem description:

This is the classical Fibonacci number problem, given an integer number n, find the nth Fibonacci number, which is called *Fn*.

### Input

One single input, an integer n.

### Output

The Fibonacci number Fn.

### Constraints

0 <= n <= 45

### Sample 1

* Input:

> 10

* Output:

> 55 


### Sample 2

* Input:

> 30

* Output:

> 832040


## Solving the problem.

### Theory

The Fibonacci numbers are a sequence of numbers which are obtained using the following function:

> 	F(n) = n			when n = 0 or n = 1;
> 	F(n) = F(n-1) + F(n-2)		when n > 1;


### Naive algorithm

First we see an algorithm for solving the n Fibonacci number which is based on a recursive solution, however we see that when this solution is tested using big numbers to compute it is too slow. Although this algoritm works, it is not efficient neither fast.

Algorithm:
	
	function Fibonacci_number(n):
		if n = 0 or n = 1: 
			then return n
		return Fibonacci_number(n-1) + Fibonacci_number(n-2)

This algorithm is not efficient because the amount of computations it has to perform on each recursive call. 

Fastest algorithm.

The faster algorithm for solving this problem is based on the idea of creating the sequence of Fibonacci numbers from 0 to n and store the values in an array/list so the values are there and there is no need for recursive calls. This algorithm is much much faster since the sequence is created as the algorithm goes and just return the last item in the sequence since it is actually F(n).

**NOTE:** Here we are using the *table solution approach*, this solution is more efficient than the naive algorithm BUT, whereas this solution is **time-complexity efficient**, is **space-complexity inefficient.** 

Algorithm:

	function Fibonacci_number(n):
		if n = 0 or n = 1:
			then return n
		
		array[0] = 0
		array[1] = 1

		for i from 2 to n:
			array[i] = array[i-1] + array[i-2]

		return array[n]


