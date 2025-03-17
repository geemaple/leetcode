//  Tag: Array, Binary Search
//  Time: O(AlogN)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/0iwaFdV71Dk

//  You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
//  You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
//  Return the minimum time taken to repair all the cars.
//  Note: All the mechanics can repair the cars simultaneously.
//   
//  Example 1:
//  
//  Input: ranks = [4,2,3,1], cars = 10
//  Output: 16
//  Explanation: 
//  - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
//  - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
//  - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
//  - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
//  It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
//  
//  Example 2:
//  
//  Input: ranks = [5,1,8], cars = 6
//  Output: 16
//  Explanation: 
//  - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
//  - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
//  - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
//  It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
//  
//   
//  Constraints:
//  
//  1 <= ranks.length <= 105
//  1 <= ranks[i] <= 100
//  1 <= cars <= 106
//  
//  

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r = 100 * 1e6 * 1e6;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (fit(ranks, m, cars)){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    bool fit(vector<int>& ranks, long long k, int cars) {
        int n = ranks.size();
        int res = 0;
        for (int i = 0; i < n && res < cars; i++) {
            if (k >= ranks[i]) {
                res += floor(sqrt(k / ranks[i]));
            }
        }

        return res >= cars;
    }
};

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            unordered_map<int, int> counter;
            for (int rank : ranks) {
                counter[rank]++;
            }
    
            priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int>>, greater<>> heap;
    
            for (auto& [rank, count] : counter) {
                long long time = rank;
                heap.push({time, rank, 1, count});
            }
    
            long long time = 0;
    
            while (cars > 0) {
                auto [cur_time, rank, fixed, count] = heap.top();
                heap.pop();
                cars -= count;
                time = cur_time;
                fixed++;
                heap.push({(long long) rank * fixed * fixed, rank, fixed, count});
            }
    
            return time;
        }
    };