class Solution {
public:
    int binarysearch(vector<int>&nums,int n,int target)
    {
        int l=0,r=n-1;
        int mid;
        int result_idx=-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(nums[mid]<=target)
            {
                result_idx=mid;
                l=mid+1;
            }
            else
            {
               r= mid-1;
            }
        }
    return result_idx+1;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n=nums.size();
    sort(begin(nums),end(nums));

    for(int i=1;i<n;i++)
    {
        nums[i]+=nums[i-1];
    }

    vector<int> result;
    for(int &query:queries)
    {
        int count=binarysearch(nums,n,query);

        result.push_back(count);
    }
    return result;
    }
};