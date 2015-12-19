//Group the number by thousands 
class Solution {
public:
   static string singles[];
   static string doubles[];
   static string multi[];
	
    string numberToWords(int num) {
    	if (num == 0) return "Zero";
    	string res = "";
    	int i = 0;
    	while (num > 0){
    		if ((num % 1000) != 0)
    			res = helper(num % 1000) + multi[i]+ " " + res;
    		num /= 1000;
    		++i;
    	}
       while (res.back() == ' ')
       res.pop_back();
       return res;
    }
    	string helper(int num)
    	{
    		if (num == 0) return "";
    		else if (num < 20)
    			return  singles[num] + " ";
    		else if (num < 100)
    			return doubles[num / 10] + " " + helper(num % 10);
    		else 
    			return  singles[num / 100] + " Hundred " + helper(num % 100);
    	}        
};
  string Solution:: singles[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  string Solution :: doubles[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
	"Seventy", "Eighty", "Ninety"};
  string Solution ::multi[] = {"", "Thousand", "Million", "Billion"};
