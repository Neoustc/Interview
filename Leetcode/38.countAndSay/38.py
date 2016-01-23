def countAndSay(self,n):
	s = "1"
	while n > 1:
		s = self.gen(s)
		n -= 1
	return s

def gen(self, s):
	count, v, i = 1, "", 0
	while i < len(s):
		count = 1
		while i < len(s) - 1 and s[i] == s[i + 1]:
			count += 1
			i += 1
		v = v + str(count) + s[i]
		i += 1
	return v
