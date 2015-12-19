// careful the  definition of static member variable
class Solution {
private:
	static string word1[];
	static string word2[];
	static string word3[];

public:
    string numberToWords(int num) {
    	if (num == 0 ) return "Zero";
    	string res = "";
    	return helper(num).substr(1);
    }
    string helper (int num){
    		if (num >= 1000000000) {return helper(num / 1000000000) + " " + word3[4] + helper(num % 1000000000);}      
 	   		else if (num >= 1000000) {return helper(num / 1000000) + " "+ word3[3] + helper(num % 1000000);}
 	   		else if (num >= 1000) {return helper(num / 1000) + " " + word3[2] + helper(num % 1000);}
 	   		else if (num >= 100) {return helper(num / 100) + " " + word3[1] + helper(num % 100);}
 	   		else if (num >= 20) {return " " + word2[num / 10] + helper(num % 10);}
 	   		else  if (num >= 1) {return " " + word1[num];}
 	   		else return "";
    }
 	   	
};
string Solution :: word1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string Solution :: word2[] = {"", "ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty","Seventy", "Eighty", "Ninety"};
string Solution :: word3[] = {"", "Hundred","Thousand", "Million", "Billion"};
