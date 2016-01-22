http://blog.csdn.net/u010738052/article/details/50568102
  int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (auto c : nums)
    {
        int tmp = (a & ~b & ~c) + (~a & b &c);
        b = (~a & b & ~c) + (~a & ~b &c);
        a = tmp;
    }
    return a | b;
    }
