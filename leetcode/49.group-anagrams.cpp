// N * k * Logk k=average string length
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, int> map;
        vector<vector<string>> res;
        
        for (auto str: strs){

            string tmp = str;
            sort(tmp.begin(), tmp.end());
            
            if (map.count(tmp) > 0){
                res[map[tmp]].push_back(str);
            }else{
                vector<string> list;
                list.push_back(str);
                res.push_back(list);
                map[tmp] = res.size() - 1;
            }
        }
        
        return res;
    }
};