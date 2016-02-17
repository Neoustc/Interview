 vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    sort(num.begin(), num.end());
    ans.push_back(num);
    while(next_permutation(num.begin(), num.end()))//Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.
        ans.push_back(num);
    return ans;
}
