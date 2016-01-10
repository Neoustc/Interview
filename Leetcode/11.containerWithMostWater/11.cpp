 //https://leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
 int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxArea=0;
        while(i<j)
        {
        	maxArea=max(maxArea,min(height[i],height[j])*(j-i));

        	height[i]<=height[j]?i++:j--;
        }
        return maxArea;
    }
