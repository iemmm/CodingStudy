class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int size = nums.size();
        for(int fast = 0; fast < size; fast++){
            if(val != nums[fast]){
                nums[slow]=nums[fast];
                slow ++;
            }
        }
        return slow;
    }
};