//http://blog.csdn.net/u010738052/article/details/50526693
class Solution 
{
public :
 int minMeetingRooms(vector& intervals) 
 {
 	map<int, int> mp;
 	for (int i = 0; i < intervals.size(); ++i)
 	{
 		mp[intervals[i].start]++;
 		mp[intervals[i].end]--;
 	}
 	int cnt = 0, maxCnt = 0;
 	for (auto i : mp)
 	{
 		cnt += i.second;
 		maxCnt = max(maxCnt, cnt);
 	}
 	return maxCnt;
 }
 
 int findNonoverlapping(vector<Interval>& rooms, Interval & interval)
 {
 	for (int i = 0; i < rooms.size(); ++i)
 		if (interval.start >= rooms[i].end)
 			return i;
 	return -1;
 }

int minMeetingRooms(vector<Interval>& intervals) 
 {
 	sort (intervals.begin(), intervals.end(),[](Interval & s1, Interval &s2){return s1.start < s2.start;});
 	vector<Interval> rooms;
 	for (auto interval : intervals)
 	{
 		int idx = findNonoverlapping(rooms, interval);
 		if (rooms.empty() || idx == -1)
 			rooms.push_back(interval);
 		else rooms[idx] = interval;
 	}
 	return rooms.size();
 }
 


}
