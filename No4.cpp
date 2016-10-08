class Solution {
public:
	//the solution is inspired by 
	//https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/2
	//a consice and elegent solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
    	int len1=nums1.size();
    	int len2=nums2.size();
    	if(len1<len2)
    	{
    		return findMedianSortedArrays(nums2,nums1);
    	}    

    	if (len2==0)
    	{
    		return ((double)nums1[(len1-1)/2]+(double)nums1[len1/2])/2;
    	}

    	int low=0; int high=len2*2;

    	while(low<=high)
    	{
    		int mid2 = (low+high)/2;
    		int mid1 = len1+len2-mid2;

    		int L1=(mid1==0)?INT_MIN:nums1[(mid1-1)/2];
    		int L2=(mid2==0)?INT_MIN:nums2[(mid2-1)/2];
    		int R1=(mid1*2==len1)?INT_MAX:nums1[mid1/2];
    		int R2=(mid2*2==len2)?INT_MAX:nums2[mid2/2];

    		if(L1>R2)	low=mid2+1;
    		else if(L2>R1)	high=mid2-1;
    		else return (max(L1,L2)+min(R1,R2))/2;
    	}
    	return -1;

    }
};