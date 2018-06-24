// O * logN
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(auto num: nums){
            map[num] += 1;
        }
        
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (auto it = map.begin(); it != map.end(); ++it){
            pq.push(make_pair(it->second, it->first));

            if (pq.size() > map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
            
        }
        
        return res;
    }
};