struct Triple {
    int height, x, y;
    
    Triple(int height, int x, int y){
        this->height = height;
        this->x = x;
        this->y = y;
    }
    
    // default is max heap, less. we need min heap, so greater
    friend bool operator<(const Triple& a, const Triple& b)
    {
        return a.height > b.height;
    }
};

class Solution {
private:
    int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    priority_queue<Triple, vector<Triple>> pq;
    unordered_set<int> visited;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3)
        {
            return 0;
        }
        
        int row = (int)(heightMap.size());
        int col = (int)(heightMap[0].size());
        initialize(heightMap, row, col);
        
        int result = 0;
        while (pq.size() > 0)
        {
            Triple top = pq.top();
            pq.pop();
            
            // loop 4 directions
            for (auto dir: directions)
            {
                int new_x = top.x + dir[0];
                int new_y = top.y + dir[1];
                int point = convertPoint(new_x, new_y, col);
                if (inBoundary(new_x, new_y, heightMap) && visited.count(point) == 0)
                {
                    int new_height = heightMap[new_x][new_y];
                    result += max(0, top.height - new_height);
                    add(max(top.height, new_height), new_x, new_y, col);
                }
            }
        }
        
        return result;
    }
    
    int convertPoint(int x, int y, int col)
    {
        return x * col + y;
    }
    
    // add 4 edge to priority_queue
    void initialize(vector<vector<int>>& heightMap, int row, int col)
    {
        // add first and last col
        for (int i = 0; i < row; ++i)
        {
            add(heightMap[i][0], i, 0, col);
            add(heightMap[i][col - 1], i, col - 1, col);
        }
        
        // add first and last row
        for (int i = 1; i < col - 1; ++i)
        {
            add(heightMap[0][i], 0, i, col);
            add(heightMap[row - 1][i], row - 1, i, col);
        }
    }
    
    void add(int height, int x, int y, int col)
    {
        visited.insert(convertPoint(x, y, col));
        pq.push(Triple(height, x, y));
    }
    
    bool inBoundary(int x, int y, vector<vector<int>>& heightMap)
    {
        return (x >= 0 && x < heightMap.size() && y >= 0 && y < heightMap[x].size());
    }
};