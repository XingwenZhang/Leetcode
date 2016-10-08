class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
    	int size1 = nums1.size();
    	int size2 = nums2.size();
    	vector<int> v(size1+size2);
    	vector<int>::iterator it;
    	sort(nums1.begin(),nums1.end());
    	sort(nums2.begin(),nums2.end());
    	it=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),v.begin());
    	v.resize(it-v.begin());
    	it=unique(v.begin(),v.end());
    	v.resize(it-v.begin());
    	return v;

    }
};