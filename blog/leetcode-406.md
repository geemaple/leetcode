---
layout: post
index: 406
title: "LeetCode-406.根据身高重建队列(Minimum Number of Arrows to Burst Balloons)"
categories: Leetcode
tags: Leetcode Greedy
excerpt: ""
---

* content
{:toc}

## 406. 根据身高重建队列

假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

示例 1：

```
输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
```

示例 2：

```
输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
``` 

提示：

```
1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
题目数据确保队列可以被重建
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/queue-reconstruction-by-height](https://leetcode-cn.com/problems/queue-reconstruction-by-height)

Link：[https://leetcode.com/problems/queue-reconstruction-by-height/](https://leetcode.com/problems/queue-reconstruction-by-height/)


## 贪心

O(N^2)

如果先排序个子高的，那么当个子矮的放入队伍中，不会对已有的下标K造成影响

所以按照身高降序排列，如果身高相同，按照k值生序排列

```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        
        people.sort(key=lambda x : (-x[0], x[1]))
        res = []
        
        for i in range(len(people)):
            index = people[i][1]
            res.insert(index, people[i])
                
        return res
```

反逻辑, 按照身高从小到大排序，如果身高相同，K值需要降序, 这样数空格预留前面的位置才有效

K值代表它的前面有多少个是空位

```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        
        people.sort(key=lambda x : (x[0], -x[1]))
        res = [[] for i in range(len(people))]
        
        for i in range(len(people)):
            count = 0
            for j in range(len(res)):
                if len(res[j]) == 0:
                    if count == people[i][1]:
                        res[j] = people[i]
                        break    
                        
                    count += 1
                
        return res
```

--End--


