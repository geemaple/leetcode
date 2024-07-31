---
layout: post
index: 93
title: "LeetCode-93.复原IP地址(Restore IP Addresses)"
categories: Leetcode
tags: Leetcode String Backtracking
excerpt: "肖生克的救赎"
---

* content
{:toc}

## 93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。


示例 1：

```
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

示例 2：

```
输入：s = "0000"
输出：["0.0.0.0"]
```

示例 3：

```
输入：s = "1111"
输出：["1.1.1.1"]
```

示例 4：

```
输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
```

示例 5：

```
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```
 
提示：

```
0 <= s.length <= 3000
s 仅由数字组成
```

来源：力扣（LeetCode）

链接：[https://leetcode-cn.com/problems/restore-ip-addresses](https://leetcode-cn.com/problems/restore-ip-addresses)

Link：[https://leetcode.com/problems/restore-ip-addresses/](https://leetcode.com/problems/restore-ip-addresses/)

## 回溯法

给一个字符串, 把它转换成**一个有效ip地址**。其中ip地址有四部分组成(不能有前置0)。输出所有返回结果

显然，字符串小于4位，根本无法转换成4个部分，直接排除

显然，如果字符串大于12位，分成4部分，会有一部分大于255，直接排除

剩下的4～12位，使用DFS枚举所有可能，把符合的放入到结果

### 实现代码

```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4 or len(s) > 12:
            return []
        
        res = []
        self.helper(s, [], res)
        return res
        
    def helper(self, s: str, ans: List[str], res: List[str]):
        
        if len(ans) == 4 and len(s) == 0:
            address = '.'.join(ans)
            res.append(address)
            return
            
        if len(ans) == 4 or len(s) == 0:
            return

        if len(s) > 0 and s[0] == '0':
            self.helper(s[1:], ans + [s[:1]], res)
            return
            
        if len(s) > 0:
            self.helper(s[1:], ans + [s[:1]], res)
        
        if len(s) > 1:
            self.helper(s[2:], ans + [s[:2]], res)
            
        if len(s) > 2 and int(s[:3]) <= 255:
            self.helper(s[3:], ans + [s[:3]], res)
```

换成for循环写法

```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4 or len(s) > 12:
            return []
        
        res = []
        self.helper(s, [], res)
        return res
        
    def helper(self, s: str, ans: List[str], res: List[str]):
        
        if len(ans) == 4 and len(s) == 0:
            address = '.'.join(ans)
            res.append(address)
            return
            
        length = min(3, len(s))   
        for i in range(length):
            sub = s[: i + 1]
            if len(sub) > 1 and (sub.startswith('0') or int(sub) > 255):
                continue
                
            self.helper(s[i + 1:], ans + [sub], res)
```

--End--
