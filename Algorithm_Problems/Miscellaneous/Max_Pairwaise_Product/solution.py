
def max_pair_product(dataset):
	
	index = 0
	for i,data in enumerate(dataset):
		if dataset[index] < data:
			index = i

	temp = dataset[-1]
	dataset[-1] = dataset[index]
	dataset[index] = temp

	index = 0
	for i, data in enumerate(dataset[:-1]):
		if dataset[index] < data:
			index = i

	temp = dataset[-2]
	dataset[-2] = dataset[index]
	dataset[index] = temp

	return dataset[-1] * dataset[-2]	


n = int( input() )

dataset = [int(x) for x in input().split()]

result = max_pair_product(dataset)

print(result)
