# collections.counter return a dict(key:value)
#for  counting the hashable obejects 
#collections.Counter("102")
#Counter({'1': 1, '0': 1, '2': 1})
#zip(*iterables)
#Make an iterator that aggregates elements from each of the iterables.
#s=Counter({'1': 1, '0': 1, '2': 1}) 
#d=Counter({'1': 1, '0': 1, '3': 1})
#zip (s,d)
#[('1', '1'), ('0', '0'), ('2', '3')]
#s&d 
#s&d=Counter({'1': 1, '0': 1})
#(s&d).values()
#>>>[1, 1]

import collections
class Solution(object):
    def getHint(self, secret, guess):
		s, g = Counter(secret), Counter(guess)
	    a = sum(i == j for i, j in zip(secret, guess))
	    return '%sA%sB' % (a, sum((s & g).values()) - a)
