# 算法/Algorithm
我个人的力扣答案, **公众号:GeekPal**<br/>
这是一个持续更新的开源项目<br/>
<br/>
My personal leetcode answers<br/>
This is a **continually updated** open source project<br/>
<br/>
Total sovled: **354**<br/>
Auto updated at: **2024-07-26 17:15:42**<br/>

## 软件/Softwares
- [Anki](https://apps.ankiweb.net/)
- [Tldraw](https://www.tldraw.com/)
- [OBS](https://www.tldraw.com/)
- [Leetcode中英网站切换](https://greasyfork.org/en/scripts/478450-leetcode-cn-en-site-switcher)

## 脚本/Script
```shell
pip install -r requirements.txt
python problem.py <leetcode/lintcode> [-l java|cpp|python(default)] [-t]
# 例如(e.g.):
python problem.py https://leetcode.com/problems/online-stock-span/
python problem.py https://www.lintcode.com/problem/92 -l cpp
```

## 链接/Links
- [本人博客](https://blog.mogoal.com/category/#Algorithm)
- [极客时间](https://github.com/geektime-geekbang/algorithm-1)
- [LeetCode 101](https://github.com/changgyhub/leetcode_101)

## 书籍/Books
- 《算法技术手册》/ Algorithms in a Nutshell
- 《STL源码剖析》/ The Annotated STL Sources
- 《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition
- 《数学之美》(A chinese version book by Doctor Wujun)
- 《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)

## [Category](category)
- [Math](#math)
- [Bit Manipulation](#bit-manipulation)
- [Simulation](#simulation)
- [Design](#design)
- [Binary Search](#binary-search)
- [Linked List](#linked-list)
- [Two Pointers](#two-pointers)
- [Sliding Window](#sliding-window)
- [Stack](#stack)
- [Sorting](#sorting)
- [Counting](#counting)
- [Greedy](#greedy)
- [Dynamic Programming](#dynamic-programming)
- [Backtracking](#backtracking)
- [Divide and Conquer](#divide-and-conquer)
- [Breadth-First Search](#breadth-first-search)
- [Topological Sort](#topological-sort)
- [Depth-First Search](#depth-first-search)
- [Priority Queue](#priority-queue)
- [Union Find](#union-find)
- [Trie](#trie)
- [Segment Tree](#segment-tree)

## Math
| Problem(14) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-69. Sqrtx](https://leetcode.com/problems/sqrtx/description/) | [c++](./leetcode/69.sqrtx.cpp), [python](./leetcode/69.sqrtx.py) | N\(logN\) | O\(1\) | \- | - |
| [Leetcode-70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/) | [c++](./leetcode/70.climbing-stairs.cpp), [python](./leetcode/70.climbing-stairs.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-172. Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/description/) | [c++](./leetcode/172.factorial-trailing-zeroes.cpp), [python](./leetcode/172.factorial-trailing-zeroes.py) | O\(log5\(n\)\) | O\(1\) | \- | - |
| [Leetcode-204. Count Primes](https://leetcode.com/problems/count-primes/description/) | [c++](./leetcode/204.count-primes.cpp), [python](./leetcode/204.count-primes.py) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-241. Different Ways To Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/) | [c++](./leetcode/241.different-ways-to-add-parentheses.cpp), [python](./leetcode/241.different-ways-to-add-parentheses.py) | \- | \- | \- | - |
| [Leetcode-263. Ugly Number](https://leetcode.com/problems/ugly-number/description/) | [c++](./leetcode/263.ugly-number.cpp), [python](./leetcode/263.ugly-number.py) | O\(k\) | O\(1\) | \- | - |
| [Leetcode-279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/) | [c++](./leetcode/279.perfect-squares.cpp), [python](./leetcode/279.perfect-squares.py) | O\(n^\{3/2\}\) | O\(N\) | \- | - |
| [Leetcode-343. Integer Break](https://leetcode.com/problems/integer-break/description/) | [c++](./leetcode/343.integer-break.cpp), [python](./leetcode/343.integer-break.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-375. Guess Number Higher Or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/) | [c++](./leetcode/375.guess-number-higher-or-lower-ii.cpp), [python](./leetcode/375.guess-number-higher-or-lower-ii.py) | O\(N^3\) | O\(N^2\) | DP\(Index\) | - |
| [Leetcode-415. Add Strings](https://leetcode.com/problems/add-strings/description/) | [c++](./leetcode/415.add-strings.cpp), [python](./leetcode/415.add-strings.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-504. Base 7](https://leetcode.com/problems/base-7/description/) | [python](./leetcode/504.base-7.py), [c++](./leetcode/504.base-7.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [python](./leetcode/633.sum-of-square-numbers.py), [c++](./leetcode/633.sum-of-square-numbers.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/) | [c++](./leetcode/650.2-keys-keyboard.cpp), [python](./leetcode/650.2-keys-keyboard.py) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-932. Beautiful Array](https://leetcode.com/problems/beautiful-array/description/) | [python](./leetcode/932.beautiful-array.py), [c++](./leetcode/932.beautiful-array.cpp) | O\(N\) | O\(N\) | dp | - |

## Simulation
| Problem(2) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-415. Add Strings](https://leetcode.com/problems/add-strings/description/) | [c++](./leetcode/415.add-strings.cpp), [python](./leetcode/415.add-strings.py) | O\(N\) | O\(1\) | \- | - |
| [Lintcode-39. Recover Rotated Sorted Array](https://www.lintcode.com/problem/recover-rotated-sorted-array) | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python](./lintcode/39.recover-rotated-sorted-array.py) | O\(N\) | O\(1\) | Rotated | - |

## Design
| Problem(2) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [python](./leetcode/173.binary-search-tree-iterator.py), [c++](./leetcode/173.binary-search-tree-iterator.cpp) | O\(1\) | O\(Height\) | InOrder | - |
| [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python](./leetcode/297.serialize-and-deserialize-binary-tree.py) | O\(N\) | O\(N\) | Serialization | - |

## Binary Search
| Problem(33) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-4. Median Of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/) | [python](./leetcode/4.median-of-two-sorted-arrays.py), [c++](./leetcode/4.median-of-two-sorted-arrays.cpp) | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| [Leetcode-33. Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/) | [python](./leetcode/33.search-in-rotated-sorted-array.py), [c++](./leetcode/33.search-in-rotated-sorted-array.cpp) | O\(logN\) | O\(1\) | Rotated; | - |
| [Leetcode-34. Find First And Last Position Of Element In Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/) | [c++](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp), [python](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.py) | O\(logN\) | O\(1\) | std::lower\_bound; | [Video](https://youtu.be/y6OT8heV-30) |
| [Leetcode-35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/) | [python](./leetcode/35.search-insert-position.py), [c++](./leetcode/35.search-insert-position.cpp) | O\(logN\) | O\(1\) | std::lower\_bound | - |
| [Leetcode-69. Sqrtx](https://leetcode.com/problems/sqrtx/description/) | [c++](./leetcode/69.sqrtx.cpp), [python](./leetcode/69.sqrtx.py) | N\(logN\) | O\(1\) | \- | - |
| [Leetcode-74. Search A 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/) | [python](./leetcode/74.search-a-2d-matrix.py), [c++](./leetcode/74.search-a-2d-matrix.cpp) | O\(log\(m \* n\)\) | O\(1\) | Matrix; | - |
| [Leetcode-81. Search In Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/) | [python](./leetcode/81.search-in-rotated-sorted-array-ii.py), [c++](./leetcode/81.search-in-rotated-sorted-array-ii.cpp) | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| [Leetcode-98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) | [python](./leetcode/98.validate-binary-search-tree.py), [c++](./leetcode/98.validate-binary-search-tree.cpp) | O\(N\) | O\(Height\) | BST | - |
| [Leetcode-153. Find Minimum In Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/) | [c++](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | O\(logN\) | O\(1\) | Rotated; | [Video](https://youtu.be/GsecRZC5to4) |
| [Leetcode-154. Find Minimum In Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/) | [python](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py), [c++](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp) | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| [Leetcode-162. Find Peak Element](https://leetcode.com/problems/find-peak-element/description/) | [python](./leetcode/162.find-peak-element.py), [c++](./leetcode/162.find-peak-element.cpp) | O\(logN\) | O\(1\) | Mountain; | [Video](https://youtu.be/bexO0N9eP1I) |
| [Leetcode-167. Two Sum Ii Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [python](./leetcode/173.binary-search-tree-iterator.py), [c++](./leetcode/173.binary-search-tree-iterator.cpp) | O\(1\) | O\(Height\) | InOrder | - |
| [Leetcode-240. Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/) | [python](./leetcode/240.search-a-2d-matrix-ii.py), [c++](./leetcode/240.search-a-2d-matrix-ii.cpp) | O\(m \* logN\) | O\(1\) | Matrix | - |
| [Leetcode-278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/) | [python](./leetcode/278.first-bad-version.py), [c++](./leetcode/278.first-bad-version.cpp) | O\(logN\) | O\(1\) | Range; | [Video](https://youtu.be/xNzBpfqzYSg) |
| [Leetcode-300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [python](./leetcode/300.longest-increasing-subsequence.py), [c++](./leetcode/300.longest-increasing-subsequence.cpp) | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| [Leetcode-374. Guess Number Higher Or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/description/) | [python](./leetcode/374.guess-number-higher-or-lower.py), [c++](./leetcode/374.guess-number-higher-or-lower.cpp) | O\(logN\) | O\(1\) | Standard | - |
| [Leetcode-450. Delete Node In A Bst](https://leetcode.com/problems/delete-node-in-a-bst/description/) | [c++](./leetcode/450.delete-node-in-a-bst.cpp), [python](./leetcode/450.delete-node-in-a-bst.py) | O\(Height\) | O\(Height\) | Delete | - |
| [Leetcode-540. Single Element In A Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/) | [python](./leetcode/540.single-element-in-a-sorted-array.py), [c++](./leetcode/540.single-element-in-a-sorted-array.cpp) | O\(logN\) | O\(1\) | \- | - |
| [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [python](./leetcode/633.sum-of-square-numbers.py), [c++](./leetcode/633.sum-of-square-numbers.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [python](./leetcode/658.find-k-closest-elements.py), [c++](./leetcode/658.find-k-closest-elements.cpp) | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [Leetcode-701. Insert Into A Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/) | [python](./leetcode/701.insert-into-a-binary-search-tree.py), [c++](./leetcode/701.insert-into-a-binary-search-tree.cpp) | O\(Height\) | O\(Height\) | Insert | - |
| [Leetcode-704. Binary Search](https://leetcode.com/problems/binary-search/description/) | [c++](./leetcode/704.binary-search.cpp), [python](./leetcode/704.binary-search.py) | O\(logN\) | O\(1\) | Standard; | [Video](https://youtu.be/oxWpJtUGG_0) |
| [Leetcode-852. Peak Index In A Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/) | [python](./leetcode/852.peak-index-in-a-mountain-array.py), [c++](./leetcode/852.peak-index-in-a-mountain-array.cpp) | O\(logN\) | O\(1\) | Mountain | - |
| [Leetcode-1901. Find A Peak Element II](https://leetcode.com/problems/find-a-peak-element-ii/description/) | [python](./leetcode/1901.find-a-peak-element-ii.py), [c++](./leetcode/1901.find-a-peak-element-ii.cpp) | O\(N \* logM\) | O\(1\) | Mountain; | - |
| [Leetcode-2468. Split Message Based On Limit](https://leetcode.com/problems/split-message-based-on-limit/description/) | [python](./leetcode/2468.split-message-based-on-limit.py), [c++](./leetcode/2468.split-message-based-on-limit.cpp) | O\(logN \+ K\) | O\(1\) | Answer \| Bruteforce | - |
| [Leetcode-2529. Maximum Count Of Positive Integer And Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/) | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | O\(logN\) | O\(1\) | std::lower\_bound | - |
| [Leetcode-3048. Earliest Second To Mark Indices I](https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/) | [python](./leetcode/3048.earliest-second-to-mark-indices-i.py), [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp) | O\(M\*logM\) | O\(M\) | \- | - |
| [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python](./lintcode/11.search-range-in-binary-search-tree.py) | O\(N\) | O\(Height\) | InOrder | - |
| [Lintcode-437. Copy Books](https://www.lintcode.com/problem/copy-books) | [c++](./lintcode/437.copy-books.cpp), [python](./lintcode/437.copy-books.py) | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| [Lintcode-448. Inorder Successor In Bst](https://www.lintcode.com/problem/inorder-successor-in-bst) | [python](./lintcode/448.inorder-successor-in-bst.py), [c++](./lintcode/448.inorder-successor-in-bst.cpp) | O\(Height\) | O\(1\) | Successor \| Leetcode\-285 | - |
| [Lintcode-600. Smallest Rectangle Enclosing Black Pixels](https://www.lintcode.com/problem/smallest-rectangle-enclosing-black-pixels) | [python](./lintcode/600.smallest-rectangle-enclosing-black-pixels.py), [c++](./lintcode/600.smallest-rectangle-enclosing-black-pixels.cpp) | O\(N \* logM \+ M \* logN\) | O\(1\) | Graph \| Leetcode\-302 | - |
| [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | O\(N\) | O\(Height\) | BST \| Leetcode\-426 | - |

## Linked List
| Problem(4) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [python](./leetcode/114.flatten-binary-tree-to-linked-list.py), [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp) | O\(N\) | O\(Height\) | PreOrder | - |
| [Leetcode-141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) | [c++](./leetcode/141.linked-list-cycle.cpp), [python](./leetcode/141.linked-list-cycle.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/) | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python](./leetcode/142.linked-list-cycle-ii.py) | O\(N\) | O\(1\) | \- | - |
| [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | O\(N\) | O\(Height\) | BST \| Leetcode\-426 | - |

## Two Pointers
| Problem(12) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-75. Sort Colors](https://leetcode.com/problems/sort-colors/description/) | [python](./leetcode/75.sort-colors.py), [c++](./leetcode/75.sort-colors.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/) | [python](./leetcode/88.merge-sorted-array.py), [c++](./leetcode/88.merge-sorted-array.cpp) | O\(M \+ N\) | O\(1\) | \- | - |
| [Leetcode-141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) | [c++](./leetcode/141.linked-list-cycle.cpp), [python](./leetcode/141.linked-list-cycle.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/) | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python](./leetcode/142.linked-list-cycle-ii.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-167. Two Sum Ii Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python](./leetcode/455.assign-cookies.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-524. Longest Word In Dictionary Through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/) | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [python](./leetcode/633.sum-of-square-numbers.py), [c++](./leetcode/633.sum-of-square-numbers.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [python](./leetcode/658.find-k-closest-elements.py), [c++](./leetcode/658.find-k-closest-elements.cpp) | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [Leetcode-680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/) | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python](./leetcode/680.valid-palindrome-ii.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-763. Partition Labels](https://leetcode.com/problems/partition-labels/description/) | [c++](./leetcode/763.partition-labels.cpp), [python](./leetcode/763.partition-labels.py) | O\(N\) | O\(N\) | \- | - |
| [Lintcode-386. Longest Substring With At Most K Distinct Characters](https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters) | [c++](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.cpp), [python](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.py) | O\(N\) | O\(K\) | Leetcode\-340 | - |

## Sliding Window
| Problem(2) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/) | [python](./leetcode/76.minimum-window-substring.py), [c++](./leetcode/76.minimum-window-substring.cpp) | O\(M\) | O\(N\) | Hash \+ TP | - |
| [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [python](./leetcode/658.find-k-closest-elements.py), [c++](./leetcode/658.find-k-closest-elements.cpp) | O\(Log\(N \- K\)\) | O\(1\) | Range | - |

## Stack
| Problem(6) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python](./leetcode/94.binary-tree-inorder-traversal.py) | O\(N\) | O\(Height\) | InOrder | - |
| [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [python](./leetcode/114.flatten-binary-tree-to-linked-list.py), [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp) | O\(N\) | O\(Height\) | PreOrder | - |
| [Leetcode-144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python](./leetcode/144.binary-tree-preorder-traversal.py) | O\(N\) | O\(Height\) | PreOrder | - |
| [Leetcode-145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python](./leetcode/145.binary-tree-postorder-traversal.py) | O\(N\) | O\(Height\) | PostOrder | - |
| [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [python](./leetcode/173.binary-search-tree-iterator.py), [c++](./leetcode/173.binary-search-tree-iterator.cpp) | O\(1\) | O\(Height\) | InOrder | - |
| [Leetcode-1249. Minimum Remove To Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/) | [c++](./leetcode/1249.minimum-remove-to-make-valid-parentheses.cpp), [python](./leetcode/1249.minimum-remove-to-make-valid-parentheses.py) | O\(N\) | O\(N\) | \- | - |

## Sorting
| Problem(13) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-75. Sort Colors](https://leetcode.com/problems/sort-colors/description/) | [python](./leetcode/75.sort-colors.py), [c++](./leetcode/75.sort-colors.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/) | [python](./leetcode/88.merge-sorted-array.py), [c++](./leetcode/88.merge-sorted-array.cpp) | O\(M \+ N\) | O\(1\) | \- | - |
| [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [python](./leetcode/215.kth-largest-element-in-an-array.py), [c++](./leetcode/215.kth-largest-element-in-an-array.cpp) | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [python](./leetcode/347.top-k-frequent-elements.py), [c++](./leetcode/347.top-k-frequent-elements.cpp) | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [Leetcode-406. Queue Reconstruction By Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/) | [python](./leetcode/406.queue-reconstruction-by-height.py), [c++](./leetcode/406.queue-reconstruction-by-height.cpp) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python](./leetcode/435.non-overlapping-intervals.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python](./leetcode/451.sort-characters-by-frequency.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-452. Minimum Number Of Arrows To Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/) | [python](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py), [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp) | O\(N\*logN\) | O\(1\) | \- | - |
| [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python](./leetcode/455.assign-cookies.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-524. Longest Word In Dictionary Through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/) | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [python](./leetcode/646.maximum-length-of-pair-chain.py), [c++](./leetcode/646.maximum-length-of-pair-chain.cpp) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [python](./leetcode/658.find-k-closest-elements.py), [c++](./leetcode/658.find-k-closest-elements.cpp) | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [Lintcode-39. Recover Rotated Sorted Array](https://www.lintcode.com/problem/recover-rotated-sorted-array) | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python](./lintcode/39.recover-rotated-sorted-array.py) | O\(N\) | O\(1\) | Rotated | - |

## Counting
| Problem(3) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [python](./leetcode/347.top-k-frequent-elements.py), [c++](./leetcode/347.top-k-frequent-elements.cpp) | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python](./leetcode/451.sort-characters-by-frequency.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-2529. Maximum Count Of Positive Integer And Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/) | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | O\(logN\) | O\(1\) | std::lower\_bound | - |

## Greedy
| Problem(12) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-122. Best Time To Buy And Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/) | [python](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py), [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-135. Candy](https://leetcode.com/problems/candy/description/) | [python](./leetcode/135.candy.py), [c++](./leetcode/135.candy.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/description/) | [c++](./leetcode/376.wiggle-subsequence.cpp), [python](./leetcode/376.wiggle-subsequence.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python](./leetcode/435.non-overlapping-intervals.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-452. Minimum Number Of Arrows To Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/) | [python](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py), [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp) | O\(N\*logN\) | O\(1\) | \- | - |
| [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python](./leetcode/455.assign-cookies.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/description/) | [c++](./leetcode/605.can-place-flowers.cpp), [python](./leetcode/605.can-place-flowers.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [python](./leetcode/646.maximum-length-of-pair-chain.py), [c++](./leetcode/646.maximum-length-of-pair-chain.cpp) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/) | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python](./leetcode/680.valid-palindrome-ii.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-714. Best Time To Buy And Sell Stock With Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | [python](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py), [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-763. Partition Labels](https://leetcode.com/problems/partition-labels/description/) | [c++](./leetcode/763.partition-labels.cpp), [python](./leetcode/763.partition-labels.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-3048. Earliest Second To Mark Indices I](https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/) | [python](./leetcode/3048.earliest-second-to-mark-indices-i.py), [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp) | O\(M\*logM\) | O\(M\) | \- | - |

## Dynamic Programming
| Problem(39) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/description/) | [python](./leetcode/10.regular-expression-matching.py), [c++](./leetcode/10.regular-expression-matching.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) | [python](./leetcode/53.maximum-subarray.py), [c++](./leetcode/53.maximum-subarray.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/) | [c++](./leetcode/64.minimum-path-sum.cpp), [python](./leetcode/64.minimum-path-sum.py) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/) | [c++](./leetcode/70.climbing-stairs.cpp), [python](./leetcode/70.climbing-stairs.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-72. Edit Distance](https://leetcode.com/problems/edit-distance/description/) | [c++](./leetcode/72.edit-distance.cpp), [python](./leetcode/72.edit-distance.py) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-91. Decode Ways](https://leetcode.com/problems/decode-ways/description/) | [python](./leetcode/91.decode-ways.py), [c++](./leetcode/91.decode-ways.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-120. Triangle](https://leetcode.com/problems/triangle/description/) | [python](./leetcode/120.triangle.py), [c++](./leetcode/120.triangle.cpp) | O\(N^2\) | O\(N\) | \- | - |
| [Leetcode-121. Best Time To Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) | [c++](./leetcode/121.best-time-to-buy-and-sell-stock.cpp), [python](./leetcode/121.best-time-to-buy-and-sell-stock.py) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-122. Best Time To Buy And Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/) | [python](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py), [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-139. Word Break](https://leetcode.com/problems/word-break/description/) | [c++](./leetcode/139.word-break.cpp), [python](./leetcode/139.word-break.py) | O\(MN\) | O\(N\) | \- | - |
| [Leetcode-188. Best Time To Buy And Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/) | [python](./leetcode/188.best-time-to-buy-and-sell-stock-iv.py), [c++](./leetcode/188.best-time-to-buy-and-sell-stock-iv.cpp) | O\(NK\) | O\(NK\) | \- | - |
| [Leetcode-198. House Robber](https://leetcode.com/problems/house-robber/description/) | [c++](./leetcode/198.house-robber.cpp), [python](./leetcode/198.house-robber.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-213. House Robber II](https://leetcode.com/problems/house-robber-ii/description/) | [c++](./leetcode/213.house-robber-ii.cpp), [python](./leetcode/213.house-robber-ii.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-221. Maximal Square](https://leetcode.com/problems/maximal-square/description/) | [python](./leetcode/221.maximal-square.py), [c++](./leetcode/221.maximal-square.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-241. Different Ways To Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/) | [c++](./leetcode/241.different-ways-to-add-parentheses.cpp), [python](./leetcode/241.different-ways-to-add-parentheses.py) | \- | \- | \- | - |
| [Leetcode-279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/) | [c++](./leetcode/279.perfect-squares.cpp), [python](./leetcode/279.perfect-squares.py) | O\(n^\{3/2\}\) | O\(N\) | \- | - |
| [Leetcode-300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [python](./leetcode/300.longest-increasing-subsequence.py), [c++](./leetcode/300.longest-increasing-subsequence.cpp) | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| [Leetcode-309. Best Time To Buy And Sell Stock With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/) | [c++](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp), [python](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-312. Burst Balloons](https://leetcode.com/problems/burst-balloons/description/) | [c++](./leetcode/312.burst-balloons.cpp), [python](./leetcode/312.burst-balloons.py) | O\(N^3\) | O\(N^2\) | \- | - |
| [Leetcode-322. Coin Change](https://leetcode.com/problems/coin-change/description/) | [c++](./leetcode/322.coin-change.cpp), [python](./leetcode/322.coin-change.py) | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| [Leetcode-343. Integer Break](https://leetcode.com/problems/integer-break/description/) | [c++](./leetcode/343.integer-break.cpp), [python](./leetcode/343.integer-break.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-375. Guess Number Higher Or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/) | [c++](./leetcode/375.guess-number-higher-or-lower-ii.cpp), [python](./leetcode/375.guess-number-higher-or-lower-ii.py) | O\(N^3\) | O\(N^2\) | DP\(Index\) | - |
| [Leetcode-376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/description/) | [c++](./leetcode/376.wiggle-subsequence.cpp), [python](./leetcode/376.wiggle-subsequence.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/description/) | [c++](./leetcode/413.arithmetic-slices.cpp), [python](./leetcode/413.arithmetic-slices.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/) | [python](./leetcode/416.partition-equal-subset-sum.py), [c++](./leetcode/416.partition-equal-subset-sum.cpp) | O\(N^2\) | O\(N\) | \- | - |
| [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python](./leetcode/435.non-overlapping-intervals.py) | O\(N \* logN\) | O\(1\) | \- | - |
| [Leetcode-474. Ones And Zeroes](https://leetcode.com/problems/ones-and-zeroes/description/) | [c++](./leetcode/474.ones-and-zeroes.cpp), [python](./leetcode/474.ones-and-zeroes.py) | O\(KMN\) | O\(MN\) | \- | - |
| [Leetcode-494. Target Sum](https://leetcode.com/problems/target-sum/description/) | [c++](./leetcode/494.target-sum.cpp), [python](./leetcode/494.target-sum.py) | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |
| [Leetcode-542. 01 Matrix](https://leetcode.com/problems/01-matrix/description/) | [python](./leetcode/542.01-matrix.py), [c++](./leetcode/542.01-matrix.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-583. Delete Operation For Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/description/) | [python](./leetcode/583.delete-operation-for-two-strings.py), [c++](./leetcode/583.delete-operation-for-two-strings.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [python](./leetcode/646.maximum-length-of-pair-chain.py), [c++](./leetcode/646.maximum-length-of-pair-chain.cpp) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/) | [c++](./leetcode/650.2-keys-keyboard.cpp), [python](./leetcode/650.2-keys-keyboard.py) | O\(NlogN\) | O\(N\) | \- | - |
| [Leetcode-714. Best Time To Buy And Sell Stock With Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | [python](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py), [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/) | [python](./leetcode/1143.longest-common-subsequence.py), [c++](./leetcode/1143.longest-common-subsequence.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Lintcode-92. Backpack](https://www.lintcode.com/problem/backpack) | [python](./lintcode/92.backpack.py), [c++](./lintcode/92.backpack.cpp) | O\(N^2\) | O\(N^2\) | \- | - |
| [Lintcode-125. Backpack II](https://www.lintcode.com/problem/backpack-ii) | [python](./lintcode/125.backpack-ii.py), [c++](./lintcode/125.backpack-ii.cpp) | O\(N^2\) | O\(N^2\) | \- | - |
| [Lintcode-437. Copy Books](https://www.lintcode.com/problem/copy-books) | [c++](./lintcode/437.copy-books.cpp), [python](./lintcode/437.copy-books.py) | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| [Lintcode-440. Backpack III](https://www.lintcode.com/problem/backpack-iii) | [c++](./lintcode/440.backpack-iii.cpp), [python](./lintcode/440.backpack-iii.py) | O\(N^2\) | O\(N^2\) | \- | - |
| [Lintcode-562. Backpack IV](https://www.lintcode.com/problem/backpack-iv) | [c++](./lintcode/562.backpack-iv.cpp), [python](./lintcode/562.backpack-iv.py) | O\(N^2\) | O\(N^2\) | \- | - |

## Backtracking
| Problem(10) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/description/) | [python](./leetcode/37.sudoku-solver.py), [c++](./leetcode/37.sudoku-solver.cpp) | O\(N^\(N^2\)\) | O\(N\) | \- | - |
| [Leetcode-40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/) | [c++](./leetcode/40.combination-sum-ii.cpp), [python](./leetcode/40.combination-sum-ii.py) | O\(2^N\) | O\(N\) | \- | - |
| [Leetcode-46. Permutations](https://leetcode.com/problems/permutations/description/) | [python](./leetcode/46.permutations.py), [c++](./leetcode/46.permutations.cpp) | O\(N\!\) | O\(N\) | \- | - |
| [Leetcode-47. Permutations II](https://leetcode.com/problems/permutations-ii/description/) | [python](./leetcode/47.permutations-ii.py), [c++](./leetcode/47.permutations-ii.cpp) | O\(N\!\) | O\(N\) | \- | - |
| [Leetcode-51. N Queens](https://leetcode.com/problems/n-queens/description/) | [c++](./leetcode/51.n-queens.cpp), [python](./leetcode/51.n-queens.py) | O\(N\!\) | O\(N\) | \- | - |
| [Leetcode-77. Combinations](https://leetcode.com/problems/combinations/description/) | [python](./leetcode/77.combinations.py), [c++](./leetcode/77.combinations.cpp) |  O\(k \* C\(n, k\)\)  | O\(K\) | \- | - |
| [Leetcode-79. Word Search](https://leetcode.com/problems/word-search/description/) | [python](./leetcode/79.word-search.py), [c++](./leetcode/79.word-search.cpp) | O\(MN\*4^L\) | O\(MN\) | \- | - |
| [Leetcode-126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/) | [c++](./leetcode/126.word-ladder-ii.cpp), [python](./leetcode/126.word-ladder-ii.py) | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| [Leetcode-257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/) | [c++](./leetcode/257.binary-tree-paths.cpp), [python](./leetcode/257.binary-tree-paths.py) | O\(N\) | O\(Height\) | \- | - |
| [Leetcode-494. Target Sum](https://leetcode.com/problems/target-sum/description/) | [c++](./leetcode/494.target-sum.cpp), [python](./leetcode/494.target-sum.py) | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |

## Divide and Conquer
| Problem(8) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-4. Median Of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/) | [python](./leetcode/4.median-of-two-sorted-arrays.py), [c++](./leetcode/4.median-of-two-sorted-arrays.cpp) | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| [Leetcode-53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) | [python](./leetcode/53.maximum-subarray.py), [c++](./leetcode/53.maximum-subarray.cpp) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [python](./leetcode/215.kth-largest-element-in-an-array.py), [c++](./leetcode/215.kth-largest-element-in-an-array.cpp) | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [Leetcode-240. Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/) | [python](./leetcode/240.search-a-2d-matrix-ii.py), [c++](./leetcode/240.search-a-2d-matrix-ii.cpp) | O\(m \* logN\) | O\(1\) | Matrix | - |
| [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [python](./leetcode/347.top-k-frequent-elements.py), [c++](./leetcode/347.top-k-frequent-elements.cpp) | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [Leetcode-932. Beautiful Array](https://leetcode.com/problems/beautiful-array/description/) | [python](./leetcode/932.beautiful-array.py), [c++](./leetcode/932.beautiful-array.cpp) | O\(N\) | O\(N\) | dp | - |
| [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python](./lintcode/11.search-range-in-binary-search-tree.py) | O\(N\) | O\(Height\) | InOrder | - |
| [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | O\(N\) | O\(Height\) | BST \| Leetcode\-426 | - |

## Breadth-First Search
| Problem(13) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/) | [python](./leetcode/102.binary-tree-level-order-traversal.py), [c++](./leetcode/102.binary-tree-level-order-traversal.cpp) | O\(N\) | O\(Width\) | Level | - |
| [Leetcode-104. Maximum Depth Of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | [python](./leetcode/104.maximum-depth-of-binary-tree.py), [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp) | O\(N\) | O\(Height\) | Recursion | - |
| [Leetcode-126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/) | [c++](./leetcode/126.word-ladder-ii.cpp), [python](./leetcode/126.word-ladder-ii.py) | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [python](./leetcode/130.surrounded-regions.py), [c++](./leetcode/130.surrounded-regions.cpp) | O\(MN\) | O\(1\) | \- | - |
| [Leetcode-279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/) | [c++](./leetcode/279.perfect-squares.cpp), [python](./leetcode/279.perfect-squares.py) | O\(n^\{3/2\}\) | O\(N\) | \- | - |
| [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python](./leetcode/297.serialize-and-deserialize-binary-tree.py) | O\(N\) | O\(N\) | Serialization | - |
| [Leetcode-310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/description/) | [c++](./leetcode/310.minimum-height-trees.cpp), [python](./leetcode/310.minimum-height-trees.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-322. Coin Change](https://leetcode.com/problems/coin-change/description/) | [c++](./leetcode/322.coin-change.cpp), [python](./leetcode/322.coin-change.py) | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| [Leetcode-417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/) | [python](./leetcode/417.pacific-atlantic-water-flow.py), [c++](./leetcode/417.pacific-atlantic-water-flow.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-542. 01 Matrix](https://leetcode.com/problems/01-matrix/description/) | [python](./leetcode/542.01-matrix.py), [c++](./leetcode/542.01-matrix.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python](./leetcode/547.number-of-provinces.py) | O\(N^2\) | O\(N\) | \- | - |
| [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python](./leetcode/695.max-area-of-island.py) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/description/) | [c++](./leetcode/934.shortest-bridge.cpp), [python](./leetcode/934.shortest-bridge.py) | O\(N^2\) | O\(N^2\) | \- | - |

## Topological Sort
| Problem(1) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/description/) | [c++](./leetcode/310.minimum-height-trees.cpp), [python](./leetcode/310.minimum-height-trees.py) | O\(N\) | O\(N\) | \- | - |

## Depth-First Search
| Problem(17) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python](./leetcode/94.binary-tree-inorder-traversal.py) | O\(N\) | O\(Height\) | InOrder | - |
| [Leetcode-98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) | [python](./leetcode/98.validate-binary-search-tree.py), [c++](./leetcode/98.validate-binary-search-tree.cpp) | O\(N\) | O\(Height\) | BST | - |
| [Leetcode-104. Maximum Depth Of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | [python](./leetcode/104.maximum-depth-of-binary-tree.py), [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp) | O\(N\) | O\(Height\) | Recursion | - |
| [Leetcode-110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/) | [c++](./leetcode/110.balanced-binary-tree.cpp), [python](./leetcode/110.balanced-binary-tree.py) | O\(N\) | O\(Height\) | Recursion | - |
| [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [python](./leetcode/114.flatten-binary-tree-to-linked-list.py), [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp) | O\(N\) | O\(Height\) | PreOrder | - |
| [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [python](./leetcode/130.surrounded-regions.py), [c++](./leetcode/130.surrounded-regions.cpp) | O\(MN\) | O\(1\) | \- | - |
| [Leetcode-144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python](./leetcode/144.binary-tree-preorder-traversal.py) | O\(N\) | O\(Height\) | PreOrder | - |
| [Leetcode-145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python](./leetcode/145.binary-tree-postorder-traversal.py) | O\(N\) | O\(Height\) | PostOrder | - |
| [Leetcode-236. Lowest Common Ancestor Of A Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/) | [python](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py), [c++](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp) | O\(N\) | O\(Height\) | Recursion | - |
| [Leetcode-257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/) | [c++](./leetcode/257.binary-tree-paths.cpp), [python](./leetcode/257.binary-tree-paths.py) | O\(N\) | O\(Height\) | \- | - |
| [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python](./leetcode/297.serialize-and-deserialize-binary-tree.py) | O\(N\) | O\(N\) | Serialization | - |
| [Leetcode-310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/description/) | [c++](./leetcode/310.minimum-height-trees.cpp), [python](./leetcode/310.minimum-height-trees.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/) | [python](./leetcode/417.pacific-atlantic-water-flow.py), [c++](./leetcode/417.pacific-atlantic-water-flow.cpp) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python](./leetcode/547.number-of-provinces.py) | O\(N^2\) | O\(N\) | \- | - |
| [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python](./leetcode/695.max-area-of-island.py) | O\(MN\) | O\(MN\) | \- | - |
| [Leetcode-934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/description/) | [c++](./leetcode/934.shortest-bridge.cpp), [python](./leetcode/934.shortest-bridge.py) | O\(N^2\) | O\(N^2\) | \- | - |
| [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python](./lintcode/11.search-range-in-binary-search-tree.py) | O\(N\) | O\(Height\) | InOrder | - |

## Priority Queue
| Problem(4) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [python](./leetcode/215.kth-largest-element-in-an-array.py), [c++](./leetcode/215.kth-largest-element-in-an-array.cpp) | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [python](./leetcode/347.top-k-frequent-elements.py), [c++](./leetcode/347.top-k-frequent-elements.cpp) | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python](./leetcode/451.sort-characters-by-frequency.py) | O\(N\) | O\(N\) | \- | - |
| [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [python](./leetcode/658.find-k-closest-elements.py), [c++](./leetcode/658.find-k-closest-elements.cpp) | O\(Log\(N \- K\)\) | O\(1\) | Range | - |

## Union Find
| Problem(3) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [python](./leetcode/130.surrounded-regions.py), [c++](./leetcode/130.surrounded-regions.cpp) | O\(MN\) | O\(1\) | \- | - |
| [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python](./leetcode/547.number-of-provinces.py) | O\(N^2\) | O\(N\) | \- | - |
| [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python](./leetcode/695.max-area-of-island.py) | O\(MN\) | O\(MN\) | \- | - |

## Trie
| Problem(1) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-139. Word Break](https://leetcode.com/problems/word-break/description/) | [c++](./leetcode/139.word-break.cpp), [python](./leetcode/139.word-break.py) | O\(MN\) | O\(N\) | \- | - |

## Segment Tree
| Problem(1) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-406. Queue Reconstruction By Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/) | [python](./leetcode/406.queue-reconstruction-by-height.py), [c++](./leetcode/406.queue-reconstruction-by-height.cpp) | O\(N \* logN\) | O\(1\) | \- | - |

## Array
| Problem(2) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-665. Non Decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/) | [python](./leetcode/665.non-decreasing-array.py), [c++](./leetcode/665.non-decreasing-array.cpp) | O\(N\) | O\(1\) | \- | - |
| [Leetcode-2210. Count Hills And Valleys In An Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/) | [c++](./leetcode/2210.count-hills-and-valleys-in-an-array.cpp), [python](./leetcode/2210.count-hills-and-valleys-in-an-array.py) | O\(N\) | O\(1\) | \- | - |

## String
| Problem(1) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Lintcode-1790. Rotate String II](https://www.lintcode.com/problem/rotate-string-ii) | [c++](./lintcode/1790.rotate-string-ii.cpp), [python](./lintcode/1790.rotate-string-ii.py) | O\(N\) | O\(N\) | Simulation | - |

## Other
| Problem(233) | Solution | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- |
| [Leetcode-1. Two Sum](https://leetcode.com/problems/two-sum/description/) | [python](./leetcode/1.two-sum.py), [c++](./leetcode/1.two-sum.cpp) | \- | \- | \- | - |
| [Leetcode-2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/) | [python](./leetcode/2.add-two-numbers.py), [c++](./leetcode/2.add-two-numbers.cpp) | \- | \- | \- | - |
| [Leetcode-3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/) | [c++](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python](./leetcode/3.longest-substring-without-repeating-characters.py) | \- | \- | \- | - |
| [Leetcode-5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/) | [python](./leetcode/5.longest-palindromic-substring.py) | \- | \- | \- | - |
| [Leetcode-6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/) | [python](./leetcode/6.zigzag-conversion.py) | \- | \- | \- | - |
| [Leetcode-7. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/) | [c++](./leetcode/7.reverse-integer.cpp), [python](./leetcode/7.reverse-integer.py) | \- | \- | \- | - |
| [Leetcode-8. String To Integer Atoi](https://leetcode.com/problems/string-to-integer-atoi/description/) | [c++](./leetcode/8.string-to-integer-atoi.cpp), [python](./leetcode/8.string-to-integer-atoi.py) | \- | \- | \- | - |
| [Leetcode-9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/) | [c++](./leetcode/9.palindrome-number.cpp), [python](./leetcode/9.palindrome-number.py) | \- | \- | \- | - |
| [Leetcode-11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/) | [python](./leetcode/11.container-with-most-water.py) | \- | \- | \- | - |
| [Leetcode-12. Integer To Roman](https://leetcode.com/problems/integer-to-roman/description/) | [c++](./leetcode/12.integer-to-roman.cpp), [python](./leetcode/12.integer-to-roman.py) | \- | \- | \- | - |
| [Leetcode-13. Roman To Integer](https://leetcode.com/problems/roman-to-integer/description/) | [python](./leetcode/13.roman-to-integer.py), [c++](./leetcode/13.roman-to-integer.cpp) | \- | \- | \- | - |
| [Leetcode-14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/) | [python](./leetcode/14.longest-common-prefix.py), [c++](./leetcode/14.longest-common-prefix.cpp) | \- | \- | \- | - |
| [Leetcode-15. 3Sum](https://leetcode.com/problems/3sum/description/) | [c++](./leetcode/15.3sum.cpp), [python](./leetcode/15.3sum.py) | \- | \- | \- | - |
| [Leetcode-16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/) | [c++](./leetcode/16.3sum-closest.cpp), [python](./leetcode/16.3sum-closest.py) | \- | \- | \- | - |
| [Leetcode-17. Letter Combinations Of A Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/) | [c++](./leetcode/17.letter-combinations-of-a-phone-number.cpp), [python](./leetcode/17.letter-combinations-of-a-phone-number.py) | \- | \- | \- | - |
| [Leetcode-18. 4Sum](https://leetcode.com/problems/4sum/description/) | [python](./leetcode/18.4sum.py), [c++](./leetcode/18.4sum.cpp) | \- | \- | \- | - |
| [Leetcode-19. Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/) | [c++](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python](./leetcode/19.remove-nth-node-from-end-of-list.py) | \- | \- | \- | - |
| [Leetcode-20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/) | [python](./leetcode/20.valid-parentheses.py), [c++](./leetcode/20.valid-parentheses.cpp) | \- | \- | \- | - |
| [Leetcode-21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/) | [c++](./leetcode/21.merge-two-sorted-lists.cpp), [python](./leetcode/21.merge-two-sorted-lists.py) | \- | \- | \- | - |
| [Leetcode-22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/) | [python](./leetcode/22.generate-parentheses.py) | \- | \- | \- | - |
| [Leetcode-23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python](./leetcode/23.merge-k-sorted-lists.py) | \- | \- | \- | - |
| [Leetcode-24. Swap Nodes In Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/description/) | [python](./leetcode/24.swap-nodes-in-pairs.py), [c++](./leetcode/24.swap-nodes-in-pairs.cpp) | \- | \- | \- | - |
| [Leetcode-25. Reverse Nodes In K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) | [python](./leetcode/25.reverse-nodes-in-k-group.py), [c++](./leetcode/25.reverse-nodes-in-k-group.cpp) | \- | \- | \- | - |
| [Leetcode-26. Remove Duplicates From Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | [python](./leetcode/26.remove-duplicates-from-sorted-array.py), [c++](./leetcode/26.remove-duplicates-from-sorted-array.cpp) | \- | \- | \- | - |
| [Leetcode-27. Remove Element](https://leetcode.com/problems/remove-element/description/) | [python](./leetcode/27.remove-element.py), [c++](./leetcode/27.remove-element.cpp) | \- | \- | \- | - |
| [Leetcode-28. Implement Strstr](https://leetcode.com/problems/implement-strstr/description/) | [c++](./leetcode/28.implement-strstr.cpp), [python](./leetcode/28.implement-strstr.py) | \- | \- | \- | - |
| [Leetcode-29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/) | [python](./leetcode/29.divide-two-integers.py), [c++](./leetcode/29.divide-two-integers.cpp) | \- | \- | \- | - |
| [Leetcode-30. Substring With Concatenation Of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/) | [c++](./leetcode/30.substring-with-concatenation-of-all-words.cpp), [python](./leetcode/30.substring-with-concatenation-of-all-words.py) | \- | \- | \- | - |
| [Leetcode-31. Next Permutation](https://leetcode.com/problems/next-permutation/description/) | [c++](./leetcode/31.next-permutation.cpp), [python](./leetcode/31.next-permutation.py) | \- | \- | \- | - |
| [Leetcode-36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/) | [python](./leetcode/36.valid-sudoku.py), [c++](./leetcode/36.valid-sudoku.cpp) | \- | \- | \- | - |
| [Leetcode-38. Count And Say](https://leetcode.com/problems/count-and-say/description/) | [python](./leetcode/38.count-and-say.py) | \- | \- | Each term of the sequence of integers will be represented as a | - |
| [Leetcode-39. Combination Sum](https://leetcode.com/problems/combination-sum/description/) | [c++](./leetcode/39.combination-sum.cpp), [python](./leetcode/39.combination-sum.py) | \- | \- | \- | - |
| [Leetcode-41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/) | [python](./leetcode/41.first-missing-positive.py) | \- | \- | \- | - |
| [Leetcode-42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/) | [python](./leetcode/42.trapping-rain-water.py), [c++](./leetcode/42.trapping-rain-water.cpp) | \- | \- | \- | - |
| [Leetcode-43. Multiply Strings](https://leetcode.com/problems/multiply-strings/description/) | [python](./leetcode/43.multiply-strings.py), [c++](./leetcode/43.multiply-strings.cpp) | \- | \- | \- | - |
| [Leetcode-44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/) | [python](./leetcode/44.wildcard-matching.py), [c++](./leetcode/44.wildcard-matching.cpp) | \- | \- | \- | - |
| [Leetcode-45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/) | [c++](./leetcode/45.jump-game-ii.cpp), [python](./leetcode/45.jump-game-ii.py) | \- | \- | \- | - |
| [Leetcode-48. Rotate Image](https://leetcode.com/problems/rotate-image/description/) | [python](./leetcode/48.rotate-image.py), [c++](./leetcode/48.rotate-image.cpp) | \- | \- | \- | - |
| [Leetcode-49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/) | [c++](./leetcode/49.group-anagrams.cpp) | \- | \- | \- | - |
| [Leetcode-50. Powx N](https://leetcode.com/problems/powx-n/description/) | [c++](./leetcode/50.powx-n.cpp), [python](./leetcode/50.powx-n.py) | \- | \- | \- | - |
| [Leetcode-52. N Queens II](https://leetcode.com/problems/n-queens-ii/description/) | [python](./leetcode/52.n-queens-ii.py), [c++](./leetcode/52.n-queens-ii.cpp) | \- | \- | \- | - |
| [Leetcode-54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/) | [c++](./leetcode/54.spiral-matrix.cpp), [python](./leetcode/54.spiral-matrix.py) | \- | \- | \- | - |
| [Leetcode-55. Jump Game](https://leetcode.com/problems/jump-game/description/) | [python](./leetcode/55.jump-game.py), [c++](./leetcode/55.jump-game.cpp) | \- | \- | \- | - |
| [Leetcode-56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | [python](./leetcode/56.merge-intervals.py), [c++](./leetcode/56.merge-intervals.cpp) | \- | \- | \- | - |
| [Leetcode-57. Insert Interval](https://leetcode.com/problems/insert-interval/description/) | [c++](./leetcode/57.insert-interval.cpp), [python](./leetcode/57.insert-interval.py) | \- | \- | \- | - |
| [Leetcode-61. Rotate List](https://leetcode.com/problems/rotate-list/description/) | [python](./leetcode/61.rotate-list.py) | \- | \- | \- | - |
| [Leetcode-62. Unique Paths](https://leetcode.com/problems/unique-paths/description/) | [python](./leetcode/62.unique-paths.py), [c++](./leetcode/62.unique-paths.cpp) | \- | \- | \- | - |
| [Leetcode-63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/description/) | [python](./leetcode/63.unique-paths-ii.py), [c++](./leetcode/63.unique-paths-ii.cpp) | \- | \- | \- | - |
| [Leetcode-66. Plus One](https://leetcode.com/problems/plus-one/description/) | [python](./leetcode/66.plus-one.py), [c++](./leetcode/66.plus-one.cpp) | \- | \- | \- | - |
| [Leetcode-67. Add Binary](https://leetcode.com/problems/add-binary/description/) | [c++](./leetcode/67.add-binary.cpp), [python](./leetcode/67.add-binary.py) | \- | \- | \- | - |
| [Leetcode-68. Text Justification](https://leetcode.com/problems/text-justification/description/) | [python](./leetcode/68.text-justification.py) | \- | \- | \- | - |
| [Leetcode-78. Subsets](https://leetcode.com/problems/subsets/description/) | [c++](./leetcode/78.subsets.cpp), [python](./leetcode/78.subsets.py) | \- | \- | \- | - |
| [Leetcode-84. Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/) | [c++](./leetcode/84.largest-rectangle-in-histogram.cpp), [python](./leetcode/84.largest-rectangle-in-histogram.py) | \- | \- | \- | - |
| [Leetcode-85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/description/) | [python](./leetcode/85.maximal-rectangle.py), [c++](./leetcode/85.maximal-rectangle.cpp) | \- | \- | \- | - |
| [Leetcode-86. Partition List](https://leetcode.com/problems/partition-list/description/) | [c++](./leetcode/86.partition-list.cpp), [python](./leetcode/86.partition-list.py) | \- | \- | \- | - |
| [Leetcode-87. Scramble String](https://leetcode.com/problems/scramble-string/description/) | [python](./leetcode/87.scramble-string.py), [c++](./leetcode/87.scramble-string.cpp) | \- | \- | \- | - |
| [Leetcode-90. Subsets II](https://leetcode.com/problems/subsets-ii/description/) | [c++](./leetcode/90.subsets-ii.cpp), [python](./leetcode/90.subsets-ii.py) | \- | \- | \- | - |
| [Leetcode-92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/) | [python](./leetcode/92.reverse-linked-list-ii.py), [c++](./leetcode/92.reverse-linked-list-ii.cpp) | \- | \- | \- | - |
| [Leetcode-97. Interleaving String](https://leetcode.com/problems/interleaving-string/description/) | [python](./leetcode/97.interleaving-string.py), [c++](./leetcode/97.interleaving-string.cpp) | \- | \- | \- | - |
| [Leetcode-103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) | [c++](./leetcode/103.binary-tree-zigzag-level-order-traversal.cpp), [python](./leetcode/103.binary-tree-zigzag-level-order-traversal.py) | \- | \- | \- | - |
| [Leetcode-107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/) | [c++](./leetcode/107.binary-tree-level-order-traversal-ii.cpp), [python](./leetcode/107.binary-tree-level-order-traversal-ii.py) | \- | \- | \- | - |
| [Leetcode-115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/) | [python](./leetcode/115.distinct-subsequences.py), [c++](./leetcode/115.distinct-subsequences.cpp) | \- | \- | \- | - |
| [Leetcode-118. Pascals Triangle](https://leetcode.com/problems/pascals-triangle/description/) | [python](./leetcode/118.pascals-triangle.py), [c++](./leetcode/118.pascals-triangle.cpp) | \- | \- | \- | - |
| [Leetcode-119. Pascals Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/) | [python](./leetcode/119.pascals-triangle-ii.py), [c++](./leetcode/119.pascals-triangle-ii.cpp) | \- | \- | \- | - |
| [Leetcode-123. Best Time To Buy And Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/) | [c++](./leetcode/123.best-time-to-buy-and-sell-stock-iii.cpp), [python](./leetcode/123.best-time-to-buy-and-sell-stock-iii.py) | \- | \- | \- | - |
| [Leetcode-125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/) | [python](./leetcode/125.valid-palindrome.py), [c++](./leetcode/125.valid-palindrome.cpp) | \- | \- | \- | - |
| [Leetcode-127. Word Ladder](https://leetcode.com/problems/word-ladder/description/) | [c++](./leetcode/127.word-ladder.cpp), [python](./leetcode/127.word-ladder.py) | \- | \- | \- | - |
| [Leetcode-128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/) | [python](./leetcode/128.longest-consecutive-sequence.py), [c++](./leetcode/128.longest-consecutive-sequence.cpp) | \- | \- | \- | - |
| [Leetcode-131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/) | [python](./leetcode/131.palindrome-partitioning.py), [c++](./leetcode/131.palindrome-partitioning.cpp) | \- | \- | \- | - |
| [Leetcode-132. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/description/) | [c++](./leetcode/132.palindrome-partitioning-ii.cpp), [python](./leetcode/132.palindrome-partitioning-ii.py) | \- | \- | \- | - |
| [Leetcode-133. Clone Graph](https://leetcode.com/problems/clone-graph/description/) | [c++](./leetcode/133.clone-graph.cpp), [python](./leetcode/133.clone-graph.py) | \- | \- | \- | - |
| [Leetcode-136. Single Number](https://leetcode.com/problems/single-number/description/) | [c++](./leetcode/136.single-number.cpp), [python](./leetcode/136.single-number.py) | \- | \- | \- | - |
| [Leetcode-138. Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/description/) | [python](./leetcode/138.copy-list-with-random-pointer.py) | \- | \- | \- | - |
| [Leetcode-143. Reorder List](https://leetcode.com/problems/reorder-list/description/) | [python](./leetcode/143.reorder-list.py) | \- | \- | \- | - |
| [Leetcode-148. Sort List](https://leetcode.com/problems/sort-list/description/) | [python](./leetcode/148.sort-list.py) | \- | \- | \- | - |
| [Leetcode-155. Min Stack](https://leetcode.com/problems/min-stack/description/) | [python](./leetcode/155.min-stack.py), [c++](./leetcode/155.min-stack.cpp) | \- | \- | \- | - |
| [Leetcode-156. Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/description/) | [python](./leetcode/156.binary-tree-upside-down.py), [c++](./leetcode/156.binary-tree-upside-down.cpp) | \- | \- | \- | - |
| [Leetcode-157. Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/description/) | [python](./leetcode/157.read-n-characters-given-read4.py), [c++](./leetcode/157.read-n-characters-given-read4.cpp) | \- | \- | \- | - |
| [Leetcode-159. Longest Substring With At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/) | [c++](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.cpp), [python](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.py) | \- | \- | \- | - |
| [Leetcode-160. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python](./leetcode/160.intersection-of-two-linked-lists.py) | \- | \- | \- | - |
| [Leetcode-161. One Edit Distance](https://leetcode.com/problems/one-edit-distance/description/) | [c++](./leetcode/161.one-edit-distance.cpp), [python](./leetcode/161.one-edit-distance.py) | \- | \- | \- | - |
| [Leetcode-163. Missing Ranges](https://leetcode.com/problems/missing-ranges/description/) | [python](./leetcode/163.missing-ranges.py), [c++](./leetcode/163.missing-ranges.cpp) | \- | \- | \- | - |
| [Leetcode-169. Majority Element](https://leetcode.com/problems/majority-element/description/) | [python](./leetcode/169.majority-element.py), [c++](./leetcode/169.majority-element.cpp) | \- | \- | \- | - |
| [Leetcode-170. Two Sum Iii Data Structure Design](https://leetcode.com/problems/two-sum-iii-data-structure-design/description/) | [python](./leetcode/170.two-sum-iii-data-structure-design.py), [c++](./leetcode/170.two-sum-iii-data-structure-design.cpp) | \- | \- | \- | - |
| [Leetcode-175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/) | [sql](./leetcode/175.combine-two-tables.sql) | \- | \- | \- | - |
| [Leetcode-200. Number Of Islands](https://leetcode.com/problems/number-of-islands/description/) | [c++](./leetcode/200.number-of-islands.cpp), [python](./leetcode/200.number-of-islands.py) | \- | \- | \- | - |
| [Leetcode-202. Happy Number](https://leetcode.com/problems/happy-number/description/) | [python](./leetcode/202.happy-number.py), [c++](./leetcode/202.happy-number.cpp) | \- | \- | \- | - |
| [Leetcode-203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/) | [python](./leetcode/203.remove-linked-list-elements.py) | \- | \- | \- | - |
| [Leetcode-205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/) | [c++](./leetcode/205.isomorphic-strings.cpp), [python](./leetcode/205.isomorphic-strings.py) | \- | \- | \- | - |
| [Leetcode-206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/) | [python](./leetcode/206.reverse-linked-list.py), [c++](./leetcode/206.reverse-linked-list.cpp) | \- | \- | \- | - |
| [Leetcode-207. Course Schedule](https://leetcode.com/problems/course-schedule/description/) | [c++](./leetcode/207.course-schedule.cpp), [python](./leetcode/207.course-schedule.py) | \- | \- | \- | - |
| [Leetcode-208. Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/description/) | [python](./leetcode/208.implement-trie-prefix-tree.py), [c++](./leetcode/208.implement-trie-prefix-tree.cpp) | \- | \- | \- | - |
| [Leetcode-209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/) | [c++](./leetcode/209.minimum-size-subarray-sum.cpp), [python](./leetcode/209.minimum-size-subarray-sum.py) | \- | \- | \- | - |
| [Leetcode-210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/description/) | [c++](./leetcode/210.course-schedule-ii.cpp), [python](./leetcode/210.course-schedule-ii.py) | \- | \- | \- | - |
| [Leetcode-211. Add And Search Word Data Structure Design](https://leetcode.com/problems/add-and-search-word-data-structure-design/description/) | [c++](./leetcode/211.add-and-search-word-data-structure-design.cpp), [python](./leetcode/211.add-and-search-word-data-structure-design.py) | \- | \- | \- | - |
| [Leetcode-212. Word Search II](https://leetcode.com/problems/word-search-ii/description/) | [c++](./leetcode/212.word-search-ii.cpp), [python](./leetcode/212.word-search-ii.py) | \- | \- | \- | - |
| [Leetcode-217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/) | [c++](./leetcode/217.contains-duplicate.cpp) | \- | \- | \- | - |
| [Leetcode-219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/) | [c++](./leetcode/219.contains-duplicate-ii.cpp) | \- | \- | \- | - |
| [Leetcode-228. Summary Ranges](https://leetcode.com/problems/summary-ranges/description/) | [python](./leetcode/228.summary-ranges.py) | \- | \- | \- | - |
| [Leetcode-229. Majority Element II](https://leetcode.com/problems/majority-element-ii/description/) | [c++](./leetcode/229.majority-element-ii.cpp), [python](./leetcode/229.majority-element-ii.py) | \- | \- | The algorithm should run in linear time and in O\(1\) space\. | - |
| [Leetcode-231. Power Of Two](https://leetcode.com/problems/power-of-two/description/) | [python](./leetcode/231.power-of-two.py) | \- | \- | \- | - |
| [Leetcode-234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/) | [c++](./leetcode/234.palindrome-linked-list.cpp), [python](./leetcode/234.palindrome-linked-list.py) | \- | \- | \- | - |
| [Leetcode-237. Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/description/) | [python](./leetcode/237.delete-node-in-a-linked-list.py) | \- | \- | \- | - |
| [Leetcode-239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/) | [python](./leetcode/239.sliding-window-maximum.py), [c++](./leetcode/239.sliding-window-maximum.cpp) | \- | \- | \- | - |
| [Leetcode-242. Valid Anagram](https://leetcode.com/problems/valid-anagram/description/) | [c++](./leetcode/242.valid-anagram.cpp), [python](./leetcode/242.valid-anagram.py) | \- | \- | \- | - |
| [Leetcode-246. Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/description/) | [c++](./leetcode/246.strobogrammatic-number.cpp), [python](./leetcode/246.strobogrammatic-number.py) | \- | \- | \- | - |
| [Leetcode-249. Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/description/) | [c++](./leetcode/249.group-shifted-strings.cpp) | \- | \- | \- | - |
| [Leetcode-251. Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/description/) | [python](./leetcode/251.flatten-2d-vector.py) | \- | \- | \- | - |
| [Leetcode-253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/description/) | [python](./leetcode/253.meeting-rooms-ii.py), [c++](./leetcode/253.meeting-rooms-ii.cpp) | \- | \- | \- | - |
| [Leetcode-256. Paint House](https://leetcode.com/problems/paint-house/description/) | [c++](./leetcode/256.paint-house.cpp), [python](./leetcode/256.paint-house.py) | \- | \- | \- | - |
| [Leetcode-261. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/description/) | [python](./leetcode/261.graph-valid-tree.py), [c++](./leetcode/261.graph-valid-tree.cpp) | \- | \- | \- | - |
| [Leetcode-265. Paint House II](https://leetcode.com/problems/paint-house-ii/description/) | [python](./leetcode/265.paint-house-ii.py), [c++](./leetcode/265.paint-house-ii.cpp) | \- | \- | \- | - |
| [Leetcode-269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/description/) | [python](./leetcode/269.alien-dictionary.py) | \- | \- | \- | - |
| [Leetcode-270. Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/description/) | [python](./leetcode/270.closest-binary-search-tree-value.py), [c++](./leetcode/270.closest-binary-search-tree-value.cpp) | \- | \- | \- | - |
| [Leetcode-271. Encode And Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/description/) | [python](./leetcode/271.encode-and-decode-strings.py), [c++](./leetcode/271.encode-and-decode-strings.cpp) | \- | \- | \- | - |
| [Leetcode-273. Integer To English Words](https://leetcode.com/problems/integer-to-english-words/description/) | [python](./leetcode/273.integer-to-english-words.py) | \- | \- | \- | - |
| [Leetcode-276. Paint Fence](https://leetcode.com/problems/paint-fence/description/) | [python](./leetcode/276.paint-fence.py), [c++](./leetcode/276.paint-fence.cpp) | \- | \- | \- | - |
| [Leetcode-277. Find The Celebrity](https://leetcode.com/problems/find-the-celebrity/description/) | [python](./leetcode/277.find-the-celebrity.py), [c++](./leetcode/277.find-the-celebrity.cpp) | \- | \- | \- | - |
| [Leetcode-280. Wiggle Sort](https://leetcode.com/problems/wiggle-sort/description/) | [python](./leetcode/280.wiggle-sort.py) | \- | \- | \- | - |
| [Leetcode-282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/description/) | [python](./leetcode/282.expression-add-operators.py), [c++](./leetcode/282.expression-add-operators.cpp) | \- | \- | \- | - |
| [Leetcode-283. Move Zeroes](https://leetcode.com/problems/move-zeroes/description/) | [python](./leetcode/283.move-zeroes.py), [c++](./leetcode/283.move-zeroes.cpp) | \- | \- | \- | - |
| [Leetcode-286. Walls And Gates](https://leetcode.com/problems/walls-and-gates/description/) | [python](./leetcode/286.walls-and-gates.py), [c++](./leetcode/286.walls-and-gates.cpp) | \- | \- | \- | - |
| [Leetcode-288. Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/description/) | [python](./leetcode/288.unique-word-abbreviation.py), [c++](./leetcode/288.unique-word-abbreviation.cpp) | \- | \- | \- | - |
| [Leetcode-289. Game Of Life](https://leetcode.com/problems/game-of-life/description/) | [python](./leetcode/289.game-of-life.py) | \- | \- | \- | - |
| [Leetcode-295. Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/) | [c++](./leetcode/295.find-median-from-data-stream.cpp), [python](./leetcode/295.find-median-from-data-stream.py) | \- | \- | \- | - |
| [Leetcode-305. Number Of Islands II](https://leetcode.com/problems/number-of-islands-ii/description/) | [python](./leetcode/305.number-of-islands-ii.py), [c++](./leetcode/305.number-of-islands-ii.cpp) | \- | \- | \- | - |
| [Leetcode-311. Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/description/) | [python](./leetcode/311.sparse-matrix-multiplication.py), [c++](./leetcode/311.sparse-matrix-multiplication.cpp) | \- | \- | \- | - |
| [Leetcode-314. Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/) | [c++](./leetcode/314.binary-tree-vertical-order-traversal.cpp), [python](./leetcode/314.binary-tree-vertical-order-traversal.py) | \- | \- | \- | - |
| [Leetcode-318. Maximum Product Of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/description/) | [c++](./leetcode/318.maximum-product-of-word-lengths.cpp), [python](./leetcode/318.maximum-product-of-word-lengths.py) | \- | \- | \- | - |
| [Leetcode-323. Number Of Connected Components In An Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/) | [python](./leetcode/323.number-of-connected-components-in-an-undirected-graph.py), [c++](./leetcode/323.number-of-connected-components-in-an-undirected-graph.cpp) | \- | \- | \- | - |
| [Leetcode-324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/description/) | [python](./leetcode/324.wiggle-sort-ii.py) | \- | \- | \- | - |
| [Leetcode-326. Power Of Three](https://leetcode.com/problems/power-of-three/description/) | [python](./leetcode/326.power-of-three.py) | \- | \- | \- | - |
| [Leetcode-328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/description/) | [python](./leetcode/328.odd-even-linked-list.py) | \- | \- | \- | - |
| [Leetcode-336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/description/) | [python](./leetcode/336.palindrome-pairs.py) | \- | \- | \- | - |
| [Leetcode-338. Counting Bits](https://leetcode.com/problems/counting-bits/description/) | [python](./leetcode/338.counting-bits.py), [c++](./leetcode/338.counting-bits.cpp) | \- | \- | \- | - |
| [Leetcode-341. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/description/) | [python](./leetcode/341.flatten-nested-list-iterator.py) | \- | \- | \- | - |
| [Leetcode-342. Power Of Four](https://leetcode.com/problems/power-of-four/description/) | [python](./leetcode/342.power-of-four.py) | \- | \- | \- | - |
| [Leetcode-344. Reverse String](https://leetcode.com/problems/reverse-string/description/) | [c++](./leetcode/344.reverse-string.cpp), [python](./leetcode/344.reverse-string.py) | \- | \- | \- | - |
| [Leetcode-345. Reverse Vowels Of A String](https://leetcode.com/problems/reverse-vowels-of-a-string/description/) | [c++](./leetcode/345.reverse-vowels-of-a-string.cpp), [python](./leetcode/345.reverse-vowels-of-a-string.py) | \- | \- | \- | - |
| [Leetcode-346. Moving Average From Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/description/) | [c++](./leetcode/346.moving-average-from-data-stream.cpp), [python](./leetcode/346.moving-average-from-data-stream.py) | \- | \- | \- | - |
| [Leetcode-349. Intersection Of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/) | [c++](./leetcode/349.intersection-of-two-arrays.cpp), [python](./leetcode/349.intersection-of-two-arrays.py) | \- | \- | \- | - |
| [Leetcode-350. Intersection Of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/description/) | [c++](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python](./leetcode/350.intersection-of-two-arrays-ii.py) | \- | \- | \- | - |
| [Leetcode-354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/description/) | [python](./leetcode/354.russian-doll-envelopes.py), [c++](./leetcode/354.russian-doll-envelopes.cpp) | \- | \- | \- | - |
| [Leetcode-359. Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/description/) | [c++](./leetcode/359.logger-rate-limiter.cpp) | \- | \- | \- | - |
| [Leetcode-361. Bomb Enemy](https://leetcode.com/problems/bomb-enemy/description/) | [c++](./leetcode/361.bomb-enemy.cpp), [python](./leetcode/361.bomb-enemy.py) | \- | \- | \- | - |
| [Leetcode-366. Find Leaves Of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/description/) | [python](./leetcode/366.find-leaves-of-binary-tree.py), [c++](./leetcode/366.find-leaves-of-binary-tree.cpp) | \- | \- | \- | - |
| [Leetcode-367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/description/) | [c++](./leetcode/367.valid-perfect-square.cpp), [python](./leetcode/367.valid-perfect-square.py) | \- | \- | \- | - |
| [Leetcode-368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/description/) | [c++](./leetcode/368.largest-divisible-subset.cpp), [python](./leetcode/368.largest-divisible-subset.py) | \- | \- | \- | - |
| [Leetcode-370. Range Addition](https://leetcode.com/problems/range-addition/description/) | [c++](./leetcode/370.range-addition.cpp), [python](./leetcode/370.range-addition.py) | \- | \- | \- | - |
| [Leetcode-377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/description/) | [python](./leetcode/377.combination-sum-iv.py), [c++](./leetcode/377.combination-sum-iv.cpp) | \- | \- | \- | - |
| [Leetcode-378. Kth Smallest Element In A Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/) | [python](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.py), [c++](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.cpp) | \- | \- | \- | - |
| [Leetcode-380. Insert Delete Getrandom O1](https://leetcode.com/problems/insert-delete-getrandom-o1/description/) | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp) | \- | \- | \- | - |
| [Leetcode-387. First Unique Character In A String](https://leetcode.com/problems/first-unique-character-in-a-string/description/) | [c++](./leetcode/387.first-unique-character-in-a-string.cpp), [python](./leetcode/387.first-unique-character-in-a-string.py) | \- | \- | \- | - |
| [Leetcode-388. Longest Absolute File Path](https://leetcode.com/problems/longest-absolute-file-path/description/) | [python](./leetcode/388.longest-absolute-file-path.py), [c++](./leetcode/388.longest-absolute-file-path.cpp) | \- | \- | \- | - |
| [Leetcode-393. Utf 8 Validation](https://leetcode.com/problems/utf-8-validation/description/) | [c++](./leetcode/393.utf-8-validation.cpp), [python](./leetcode/393.utf-8-validation.py) | \- | \- | \- | - |
| [Leetcode-394. Decode String](https://leetcode.com/problems/decode-string/description/) | [python](./leetcode/394.decode-string.py), [c++](./leetcode/394.decode-string.cpp) | \- | \- | \- | - |
| [Leetcode-403. Frog Jump](https://leetcode.com/problems/frog-jump/description/) | [c++](./leetcode/403.frog-jump.cpp) | \- | \- | \- | - |
| [Leetcode-407. Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/description/) | [python](./leetcode/407.trapping-rain-water-ii.py), [c++](./leetcode/407.trapping-rain-water-ii.cpp) | \- | \- | \- | - |
| [Leetcode-408. Valid Word Abbreviation](https://leetcode.com/problems/valid-word-abbreviation/description/) | [python](./leetcode/408.valid-word-abbreviation.py), [c++](./leetcode/408.valid-word-abbreviation.cpp) | \- | \- | \- | - |
| [Leetcode-425. Word Squares](https://leetcode.com/problems/word-squares/description/) | [python](./leetcode/425.word-squares.py), [c++](./leetcode/425.word-squares.cpp) | \- | \- | \- | - |
| [Leetcode-433. Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/description/) | [python](./leetcode/433.minimum-genetic-mutation.py), [c++](./leetcode/433.minimum-genetic-mutation.cpp) | \- | \- | \- | - |
| [Leetcode-438. Find All Anagrams In A String](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/) | [c++](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python](./leetcode/438.find-all-anagrams-in-a-string.py) | \- | \- | \- | - |
| [Leetcode-444. Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/description/) | [c++](./leetcode/444.sequence-reconstruction.cpp), [python](./leetcode/444.sequence-reconstruction.py) | \- | \- | \- | - |
| [Leetcode-447. Number Of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/description/) | [c++](./leetcode/447.number-of-boomerangs.cpp), [python](./leetcode/447.number-of-boomerangs.py) | \- | \- | \- | - |
| [Leetcode-448. Find All Numbers Disappeared In An Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/) | [python](./leetcode/448.find-all-numbers-disappeared-in-an-array.py) | \- | \- | \- | - |
| [Leetcode-454. 4Sum II](https://leetcode.com/problems/4sum-ii/description/) | [c++](./leetcode/454.4sum-ii.cpp) | \- | \- | \- | - |
| [Leetcode-463. Island Perimeter](https://leetcode.com/problems/island-perimeter/description/) | [python](./leetcode/463.island-perimeter.py) | \- | \- | \- | - |
| [Leetcode-485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/) | [c++](./leetcode/485.max-consecutive-ones.cpp) | \- | \- | \- | - |
| [Leetcode-498. Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description/) | [c++](./leetcode/498.diagonal-traverse.cpp) | \- | \- | \- | - |
| [Leetcode-516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/) | [c++](./leetcode/516.longest-palindromic-subsequence.cpp), [python](./leetcode/516.longest-palindromic-subsequence.py) | \- | \- | \- | - |
| [Leetcode-527. Word Abbreviation](https://leetcode.com/problems/word-abbreviation/description/) | [c++](./leetcode/527.word-abbreviation.cpp), [python](./leetcode/527.word-abbreviation.py) | \- | \- | \- | - |
| [Leetcode-532. K Diff Pairs In An Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/) | [python](./leetcode/532.k-diff-pairs-in-an-array.py), [c++](./leetcode/532.k-diff-pairs-in-an-array.cpp) | \- | \- | \- | - |
| [Leetcode-535. Encode And Decode Tinyurl](https://leetcode.com/problems/encode-and-decode-tinyurl/description/) | [python](./leetcode/535.encode-and-decode-tinyurl.py) | \- | \- | \- | - |
| [Leetcode-538. Convert Bst To Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/description/) | [c++](./leetcode/538.convert-bst-to-greater-tree.cpp), [python](./leetcode/538.convert-bst-to-greater-tree.py) | \- | \- | \- | - |
| [Leetcode-560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/) | [c++](./leetcode/560.subarray-sum-equals-k.cpp), [python](./leetcode/560.subarray-sum-equals-k.py) | \- | \- | \- | - |
| [Leetcode-561. Array Partition I](https://leetcode.com/problems/array-partition-i/description/) | [c++](./leetcode/561.array-partition-i.cpp) | \- | \- | \- | - |
| [Leetcode-599. Minimum Index Sum Of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/) | [c++](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | \- | \- | \- | - |
| [Leetcode-652. Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/description/) | [c++](./leetcode/652.find-duplicate-subtrees.cpp) | \- | \- | \- | - |
| [Leetcode-654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/description/) | [python](./leetcode/654.maximum-binary-tree.py), [c++](./leetcode/654.maximum-binary-tree.cpp) | \- | \- | \- | - |
| [Leetcode-657. Robot Return To Origin](https://leetcode.com/problems/robot-return-to-origin/description/) | [python](./leetcode/657.robot-return-to-origin.py) | \- | \- | \- | - |
| [Leetcode-674. Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/) | [c++](./leetcode/674.longest-continuous-increasing-subsequence.cpp), [python](./leetcode/674.longest-continuous-increasing-subsequence.py) | \- | \- | \- | - |
| [Leetcode-677. Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/description/) | [python](./leetcode/677.map-sum-pairs.py), [c++](./leetcode/677.map-sum-pairs.cpp) | \- | \- | \- | - |
| [Leetcode-683. K Empty Slots](https://leetcode.com/problems/k-empty-slots/description/) | [python](./leetcode/683.k-empty-slots.py), [c++](./leetcode/683.k-empty-slots.cpp) | \- | \- | \- | - |
| [Leetcode-687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/description/) | [python](./leetcode/687.longest-univalue-path.py), [c++](./leetcode/687.longest-univalue-path.cpp) | \- | \- | \- | - |
| [Leetcode-702. Search In A Sorted Array Of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/) | [c++](./leetcode/702.search-in-a-sorted-array-of-unknown-size.cpp), [python](./leetcode/702.search-in-a-sorted-array-of-unknown-size.py) | \- | \- | \- | - |
| [Leetcode-721. Accounts Merge](https://leetcode.com/problems/accounts-merge/description/) | [c++](./leetcode/721.accounts-merge.cpp), [python](./leetcode/721.accounts-merge.py) | \- | \- | \- | - |
| [Leetcode-724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/description/) | [c++](./leetcode/724.find-pivot-index.cpp) | \- | \- | \- | - |
| [Leetcode-739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/) | [python](./leetcode/739.daily-temperatures.py) | \- | \- | \- | - |
| [Leetcode-747. Largest Number At Least Twice Of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/) | [c++](./leetcode/747.largest-number-at-least-twice-of-others.cpp) | \- | \- | \- | - |
| [Leetcode-751. Ip To Cidr](https://leetcode.com/problems/ip-to-cidr/description/) | [python](./leetcode/751.ip-to-cidr.py) | \- | \- | \- | - |
| [Leetcode-755. Pour Water](https://leetcode.com/problems/pour-water/description/) | [python](./leetcode/755.pour-water.py) | \- | \- | \- | - |
| [Leetcode-760. Find Anagram Mappings](https://leetcode.com/problems/find-anagram-mappings/description/) | [python](./leetcode/760.find-anagram-mappings.py) | \- | \- | \- | - |
| [Leetcode-771. Jewels And Stones](https://leetcode.com/problems/jewels-and-stones/description/) | [c++](./leetcode/771.jewels-and-stones.cpp) | \- | \- | \- | - |
| [Leetcode-773. Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/description/) | [python](./leetcode/773.sliding-puzzle.py) | \- | \- | \- | - |
| [Leetcode-787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/) | [python](./leetcode/787.cheapest-flights-within-k-stops.py) | \- | \- | \- | - |
| [Leetcode-796. Rotate String](https://leetcode.com/problems/rotate-string/description/) | [python](./leetcode/796.rotate-string.py), [c++](./leetcode/796.rotate-string.cpp) | \- | \- | \- | - |
| [Leetcode-815. Bus Routes](https://leetcode.com/problems/bus-routes/description/) | [python](./leetcode/815.bus-routes.py) | \- | \- | \- | - |
| [Leetcode-829. Consecutive Numbers Sum](https://leetcode.com/problems/consecutive-numbers-sum/description/) | [python](./leetcode/829.consecutive-numbers-sum.py) | \- | \- | \- | - |
| [Leetcode-832. Flipping An Image](https://leetcode.com/problems/flipping-an-image/description/) | [python](./leetcode/832.flipping-an-image.py) | \- | \- | \- | - |
| [Leetcode-836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/description/) | [c++](./leetcode/836.rectangle-overlap.cpp), [python](./leetcode/836.rectangle-overlap.py) | \- | \- | \- | - |
| [Leetcode-844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/description/) | [c++](./leetcode/844.backspace-string-compare.cpp), [python](./leetcode/844.backspace-string-compare.py) | \- | \- | \- | - |
| [Leetcode-859. Buddy Strings](https://leetcode.com/problems/buddy-strings/description/) | [c++](./leetcode/859.buddy-strings.cpp) | \- | \- | \- | - |
| [Leetcode-924. Minimize Malware Spread](https://leetcode.com/problems/minimize-malware-spread/description/) | [python](./leetcode/924.minimize-malware-spread.py) | \- | \- | \- | - |
| [Leetcode-928. Minimize Malware Spread II](https://leetcode.com/problems/minimize-malware-spread-ii/description/) | [python](./leetcode/928.minimize-malware-spread-ii.py) | \- | \- | \- | - |
| [Leetcode-929. Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/description/) | [python](./leetcode/929.unique-email-addresses.py) | \- | \- | \- | - |
| [Leetcode-933. Number Of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/description/) | [c++](./leetcode/933.number-of-recent-calls.cpp), [python](./leetcode/933.number-of-recent-calls.py) | \- | \- | \- | - |
| [Leetcode-1150. Check If A Number Is Majority Element In A Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/) | [c++](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.cpp), [python](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.py) | \- | \- | \- | - |
| [Lintcode-31. Partition Array](https://www.lintcode.com/problem/partition-array) | [python](./lintcode/31.partition-array.py) | \- | \- | \- | - |
| [Lintcode-81. Find Median From Data Stream](https://www.lintcode.com/problem/find-median-from-data-stream) | [c++](./lintcode/81.find-median-from-data-stream.cpp), [python](./lintcode/81.find-median-from-data-stream.py) | \- | \- | \- | - |
| [Lintcode-89. K Sum](https://www.lintcode.com/problem/k-sum) | [c++](./lintcode/89.k-sum.cpp), [python](./lintcode/89.k-sum.py) | \- | \- | \- | - |
| [Lintcode-91. Minimum Adjustment Cost](https://www.lintcode.com/problem/minimum-adjustment-cost) | [c++](./lintcode/91.minimum-adjustment-cost.cpp), [python](./lintcode/91.minimum-adjustment-cost.py) | \- | \- | \- | - |
| [Lintcode-139. Subarray Sum Closest](https://www.lintcode.com/problem/subarray-sum-closest) | [c++](./lintcode/139.subarray-sum-closest.cpp), [python](./lintcode/139.subarray-sum-closest.py) | \- | \- | \- | - |
| [Lintcode-144. Interleaving Positive And Negative Numbers](https://www.lintcode.com/problem/interleaving-positive-and-negative-numbers) | [python](./lintcode/144.interleaving-positive-and-negative-numbers.py), [c++](./lintcode/144.interleaving-positive-and-negative-numbers.cpp) | \- | \- | \- | - |
| [Lintcode-183. Wood Cut](https://www.lintcode.com/problem/wood-cut) | [c++](./lintcode/183.wood-cut.cpp), [python](./lintcode/183.wood-cut.py) | \- | \- | \- | - |
| [Lintcode-382. Triangle Count](https://www.lintcode.com/problem/triangle-count) | [c++](./lintcode/382.triangle-count.cpp), [python](./lintcode/382.triangle-count.py) | \- | \- | \- | - |
| [Lintcode-390. Find Peak Element II](https://www.lintcode.com/problem/find-peak-element-ii) | [python](./lintcode/390.find-peak-element-ii.py), [c++](./lintcode/390.find-peak-element-ii.cpp) | \- | \- | \- | - |
| [Lintcode-391. Number Of Airplanes In The Sky](https://www.lintcode.com/problem/number-of-airplanes-in-the-sky) | [c++](./lintcode/391.number-of-airplanes-in-the-sky.cpp), [python](./lintcode/391.number-of-airplanes-in-the-sky.py) | \- | \- | \- | - |
| [Lintcode-394. Coins In A Line](https://www.lintcode.com/problem/coins-in-a-line) | [python](./lintcode/394.coins-in-a-line.py), [c++](./lintcode/394.coins-in-a-line.cpp) | \- | \- | \- | - |
| [Lintcode-396. Coins In A Line III](https://www.lintcode.com/problem/coins-in-a-line-iii) | [python](./lintcode/396.coins-in-a-line-iii.py), [c++](./lintcode/396.coins-in-a-line-iii.cpp) | \- | \- | \- | - |
| [Lintcode-447. Search In A Big Sorted Array](https://www.lintcode.com/problem/search-in-a-big-sorted-array) | [python](./lintcode/447.search-in-a-big-sorted-array.py), [c++](./lintcode/447.search-in-a-big-sorted-array.cpp) | \- | \- | \- | - |
| [Lintcode-465. Kth Smallest Sum In Two Sorted Arrays](https://www.lintcode.com/problem/kth-smallest-sum-in-two-sorted-arrays) | [python](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.py), [c++](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.cpp) | \- | \- | \- | - |
| [Lintcode-526. Load Balancer](https://www.lintcode.com/problem/load-balancer) | [c++](./lintcode/526.load-balancer.cpp), [python](./lintcode/526.load-balancer.py) | \- | \- | \- | - |
| [Lintcode-543. Kth Largest In N Arrays](https://www.lintcode.com/problem/kth-largest-in-n-arrays) | [c++](./lintcode/543.kth-largest-in-n-arrays.cpp), [python](./lintcode/543.kth-largest-in-n-arrays.py) | \- | \- | \- | - |
| [Lintcode-563. Backpack V](https://www.lintcode.com/problem/backpack-v) | [python](./lintcode/563.backpack-v.py), [c++](./lintcode/563.backpack-v.cpp) | \- | \- | \- | - |
| [Lintcode-586. Sqrtx II](https://www.lintcode.com/problem/sqrtx-ii) | [c++](./lintcode/586.sqrtx-ii.cpp), [python](./lintcode/586.sqrtx-ii.py) | \- | \- | \- | - |
| [Lintcode-589. Connecting Graph](https://www.lintcode.com/problem/connecting-graph) | [c++](./lintcode/589.connecting-graph.cpp), [python](./lintcode/589.connecting-graph.py) | \- | \- | \- | - |
| [Lintcode-590. Connecting Graph II](https://www.lintcode.com/problem/connecting-graph-ii) | [python](./lintcode/590.connecting-graph-ii.py), [c++](./lintcode/590.connecting-graph-ii.cpp) | \- | \- | \- | - |
| [Lintcode-591. Connecting Graph III](https://www.lintcode.com/problem/connecting-graph-iii) | [python](./lintcode/591.connecting-graph-iii.py), [c++](./lintcode/591.connecting-graph-iii.cpp) | \- | \- | \- | - |
| [Lintcode-598. Zombie In Matrix](https://www.lintcode.com/problem/zombie-in-matrix) | [python](./lintcode/598.zombie-in-matrix.py), [c++](./lintcode/598.zombie-in-matrix.cpp) | \- | \- | \- | - |
| [Lintcode-611. Knight Shortest Path](https://www.lintcode.com/problem/knight-shortest-path) | [c++](./lintcode/611.knight-shortest-path.cpp), [python](./lintcode/611.knight-shortest-path.py) | \- | \- | \- | - |
| [Lintcode-618. Search Graph Nodes](https://www.lintcode.com/problem/search-graph-nodes) | [python](./lintcode/618.search-graph-nodes.py), [c++](./lintcode/618.search-graph-nodes.cpp) | \- | \- | \- | - |
| [Lintcode-629. Minimum Spanning Tree](https://www.lintcode.com/problem/minimum-spanning-tree) | [c++](./lintcode/629.minimum-spanning-tree.cpp), [python](./lintcode/629.minimum-spanning-tree.py) | \- | \- | \- | - |
| [Lintcode-652. Factorization](https://www.lintcode.com/problem/factorization) | [python](./lintcode/652.factorization.py), [c++](./lintcode/652.factorization.cpp) | \- | \- | \- | - |

