class Solution {
private:
    static bool cmp(pair<int, int> left, pair<int, int> right)
    {
        // Height descending
        if (left.first > right.first){return true;}
        if (left.first < right.first){return false;}
        
        // key asscending
        if (left.second < right.second){return true;}
        if (left.second > right.second){return false;}
        
        return false;
    }
    
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        
        vector<pair<int, int>> res;
        for(auto i = 0; i < people.size(); ++i)
        {
            if (people[i].second < res.size())
            {
                res.insert(res.begin() + people[i].second, people[i]);
            }
            else
            {
                res.push_back(people[i]);
            }
        }
        
        return res;
    }
};