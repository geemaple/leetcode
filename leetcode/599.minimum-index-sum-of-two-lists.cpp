class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); ++i){
            map.insert(make_pair(list1[i], i));
        }
        
        int sum = INT_MAX;
        vector<string> res;
        for (int j = 0; j < list2.size(); ++j){
            if (map.count(list2[j]) > 0){
                int tmp = map[list2[j]] + j;
                
                if (tmp == sum){
                    res.push_back(list2[j]);
                }else if (tmp < sum){
                    res.clear();
                    sum = tmp;
                    res.push_back(list2[j]);
                }
            }   
        }
        
        return res;
    }
};