vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        int length = buildings.size();
        if (length <= 1) return buildings;
        sort(buildings.begin(), buildings.end());
        int cur = 0, end_X = 0, start_X = 0, cur_H = 0, last = 0;
        priority_queue<pair<int, int>> pq;//height, end;
        vector<vector<int> > res;
        while (cur < length || !pq.empty()) {
            if (pq.empty() || cur < length && buildings[cur][0] <= pq.top().second) {
                start_X = buildings[cur][0];
                end_X = buildings[cur][1];
                while (cur < length && buildings[cur][0] <= start_X) {
                     pq.push(make_pair(buildings[cur][2], buildings[cur][1]));
                     cur++;
                }
            } else {
                start_X = pq.top().second;
                while (!pq.empty() && pq.top().second <= start_X) {
                    pq.pop();
                }
            }
            cur_H = pq.empty() ? 0 : pq.top().first;
            if (res.empty() || (res.back()[2] != cur_H && cur_H != 0) ) {
                    if(res.size() >= 1 && last != 0 ) {
                        res.back()[1] = start_X;
                    }
                        vector<int> v;
         			    v.push_back(start_X);
         			    v.push_back(end_X);
         			    v.push_back(cur_H);
         			    res.push_back(v);
     		}
     		last = cur_H;
        }
        res.back()[1] = start_X;
        return res;
    }
