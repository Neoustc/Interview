//chr: int to char
//ord: char to int
def convertToTitle(self, num):
	capitals = [chr(x) for x in range(ord('A'), ord('Z') + 1)];
	result = []
	while n > 0 :
		result.append(capitals[(n - 1) % 26])
		n = (n - 1)// 26
	result.reverse()
	return ''.join(result)
