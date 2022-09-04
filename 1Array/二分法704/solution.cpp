#include<iostream>
#include<vector>

class Solution{
public:
    int search(vector<int>&num, int target){
        int left = 0;
        int right = nums.size();
        while(nums[left] <= nums[right]){
            int midle = left/2 + (right - left)/2;
            if(nums[midle] <= target){
                left = midle;
            }
            else if(nums[midle] > target){
                right = midle;
            }
            else{
                return nums[midle];
            }
        }
        return -1;
    }
}

int main(){
    int a=2;
    std::cout<<1/a<<std::endl;
}