/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    int n = ins.size();
    sort(ins.begin(), ins.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
    res.push_back(ins[0]);
    for (int j = 1; j < n; ++j)
	    {	
	    	if (res.back().end < ins[j].start) res.push_back(ins[j]);
	    	else res.back().end = max (res.back().end, ins[j].end);
	    }
	    return res;
}
   
};
