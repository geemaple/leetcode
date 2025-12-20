//  Tag: Array, Dynamic Programming, Tree, Depth-First Search
//  Time: O(N * Budget^2)
//  Space: O(N * Budget)
//  Ref: -
//  Note: -

//  You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO. You are given two 1-based integer arrays, present and future, each of length n, where:
//  
//  present[i] represents the current price at which the ith employee can buy a stock today.
//  future[i] represents the expected price at which the ith employee can sell the stock tomorrow.
//  
//  The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.
//  Additionally, you have an integer budget representing the total funds available for investment.
//  However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).
//  Return the maximum profit that can be achieved without exceeding the given budget.
//  Note:
//  
//  You may buy each stock at most once.
//  You cannot use any profit earned from future stock prices to fund additional investments and must buy only from budget.
//  
//   
//  Example 1:
//  
//  Input: n = 2, present = [1,2], future = [4,3], hierarchy = [[1,2]], budget = 3
//  Output: 5
//  Explanation:
//  
//  
//  Employee 1 buys the stock at price 1 and earns a profit of 4 - 1 = 3.
//  Since Employee 1 is the direct boss of Employee 2, Employee 2 gets a discounted price of floor(2 / 2) = 1.
//  Employee 2 buys the stock at price 1 and earns a profit of 3 - 1 = 2.
//  The total buying cost is 1 + 1 = 2 <= budget. Thus, the maximum total profit achieved is 3 + 2 = 5.
//  
//  
//  Example 2:
//  
//  Input: n = 2, present = [3,4], future = [5,8], hierarchy = [[1,2]], budget = 4
//  Output: 4
//  Explanation:
//  
//  
//  Employee 2 buys the stock at price 4 and earns a profit of 8 - 4 = 4.
//  Since both employees cannot buy together, the maximum profit is 4.
//  
//  
//  Example 3:
//  
//  Input: n = 3, present = [4,6,8], future = [7,9,11], hierarchy = [[1,2],[1,3]], budget = 10
//  Output: 10
//  Explanation:
//  
//  
//  Employee 1 buys the stock at price 4 and earns a profit of 7 - 4 = 3.
//  Employee 3 would get a discounted price of floor(8 / 2) = 4 and earns a profit of 11 - 4 = 7.
//  Employee 1 and Employee 3 buy their stocks at a total cost of 4 + 4 = 8 <= budget. Thus, the maximum total profit achieved is 3 + 7 = 10.
//  
//  
//  Example 4:
//  
//  Input: n = 3, present = [5,2,3], future = [8,5,6], hierarchy = [[1,2],[2,3]], budget = 7
//  Output: 12
//  Explanation:
//  
//  
//  Employee 1 buys the stock at price 5 and earns a profit of 8 - 5 = 3.
//  Employee 2 would get a discounted price of floor(2 / 2) = 1 and earns a profit of 5 - 1 = 4.
//  Employee 3 would get a discounted price of floor(3 / 2) = 1 and earns a profit of 6 - 1 = 5.
//  The total cost becomes 5 + 1 + 1 = 7 <= budget. Thus, the maximum total profit achieved is 3 + 4 + 5 = 12.
//  
//  
//   
//  Constraints:
//  
//  1 <= n <= 160
//  present.length, future.length == n
//  1 <= present[i], future[i] <= 50
//  hierarchy.length == n - 1
//  hierarchy[i] == [ui, vi]
//  1 <= ui, vi <= n
//  ui != vi
//  1 <= budget <= 160
//  There are no duplicate edges.
//  Employee 1 is the direct or indirect boss of every employee.
//  The input graph hierarchy is guaranteed to have no cycles.
//  
//  

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        unordered_map<int, vector<int>> graph;
        for (auto &e : hierarchy) {
            graph[e[0]].push_back(e[1]);
        }

        auto res = dfs(graph, present, future, budget, 1, false, dp);
        int ans = 0;
        for (auto &[cost, profit] : res) {
            ans = max(ans, profit);
        }
        return ans;
    }

    unordered_map<int, int> dfs(unordered_map<int, vector<int>> &graph, vector<int>& present, vector<int>& future, int budget, int cur, bool discount, unordered_map<int, unordered_map<int, unordered_map<int, int>>> &dp) {

        if (dp.find(cur) == dp.end() || dp[cur].find(discount) == dp[cur].end()) {
            int cost = discount ? floor(present[cur - 1] / 2.0) : present[cur - 1];
            int profit = future[cur - 1] - cost;

            unordered_map<int, int> buy_current;
            unordered_map<int, int> skip_current;
            skip_current[0] = 0;
            if (cost <= budget) {
                buy_current[cost] = profit;
            }

            for (int child : graph[cur]) {
                auto child_with_discount = dfs(graph, present, future, budget, child, true, dp);
                auto child_no_discount = dfs(graph, present, future, budget, child, false, dp);

                unordered_map<int, int> new_buy;
                for (auto &[spent, p] : buy_current) {
                    for (auto &[c_spent, c_profit] : child_with_discount) {
                        int total_spent = spent + c_spent;
                        if (total_spent <= budget) {
                            int total_profit = p + c_profit;
                            if (!new_buy.count(total_spent) ||
                                new_buy[total_spent] < total_profit) {
                                new_buy[total_spent] = total_profit;
                            }
                        }
                    }
                }
                buy_current.swap(new_buy);

                unordered_map<int, int> new_skip;
                for (auto &[spent, p] : skip_current) {
                    for (auto &[c_spent, c_profit] : child_no_discount) {
                        int total_spent = spent + c_spent;
                        if (total_spent <= budget) {
                            int total_profit = p + c_profit;
                            if (!new_skip.count(total_spent) ||
                                new_skip[total_spent] < total_profit) {
                                new_skip[total_spent] = total_profit;
                            }
                        }
                    }
                }
                skip_current.swap(new_skip);
            }

            unordered_map<int, int> res;
            for (auto &[spent, p] : buy_current) {
                if (!res.count(spent) || res[spent] < p) {
                    res[spent] = p;
                }
            }
            for (auto &[spent, p] : skip_current) {
                if (!res.count(spent) || res[spent] < p) {
                    res[spent] = p;
                }
            }

            dp[cur][discount] = res;
        }

        return dp[cur][discount];   
    }
};