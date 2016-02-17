 string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string res(n + m, '0'); // the max size of the result
        for (int i = n - 1; i >= 0; --i)// traverse backwards 
            {
                int carry = 0;
                for (int j = m - 1; j >= 0; --j)
                {
                    int tmp = (num1[i] - '0') * (num2[j] - '0') + carry  + (res[i + j + 1] - '0');
                    res[i + j + 1] = (tmp % 10 + '0');
                    carry = tmp / 10;
                }
                res[i] += carry;// don't forget the carry and shouldn't add '0';
            }
            int pos = res.find_first_not_of("0");
            if (pos != string :: npos) // or  != -1
            return res.substr(pos);
            else return "0";
    }
