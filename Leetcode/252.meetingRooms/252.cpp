//http://blog.csdn.net/u010738052/article/details/50526693
// Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
// The function shall not modify any of its arguments.
// This can either be a function pointer or a function object.
 bool canAttendMeetings(vector<Interval>& intervals) 
 {
 	sort(intervals.begin(), intervals.end(), compare);
 	int n = intervals.size();
 	for (int i = 0; i < n - 1; ++i)
 		if (intervals[i].end > intervals[i + 1].start)
 			return false;
 		return true;
 }
static bool compare(Intervals & inter1, Intervals & inter2)
{
	return inter1.start < inter2.start;
}
