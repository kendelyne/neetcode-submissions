class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            //find the middle
            int mid = left + ((right - left) / 2);
            if(nums[mid] > target) {
        //if middle is bigger than the target, shift right over
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                //nums[mid] is equal to the target
                return mid;
            }
        }
        return -1;
    }
};
