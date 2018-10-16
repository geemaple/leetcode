class Solution {
private:
    bool static cmp(const pair<int, int>&a, const pair<int, int>&b){
        if (a.first < b.first) return true;
        if (a.first > b.first) return false;
        return a.second < b.second;
    }
    
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        
        vector<pair<int, int>> dots;
        
        for(auto i = 0; i < airplanes.size(); ++i)
        {
            dots.push_back(make_pair(airplanes[i].start, 1));
            dots.push_back(make_pair(airplanes[i].end, -1));
        }
        
        sort(dots.begin(), dots.end(), cmp);
        
        int result = 0;
        int count = 0;
        for(auto i = 0; i < dots.size(); ++i)
        {
            count += dots[i].second;
            result = max(result, count);
        }
        
        return result;
    }
};