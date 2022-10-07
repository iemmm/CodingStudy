/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

思路：
主要是创建两个指针，一个记录头部位置，一个记录尾部位置，然后用一个for循环不断更新头部位置和尾部位置。
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int j = 0;
        int result = INT32_MAX;
        for(int i=0; i < size; i++){
            sum += nums[i];
            while(sum >= target){
                result = (i - j + 1) < result ? (i -j + 1) : result;
                sum -=nums[j];
                j ++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};