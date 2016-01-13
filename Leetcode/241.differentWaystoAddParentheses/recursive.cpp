vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        for (int i = 0; i < n; i++ )
        {
            char c = input[i];
            if (ispunct(c)){
                 // Split input string into two parts and solve them recursively
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
            for (auto op1 : res1)
                for (auto op2 : res2){
                    if (c == '+')
                        res.push_back(op1 + op2);
                    else if (c == '-')
                        res.push_back(op1 - op2);
                    else 
                        res.push_back(op1 * op2);
                }
            }
        }
            if (res.empty()) 
                //res.push_back(atoi(input.c_str());
                res.push_back(stoi(input));
            return res;
    }
