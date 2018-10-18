class Solution {
private:
    int byteLength(int n)
    {
        if ((n >> 7) == 0b0)
        {
            return 1;
        }
        else if ((n >> 5) == 0b110)
        {
            return 2;
        }
        else if ((n >> 4) == 0b1110)
        {
            return 3;
        }
        else if ((n >> 3) == 0b11110)
        {
            return 4;
        }
        
        return 0;
    }
public:
    bool validUtf8(vector<int>& data) {
        
        if (data.size() == 0)
        {
            return false;
        }
        
        int i = 0;
        
        while (i < data.size())
        {
            int n = data[i];
            int len = byteLength(n);
            
            if (len == 0 || i + len - 1 >= data.size())
            {
                return false;
            }
            
            for (auto j = i + 1; j <= i + len - 1; ++j)
            {
                if (data[j] >> 6 != 0b10)
                {
                    return false;
                }
            }
            
            i = i + len;
        }
        
        return true;
    }
};