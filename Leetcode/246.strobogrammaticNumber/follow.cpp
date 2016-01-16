// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> Strobogrammatic_print(int n)
  {
	vector<string> res;
	if (n & 1)  res ={"0", "1", "8"};
	else res = {""};
	vector <string> pair = {"00", "11", "69", "88", "96"};
	for (; n > 1; n -= 2)
	{
		vector<string> temp;
		for (string rel : res)
			for (int i = n < 4; i < pair.size(); i++)
			temp.push_back(pair[i][0] + rel + pair[i][1]);	
		res = move(temp);	
	}
	return res;
  }
  vector<string> findStrobogrammatic1(int n) {
        vector<string> strobos;
        if (n & 1) strobos = {"0", "1", "8"};
        else strobos = {""};
        vector<string> bases = {"00", "11", "69", "88", "96"};
        int m = bases.size();
        // while (n > 1) {
        //     n -= 2;
        //     vector<string> temp; 
        //     for (string strobo : strobos)
        //         for (int i = n < 2; i < m; i++)
        //             temp.push_back(bases[i][0] + strobo + bases[i][1]);
        //     strobos = move(temp);
        // }
        return strobos;
    }
  
int main()
{
 vector<string> s = Strobogrammatic_print(6);
 vector<string> v = findStrobogrammatic1(6);
 for (auto i : s)
 cout<<i<<" ";
 cout<<"ss"<<endl;
 for (auto i : v)
 cout<<i<< " ";
 return 0;
}
