class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        int k = size - 1;
        for(int i = 0, j = size - 1; i<=j; ){
            if(abs(nums[i])> abs(nums[j])){
                result[k] = nums[i] * nums[i];
                k--;
                i++;
            }
            else{
                result[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return result;
    }
};