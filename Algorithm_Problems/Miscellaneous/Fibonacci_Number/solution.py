
def calculate_Fn(n):
	if n <= 1:
		return n

	ftable = [0,1]

	for i in range(2, n + 1):
		ftable.append( ftable[i-1] + ftable[i-2] )

	return ftable[n]

n = int( input() )

Fn = calculate_Fn(n)

print(Fn)
