class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // indexes  bottom-left 0x, 1y  top-right 2x, 3y
        
        if (rec1[1] >= rec2[3] || rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2]) {
            return false;
        }

        return true;
    }
};
