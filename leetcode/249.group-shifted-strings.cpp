// O(N * K) k = length of string to be shift
class Solution {
private:
    // shift str to begin with 'a' for example 'xyz' -> 'abc'
    string shiftString(string str){
        int offset = 'a' - str[0];
        for(int i = 0; i < str.size(); ++i){
            str[i] = 'a' + (str[i] + offset - 'a' + 26) % 26;
        }

        return str;
    }
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        
        for (auto str: strings){
            string tmp = shiftString(str);

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