// This is just like a coin change/knapsack problem.
//  We need to create a vector of the size of target. 
//  and for each o(1)...o(target) we get the values. 
// and if in between we find any sum == target, 
// add that into the result

class Solution {
public:
std::vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
vector<vector<vector<int> > > combinations(target+1,vector<vector<int> >());
combinations[0].push_back(vector<int>());
for( auto & score:candidates)
	for(int j=score;j<=target;j++)
	{
		if(combinations[j-score].size()>0)
		{
			auto tmp=combinations[j-score];
			for(auto & s:tmp)
				s.push_back(score);
			combinations[j].insert(combinations[j].end(), tmp.begin(), tmp.end());
		}
	}
	auto ret=combinations[target];
	for (int i = 0; i < ret.size(); i++)
            sort(ret[i].begin(), ret[i].end());
        return ret;


    }
};
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector< vector< vector<int> > > combinations(target + 1, vector<vector<int>>());
    combinations[0].push_back(vector<int>());
    for (auto& score : candidates)
        for (int j = score; j <= target; j++){
            auto sls = combinations[j - score];
            if (sls.size() > 0) {
                for (auto& s : sls)
                    s.push_back(score);
                combinations[j].insert(combinations[j].end(), sls.begin(), sls.end());
            }
        }
    return combinations[target];
}
