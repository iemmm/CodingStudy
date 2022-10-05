/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right = getRightBorder(nums, target);
        int left = getleftBorder(nums, target);
        if(right == -2 || left == -2) return {-1, -1};
        if(right - left > 1) return{left + 1, right -1};
        return {-1, -1};
    }

private:
    int getRightBorder(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int RightBorder = -2;//记录边界没有被赋值的情况
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] > target){
                right = middle -1;
            }
            else{
                left = middle + 1;
                RightBorder = left;
            }
        }
        return RightBorder;
    }
    int getleftBorder(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int LeftBorder = -2;//记录边界没有被赋值的情况
        while(left <= right){
            int middle = left + (right - left) / 2;
            // if(nums[middle] >= target){
            //     right = middle - 1;
            //     LeftBorder = right;
            // }
            // else{
            //     left = middle + 1;
            // }
            if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                right = middle - 1;
                LeftBorder = right;
            }
        }
        return LeftBorder;
    }
};