#include <iostream>
#include <string>
using namespace std;
//The example can be written as follow:

/*
P.......A........H.......N
..A..P....L..S....I...I....G
....Y.........I........R

row every time take a step,when the row==0,step=1;
when row=numrows-1,step=-1;
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
        int len=s.size();
        string *str=new string[numRows];
        int row=0,step=1;
        for(int i=0;i<len;i++)
        {
        	str[row].push_back(s[i]);
        	if(row==0)
        		step=1;
        	else if(row==numRows-1)
        		step=-1;
        	row+=step;
        }
        s.clear();
        for(int j=0;j<numRows;j++)
        {
        	s.append(str[j]);
        }
        delete[] str;
        return s;
    }
};
