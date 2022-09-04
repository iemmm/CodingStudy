class solution{
public:
    int search(vector<int>&nums, int target){
        int left, right;
        int midle = 0;
        while(left <= right){
            midle = (right - left) >> 1 + left;
            if(nums[midle] < target){
                left = middle;
            }
            else if(nums[midle] > target){
                right = midle;
            }
            else{
                return midle;
            }
        }
        return -1;
    }
};