#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    std::vector<int> nums;
public:
    MedianFinder() {}
    void addNum(int num) {
        auto  it = std::lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2 != 0)
            return nums[n / 2];
        else {
            return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */