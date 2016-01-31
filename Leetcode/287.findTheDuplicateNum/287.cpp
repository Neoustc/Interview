//http://keithschwarz.com/interesting/code/?dir=find-duplicate

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1,n=nums.size();
        int r=n-1;
        while(l<r)
        {
        	int m=l+((r-l)>>1);
        	int cnt=notGreaterThan(nums,m);
        	if(cnt<=m)l=m+1;
        	else r=m;
        }
        return l;
    }
int notGreaterThan(std::vector<int>& nums,int target)
{
	int cnt=0;
	for(int num:nums)
		if(num<=target)
			cnt++;
		return cnt;

}
//same as find linked cycle!
// if the index=f(index) we should isolated this index because 
//it will never go to the chain
//like  this example value :1~n; index: 0~n;we could start  from both side 
//but like value:0~（n-2),index:0~n-1;  we shouldn't start from 0 because maybe f(0)==0;
//we will never meet cycle.so we start from the end, and we minus the 1 of the value
//like:slow=nums[slow]-1;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        int find=0;
        while(slow!=find){
            slow=nums[slow];
            find=nums[find];
        }
        return find;
    }
};
	
};
