#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& p) {
        using pii = pair<int, int>;
        vector<pii> a;
        for(auto e : p){
            a.emplace_back(e[0], e[1]);
        }
        a.emplace_back(kx, ky);
        int n = a.size();
        vector dist(n, vector(50, vector(50, -1)));
        vector<int> di({-2, -2, -1, -1, 1, 1, 2, 2});
        vector<int> dj({-1, 1, -2, 2, -2, 2, -1, 1});
        for(int s = 0; s < n; s++){
            queue<pii> q;
            q.push(a[s]);
            dist[s][a[s].first][a[s].second] = 0;
            while(!q.empty()){
                auto [i, j] = q.front(); q.pop();
                for(int e = 0; e < 8; e++){
                    int ni = i + di[e], nj = j + dj[e];
                    if(ni >= 0 && ni < 50 && nj >= 0 && nj < 50 && dist[s][ni][nj] == -1){
                        dist[s][ni][nj] = dist[s][i][j] + 1;
                        q.push(pii(ni, nj));
                    }
                }
            }
        }
        vector dp(1<<n, vector(n, 0));
        for(int msk = (1<<n) - 2; msk > 0; msk--){
            int ty = __builtin_popcount(msk) & 1;
            
            for(int i = 0; i < n; i++) dp[msk][i] = ty?  -(1<<30) : (1<<30);
            
            for(int i = 0; i < n; i++){
                if((msk>>i) & 1){
                    for(int j = 0; j < n; j++){
                        if((msk >> j) & 1) continue;
                        if(ty){
                            dp[msk][i] = max(dp[msk][i], dp[msk | (1<<j)][j] + dist[i][a[j].first][a[j].second]);
                        } else {
                            dp[msk][i] = min(dp[msk][i], dp[msk | (1<<j)][j] + dist[i][a[j].first][a[j].second]);
                        }
                    }
                }
            }
        }
        return dp[1<<(n - 1)][n - 1];
    }
};


int main() {
    vector<vector<int>> pawns= {{1,1},{2,2},{3,3}};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    int res = s.maxMoves(0, 2, pawns);
    cout << res << endl;
//    for (int word : res) {
//        cout << word << ", ";
//    }
//    cout << endl;
    
    return 0;
}

