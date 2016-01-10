https://leetcode.com/discuss/16171/sharing-my-simple-c-code-o-n-time-o-1-space
//we should do it in a cumulative way. We set 2 pointers from the two end. 
//Meanwhile, we keep two value maxleft, maxright to maintain the max height of left and
//right respectively. In the process when we  move the two pointers  towards the center. 
//if the height[l] <= height[r], we could fill the water in the left bin. So we compare the height[left] with the maxleft,
//if height[l] is greater. then we just updated the maxleft, else we fill the water.
int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n - 1;
        int res=0;
        int maxleft=0,maxright=0;
        while(left<=right)//< works too, because in the end the two pointers will meet in the highest place
        {
        	if(height[left]<=height[right]){
        		if(height[left]>=maxleft)
        			maxleft=height[left];
        		else res+=maxleft-height[left];
        		left++;
        	}
        	else{
        		if(height[right]>=maxright)maxright=height[right];
        		else res+=maxright-height[right];
        		right--;
        	}

        }
      	return res; 	
    }
