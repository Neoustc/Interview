 class Solution {
 public :
 static string word1[];
 static string word2[];
 static string word3[];

 string numberToWords(int num) 
 {
 	string res;
 	if (num == 0) return "Zero";
    return helper(num).substr(1);////
 }

 string helper(int num)
 {
 	if (num >= 1000000000)
 		{ return helper (num / 1000000000) + " " + word3[4] + helper(num % 1000000000);}
 	if (num >= 1000000)
 		{ return helper (num / 1000000) + " " + word3[3] + helper(num % 1000000);}
 	if (num >= 1000)
 		{ return helper (num / 1000) + " " + word3[2] + helper(num % 1000);}
 	if (num >= 100)
 		{ return helper (num / 100) + " " + word3[1] + helper(num % 100);}
 	if (num >= 20)
 		{ return  " " + word2[num / 10]  +  helper (num % 10);}
 	if (num > 0)
 		{ return " "  + word1[num];}
 	else return "";
 }
 };
 string Solution :: word1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
 string Solution :: word2[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty","Seventy", "Eighty", "Ninety"};
 string Solution :: word3[] = {"", "Hundred","Thousand", "Million", "Billion"};
 
