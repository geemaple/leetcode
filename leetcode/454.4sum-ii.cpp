class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        int res = 0;
        unordered_map<int, int> abSum;
        
        for (auto a: A){
            for (auto b: B){
                abSum[a + b] += 1;
            }
        }
        
        for (auto c: C){
            for (auto d: D){
                int target = 0 - c - d;
                res += abSum[target];
            }
        }
        
        return res;
    }
};