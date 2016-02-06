class Solution {
public:
   string addBinary(string a, string b) 
 {
 	int n = a.size(), m = b.size();
 	int carry = 0;
 	string res = "";
 	while (n || m || carry)
 	{
 		carry += n ? a[--n] - '0' : 0;
 		carry += m ? b[--m] - '0' : 0;
 		res = to_string(carry % 2) + res; // faster
 		//res = char(carry % 2 + '0') + res;
 		carry = carry / 2;
 	}
 	return res;
 }
};
