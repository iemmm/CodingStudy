class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();//求数组的长度
        int left = 0;
        int right = size; //将target定义在左闭右开区间[left, right)
        while(left < right){
            int middle = left + (right - left) / 2;//避免溢出
            if(nums[middle] > target) {
                right = middle;
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                return middle;
            }
        }
        return right;
    }
};