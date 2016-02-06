#bin(3)
#'0b11'
def addBinary(self, a, b):
	a = int(a, 2)
	b = int(b, 2)
	return ("" + bin(a + b))[2 :]
