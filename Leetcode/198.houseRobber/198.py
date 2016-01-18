class Solution:
	def rob(self, nums):
		last, now = 0, 0
		for i in nums:
			#last, now = now, max(last + i, now)
			now, last = max(last + i, now), now
		return now
