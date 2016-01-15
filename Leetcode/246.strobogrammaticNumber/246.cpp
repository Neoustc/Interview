http://blog.csdn.net/u010738052/article/details/50522489
class Solution {
public:
    bool isStrobogrammatic(string num) {
        table['0'] = '0';
        table['1'] = '1';
        table['6'] = '9';
        table['8'] = '8';
        table['9'] = '6';
        int n = num.length(); 
        for (int l = 0, r = n - 1; l <= r; l++, r--)
            if (table.find(num[l]) == table.end() || table[num[l]] != num[r])
                return false;
        return true;
    }
private:
    unordered_map<char, char> table; 
};
