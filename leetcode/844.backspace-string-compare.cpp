class Solution {
public:
    
    int findPreviousCharIndex(string str, int from)
    {
        int count = 0;
        for (int i = from; i >= 0; --i)
        {
            if (str[i] == '#'){
                count++;
            }
            else
            {
                if(count > 0)
                {
                    count--;
                }
                else
                {
                    return i;
                }
            }
        }
        
        return -1;
    }
    
    bool backspaceCompare(string S, string T) {
        
        int left = (int)(S.size() - 1);
        int right = (int)(T.size() - 1);
        
        while (left >= 0 && right >= 0)
        {
            left = findPreviousCharIndex(S, left);
            right = findPreviousCharIndex(T, right);
            if (S[left] != T[right])
            {
                return false;
            }
            
            left--;
            right--;
        }
        
        if (left == -1) {
            right = findPreviousCharIndex(T, right);
        }
        
        if (right == -1) {
            left = findPreviousCharIndex(T, left);
        }
        
        return left == right;
    }
};