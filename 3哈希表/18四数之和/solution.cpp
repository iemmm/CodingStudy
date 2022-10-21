#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] > target && target > 0) return res;
            if(nums[k] > 0 && target < 0) return res;
            if(k > 0 && nums[k] == nums[k-1]) continue;
            for(int i = k + 1; i < nums.size(); i++){
                if(nums[i] > target - nums[k] && target - nums[k] > 0) break;
                if(nums[i] + nums[k] > target && target > 0) continue;
                if(i > k + 1 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while(right > left){
                    if((nums[k] + nums[i]) < target-nums[left] - nums[right]) left++;
                    else if((nums[k] + nums[i]) > target - nums[left] - nums[right]) right--;
                    else{
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while(right > left && nums[left] == nums[left + 1]) left++;
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }

                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> test={1, 0, -1, 0, -2, 2};
    // for(auto iter = test.begin(); iter != test.end(); iter++){
    //     cout << *iter<<", ";
    // }
    for(int i=0; i < test.size(); i++){
        cout << test[i]<<", ";
    }
    
    Solution a;
    vector<vector<int>> res = a.fourSum(test, 0);
    for(auto iter =res.begin(); iter != res.end(); iter++){
        cout<<"[";
        vector res1 = *iter;
        for (auto iter1 = res1.begin(); iter1 !=res1.end(); iter1++){
        cout<<*iter1<<", ";
        }
        cout <<"] ";
    }
    return 0;
}