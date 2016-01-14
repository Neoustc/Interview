def shortestDistance(self, words, word1, word2):
	p1 = p2 = float('inf')
	result = float('inf')

	for i, w in enumerate(words):
		if w == word1:
			p1 = i
		elif w ==word2:
			p2 = i
		result = min (abs(p2 - p1), result)
	return result
