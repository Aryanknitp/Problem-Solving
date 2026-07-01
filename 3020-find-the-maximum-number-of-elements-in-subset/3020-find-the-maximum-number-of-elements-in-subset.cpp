class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::unordered_map<long long, int> count;
        long long max_num = 0;
        for (int num : nums) {
            count[num]++;
            max_num = std::max(max_num, (long long)num);
        }
 
        int ans = 1;
        if (count.find(1) != count.end()) {
            ans = (count[1] % 2 != 0) ? count[1] : count[1] - 1;
        }

        for (auto& [num, freq] : count) {
            if (num == 1)
                continue;

            int current_len = 0;
            long long x = num;

            while (x <= max_num && count.find(x) != count.end() &&
                   count[x] >= 2) {
                current_len += 2;
                x = x * x;
            }

            if (x <= max_num && count.find(x) != count.end()) {
                current_len += 1;
            } else {
                current_len -= 1;
            }

            ans = std::max(ans, current_len);
        }

        return ans;
    }
};
