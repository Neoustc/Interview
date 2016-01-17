class Solution {
public:
   vector<int> plusOne (vector<int>& digits) 
 {
 	int n = digits.size(), i;
 	for (i = n - 1; i >= 0; i --)
 	{
 		if (digits[i] == 9)
 				digits[i] = 0;			
 		else 
 			{
 				digits[i]++;
 				return digits;
 			}
 	}
 	if (i < 0) digits.insert(digits.begin(), 1);
 	return digits;
 }
};
