 vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
     int n = intervals.size();
     vector<Interval> res;
     for (int i = 0; i < n; ++i)
     {
     	if (newInterval.start <= intervals[i].end)
     	{
     		newInterval.start = min (newInterval.start, intervals[i].start);
     		while (i < n && newInterval.end >= intervals[i].start) 
     		{ 
     		    newInterval.end = max (newInterval.end, intervals[i].end);
     		    ++i;
     		}
     		res.push_back(newInterval);
     		if (i == n) return res;
     		res.insert(res.end(), intervals.begin() + i, intervals.end());
     		return res;
     	}
     	else res.push_back(intervals[i]);
     }
     res.push_back(newInterval);
     return res;
}


  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
     int n = intervals.size();
     vector<Interval> res;
     for (int i = 0; i < n; ++i)
     {
     	if (newInterval.start <= intervals[i].end)
     	{
     		newInterval.start = min (newInterval.start, intervals[i].start);
     		while (i < n && newInterval.end >= intervals[i].start)
     		            ++i;
     	    newInterval.end = max(newInterval.end, intervals[i - 1].end);
     		res.push_back(newInterval);
     		if(i == n) return res;
     		res.insert(res.end(), intervals.begin() + i, intervals.end());
     		return res;
     	}
     	else res.push_back(intervals[i]);
     }
     res.push_back(newInterval);
     return res;
}


vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> left, right;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i].end < newInterval.start) {
            left.push_back(intervals[i]);
        }
        if (intervals[i].start > newInterval.end) {
            right.push_back(intervals[i]);
        }
    }
    int s = newInterval.start, e = newInterval.end;
    if ((left.size()+right.size()) != intervals.size()) {
        s = min(s, intervals[left.size()].start);
        e = max(e, intervals[intervals.size()-right.size()-1].end);
    }
    Interval middle(s,e);
    left.push_back(middle);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
