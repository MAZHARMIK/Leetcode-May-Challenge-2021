class Solution {
public:
    int minMoves2(vector<int>& nums) {
		/*
			To resolve the fight, let's tell everyone to come to mid :-)
			Because, moves taken by elements to move (change) to middle
			element will sum up to the minimum moves
		*/
        sort(begin(nums), end(nums));
        
        int n      = nums.size();
        int mid    = n/2;
        int midE = nums[mid];
        
        int i = mid-1;   //talk to left territory
        int j = mid+1; //talk to right territory
        
        int steps = 0;
        
        while(i >= 0 || j < n) {
            if(i >= 0) {
				//Hey nums[i], let's move to midE
                steps += (midE - nums[i]);
                i--;
            }
            
            if(j < n) {
				//Hey nums[j], let's move to midE
                steps += (nums[j] - midE);
                j++;
            }
        }
        
        return steps;
        
    }
};
