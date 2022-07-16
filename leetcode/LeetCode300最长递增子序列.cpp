/*

法一：动态规划 初始dp数组1 从0~i个状态跳到i 
法二：贪心+二分法  需两个数组  7 8 9 1 2 10    789->189(res 3)->1 2 9(res 3)->12910(res 4) 递增序列78910 

 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    
    int n=nums.size(),res=0;
    vector<int>dp(n,1);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(nums[j]<nums[i])
                 dp[i]=max(dp[i],dp[j]+1);  //动态规划 从0~i个状态跳到i
        }
    res=max(res,dp[i]);
    }
    
    return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    
    int n=nums.size();
    int res=0,mid,right;

    vector<int>tail(n);
    tail[0]=nums[0];
    for(int i=0;i<n;++i)
    {
        int left=0; //二分查找的起点是0
        right=res;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(nums[i]>tail[mid])
                left=mid+1;
            else
                right=mid;
        }
        tail[left]=nums[i]; //选择位置插入
        if(right==res) res++; //tail数组的末尾 right是下标从0 right=res res需要++
    }
    
    return res;
    }
};
