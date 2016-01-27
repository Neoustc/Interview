int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
        int n = heights.size();
        stack<int> indexes;
        int maxArea = 0;
        for (int i = 0; i < n; ++i)
        {
        	while (!indexes.empty() && heights[indexes.top()] > heights[i]) {
        		int h = height[indexes.top()]; indexes.pop();
        		int l = indexes.empty()? -1 : indexes.top();
        		maxArea = max(maxArea, h * (i - l - 1));
        	}
        	indexes.push(i);
        }
        return maxArea;
    }
