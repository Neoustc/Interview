/*
build heap,actually is a adjust heap
adjust heap 
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
	public:
	void heapSort(std::vector<int> &nums)
	{
		
		buildHeap(nums);
		for(int i=0;i<heap_size;i++)
		{
			swap(nums[0],nums[heap_size-1]);
			heap_size--;
			heapAdjust(nums,0);
		}

	}
	void buildHeap(vector<int >&nums)
	{
		heap_size=nums.size();
		for (int i = (heap_size/2-1); i >= 0; i--)/////
		{
			heapAdjust(nums,i);
		}
	}
	void heapAdjust(std::vector<int> &nums,int i){
		int left=2*i+1;
		int right=2*i+2;
		int max=i;
			if(left< heap_size&&nums[left]>nums[max])
			{
				max=left;
			}	
			if(right< heap_size&&nums[right]>nums[max])
			{
				max=right;
			}
			if(max!=i)
			{
				swap(nums[i],nums[max]);//////
				heapAdjust(nums,max);//top down adjust
			}
		}
private:
	int heap_size;
};

int main(int argc, char const *argv[])
{
	Solution A;
	int a[]={2,1,3,5,6,4,7,7};
	std::vector<int> v(a,a+8);
	//A.Qsort(v,0,7);
	A.heapSort(v);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<(*i);
	}
	return 0;
}
