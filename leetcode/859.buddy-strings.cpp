class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if (A.size() != B.size()){
            return false;
        }
        
        if (A.size() < 2){
            return false;
        }
        
        if (A == B){
            unordered_set<char> set = unordered_set<char>(A.begin(), A.end());
            return set.size() < A.size();
        }
        
        vector<int> indexes;
        for (int i = 0; i < A.size(); ++i){
            if (A[i] != B[i]){
                indexes.push_back(i);
            }
        }
        
        return (indexes.size() == 2 && A[indexes[0]] == B[indexes[1]] && A[indexes[1]] == B[indexes[0]]);
    }
};