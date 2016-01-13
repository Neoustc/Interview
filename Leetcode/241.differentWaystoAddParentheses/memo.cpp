class Solution {
public:
vector<int> diffWaysToCompute(string input) 
{
    unordered_map <string, vector<int> > memo;
    return Compute(memo, input);
}

vector<int> Compute(unordered_map<string, vector<int> > & memo, string input)
{
    vector<int> res;
    for (int i = 0; i < input.size(); ++i)
    {
        vector<int> res1, res2;
        if (ispunct(input[i]))
        {
        string left = input.substr(0, i);
        if (memo[left].size() > 0) 
             res1 = memo[left];
        else 
             res1 = Compute(memo, left);
        string right = input.substr(i + 1);
        if (memo[right].size() > 0)
            res2 = memo[right];
        else 
            res2 = Compute(memo, right);
        for (auto r1 : res1)
            for (auto r2 : res2)
            {
                if (input[i] == '+')
                    res.push_back(r1 + r2);
                else if (input[i] == '-')
                    res.push_back(r1 - r2);
                else res.push_back(r1 * r2);
            }
        }
    }
    if (res.empty())
        res.push_back(stoi(input));
    memo[input] = res;
    return res;
}
    };
