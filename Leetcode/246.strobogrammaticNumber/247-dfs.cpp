void dfs (vector<string>& res, string temp, vector<string> & pair, int i, int j)
{
    if (i > j)
    {
        if (temp[0] != '0' || temp.size() == 1)
        {
            res.push_back(temp);
            return;
        }
    }
    for (int x = 0; x < 5; ++x)
    {
        temp[i] = pair[x][0];
        temp[j] = pair[x][1];
        if (i == j && pair[x][0] == pair[x][1] || i < j)
        dfs(res, temp, pair, i + 1, j - 1);
    }
}

vector<string> Strobogrammatic_print(int n)
{
    vector<string>  pair = {"00", "11", "69", "88", "96"};
    string temp(n, '0');
    vector <string> res; 
    dfs (res,temp, pair, 0, n - 1);
    return res;
}
