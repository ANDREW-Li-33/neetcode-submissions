class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> set(nums.begin(), nums.end());

        /* this for loop would also solve the problem, but would significantly increase runtime
        for (int num : nums) {
            set.insert(num);
        }
        */

        int longest_seq_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i] - 1) == set.end()) {
                // we know this is the start of a sequence, begin building the sequence
                int current_streak = 1;
                int current_num = nums[i];
                while (set.find(current_num + 1) != set.end()) {
                    current_num++;
                    current_streak++;
                }
                longest_seq_length = max(longest_seq_length, current_streak);
            }
        }       
        return longest_seq_length; 
    }
};
