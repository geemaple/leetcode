---
layout: post
index: 3
title: "LeetCode-3.无重复字符的最长子串(Longest Substring Without Repeating Characters)"
categories: Leetcode
tags: Leetcode HashTable TwoPointers String SlidingWindow
excerpt: "滑动窗口"
---

* content
{:toc}

## 3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

示例 2:
```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
示例 3:
```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

Link：[https://leetcode.com/problems/longest-substring-without-repeating-characters](https://leetcode.com/problems/longest-substring-without-repeating-characters)

## 双指针

O(N)

题目要求答案不能有重复字符，**右指针**遍历，用哈希来判断是否有重复，如果有，添加之前，依次删除***左指针**的值直到满足条件

遍历过程中，使用**打擂台**的比较方法，更新最大长度

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        visited = set()
        res = 0
        
        for i in range(len(s)):
            while (s[i] in visited):
                visited.remove(s[left])
                left +=1
                
            visited.add(s[i])
            
            if i - left + 1 > res:
                res = i - left + 1
                
        return res
```

遇到重复的，直接访问hash拿到之前值的下标 + 1， 注意left不能倒退```Case="abba"```，所以要选择其中最大的

```python
class Solution2 {
private:
    static const int ASCII_COUNT = 256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        vector<int> visited(ASCII_COUNT, - 1);

        for(int i = 0; i < s.size(); ++i){

            if (visited[s[i]] >= 0){
                left  = max(visited[s[i]] + 1, left);
            }

            visited[s[i]] = i;
            res = max(res, i - left + 1);
        }

        return res;
    }
};
```

如果是C++，可以使用数组，因为ASCII只有256，所以可以开一个长度256的数组作为Hash

> 数组作为特殊的哈希(index -> val), 其访问速度要快很多

```cpp
class Solution {
private:
    static const int ASCII_COUNT = 256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        vector<int> visited(ASCII_COUNT, - 1);

        for(int i = 0; i < s.size(); ++i){

            if (visited[s[i]] >= 0){
                left  = max(visited[s[i]] + 1, left);
            }

            visited[s[i]] = i;
            res = max(res, i - left + 1);
        }

        return res;
    }
};
```

--End--