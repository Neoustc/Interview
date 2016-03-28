class Solution {
public:
    vector < pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
     	vector<pair<int, int> > res;
     	int cur = 0, cur_X, cur_H = -1, len = buildings.size();
     	priority_queue< pair<int, int> > liveBlg;//height, end time;
     	while (cur < len || !liveBlg.empty())
     	{
     		//liveBlg empty ,or the next building start before current top building ends,
     		if (liveBlg.empty() || cur < len && buildings[cur][0] <= liveBlg.top().second) {
     			cur_X = buildings[cur][0];
     			// add current bulding to the pq;  might contain dups, use while to push all the buildings
     			while (cur < len && buildings[cur][0] == cur_X)
     			{
     				liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
     				cur++;
     			}
     		} else {
     		    cout<<"pop"<<endl;
     			//update the cur_x to the end of the top building ends
     			cur_X = liveBlg.top().second;
     			//pop  the  useless ending building before cur_x;
     			while (!liveBlg.empty() && liveBlg.top().second <= cur_X)
     				liveBlg.pop();
     		}
     		cout<<liveBlg.size()<<endl;
     		cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
     		if (res.empty() || res.back().second != cur_H)//skip dups
     			{
                    cout<<"push"<<endl;
     			    res.push_back(make_pair(cur_X, cur_H));
     			}
     	}
     	return res;
    }
};
