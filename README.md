# 算法/Algorithm

我个人的力扣答案, **公众号:GeekPal**

这是一个持续更新的开源项目

My Personal LeetCode Solutions

This is an open-source project that is continually updated

**Total: 259** / **436** problems

**Updated:** 2024-09-13 20:04:32

## 列表/List

- [✅geekbang.md](./list/✅geekbang.md)
- [✅leetcode101.md](./list/✅leetcode101.md)
- [❎lee215.md](./list/❎lee215.md)
- [🚧9c-advanced.md](./list/🚧9c-advanced.md)
- [🚧9c-basic.md](./list/🚧9c-basic.md)
- [🚧9c-dp.md](./list/🚧9c-dp.md)
- [🚧9c-top.md](./list/🚧9c-top.md)

## 链接/Links

- [本人博客](https://blog.mogoal.com/category/#Algorithm)
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

## 书籍/Books

- 《算法技术手册》/ Algorithms in a Nutshell
- 《STL源码剖析》/ The Annotated STL Sources
- 《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition
- 《数学之美》(A chinese version book by Doctor Wujun)
- 《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)

## 类型/Category

- [Math](#math)
- [Probability](#probability)
- [Bit Manipulation](#bit-manipulation)
- [Simulation](#simulation)
- [Design](#design)
- [Greedy](#greedy)
- [Dynamic Programming](#dynamic-programming)
- [Binary Search](#binary-search)
- [Linked List](#linked-list)
- [Hash Table](#hash-table)
- [Stack](#stack)
- [Monotonic Stack](#monotonic-stack)
- [Queue](#queue)
- [Monotonic Queue](#monotonic-queue)
- [Heap](#heap)
- [Two Pointers](#two-pointers)
- [Sliding Window](#sliding-window)
- [Sorting](#sorting)
- [Counting](#counting)
- [Quickselect](#quickselect)
- [Divide and Conquer](#divide-and-conquer)
- [Breadth-First Search](#breadth-first-search)
- [Depth-First Search](#depth-first-search)
- [Topological Sort](#topological-sort)
- [Shortest Path](#shortest-path)
- [Backtracking](#backtracking)
- [Line Sweep](#line-sweep)
- [Ordered Set](#ordered-set)
- [Binary Search Tree](#binary-search-tree)
- [Binary Indexed Tree](#binary-indexed-tree)
- [Segment Tree](#segment-tree)
- [Union Find](#union-find)
- [Trie](#trie)

## Math

| Update | Problem(19) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-263. Ugly Number](https://leetcode.com/problems/ugly-number/description/) | [c++](./leetcode/263.ugly-number.cpp), [python3](./leetcode/263.ugly-number.py) | Math | O\(k\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Math | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-69. Sqrtx](https://leetcode.com/problems/sqrtx/description/) | [c++](./leetcode/69.sqrtx.cpp), [python3](./leetcode/69.sqrtx.py) | Math | N\(logN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-932. Beautiful Array](https://leetcode.com/problems/beautiful-array/description/) | [c++](./leetcode/932.beautiful-array.cpp), [python3](./leetcode/932.beautiful-array.py) | Math | O\(N\) | O\(N\) | dp | - |
| 2024-07 | [Leetcode-204. Count Primes](https://leetcode.com/problems/count-primes/description/) | [c++](./leetcode/204.count-primes.cpp), [python3](./leetcode/204.count-primes.py) | Math | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-504. Base 7](https://leetcode.com/problems/base-7/description/) | [c++](./leetcode/504.base-7.cpp), [python3](./leetcode/504.base-7.py) | Math | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-415. Add Strings](https://leetcode.com/problems/add-strings/description/) | [c++](./leetcode/415.add-strings.cpp), [python3](./leetcode/415.add-strings.py) | Math | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-326. Power Of Three](https://leetcode.com/problems/power-of-three/description/) | [c++](./leetcode/326.power-of-three.cpp), [python3](./leetcode/326.power-of-three.py) | Math | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-168. Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/description/) | [c++](./leetcode/168.excel-sheet-column-title.cpp), [python3](./leetcode/168.excel-sheet-column-title.py) | Math | O\(logN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-462. Minimum Moves To Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/) | [c++](./leetcode/462.minimum-moves-to-equal-array-elements-ii.cpp), [python3](./leetcode/462.minimum-moves-to-equal-array-elements-ii.py) | Math | O\(NlogN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-202. Happy Number](https://leetcode.com/problems/happy-number/description/) | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Math | O\(S\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-48. Rotate Image](https://leetcode.com/problems/rotate-image/description/) | [c++](./leetcode/48.rotate-image.cpp), [python3](./leetcode/48.rotate-image.py) | Math | O\(N^2\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-172. Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/description/) | [c++](./leetcode/172.factorial-trailing-zeroes.cpp), [python3](./leetcode/172.factorial-trailing-zeroes.py) | Math | O\(logN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-149. Max Points On A Line](https://leetcode.com/problems/max-points-on-a-line/description/) | [c++](./leetcode/149.max-points-on-a-line.cpp), [python3](./leetcode/149.max-points-on-a-line.py) | Math | O\(N^2\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/description/) | [c++](./leetcode/227.basic-calculator-ii.cpp), [python3](./leetcode/227.basic-calculator-ii.py) | Math | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-50. Powx N](https://leetcode.com/problems/powx-n/description/) | [c++](./leetcode/50.powx-n.cpp), [python3](./leetcode/50.powx-n.py) | Math | O\(logN\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3274. Check If Two Chessboard Squares Have The Same Color](https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/) | [c++](./leetcode/3274.check-if-two-chessboard-squares-have-the-same-color.cpp), [python3](./leetcode/3274.check-if-two-chessboard-squares-have-the-same-color.py) | Math | O\(1\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/description/) | [c++](./leetcode/367.valid-perfect-square.cpp), [python3](./leetcode/367.valid-perfect-square.py) | Math | O\(logN\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3280. Convert Date To Binary](https://leetcode.com/problems/convert-date-to-binary/description/) | [c++](./leetcode/3280.convert-date-to-binary.cpp), [python3](./leetcode/3280.convert-date-to-binary.py) | Math | O\(1\) | O\(1\) | \- | - |

## Probability

| Update | Problem(5) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-384. Shuffle An Array](https://leetcode.com/problems/shuffle-an-array/description/) | [c++](./leetcode/384.shuffle-an-array.cpp), [python3](./leetcode/384.shuffle-an-array.py) | Probability | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-528. Random Pick With Weight](https://leetcode.com/problems/random-pick-with-weight/description/) | [c++](./leetcode/528.random-pick-with-weight.cpp), [python3](./leetcode/528.random-pick-with-weight.py) | Probability | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/description/) | [c++](./leetcode/382.linked-list-random-node.cpp), [python3](./leetcode/382.linked-list-random-node.py) | Probability | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-470. Implement Rand10 Using Rand7](https://leetcode.com/problems/implement-rand10-using-rand7/description/) | [c++](./leetcode/470.implement-rand10-using-rand7.cpp), [python3](./leetcode/470.implement-rand10-using-rand7.py) | Probability | O\(1\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-380. Insert Delete Getrandom O1](https://leetcode.com/problems/insert-delete-getrandom-o1/description/) | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Probability | O\(1\) | O\(N\) | \- | - |

## Bit Manipulation

| Update | Problem(15) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-67. Add Binary](https://leetcode.com/problems/add-binary/description/) | [c++](./leetcode/67.add-binary.cpp), [python3](./leetcode/67.add-binary.py) | Bit Manipulation | O\(M\+N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-461. Hamming Distance](https://leetcode.com/problems/hamming-distance/description/) | [c++](./leetcode/461.hamming-distance.cpp), [python3](./leetcode/461.hamming-distance.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-190. Reverse Bits](https://leetcode.com/problems/reverse-bits/description/) | [c++](./leetcode/190.reverse-bits.cpp), [python3](./leetcode/190.reverse-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-136. Single Number](https://leetcode.com/problems/single-number/description/) | [c++](./leetcode/136.single-number.cpp), [python3](./leetcode/136.single-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-342. Power Of Four](https://leetcode.com/problems/power-of-four/description/) | [c++](./leetcode/342.power-of-four.cpp), [python3](./leetcode/342.power-of-four.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-318. Maximum Product Of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/description/) | [c++](./leetcode/318.maximum-product-of-word-lengths.cpp), [python3](./leetcode/318.maximum-product-of-word-lengths.py) | Bit Manipulation | O\(N^2\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-338. Counting Bits](https://leetcode.com/problems/counting-bits/description/) | [c++](./leetcode/338.counting-bits.cpp), [python3](./leetcode/338.counting-bits.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-268. Missing Number](https://leetcode.com/problems/missing-number/description/) | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-693. Binary Number With Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/description/) | [c++](./leetcode/693.binary-number-with-alternating-bits.cpp), [python3](./leetcode/693.binary-number-with-alternating-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-476. Number Complement](https://leetcode.com/problems/number-complement/description/) | [c++](./leetcode/476.number-complement.cpp), [python3](./leetcode/476.number-complement.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-260. Single Number III](https://leetcode.com/problems/single-number-iii/description/) | [c++](./leetcode/260.single-number-iii.cpp), [python3](./leetcode/260.single-number-iii.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-287. Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/) | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3276. Select Cells In Grid With Maximum Score](https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/) | [c++](./leetcode/3276.select-cells-in-grid-with-maximum-score.cpp), [python3](./leetcode/3276.select-cells-in-grid-with-maximum-score.py) | Bit Manipulation | O\(NM\*2^N\) | O\(2^N\) | \- | - |
| 2024-09 | [Leetcode-191. Number Of 1 Bits](https://leetcode.com/problems/number-of-1-bits/description/) | [c++](./leetcode/191.number-of-1-bits.cpp), [python3](./leetcode/191.number-of-1-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-231. Power Of Two](https://leetcode.com/problems/power-of-two/description/) | [c++](./leetcode/231.power-of-two.cpp), [python3](./leetcode/231.power-of-two.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |

## Simulation

| Update | Problem(6) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Lintcode-39. Recover Rotated Sorted Array](https://www.lintcode.com/problem/recover-rotated-sorted-array) | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python3](./lintcode/39.recover-rotated-sorted-array.py) | Simulation | O\(N\) | O\(1\) | Rotated | - |
| 2024-07 | [Leetcode-415. Add Strings](https://leetcode.com/problems/add-strings/description/) | [c++](./leetcode/415.add-strings.cpp), [python3](./leetcode/415.add-strings.py) | Simulation | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-67. Add Binary](https://leetcode.com/problems/add-binary/description/) | [c++](./leetcode/67.add-binary.cpp), [python3](./leetcode/67.add-binary.py) | Simulation | O\(M\+N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-566. Reshape The Matrix](https://leetcode.com/problems/reshape-the-matrix/description/) | [c++](./leetcode/566.reshape-the-matrix.cpp), [python3](./leetcode/566.reshape-the-matrix.py) | Simulation | O\(MN\) | O\(1\) | \- | - |
| 2024-08 | [Lintcode-849. Basic Calculator III](https://www.lintcode.com/problem/basic-calculator-iii) | [c++](./lintcode/849.basic-calculator-iii.cpp), [python3](./lintcode/849.basic-calculator-iii.py) | Simulation | O\(N\) | O\(1\) | Leetcode\-772 | - |
| 2024-09 | [Leetcode-874. Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/description/) | [c++](./leetcode/874.walking-robot-simulation.cpp), [python3](./leetcode/874.walking-robot-simulation.py) | Simulation | O\(N\) | O\(K\) | \- | - |

## Design

| Update | Problem(13) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Design | O\(N\) | O\(N\) | Serialization | - |
| 2024-08 | [Leetcode-232. Implement Queue Using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/) | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Design | O\(\*1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-155. Min Stack](https://leetcode.com/problems/min-stack/description/) | [c++](./leetcode/155.min-stack.cpp), [python3](./leetcode/155.min-stack.py) | Design | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Design | O\(1\) | O\(H\) | InOrder | - |
| 2024-08 | [Leetcode-303. Range Sum Query Immutable](https://leetcode.com/problems/range-sum-query-immutable/description/) | [c++](./leetcode/303.range-sum-query-immutable.cpp), [python3](./leetcode/303.range-sum-query-immutable.py) | Design | O\(\*1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-304. Range Sum Query 2D Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/description/) | [c++](./leetcode/304.range-sum-query-2d-immutable.cpp), [python3](./leetcode/304.range-sum-query-2d-immutable.py) | Design | O\(\*1\) | O\(MN\) | \- | - |
| 2024-08 | [Leetcode-225. Implement Stack Using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/) | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Design | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-307. Range Sum Query Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/) | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Design | O\(logN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-208. Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/description/) | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Design | O\(N\) | O\(L\) | \- | - |
| 2024-08 | [Leetcode-380. Insert Delete Getrandom O1](https://leetcode.com/problems/insert-delete-getrandom-o1/description/) | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Design | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-432. All Oone Data Structure](https://leetcode.com/problems/all-oone-data-structure/description/) | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Design | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-146. Lru Cache](https://leetcode.com/problems/lru-cache/description/) | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Design | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-703. Kth Largest Element In A Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/) | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Design | O\(logN\) | O\(N\) | \- | - |

## Greedy

| Update | Problem(19) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-135. Candy](https://leetcode.com/problems/candy/description/) | [c++](./leetcode/135.candy.cpp), [python3](./leetcode/135.candy.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-06 | [Leetcode-605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/description/) | [c++](./leetcode/605.can-place-flowers.cpp), [python3](./leetcode/605.can-place-flowers.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-06 | [Leetcode-452. Minimum Number Of Arrows To Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/) | [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp), [python3](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py) | Greedy | O\(N\*logN\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-763. Partition Labels](https://leetcode.com/problems/partition-labels/description/) | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-06 | [Leetcode-680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/) | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python3](./leetcode/680.valid-palindrome-ii.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/description/) | [c++](./leetcode/376.wiggle-subsequence.cpp), [python3](./leetcode/376.wiggle-subsequence.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-769. Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/description/) | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Greedy | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Greedy | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-3048. Earliest Second To Mark Indices I](https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/) | [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp), [python3](./leetcode/3048.earliest-second-to-mark-indices-i.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-870. Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/description/) | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/description/) | [c++](./leetcode/409.longest-palindrome.cpp), [python3](./leetcode/409.longest-palindrome.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Lintcode-3672. Connecting Cities With Minimum Cost](https://www.lintcode.com/problem/connecting-cities-with-minimum-cost) | [c++](./lintcode/3672.connecting-cities-with-minimum-cost.cpp), [python3](./lintcode/3672.connecting-cities-with-minimum-cost.py) | Greedy | O\(ElogE\) | O\(E\+V\) | Leetcode\-1135 | - |
| 2024-09 | [Leetcode-122. Best Time To Buy And Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/) | [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python3](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-860. Lemonade Change](https://leetcode.com/problems/lemonade-change/description/) | [c++](./leetcode/860.lemonade-change.cpp), [python3](./leetcode/860.lemonade-change.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-714. Best Time To Buy And Sell Stock With Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp), [python3](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-3281. Maximize Score Of Numbers In Ranges](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/) | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Greedy | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3282. Reach End Of Array With Max Score](https://leetcode.com/problems/reach-end-of-array-with-max-score/description/) | [c++](./leetcode/3282.reach-end-of-array-with-max-score.cpp), [python3](./leetcode/3282.reach-end-of-array-with-max-score.py) | Greedy | O\(N\) | O\(1\) | \- | - |

## Dynamic Programming

| Update | Problem(49) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-375. Guess Number Higher Or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/) | [c++](./leetcode/375.guess-number-higher-or-lower-ii.cpp), [python3](./leetcode/375.guess-number-higher-or-lower-ii.py) | Dynamic Programming | O\(N^3\) | O\(N^2\) | DP\(Index\) | - |
| 2024-06 | [Lintcode-437. Copy Books](https://www.lintcode.com/problem/copy-books) | [c++](./lintcode/437.copy-books.cpp), [python3](./lintcode/437.copy-books.py) | Dynamic Programming | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| 2024-07 | [Leetcode-70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/) | [c++](./leetcode/70.climbing-stairs.cpp), [python3](./leetcode/70.climbing-stairs.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-198. House Robber](https://leetcode.com/problems/house-robber/description/) | [c++](./leetcode/198.house-robber.cpp), [python3](./leetcode/198.house-robber.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/description/) | [c++](./leetcode/413.arithmetic-slices.cpp), [python3](./leetcode/413.arithmetic-slices.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/) | [c++](./leetcode/64.minimum-path-sum.cpp), [python3](./leetcode/64.minimum-path-sum.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-542. 01 Matrix](https://leetcode.com/problems/01-matrix/description/) | [c++](./leetcode/542.01-matrix.cpp), [python3](./leetcode/542.01-matrix.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-221. Maximal Square](https://leetcode.com/problems/maximal-square/description/) | [c++](./leetcode/221.maximal-square.cpp), [python3](./leetcode/221.maximal-square.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/) | [c++](./leetcode/279.perfect-squares.cpp), [python3](./leetcode/279.perfect-squares.py) | Dynamic Programming | O\(n^\{3/2\}\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-91. Decode Ways](https://leetcode.com/problems/decode-ways/description/) | [c++](./leetcode/91.decode-ways.cpp), [python3](./leetcode/91.decode-ways.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-139. Word Break](https://leetcode.com/problems/word-break/description/) | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Dynamic Programming | O\(MN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [c++](./leetcode/300.longest-increasing-subsequence.cpp), [python3](./leetcode/300.longest-increasing-subsequence.py) | Dynamic Programming | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| 2024-07 | [Leetcode-1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/) | [c++](./leetcode/1143.longest-common-subsequence.cpp), [python3](./leetcode/1143.longest-common-subsequence.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Lintcode-125. Backpack II](https://www.lintcode.com/problem/backpack-ii) | [c++](./lintcode/125.backpack-ii.cpp), [python3](./lintcode/125.backpack-ii.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Lintcode-92. Backpack](https://www.lintcode.com/problem/backpack) | [c++](./lintcode/92.backpack.cpp), [python3](./lintcode/92.backpack.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Lintcode-440. Backpack III](https://www.lintcode.com/problem/backpack-iii) | [c++](./lintcode/440.backpack-iii.cpp), [python3](./lintcode/440.backpack-iii.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Lintcode-562. Backpack IV](https://www.lintcode.com/problem/backpack-iv) | [c++](./lintcode/562.backpack-iv.cpp), [python3](./lintcode/562.backpack-iv.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Leetcode-416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/) | [c++](./leetcode/416.partition-equal-subset-sum.cpp), [python3](./leetcode/416.partition-equal-subset-sum.py) | Dynamic Programming | O\(N^2\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-474. Ones And Zeroes](https://leetcode.com/problems/ones-and-zeroes/description/) | [c++](./leetcode/474.ones-and-zeroes.cpp), [python3](./leetcode/474.ones-and-zeroes.py) | Dynamic Programming | O\(KMN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-322. Coin Change](https://leetcode.com/problems/coin-change/description/) | [c++](./leetcode/322.coin-change.cpp), [python3](./leetcode/322.coin-change.py) | Dynamic Programming | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| 2024-07 | [Leetcode-650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/description/) | [c++](./leetcode/650.2-keys-keyboard.cpp), [python3](./leetcode/650.2-keys-keyboard.py) | Dynamic Programming | \- | \- | \- | - |
| 2024-07 | [Leetcode-10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/description/) | [c++](./leetcode/10.regular-expression-matching.cpp), [python3](./leetcode/10.regular-expression-matching.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-213. House Robber II](https://leetcode.com/problems/house-robber-ii/description/) | [c++](./leetcode/213.house-robber-ii.cpp), [python3](./leetcode/213.house-robber-ii.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) | [c++](./leetcode/53.maximum-subarray.cpp), [python3](./leetcode/53.maximum-subarray.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-343. Integer Break](https://leetcode.com/problems/integer-break/description/) | [c++](./leetcode/343.integer-break.cpp), [python3](./leetcode/343.integer-break.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-583. Delete Operation For Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/description/) | [c++](./leetcode/583.delete-operation-for-two-strings.cpp), [python3](./leetcode/583.delete-operation-for-two-strings.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Dynamic Programming | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/description/) | [c++](./leetcode/376.wiggle-subsequence.cpp), [python3](./leetcode/376.wiggle-subsequence.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-494. Target Sum](https://leetcode.com/problems/target-sum/description/) | [c++](./leetcode/494.target-sum.cpp), [python3](./leetcode/494.target-sum.py) | Dynamic Programming | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |
| 2024-07 | [Leetcode-241. Different Ways To Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/) | [c++](./leetcode/241.different-ways-to-add-parentheses.cpp), [python3](./leetcode/241.different-ways-to-add-parentheses.py) | Dynamic Programming | \- | \- | \- | - |
| 2024-07 | [Leetcode-312. Burst Balloons](https://leetcode.com/problems/burst-balloons/description/) | [c++](./leetcode/312.burst-balloons.cpp), [python3](./leetcode/312.burst-balloons.py) | Dynamic Programming | O\(N^3\) | O\(N^2\) | \- | - |
| 2024-07 | [Leetcode-338. Counting Bits](https://leetcode.com/problems/counting-bits/description/) | [c++](./leetcode/338.counting-bits.cpp), [python3](./leetcode/338.counting-bits.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Dynamic Programming | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-313. Super Ugly Number](https://leetcode.com/problems/super-ugly-number/description/) | [c++](./leetcode/313.super-ugly-number.cpp), [python3](./leetcode/313.super-ugly-number.py) | Dynamic Programming | O\(NlogK\) | O\(N\+K\) | K\-Linked\-List\(dup\) | - |
| 2024-08 | [Leetcode-647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/) | [c++](./leetcode/647.palindromic-substrings.cpp), [python3](./leetcode/647.palindromic-substrings.py) | Dynamic Programming | O\(N^2\) | O\(1\) | DP Slow | - |
| 2024-08 | [Leetcode-5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/) | [c++](./leetcode/5.longest-palindromic-substring.cpp), [python3](./leetcode/5.longest-palindromic-substring.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/) | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Dynamic Programming | O\(ElogV\) | O\(E\+V\) | \- | - |
| 2024-09 | [Leetcode-122. Best Time To Buy And Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/) | [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python3](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3276. Select Cells In Grid With Maximum Score](https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/) | [c++](./leetcode/3276.select-cells-in-grid-with-maximum-score.cpp), [python3](./leetcode/3276.select-cells-in-grid-with-maximum-score.py) | Dynamic Programming | O\(NM\*2^N\) | O\(2^N\) | \- | - |
| 2024-09 | [Leetcode-22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/) | [c++](./leetcode/22.generate-parentheses.cpp), [python3](./leetcode/22.generate-parentheses.py) | Dynamic Programming | O\(2^N\) | O\(N\) | Catalan Number | - |
| 2024-09 | [Leetcode-3277. Maximum Xor Score Subarray Queries](https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/) | [c++](./leetcode/3277.maximum-xor-score-subarray-queries.cpp), [python3](./leetcode/3277.maximum-xor-score-subarray-queries.py) | Dynamic Programming | O\(N^2 \+ M\) | O\(N^2\) | \- | - |
| 2024-09 | [Leetcode-120. Triangle](https://leetcode.com/problems/triangle/description/) | [c++](./leetcode/120.triangle.cpp), [python3](./leetcode/120.triangle.py) | Dynamic Programming | O\(N^2\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/) | [c++](./leetcode/152.maximum-product-subarray.cpp), [python3](./leetcode/152.maximum-product-subarray.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-121. Best Time To Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) | [c++](./leetcode/121.best-time-to-buy-and-sell-stock.cpp), [python3](./leetcode/121.best-time-to-buy-and-sell-stock.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-123. Best Time To Buy And Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/) | [c++](./leetcode/123.best-time-to-buy-and-sell-stock-iii.cpp), [python3](./leetcode/123.best-time-to-buy-and-sell-stock-iii.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-188. Best Time To Buy And Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/) | [c++](./leetcode/188.best-time-to-buy-and-sell-stock-iv.cpp), [python3](./leetcode/188.best-time-to-buy-and-sell-stock-iv.py) | Dynamic Programming | O\(NK\) | O\(NK\) | \- | - |
| 2024-09 | [Leetcode-714. Best Time To Buy And Sell Stock With Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp), [python3](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-309. Best Time To Buy And Sell Stock With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/) | [c++](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp), [python3](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-72. Edit Distance](https://leetcode.com/problems/edit-distance/description/) | [c++](./leetcode/72.edit-distance.cpp), [python3](./leetcode/72.edit-distance.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |

## Binary Search

| Update | Problem(32) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-33. Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/) | [c++](./leetcode/33.search-in-rotated-sorted-array.cpp), [python3](./leetcode/33.search-in-rotated-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | Rotated; | - |
| 2024-06 | [Leetcode-34. Find First And Last Position Of Element In Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/) | [c++](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp), [python3](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound; | [Video](https://youtu.be/y6OT8heV-30) |
| 2024-06 | [Leetcode-35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/) | [c++](./leetcode/35.search-insert-position.cpp), [python3](./leetcode/35.search-insert-position.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound | - |
| 2024-06 | [Leetcode-74. Search A 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/) | [c++](./leetcode/74.search-a-2d-matrix.cpp), [python3](./leetcode/74.search-a-2d-matrix.py) | Binary Search | O\(log\(m \* n\)\) | O\(1\) | Matrix; | - |
| 2024-06 | [Leetcode-153. Find Minimum In Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/) | [c++](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python3](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | Rotated; | [Video](https://youtu.be/GsecRZC5to4) |
| 2024-06 | [Leetcode-162. Find Peak Element](https://leetcode.com/problems/find-peak-element/description/) | [c++](./leetcode/162.find-peak-element.cpp), [python3](./leetcode/162.find-peak-element.py) | Binary Search | O\(logN\) | O\(1\) | Mountain; | [Video](https://youtu.be/bexO0N9eP1I) |
| 2024-06 | [Leetcode-278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/) | [c++](./leetcode/278.first-bad-version.cpp), [python3](./leetcode/278.first-bad-version.py) | Binary Search | O\(logN\) | O\(1\) | Range; | [Video](https://youtu.be/xNzBpfqzYSg) |
| 2024-06 | [Leetcode-374. Guess Number Higher Or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/description/) | [c++](./leetcode/374.guess-number-higher-or-lower.cpp), [python3](./leetcode/374.guess-number-higher-or-lower.py) | Binary Search | O\(logN\) | O\(1\) | Standard | - |
| 2024-06 | [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Binary Search | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| 2024-06 | [Leetcode-704. Binary Search](https://leetcode.com/problems/binary-search/description/) | [c++](./leetcode/704.binary-search.cpp), [python3](./leetcode/704.binary-search.py) | Binary Search | O\(logN\) | O\(1\) | Standard; | [Video](https://youtu.be/oxWpJtUGG_0) |
| 2024-06 | [Leetcode-852. Peak Index In A Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/) | [c++](./leetcode/852.peak-index-in-a-mountain-array.cpp), [python3](./leetcode/852.peak-index-in-a-mountain-array.py) | Binary Search | O\(logN\) | O\(1\) | Mountain | - |
| 2024-06 | [Leetcode-1901. Find A Peak Element II](https://leetcode.com/problems/find-a-peak-element-ii/description/) | [c++](./leetcode/1901.find-a-peak-element-ii.cpp), [python3](./leetcode/1901.find-a-peak-element-ii.py) | Binary Search | O\(N \* logM\) | O\(1\) | Mountain; | - |
| 2024-06 | [Leetcode-2468. Split Message Based On Limit](https://leetcode.com/problems/split-message-based-on-limit/description/) | [c++](./leetcode/2468.split-message-based-on-limit.cpp), [python3](./leetcode/2468.split-message-based-on-limit.py) | Binary Search | O\(logN \+ K\) | O\(1\) | Answer \| Bruteforce | - |
| 2024-06 | [Leetcode-2529. Maximum Count Of Positive Integer And Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/) | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python3](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound | - |
| 2024-06 | [Lintcode-437. Copy Books](https://www.lintcode.com/problem/copy-books) | [c++](./lintcode/437.copy-books.cpp), [python3](./lintcode/437.copy-books.py) | Binary Search | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| 2024-06 | [Lintcode-600. Smallest Rectangle Enclosing Black Pixels](https://www.lintcode.com/problem/smallest-rectangle-enclosing-black-pixels) | [c++](./lintcode/600.smallest-rectangle-enclosing-black-pixels.cpp), [python3](./lintcode/600.smallest-rectangle-enclosing-black-pixels.py) | Binary Search | O\(N \* logM \+ M \* logN\) | O\(1\) | Graph \| Leetcode\-302 | - |
| 2024-06 | [Leetcode-167. Two Sum Ii Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python3](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-69. Sqrtx](https://leetcode.com/problems/sqrtx/description/) | [c++](./leetcode/69.sqrtx.cpp), [python3](./leetcode/69.sqrtx.py) | Binary Search | N\(logN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-81. Search In Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/) | [c++](./leetcode/81.search-in-rotated-sorted-array-ii.cpp), [python3](./leetcode/81.search-in-rotated-sorted-array-ii.py) | Binary Search | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| 2024-07 | [Leetcode-154. Find Minimum In Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/) | [c++](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp), [python3](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | Binary Search | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| 2024-07 | [Leetcode-540. Single Element In A Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/) | [c++](./leetcode/540.single-element-in-a-sorted-array.cpp), [python3](./leetcode/540.single-element-in-a-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-4. Median Of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/) | [c++](./leetcode/4.median-of-two-sorted-arrays.cpp), [python3](./leetcode/4.median-of-two-sorted-arrays.py) | Binary Search | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [c++](./leetcode/300.longest-increasing-subsequence.cpp), [python3](./leetcode/300.longest-increasing-subsequence.py) | Binary Search | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| 2024-07 | [Leetcode-528. Random Pick With Weight](https://leetcode.com/problems/random-pick-with-weight/description/) | [c++](./leetcode/528.random-pick-with-weight.cpp), [python3](./leetcode/528.random-pick-with-weight.py) | Binary Search | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-268. Missing Number](https://leetcode.com/problems/missing-number/description/) | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-240. Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/) | [c++](./leetcode/240.search-a-2d-matrix-ii.cpp), [python3](./leetcode/240.search-a-2d-matrix-ii.py) | Binary Search | O\(M \+ N\) | O\(1\) | Matrix | - |
| 2024-08 | [Leetcode-3048. Earliest Second To Mark Indices I](https://leetcode.com/problems/earliest-second-to-mark-indices-i/description/) | [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp), [python3](./leetcode/3048.earliest-second-to-mark-indices-i.py) | Binary Search | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-287. Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/) | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/description/) | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Binary Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| 2024-09 | [Leetcode-367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/description/) | [c++](./leetcode/367.valid-perfect-square.cpp), [python3](./leetcode/367.valid-perfect-square.py) | Binary Search | O\(logN\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3281. Maximize Score Of Numbers In Ranges](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/) | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Binary Search | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |

## Linked List

| Update | Problem(19) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/) | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/description/) | [c++](./leetcode/382.linked-list-random-node.cpp), [python3](./leetcode/382.linked-list-random-node.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Linked List | O\(N\) | O\(H\) | PreOrder | - |
| 2024-08 | [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Linked List | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |
| 2024-08 | [Leetcode-23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Linked List | O\(NlogK\) | O\(K\) | \- | - |
| 2024-08 | [Leetcode-206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/) | [c++](./leetcode/206.reverse-linked-list.cpp), [python3](./leetcode/206.reverse-linked-list.py) | Linked List | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/) | [c++](./leetcode/21.merge-two-sorted-lists.cpp), [python3](./leetcode/21.merge-two-sorted-lists.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-160. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/) | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-83. Remove Duplicates From Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/) | [c++](./leetcode/83.remove-duplicates-from-sorted-list.cpp), [python3](./leetcode/83.remove-duplicates-from-sorted-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/description/) | [c++](./leetcode/328.odd-even-linked-list.cpp), [python3](./leetcode/328.odd-even-linked-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-19. Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/) | [c++](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python3](./leetcode/19.remove-nth-node-from-end-of-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-148. Sort List](https://leetcode.com/problems/sort-list/description/) | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Linked List | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-109. Convert Sorted List To Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/) | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Linked List | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-432. All Oone Data Structure](https://leetcode.com/problems/all-oone-data-structure/description/) | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Linked List | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-146. Lru Cache](https://leetcode.com/problems/lru-cache/description/) | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Linked List | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-25. Reverse Nodes In K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) | [c++](./leetcode/25.reverse-nodes-in-k-group.cpp), [python3](./leetcode/25.reverse-nodes-in-k-group.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-24. Swap Nodes In Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/description/) | [c++](./leetcode/24.swap-nodes-in-pairs.cpp), [python3](./leetcode/24.swap-nodes-in-pairs.py) | Linked List | O\(N\) | O\(1\) | \- | - |

## Hash Table

| Update | Problem(39) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-763. Partition Labels](https://leetcode.com/problems/partition-labels/description/) | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-06 | [Leetcode-141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/) | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/) | [c++](./leetcode/76.minimum-window-substring.cpp), [python3](./leetcode/76.minimum-window-substring.py) | Hash Table | O\(M\) | O\(N\) | Hash \+ TP | - |
| 2024-07 | [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Hash Table | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/) | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Hash Table | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-139. Word Break](https://leetcode.com/problems/word-break/description/) | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Hash Table | O\(MN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-202. Happy Number](https://leetcode.com/problems/happy-number/description/) | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Hash Table | O\(S\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-268. Missing Number](https://leetcode.com/problems/missing-number/description/) | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-448. Find All Numbers Disappeared In An Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/) | [c++](./leetcode/448.find-all-numbers-disappeared-in-an-array.cpp), [python3](./leetcode/448.find-all-numbers-disappeared-in-an-array.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-169. Majority Element](https://leetcode.com/problems/majority-element/description/) | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1. Two Sum](https://leetcode.com/problems/two-sum/description/) | [c++](./leetcode/1.two-sum.cpp), [python3](./leetcode/1.two-sum.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/) | [c++](./leetcode/128.longest-consecutive-sequence.cpp), [python3](./leetcode/128.longest-consecutive-sequence.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-149. Max Points On A Line](https://leetcode.com/problems/max-points-on-a-line/description/) | [c++](./leetcode/149.max-points-on-a-line.cpp), [python3](./leetcode/149.max-points-on-a-line.py) | Hash Table | O\(N^2\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/) | [c++](./leetcode/560.subarray-sum-equals-k.cpp), [python3](./leetcode/560.subarray-sum-equals-k.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/) | [c++](./leetcode/217.contains-duplicate.cpp), [python3](./leetcode/217.contains-duplicate.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-697. Degree Of An Array](https://leetcode.com/problems/degree-of-an-array/description/) | [c++](./leetcode/697.degree-of-an-array.cpp), [python3](./leetcode/697.degree-of-an-array.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/description/) | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-242. Valid Anagram](https://leetcode.com/problems/valid-anagram/description/) | [c++](./leetcode/242.valid-anagram.cpp), [python3](./leetcode/242.valid-anagram.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/) | [c++](./leetcode/205.isomorphic-strings.cpp), [python3](./leetcode/205.isomorphic-strings.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/description/) | [c++](./leetcode/409.longest-palindrome.cpp), [python3](./leetcode/409.longest-palindrome.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/) | [c++](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python3](./leetcode/3.longest-substring-without-repeating-characters.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-160. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1110. Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/description/) | [c++](./leetcode/1110.delete-nodes-and-return-forest.cpp), [python3](./leetcode/1110.delete-nodes-and-return-forest.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-208. Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/description/) | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Hash Table | O\(N\) | O\(L\) | \- | - |
| 2024-08 | [Leetcode-572. Subtree Of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/description/) | [c++](./leetcode/572.subtree-of-another-tree.cpp), [python3](./leetcode/572.subtree-of-another-tree.py) | Hash Table | O\(NM\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-889. Construct Binary Tree From Preorder And Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/) | [c++](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.cpp), [python3](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-106. Construct Binary Tree From Inorder And Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/) | [c++](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.cpp), [python3](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-105. Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/) | [c++](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp), [python3](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-653. Two Sum Iv Input Is A Bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Hash Table | O\(NH\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-380. Insert Delete Getrandom O1](https://leetcode.com/problems/insert-delete-getrandom-o1/description/) | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-432. All Oone Data Structure](https://leetcode.com/problems/all-oone-data-structure/description/) | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-146. Lru Cache](https://leetcode.com/problems/lru-cache/description/) | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/) | [c++](./leetcode/49.group-anagrams.cpp), [python3](./leetcode/49.group-anagrams.py) | Hash Table | O\(NL\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-438. Find All Anagrams In A String](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/) | [c++](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python3](./leetcode/438.find-all-anagrams-in-a-string.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-874. Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/description/) | [c++](./leetcode/874.walking-robot-simulation.cpp), [python3](./leetcode/874.walking-robot-simulation.py) | Hash Table | O\(N\) | O\(K\) | \- | - |
| 2024-09 | [Leetcode-36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/) | [c++](./leetcode/36.valid-sudoku.cpp), [python3](./leetcode/36.valid-sudoku.py) | Hash Table | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-09 | [Leetcode-37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/description/) | [c++](./leetcode/37.sudoku-solver.cpp), [python3](./leetcode/37.sudoku-solver.py) | Hash Table | O\(N^\(N^2\)\) | O\(N\) | \- | - |

## Stack

| Update | Problem(15) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-1249. Minimum Remove To Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/) | [c++](./leetcode/1249.minimum-remove-to-make-valid-parentheses.cpp), [python3](./leetcode/1249.minimum-remove-to-make-valid-parentheses.py) | Stack | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-232. Implement Queue Using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/) | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Stack | O\(\*1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-155. Min Stack](https://leetcode.com/problems/min-stack/description/) | [c++](./leetcode/155.min-stack.cpp), [python3](./leetcode/155.min-stack.py) | Stack | O\(1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/) | [c++](./leetcode/20.valid-parentheses.cpp), [python3](./leetcode/20.valid-parentheses.py) | Stack | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Stack | O\(N\) | O\(H\) | PreOrder | - |
| 2024-08 | [Leetcode-144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python3](./leetcode/144.binary-tree-preorder-traversal.py) | Stack | O\(N\) | O\(H\) | PreOrder | - |
| 2024-08 | [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Stack | O\(1\) | O\(H\) | InOrder | - |
| 2024-08 | [Leetcode-225. Implement Stack Using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/) | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Stack | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/description/) | [c++](./leetcode/227.basic-calculator-ii.cpp), [python3](./leetcode/227.basic-calculator-ii.py) | Stack | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Lintcode-849. Basic Calculator III](https://www.lintcode.com/problem/basic-calculator-iii) | [c++](./lintcode/849.basic-calculator-iii.cpp), [python3](./lintcode/849.basic-calculator-iii.py) | Stack | O\(N\) | O\(1\) | Leetcode\-772 | - |
| 2024-08 | [Leetcode-234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/) | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Stack | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python3](./leetcode/94.binary-tree-inorder-traversal.py) | Stack | O\(N\) | O\(H\) | InOrder | - |
| 2024-08 | [Leetcode-145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python3](./leetcode/145.binary-tree-postorder-traversal.py) | Stack | O\(N\) | O\(H\) | PostOrder | - |
| 2024-08 | [Leetcode-897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/description/) | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Stack | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Lintcode-859. Max Stack](https://www.lintcode.com/problem/max-stack) | [c++](./lintcode/859.max-stack.cpp), [python3](./lintcode/859.max-stack.py) | Stack | \- | O\(N\) | Leetcode\-716 | - |

## Monotonic Stack

| Update | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-769. Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/description/) | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Monotonic Stack | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/) | [c++](./leetcode/739.daily-temperatures.cpp), [python3](./leetcode/739.daily-temperatures.py) | Monotonic Stack | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/description/) | [c++](./leetcode/503.next-greater-element-ii.cpp), [python3](./leetcode/503.next-greater-element-ii.py) | Monotonic Stack | O\(N\) | O\(N\) | \- | - |

## Queue

| Update | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-232. Implement Queue Using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/) | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Queue | O\(\*1\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-225. Implement Stack Using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/) | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Queue | O\(N\) | O\(N\) | \- | - |

## Monotonic Queue

| Update | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/) | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Monotonic Queue | O\(N\) | O\(K\) | \- | - |

## Heap

| Update | Problem(14) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Heap | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| 2024-07 | [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Heap | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| 2024-07 | [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Heap | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Heap | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Heap | O\(NlogK\) | O\(K\) | \- | - |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Heap | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-882. Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/) | [c++](./leetcode/882.reachable-nodes-in-subdivided-graph.cpp), [python3](./leetcode/882.reachable-nodes-in-subdivided-graph.py) | Heap | O\(ElogE\) | O\(V\+E\) | \- | - |
| 2024-08 | [Leetcode-743. Network Delay Time](https://leetcode.com/problems/network-delay-time/description/) | [c++](./leetcode/743.network-delay-time.cpp), [python3](./leetcode/743.network-delay-time.py) | Heap | O\(ElogE\) | O\(E\+V\) | \- | - |
| 2024-08 | [Leetcode-1514. Path With Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/description/) | [c++](./leetcode/1514.path-with-maximum-probability.cpp), [python3](./leetcode/1514.path-with-maximum-probability.py) | Heap | O\(VLogE\) | O\(E\+V\) | \- | - |
| 2024-08 | [Leetcode-787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/) | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Heap | O\(ElogV\) | O\(E\+V\) | \- | - |
| 2024-08 | [Leetcode-1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/description/) | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Heap | O\(NMlogNM\) | O\(NM\) | \- | - |
| 2024-08 | [Leetcode-703. Kth Largest Element In A Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/) | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Heap | O\(logN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/) | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Heap | O\(N\) | O\(K\) | \- | - |
| 2024-09 | [Leetcode-3275. K Th Nearest Obstacle Queries](https://leetcode.com/problems/k-th-nearest-obstacle-queries/description/) | [c++](./leetcode/3275.k-th-nearest-obstacle-queries.cpp), [python3](./leetcode/3275.k-th-nearest-obstacle-queries.py) | Heap | O\(NlogK\) | O\(K\) | \- | - |

## Two Pointers

| Update | Problem(25) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-763. Partition Labels](https://leetcode.com/problems/partition-labels/description/) | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Two Pointers | O\(N\) | O\(N\) | \- | - |
| 2024-06 | [Leetcode-167. Two Sum Ii Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python3](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/) | [c++](./leetcode/88.merge-sorted-array.cpp), [python3](./leetcode/88.merge-sorted-array.py) | Two Pointers | O\(M \+ N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/) | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/) | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-633. Sum Of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/) | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/) | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python3](./leetcode/680.valid-palindrome-ii.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-524. Longest Word In Dictionary Through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/) | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python3](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | Two Pointers | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| 2024-06 | [Lintcode-386. Longest Substring With At Most K Distinct Characters](https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters) | [c++](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.cpp), [python3](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.py) | Two Pointers | O\(N\) | O\(k\) | Leetcode\-340 | - |
| 2024-07 | [Leetcode-75. Sort Colors](https://leetcode.com/problems/sort-colors/description/) | [c++](./leetcode/75.sort-colors.cpp), [python3](./leetcode/75.sort-colors.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-202. Happy Number](https://leetcode.com/problems/happy-number/description/) | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Two Pointers | O\(S\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Two Pointers | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-287. Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/) | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-870. Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/description/) | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Two Pointers | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/) | [c++](./leetcode/647.palindromic-substrings.cpp), [python3](./leetcode/647.palindromic-substrings.py) | Two Pointers | O\(N^2\) | O\(1\) | DP Slow | - |
| 2024-08 | [Leetcode-696. Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/description/) | [c++](./leetcode/696.count-binary-substrings.cpp), [python3](./leetcode/696.count-binary-substrings.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-28. Find The Index Of The First Occurrence In A String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/) | [c++](./leetcode/28.find-the-index-of-the-first-occurrence-in-a-string.cpp), [python3](./leetcode/28.find-the-index-of-the-first-occurrence-in-a-string.py) | Two Pointers | O\(M \+ N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/) | [c++](./leetcode/5.longest-palindromic-substring.cpp), [python3](./leetcode/5.longest-palindromic-substring.py) | Two Pointers | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-160. Intersection Of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/) | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-19. Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/) | [c++](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python3](./leetcode/19.remove-nth-node-from-end-of-list.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-148. Sort List](https://leetcode.com/problems/sort-list/description/) | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Two Pointers | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-653. Two Sum Iv Input Is A Bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Two Pointers | O\(NH\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-15. 3Sum](https://leetcode.com/problems/3sum/description/) | [c++](./leetcode/15.3sum.cpp), [python3](./leetcode/15.3sum.py) | Two Pointers | O\(N^2\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-18. 4Sum](https://leetcode.com/problems/4sum/description/) | [c++](./leetcode/18.4sum.cpp), [python3](./leetcode/18.4sum.py) | Two Pointers | O\(N^3\) | O\(1\) | \- | - |

## Sliding Window

| Update | Problem(6) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Sliding Window | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| 2024-06 | [Leetcode-76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/) | [c++](./leetcode/76.minimum-window-substring.cpp), [python3](./leetcode/76.minimum-window-substring.py) | Sliding Window | O\(M\) | O\(N\) | Hash \+ TP | - |
| 2024-08 | [Leetcode-594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/description/) | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Sliding Window | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/) | [c++](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python3](./leetcode/3.longest-substring-without-repeating-characters.py) | Sliding Window | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/) | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Sliding Window | O\(N\) | O\(K\) | \- | - |
| 2024-09 | [Leetcode-438. Find All Anagrams In A String](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/) | [c++](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python3](./leetcode/438.find-all-anagrams-in-a-string.py) | Sliding Window | O\(N\) | O\(1\) | \- | - |

## Sorting

| Update | Problem(23) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/) | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Sorting | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| 2024-06 | [Lintcode-39. Recover Rotated Sorted Array](https://www.lintcode.com/problem/recover-rotated-sorted-array) | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python3](./lintcode/39.recover-rotated-sorted-array.py) | Sorting | O\(N\) | O\(1\) | Rotated | - |
| 2024-06 | [Leetcode-452. Minimum Number Of Arrows To Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/) | [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp), [python3](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py) | Sorting | O\(N\*logN\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/) | [c++](./leetcode/88.merge-sorted-array.cpp), [python3](./leetcode/88.merge-sorted-array.py) | Sorting | O\(M \+ N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-524. Longest Word In Dictionary Through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/) | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python3](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | Sorting | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Sorting | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| 2024-07 | [Leetcode-75. Sort Colors](https://leetcode.com/problems/sort-colors/description/) | [c++](./leetcode/75.sort-colors.cpp), [python3](./leetcode/75.sort-colors.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-646. Maximum Length Of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/) | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Sorting | O\(NlogN\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-462. Minimum Moves To Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/) | [c++](./leetcode/462.minimum-moves-to-equal-array-elements-ii.cpp), [python3](./leetcode/462.minimum-moves-to-equal-array-elements-ii.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-268. Missing Number](https://leetcode.com/problems/missing-number/description/) | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-769. Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/description/) | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-406. Queue Reconstruction By Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/) | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-435. Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Sorting | O\(NlogK\) | O\(K\) | \- | - |
| 2024-08 | [Leetcode-217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/) | [c++](./leetcode/217.contains-duplicate.cpp), [python3](./leetcode/217.contains-duplicate.py) | Sorting | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-870. Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/description/) | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Sorting | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-242. Valid Anagram](https://leetcode.com/problems/valid-anagram/description/) | [c++](./leetcode/242.valid-anagram.cpp), [python3](./leetcode/242.valid-anagram.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-148. Sort List](https://leetcode.com/problems/sort-list/description/) | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Sorting | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-15. 3Sum](https://leetcode.com/problems/3sum/description/) | [c++](./leetcode/15.3sum.cpp), [python3](./leetcode/15.3sum.py) | Sorting | O\(N^2\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/) | [c++](./leetcode/49.group-anagrams.cpp), [python3](./leetcode/49.group-anagrams.py) | Sorting | O\(NL\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-18. 4Sum](https://leetcode.com/problems/4sum/description/) | [c++](./leetcode/18.4sum.cpp), [python3](./leetcode/18.4sum.py) | Sorting | O\(N^3\) | O\(1\) | \- | - |
| 2024-09 | [Leetcode-3281. Maximize Score Of Numbers In Ranges](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/) | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Sorting | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |

## Counting

| Update | Problem(5) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-2529. Maximum Count Of Positive Integer And Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/) | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python3](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | Counting | O\(logN\) | O\(1\) | std::lower\_bound | - |
| 2024-07 | [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Counting | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/) | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Counting | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-169. Majority Element](https://leetcode.com/problems/majority-element/description/) | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Counting | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/description/) | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Counting | O\(N\) | O\(N\) | \- | - |

## Quickselect

| Update | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Quickselect | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| 2024-07 | [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Quickselect | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |

## Divide and Conquer

| Update | Problem(18) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-4. Median Of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/) | [c++](./leetcode/4.median-of-two-sorted-arrays.cpp), [python3](./leetcode/4.median-of-two-sorted-arrays.py) | Divide and Conquer | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-215. Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Divide and Conquer | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| 2024-07 | [Leetcode-347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Divide and Conquer | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/) | [c++](./leetcode/53.maximum-subarray.cpp), [python3](./leetcode/53.maximum-subarray.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-932. Beautiful Array](https://leetcode.com/problems/beautiful-array/description/) | [c++](./leetcode/932.beautiful-array.cpp), [python3](./leetcode/932.beautiful-array.py) | Divide and Conquer | O\(N\) | O\(N\) | dp | - |
| 2024-07 | [Leetcode-190. Reverse Bits](https://leetcode.com/problems/reverse-bits/description/) | [c++](./leetcode/190.reverse-bits.cpp), [python3](./leetcode/190.reverse-bits.py) | Divide and Conquer | O\(1\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-240. Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/) | [c++](./leetcode/240.search-a-2d-matrix-ii.cpp), [python3](./leetcode/240.search-a-2d-matrix-ii.py) | Divide and Conquer | O\(M \+ N\) | O\(1\) | Matrix | - |
| 2024-08 | [Leetcode-169. Majority Element](https://leetcode.com/problems/majority-element/description/) | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Divide and Conquer | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Divide and Conquer | O\(N\) | O\(H\) | InOrder | - |
| 2024-08 | [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Divide and Conquer | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |
| 2024-08 | [Leetcode-23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/) | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Divide and Conquer | O\(NlogK\) | O\(K\) | \- | - |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Divide and Conquer | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-148. Sort List](https://leetcode.com/problems/sort-list/description/) | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Divide and Conquer | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-889. Construct Binary Tree From Preorder And Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/) | [c++](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.cpp), [python3](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-106. Construct Binary Tree From Inorder And Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/) | [c++](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.cpp), [python3](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-105. Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/) | [c++](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp), [python3](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-109. Convert Sorted List To Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/) | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Divide and Conquer | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-09 | [Leetcode-191. Number Of 1 Bits](https://leetcode.com/problems/number-of-1-bits/description/) | [c++](./leetcode/191.number-of-1-bits.cpp), [python3](./leetcode/191.number-of-1-bits.py) | Divide and Conquer | O\(1\) | O\(1\) | \- | - |

## Breadth-First Search

| Update | Problem(25) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/) | [c++](./leetcode/102.binary-tree-level-order-traversal.cpp), [python3](./leetcode/102.binary-tree-level-order-traversal.py) | Breadth-First Search | O\(N\) | O\(Width\) | Level | - |
| 2024-06 | [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Breadth-First Search | O\(N\) | O\(N\) | Serialization | - |
| 2024-07 | [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/) | [c++](./leetcode/417.pacific-atlantic-water-flow.cpp), [python3](./leetcode/417.pacific-atlantic-water-flow.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/description/) | [c++](./leetcode/934.shortest-bridge.cpp), [python3](./leetcode/934.shortest-bridge.py) | Breadth-First Search | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Leetcode-126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/) | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Breadth-First Search | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Breadth-First Search | O\(MN\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-542. 01 Matrix](https://leetcode.com/problems/01-matrix/description/) | [c++](./leetcode/542.01-matrix.cpp), [python3](./leetcode/542.01-matrix.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/) | [c++](./leetcode/279.perfect-squares.cpp), [python3](./leetcode/279.perfect-squares.py) | Breadth-First Search | O\(n^\{3/2\}\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-322. Coin Change](https://leetcode.com/problems/coin-change/description/) | [c++](./leetcode/322.coin-change.cpp), [python3](./leetcode/322.coin-change.py) | Breadth-First Search | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| 2024-08 | [Leetcode-104. Maximum Depth Of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python3](./leetcode/104.maximum-depth-of-binary-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | Recursion | - |
| 2024-08 | [Leetcode-101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/) | [c++](./leetcode/101.symmetric-tree.cpp), [python3](./leetcode/101.symmetric-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-637. Average Of Levels In Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/description/) | [c++](./leetcode/637.average-of-levels-in-binary-tree.cpp), [python3](./leetcode/637.average-of-levels-in-binary-tree.py) | Breadth-First Search | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/) | [c++](./leetcode/226.invert-binary-tree.cpp), [python3](./leetcode/226.invert-binary-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/description/) | [c++](./leetcode/617.merge-two-binary-trees.cpp), [python3](./leetcode/617.merge-two-binary-trees.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-404. Sum Of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/) | [c++](./leetcode/404.sum-of-left-leaves.cpp), [python3](./leetcode/404.sum-of-left-leaves.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/) | [c++](./leetcode/513.find-bottom-left-tree-value.cpp), [python3](./leetcode/513.find-bottom-left-tree-value.py) | Breadth-First Search | O\(N\) | O\(W\) | \- | - |
| 2024-08 | [Leetcode-530. Minimum Absolute Difference In Bst](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/) | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-653. Two Sum Iv Input Is A Bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Breadth-First Search | O\(NH\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-785. Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/description/) | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Breadth-First Search | O\(E\+V\) | O\(W | \- | - |
| 2024-08 | [Leetcode-684. Redundant Connection](https://leetcode.com/problems/redundant-connection/description/) | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Breadth-First Search | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/description/) | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Breadth-First Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| 2024-09 | [Leetcode-111. Minimum Depth Of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/) | [c++](./leetcode/111.minimum-depth-of-binary-tree.cpp), [python3](./leetcode/111.minimum-depth-of-binary-tree.py) | Breadth-First Search | O\(N\) | O\(W\) | \- | - |
| 2024-09 | [Leetcode-200. Number Of Islands](https://leetcode.com/problems/number-of-islands/description/) | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-09 | [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Breadth-First Search | O\(N^2\) | O\(N\) | \- | - |

## Depth-First Search

| Update | Problem(38) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-297. Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/) | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Depth-First Search | O\(N\) | O\(N\) | Serialization | - |
| 2024-07 | [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/) | [c++](./leetcode/417.pacific-atlantic-water-flow.cpp), [python3](./leetcode/417.pacific-atlantic-water-flow.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/description/) | [c++](./leetcode/934.shortest-bridge.cpp), [python3](./leetcode/934.shortest-bridge.py) | Depth-First Search | O\(N^2\) | O\(N^2\) | \- | - |
| 2024-07 | [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Depth-First Search | O\(MN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) | [c++](./leetcode/98.validate-binary-search-tree.cpp), [python3](./leetcode/98.validate-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | BST | - |
| 2024-08 | [Leetcode-114. Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/) | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Depth-First Search | O\(N\) | O\(H\) | PreOrder | - |
| 2024-08 | [Leetcode-144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/) | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python3](./leetcode/144.binary-tree-preorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | PreOrder | - |
| 2024-08 | [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | InOrder | - |
| 2024-08 | [Leetcode-332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/description/) | [c++](./leetcode/332.reconstruct-itinerary.cpp), [python3](./leetcode/332.reconstruct-itinerary.py) | Depth-First Search | O\(ElogE\) | O\(E\+V\) | Containers | - |
| 2024-08 | [Leetcode-104. Maximum Depth Of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python3](./leetcode/104.maximum-depth-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| 2024-08 | [Leetcode-543. Diameter Of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/) | [c++](./leetcode/543.diameter-of-binary-tree.cpp), [python3](./leetcode/543.diameter-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/description/) | [c++](./leetcode/110.balanced-binary-tree.cpp), [python3](./leetcode/110.balanced-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| 2024-08 | [Leetcode-437. Path Sum III](https://leetcode.com/problems/path-sum-iii/description/) | [c++](./leetcode/437.path-sum-iii.cpp), [python3](./leetcode/437.path-sum-iii.py) | Depth-First Search | O\(N^2 | O\(H\) | \- | - |
| 2024-08 | [Leetcode-101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/description/) | [c++](./leetcode/101.symmetric-tree.cpp), [python3](./leetcode/101.symmetric-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-1110. Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/description/) | [c++](./leetcode/1110.delete-nodes-and-return-forest.cpp), [python3](./leetcode/1110.delete-nodes-and-return-forest.py) | Depth-First Search | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-637. Average Of Levels In Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/description/) | [c++](./leetcode/637.average-of-levels-in-binary-tree.cpp), [python3](./leetcode/637.average-of-levels-in-binary-tree.py) | Depth-First Search | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/) | [c++](./leetcode/99.recover-binary-search-tree.cpp), [python3](./leetcode/99.recover-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-669. Trim A Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/description/) | [c++](./leetcode/669.trim-a-binary-search-tree.cpp), [python3](./leetcode/669.trim-a-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/) | [c++](./leetcode/226.invert-binary-tree.cpp), [python3](./leetcode/226.invert-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/description/) | [c++](./leetcode/617.merge-two-binary-trees.cpp), [python3](./leetcode/617.merge-two-binary-trees.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-572. Subtree Of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/description/) | [c++](./leetcode/572.subtree-of-another-tree.cpp), [python3](./leetcode/572.subtree-of-another-tree.py) | Depth-First Search | O\(NM\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-404. Sum Of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/) | [c++](./leetcode/404.sum-of-left-leaves.cpp), [python3](./leetcode/404.sum-of-left-leaves.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/) | [c++](./leetcode/513.find-bottom-left-tree-value.cpp), [python3](./leetcode/513.find-bottom-left-tree-value.py) | Depth-First Search | O\(N\) | O\(W\) | \- | - |
| 2024-08 | [Leetcode-538. Convert Bst To Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/description/) | [c++](./leetcode/538.convert-bst-to-greater-tree.cpp), [python3](./leetcode/538.convert-bst-to-greater-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-530. Minimum Absolute Difference In Bst](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/) | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python3](./leetcode/94.binary-tree-inorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | InOrder | - |
| 2024-08 | [Leetcode-145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/) | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python3](./leetcode/145.binary-tree-postorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | PostOrder | - |
| 2024-08 | [Leetcode-236. Lowest Common Ancestor Of A Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/) | [c++](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp), [python3](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| 2024-08 | [Leetcode-235. Lowest Common Ancestor Of A Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/) | [c++](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.cpp), [python3](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/description/) | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-653. Two Sum Iv Input Is A Bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Depth-First Search | O\(NH\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-785. Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/description/) | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Depth-First Search | O\(E\+V\) | O\(W | \- | - |
| 2024-08 | [Leetcode-684. Redundant Connection](https://leetcode.com/problems/redundant-connection/description/) | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Depth-First Search | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/description/) | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Depth-First Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| 2024-09 | [Leetcode-111. Minimum Depth Of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/) | [c++](./leetcode/111.minimum-depth-of-binary-tree.cpp), [python3](./leetcode/111.minimum-depth-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(W\) | \- | - |
| 2024-09 | [Leetcode-200. Number Of Islands](https://leetcode.com/problems/number-of-islands/description/) | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| 2024-09 | [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Depth-First Search | O\(N^2\) | O\(N\) | \- | - |

## Topological Sort

| Update | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/description/) | [c++](./leetcode/310.minimum-height-trees.cpp), [python3](./leetcode/310.minimum-height-trees.py) | Topological Sort | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/description/) | [c++](./leetcode/210.course-schedule-ii.cpp), [python3](./leetcode/210.course-schedule-ii.py) | Topological Sort | O\(E\+V\) | O\(E\+V\) | \- | - |

## Shortest Path

| Update | Problem(4) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-882. Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/) | [c++](./leetcode/882.reachable-nodes-in-subdivided-graph.cpp), [python3](./leetcode/882.reachable-nodes-in-subdivided-graph.py) | Shortest Path | O\(ElogE\) | O\(V\+E\) | \- | - |
| 2024-08 | [Leetcode-743. Network Delay Time](https://leetcode.com/problems/network-delay-time/description/) | [c++](./leetcode/743.network-delay-time.cpp), [python3](./leetcode/743.network-delay-time.py) | Shortest Path | O\(ElogE\) | O\(E\+V\) | \- | - |
| 2024-08 | [Leetcode-1514. Path With Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/description/) | [c++](./leetcode/1514.path-with-maximum-probability.cpp), [python3](./leetcode/1514.path-with-maximum-probability.py) | Shortest Path | O\(VLogE\) | O\(E\+V\) | \- | - |
| 2024-08 | [Leetcode-787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/) | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Shortest Path | O\(ElogV\) | O\(E\+V\) | \- | - |

## Backtracking

| Update | Problem(13) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-46. Permutations](https://leetcode.com/problems/permutations/description/) | [c++](./leetcode/46.permutations.cpp), [python3](./leetcode/46.permutations.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-77. Combinations](https://leetcode.com/problems/combinations/description/) | [c++](./leetcode/77.combinations.cpp), [python3](./leetcode/77.combinations.py) | Backtracking | O\(k \* C\(n, k\)\)  | O\(K\) | \- | - |
| 2024-07 | [Leetcode-79. Word Search](https://leetcode.com/problems/word-search/description/) | [c++](./leetcode/79.word-search.cpp), [python3](./leetcode/79.word-search.py) | Backtracking | O\(MN\*4^L\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-51. N Queens](https://leetcode.com/problems/n-queens/description/) | [c++](./leetcode/51.n-queens.cpp), [python3](./leetcode/51.n-queens.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/description/) | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Backtracking | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-47. Permutations II](https://leetcode.com/problems/permutations-ii/description/) | [c++](./leetcode/47.permutations-ii.cpp), [python3](./leetcode/47.permutations-ii.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/) | [c++](./leetcode/40.combination-sum-ii.cpp), [python3](./leetcode/40.combination-sum-ii.py) | Backtracking | O\(2^N\) | O\(N\) | \- | - |
| 2024-07 | [Leetcode-494. Target Sum](https://leetcode.com/problems/target-sum/description/) | [c++](./leetcode/494.target-sum.cpp), [python3](./leetcode/494.target-sum.py) | Backtracking | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |
| 2024-08 | [Leetcode-257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/) | [c++](./leetcode/257.binary-tree-paths.cpp), [python3](./leetcode/257.binary-tree-paths.py) | Backtracking | O\(N\) | O\(H\) | \- | - |
| 2024-09 | [Leetcode-22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/) | [c++](./leetcode/22.generate-parentheses.cpp), [python3](./leetcode/22.generate-parentheses.py) | Backtracking | O\(2^N\) | O\(N\) | Catalan Number | - |
| 2024-09 | [Leetcode-37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/description/) | [c++](./leetcode/37.sudoku-solver.cpp), [python3](./leetcode/37.sudoku-solver.py) | Backtracking | O\(N^\(N^2\)\) | O\(N\) | \- | - |
| 2024-09 | [Leetcode-212. Word Search II](https://leetcode.com/problems/word-search-ii/description/) | [c++](./leetcode/212.word-search-ii.cpp), [python3](./leetcode/212.word-search-ii.py) | Backtracking | O\(NM\*4^L\) | O\(MN \+ KL\) | \- | - |
| 2024-09 | [Leetcode-52. N Queens II](https://leetcode.com/problems/n-queens-ii/description/) | [c++](./leetcode/52.n-queens-ii.cpp), [python3](./leetcode/52.n-queens-ii.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |

## Line Sweep

| Update | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Line Sweep | O\(NlogN\) | O\(N\) | \- | - |

## Ordered Set

| Update | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Ordered Set | O\(NlogN\) | O\(N\) | \- | - |

## Binary Search Tree

| Update | Problem(16) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/) | [c++](./leetcode/98.validate-binary-search-tree.cpp), [python3](./leetcode/98.validate-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | BST | - |
| 2024-08 | [Leetcode-173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/) | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Binary Search Tree | O\(1\) | O\(H\) | InOrder | - |
| 2024-08 | [Lintcode-11. Search Range In Binary Search Tree](https://www.lintcode.com/problem/search-range-in-binary-search-tree) | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | InOrder | - |
| 2024-08 | [Lintcode-1534. Convert Binary Search Tree To Sorted Doubly Linked List](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list) | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Binary Search Tree | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |
| 2024-08 | [Leetcode-701. Insert Into A Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/) | [c++](./leetcode/701.insert-into-a-binary-search-tree.cpp), [python3](./leetcode/701.insert-into-a-binary-search-tree.py) | Binary Search Tree | O\(H\) | O\(H\) | Insert | - |
| 2024-08 | [Lintcode-448. Inorder Successor In Bst](https://www.lintcode.com/problem/inorder-successor-in-bst) | [c++](./lintcode/448.inorder-successor-in-bst.cpp), [python3](./lintcode/448.inorder-successor-in-bst.py) | Binary Search Tree | O\(H\) | O\(1\) | Successor \| Leetcode\-285 | - |
| 2024-08 | [Leetcode-99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/description/) | [c++](./leetcode/99.recover-binary-search-tree.cpp), [python3](./leetcode/99.recover-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-669. Trim A Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/description/) | [c++](./leetcode/669.trim-a-binary-search-tree.cpp), [python3](./leetcode/669.trim-a-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-538. Convert Bst To Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/description/) | [c++](./leetcode/538.convert-bst-to-greater-tree.cpp), [python3](./leetcode/538.convert-bst-to-greater-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-530. Minimum Absolute Difference In Bst](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/) | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-235. Lowest Common Ancestor Of A Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/) | [c++](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.cpp), [python3](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-109. Convert Sorted List To Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/) | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Binary Search Tree | O\(NlogN\) | O\(logN\) | \- | - |
| 2024-08 | [Leetcode-897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/description/) | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-653. Two Sum Iv Input Is A Bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/) | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Binary Search Tree | O\(NH\) | O\(H\) | \- | - |
| 2024-08 | [Leetcode-450. Delete Node In A Bst](https://leetcode.com/problems/delete-node-in-a-bst/description/) | [c++](./leetcode/450.delete-node-in-a-bst.cpp), [python3](./leetcode/450.delete-node-in-a-bst.py) | Binary Search Tree | O\(H\) | O\(H\) | Delete | - |
| 2024-08 | [Leetcode-703. Kth Largest Element In A Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/) | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Binary Search Tree | O\(logN\) | O\(N\) | \- | - |

## Binary Indexed Tree

| Update | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-406. Queue Reconstruction By Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/) | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Binary Indexed Tree | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Binary Indexed Tree | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-307. Range Sum Query Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/) | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Binary Indexed Tree | O\(logN\) | O\(N\) | \- | - |

## Segment Tree

| Update | Problem(7) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-08 | [Leetcode-406. Queue Reconstruction By Height](https://leetcode.com/problems/queue-reconstruction-by-height/description/) | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Segment Tree | O\(NlogN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/) | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Segment Tree | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Lintcode-201. Segment Tree Build](https://www.lintcode.com/problem/segment-tree-build) | [c++](./lintcode/201.segment-tree-build.cpp), [python3](./lintcode/201.segment-tree-build.py) | Segment Tree | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Lintcode-439. Segment Tree Build II](https://www.lintcode.com/problem/segment-tree-build-ii) | [c++](./lintcode/439.segment-tree-build-ii.cpp), [python3](./lintcode/439.segment-tree-build-ii.py) | Segment Tree | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Lintcode-203. Segment Tree Modify](https://www.lintcode.com/problem/segment-tree-modify) | [c++](./lintcode/203.segment-tree-modify.cpp), [python3](./lintcode/203.segment-tree-modify.py) | Segment Tree | O\(logN\) | O\(1\) | \- | - |
| 2024-08 | [Lintcode-205. Interval Minimum Number](https://www.lintcode.com/problem/interval-minimum-number) | [c++](./lintcode/205.interval-minimum-number.cpp), [python3](./lintcode/205.interval-minimum-number.py) | Segment Tree | O\(NlogN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-307. Range Sum Query Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/) | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Segment Tree | O\(logN\) | O\(N\) | \- | - |

## Union Find

| Update | Problem(9) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-695. Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/) | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Union Find | O\(MN\) | O\(MN\) | \- | - |
| 2024-07 | [Leetcode-130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/) | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Union Find | O\(MN\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/) | [c++](./leetcode/128.longest-consecutive-sequence.cpp), [python3](./leetcode/128.longest-consecutive-sequence.py) | Union Find | O\(N\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-785. Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/description/) | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Union Find | O\(E\+V\) | O\(W | \- | - |
| 2024-08 | [Lintcode-3672. Connecting Cities With Minimum Cost](https://www.lintcode.com/problem/connecting-cities-with-minimum-cost) | [c++](./lintcode/3672.connecting-cities-with-minimum-cost.cpp), [python3](./lintcode/3672.connecting-cities-with-minimum-cost.py) | Union Find | O\(ElogE\) | O\(E\+V\) | Leetcode\-1135 | - |
| 2024-08 | [Leetcode-684. Redundant Connection](https://leetcode.com/problems/redundant-connection/description/) | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Union Find | O\(N\) | O\(1\) | \- | - |
| 2024-08 | [Leetcode-1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/description/) | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Union Find | O\(NMlogNM\) | O\(NM\) | \- | - |
| 2024-09 | [Leetcode-200. Number Of Islands](https://leetcode.com/problems/number-of-islands/description/) | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Union Find | O\(MN\) | O\(MN\) | \- | - |
| 2024-09 | [Leetcode-547. Number Of Provinces](https://leetcode.com/problems/number-of-provinces/description/) | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Union Find | O\(N^2\) | O\(N\) | \- | - |

## Trie

| Update | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-07 | [Leetcode-139. Word Break](https://leetcode.com/problems/word-break/description/) | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Trie | O\(MN\) | O\(N\) | \- | - |
| 2024-08 | [Leetcode-208. Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/description/) | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Trie | O\(N\) | O\(L\) | \- | - |
| 2024-09 | [Leetcode-212. Word Search II](https://leetcode.com/problems/word-search-ii/description/) | [c++](./leetcode/212.word-search-ii.cpp), [python3](./leetcode/212.word-search-ii.py) | Trie | O\(NM\*4^L\) | O\(MN \+ KL\) | \- | - |

## Array

| Update | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Leetcode-2210. Count Hills And Valleys In An Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/) | [c++](./leetcode/2210.count-hills-and-valleys-in-an-array.cpp), [python3](./leetcode/2210.count-hills-and-valleys-in-an-array.py) | Array | O\(N\) | O\(1\) | \- | - |
| 2024-06 | [Leetcode-665. Non Decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/) | [c++](./leetcode/665.non-decreasing-array.cpp), [python3](./leetcode/665.non-decreasing-array.py) | Array | O\(N\) | O\(1\) | \- | - |
| 2024-07 | [Leetcode-238. Product Of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/) | [c++](./leetcode/238.product-of-array-except-self.cpp), [python3](./leetcode/238.product-of-array-except-self.py) | Array | O\(N\) | O\(1\) | \- | - |

## String

| Update | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2024-06 | [Lintcode-1790. Rotate String II](https://www.lintcode.com/problem/rotate-string-ii) | [c++](./lintcode/1790.rotate-string-ii.cpp), [python3](./lintcode/1790.rotate-string-ii.py) | String | O\(N\) | O\(N\) | Simulation | - |

## Other

| Update | Problem(181) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 2023-09 | [Leetcode-2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/) | [c++](./leetcode/2.add-two-numbers.cpp), [python3](./leetcode/2.add-two-numbers.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-7. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/) | [c++](./leetcode/7.reverse-integer.cpp), [python3](./leetcode/7.reverse-integer.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-8. String To Integer Atoi](https://leetcode.com/problems/string-to-integer-atoi/description/) | [c++](./leetcode/8.string-to-integer-atoi.cpp), [python3](./leetcode/8.string-to-integer-atoi.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/) | [c++](./leetcode/9.palindrome-number.cpp), [python3](./leetcode/9.palindrome-number.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/) | [python3](./leetcode/11.container-with-most-water.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-12. Integer To Roman](https://leetcode.com/problems/integer-to-roman/description/) | [c++](./leetcode/12.integer-to-roman.cpp), [python3](./leetcode/12.integer-to-roman.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-13. Roman To Integer](https://leetcode.com/problems/roman-to-integer/description/) | [c++](./leetcode/13.roman-to-integer.cpp), [python3](./leetcode/13.roman-to-integer.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/) | [c++](./leetcode/14.longest-common-prefix.cpp), [python3](./leetcode/14.longest-common-prefix.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/) | [c++](./leetcode/16.3sum-closest.cpp), [python3](./leetcode/16.3sum-closest.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-17. Letter Combinations Of A Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/) | [c++](./leetcode/17.letter-combinations-of-a-phone-number.cpp), [python3](./leetcode/17.letter-combinations-of-a-phone-number.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-26. Remove Duplicates From Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | [c++](./leetcode/26.remove-duplicates-from-sorted-array.cpp), [python3](./leetcode/26.remove-duplicates-from-sorted-array.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-27. Remove Element](https://leetcode.com/problems/remove-element/description/) | [c++](./leetcode/27.remove-element.cpp), [python3](./leetcode/27.remove-element.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/) | [c++](./leetcode/29.divide-two-integers.cpp), [python3](./leetcode/29.divide-two-integers.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-30. Substring With Concatenation Of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/) | [c++](./leetcode/30.substring-with-concatenation-of-all-words.cpp), [python3](./leetcode/30.substring-with-concatenation-of-all-words.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-31. Next Permutation](https://leetcode.com/problems/next-permutation/description/) | [c++](./leetcode/31.next-permutation.cpp), [python3](./leetcode/31.next-permutation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-38. Count And Say](https://leetcode.com/problems/count-and-say/description/) | [python3](./leetcode/38.count-and-say.py) | Other | \- | \- | Each term of the sequence of integers will be represented as a | - |
| 2023-09 | [Leetcode-39. Combination Sum](https://leetcode.com/problems/combination-sum/description/) | [c++](./leetcode/39.combination-sum.cpp), [python3](./leetcode/39.combination-sum.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/) | [python3](./leetcode/41.first-missing-positive.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/) | [c++](./leetcode/42.trapping-rain-water.cpp), [python3](./leetcode/42.trapping-rain-water.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-43. Multiply Strings](https://leetcode.com/problems/multiply-strings/description/) | [c++](./leetcode/43.multiply-strings.cpp), [python3](./leetcode/43.multiply-strings.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/) | [c++](./leetcode/44.wildcard-matching.cpp), [python3](./leetcode/44.wildcard-matching.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/) | [c++](./leetcode/45.jump-game-ii.cpp), [python3](./leetcode/45.jump-game-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/description/) | [c++](./leetcode/54.spiral-matrix.cpp), [python3](./leetcode/54.spiral-matrix.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-55. Jump Game](https://leetcode.com/problems/jump-game/description/) | [c++](./leetcode/55.jump-game.cpp), [python3](./leetcode/55.jump-game.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | [c++](./leetcode/56.merge-intervals.cpp), [python3](./leetcode/56.merge-intervals.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-57. Insert Interval](https://leetcode.com/problems/insert-interval/description/) | [c++](./leetcode/57.insert-interval.cpp), [python3](./leetcode/57.insert-interval.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-61. Rotate List](https://leetcode.com/problems/rotate-list/description/) | [python3](./leetcode/61.rotate-list.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-62. Unique Paths](https://leetcode.com/problems/unique-paths/description/) | [c++](./leetcode/62.unique-paths.cpp), [python3](./leetcode/62.unique-paths.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/description/) | [c++](./leetcode/63.unique-paths-ii.cpp), [python3](./leetcode/63.unique-paths-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-66. Plus One](https://leetcode.com/problems/plus-one/description/) | [c++](./leetcode/66.plus-one.cpp), [python3](./leetcode/66.plus-one.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-68. Text Justification](https://leetcode.com/problems/text-justification/description/) | [python3](./leetcode/68.text-justification.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-78. Subsets](https://leetcode.com/problems/subsets/description/) | [c++](./leetcode/78.subsets.cpp), [python3](./leetcode/78.subsets.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-84. Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/) | [c++](./leetcode/84.largest-rectangle-in-histogram.cpp), [python3](./leetcode/84.largest-rectangle-in-histogram.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/description/) | [c++](./leetcode/85.maximal-rectangle.cpp), [python3](./leetcode/85.maximal-rectangle.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-86. Partition List](https://leetcode.com/problems/partition-list/description/) | [c++](./leetcode/86.partition-list.cpp), [python3](./leetcode/86.partition-list.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-87. Scramble String](https://leetcode.com/problems/scramble-string/description/) | [c++](./leetcode/87.scramble-string.cpp), [python3](./leetcode/87.scramble-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-90. Subsets II](https://leetcode.com/problems/subsets-ii/description/) | [c++](./leetcode/90.subsets-ii.cpp), [python3](./leetcode/90.subsets-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/) | [c++](./leetcode/92.reverse-linked-list-ii.cpp), [python3](./leetcode/92.reverse-linked-list-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-97. Interleaving String](https://leetcode.com/problems/interleaving-string/description/) | [c++](./leetcode/97.interleaving-string.cpp), [python3](./leetcode/97.interleaving-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) | [c++](./leetcode/103.binary-tree-zigzag-level-order-traversal.cpp), [python3](./leetcode/103.binary-tree-zigzag-level-order-traversal.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/) | [c++](./leetcode/107.binary-tree-level-order-traversal-ii.cpp), [python3](./leetcode/107.binary-tree-level-order-traversal-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/) | [c++](./leetcode/115.distinct-subsequences.cpp), [python3](./leetcode/115.distinct-subsequences.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-118. Pascals Triangle](https://leetcode.com/problems/pascals-triangle/description/) | [c++](./leetcode/118.pascals-triangle.cpp), [python3](./leetcode/118.pascals-triangle.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-119. Pascals Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/) | [c++](./leetcode/119.pascals-triangle-ii.cpp), [python3](./leetcode/119.pascals-triangle-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/) | [c++](./leetcode/125.valid-palindrome.cpp), [python3](./leetcode/125.valid-palindrome.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-127. Word Ladder](https://leetcode.com/problems/word-ladder/description/) | [c++](./leetcode/127.word-ladder.cpp), [python3](./leetcode/127.word-ladder.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/) | [c++](./leetcode/131.palindrome-partitioning.cpp), [python3](./leetcode/131.palindrome-partitioning.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-132. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/description/) | [c++](./leetcode/132.palindrome-partitioning-ii.cpp), [python3](./leetcode/132.palindrome-partitioning-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-133. Clone Graph](https://leetcode.com/problems/clone-graph/description/) | [c++](./leetcode/133.clone-graph.cpp), [python3](./leetcode/133.clone-graph.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-138. Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/description/) | [python3](./leetcode/138.copy-list-with-random-pointer.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-143. Reorder List](https://leetcode.com/problems/reorder-list/description/) | [python3](./leetcode/143.reorder-list.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-156. Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/description/) | [c++](./leetcode/156.binary-tree-upside-down.cpp), [python3](./leetcode/156.binary-tree-upside-down.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-157. Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/description/) | [c++](./leetcode/157.read-n-characters-given-read4.cpp), [python3](./leetcode/157.read-n-characters-given-read4.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-159. Longest Substring With At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/) | [c++](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.cpp), [python3](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-161. One Edit Distance](https://leetcode.com/problems/one-edit-distance/description/) | [c++](./leetcode/161.one-edit-distance.cpp), [python3](./leetcode/161.one-edit-distance.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-163. Missing Ranges](https://leetcode.com/problems/missing-ranges/description/) | [c++](./leetcode/163.missing-ranges.cpp), [python3](./leetcode/163.missing-ranges.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-170. Two Sum Iii Data Structure Design](https://leetcode.com/problems/two-sum-iii-data-structure-design/description/) | [c++](./leetcode/170.two-sum-iii-data-structure-design.cpp), [python3](./leetcode/170.two-sum-iii-data-structure-design.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/) | [sql](./leetcode/175.combine-two-tables.sql) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/) | [python3](./leetcode/203.remove-linked-list-elements.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-207. Course Schedule](https://leetcode.com/problems/course-schedule/description/) | [c++](./leetcode/207.course-schedule.cpp), [python3](./leetcode/207.course-schedule.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/) | [c++](./leetcode/209.minimum-size-subarray-sum.cpp), [python3](./leetcode/209.minimum-size-subarray-sum.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-211. Add And Search Word Data Structure Design](https://leetcode.com/problems/add-and-search-word-data-structure-design/description/) | [c++](./leetcode/211.add-and-search-word-data-structure-design.cpp), [python3](./leetcode/211.add-and-search-word-data-structure-design.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/) | [c++](./leetcode/219.contains-duplicate-ii.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-228. Summary Ranges](https://leetcode.com/problems/summary-ranges/description/) | [python3](./leetcode/228.summary-ranges.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-229. Majority Element II](https://leetcode.com/problems/majority-element-ii/description/) | [c++](./leetcode/229.majority-element-ii.cpp), [python3](./leetcode/229.majority-element-ii.py) | Other | \- | \- | The algorithm should run in linear time and in O\(1\) space\. | - |
| 2023-09 | [Leetcode-237. Delete Node In A Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/description/) | [python3](./leetcode/237.delete-node-in-a-linked-list.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-246. Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/description/) | [c++](./leetcode/246.strobogrammatic-number.cpp), [python3](./leetcode/246.strobogrammatic-number.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-249. Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/description/) | [c++](./leetcode/249.group-shifted-strings.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-251. Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/description/) | [python3](./leetcode/251.flatten-2d-vector.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/description/) | [c++](./leetcode/253.meeting-rooms-ii.cpp), [python3](./leetcode/253.meeting-rooms-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-256. Paint House](https://leetcode.com/problems/paint-house/description/) | [c++](./leetcode/256.paint-house.cpp), [python3](./leetcode/256.paint-house.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-261. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/description/) | [c++](./leetcode/261.graph-valid-tree.cpp), [python3](./leetcode/261.graph-valid-tree.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-265. Paint House II](https://leetcode.com/problems/paint-house-ii/description/) | [c++](./leetcode/265.paint-house-ii.cpp), [python3](./leetcode/265.paint-house-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/description/) | [python3](./leetcode/269.alien-dictionary.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-270. Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/description/) | [c++](./leetcode/270.closest-binary-search-tree-value.cpp), [python3](./leetcode/270.closest-binary-search-tree-value.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-271. Encode And Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/description/) | [c++](./leetcode/271.encode-and-decode-strings.cpp), [python3](./leetcode/271.encode-and-decode-strings.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-273. Integer To English Words](https://leetcode.com/problems/integer-to-english-words/description/) | [python3](./leetcode/273.integer-to-english-words.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-276. Paint Fence](https://leetcode.com/problems/paint-fence/description/) | [c++](./leetcode/276.paint-fence.cpp), [python3](./leetcode/276.paint-fence.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-277. Find The Celebrity](https://leetcode.com/problems/find-the-celebrity/description/) | [c++](./leetcode/277.find-the-celebrity.cpp), [python3](./leetcode/277.find-the-celebrity.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-280. Wiggle Sort](https://leetcode.com/problems/wiggle-sort/description/) | [python3](./leetcode/280.wiggle-sort.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/description/) | [c++](./leetcode/282.expression-add-operators.cpp), [python3](./leetcode/282.expression-add-operators.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-283. Move Zeroes](https://leetcode.com/problems/move-zeroes/description/) | [c++](./leetcode/283.move-zeroes.cpp), [python3](./leetcode/283.move-zeroes.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-286. Walls And Gates](https://leetcode.com/problems/walls-and-gates/description/) | [c++](./leetcode/286.walls-and-gates.cpp), [python3](./leetcode/286.walls-and-gates.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-288. Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/description/) | [c++](./leetcode/288.unique-word-abbreviation.cpp), [python3](./leetcode/288.unique-word-abbreviation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-289. Game Of Life](https://leetcode.com/problems/game-of-life/description/) | [python3](./leetcode/289.game-of-life.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-295. Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/) | [c++](./leetcode/295.find-median-from-data-stream.cpp), [python3](./leetcode/295.find-median-from-data-stream.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-305. Number Of Islands II](https://leetcode.com/problems/number-of-islands-ii/description/) | [c++](./leetcode/305.number-of-islands-ii.cpp), [python3](./leetcode/305.number-of-islands-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-311. Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/description/) | [c++](./leetcode/311.sparse-matrix-multiplication.cpp), [python3](./leetcode/311.sparse-matrix-multiplication.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-314. Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/) | [c++](./leetcode/314.binary-tree-vertical-order-traversal.cpp), [python3](./leetcode/314.binary-tree-vertical-order-traversal.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-323. Number Of Connected Components In An Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/) | [c++](./leetcode/323.number-of-connected-components-in-an-undirected-graph.cpp), [python3](./leetcode/323.number-of-connected-components-in-an-undirected-graph.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/description/) | [python3](./leetcode/324.wiggle-sort-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/description/) | [python3](./leetcode/336.palindrome-pairs.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-341. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/description/) | [python3](./leetcode/341.flatten-nested-list-iterator.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-344. Reverse String](https://leetcode.com/problems/reverse-string/description/) | [c++](./leetcode/344.reverse-string.cpp), [python3](./leetcode/344.reverse-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-345. Reverse Vowels Of A String](https://leetcode.com/problems/reverse-vowels-of-a-string/description/) | [c++](./leetcode/345.reverse-vowels-of-a-string.cpp), [python3](./leetcode/345.reverse-vowels-of-a-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-346. Moving Average From Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/description/) | [c++](./leetcode/346.moving-average-from-data-stream.cpp), [python3](./leetcode/346.moving-average-from-data-stream.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-349. Intersection Of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/) | [c++](./leetcode/349.intersection-of-two-arrays.cpp), [python3](./leetcode/349.intersection-of-two-arrays.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-350. Intersection Of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/description/) | [c++](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python3](./leetcode/350.intersection-of-two-arrays-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/description/) | [c++](./leetcode/354.russian-doll-envelopes.cpp), [python3](./leetcode/354.russian-doll-envelopes.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-359. Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/description/) | [c++](./leetcode/359.logger-rate-limiter.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-361. Bomb Enemy](https://leetcode.com/problems/bomb-enemy/description/) | [c++](./leetcode/361.bomb-enemy.cpp), [python3](./leetcode/361.bomb-enemy.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-366. Find Leaves Of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/description/) | [c++](./leetcode/366.find-leaves-of-binary-tree.cpp), [python3](./leetcode/366.find-leaves-of-binary-tree.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/description/) | [c++](./leetcode/368.largest-divisible-subset.cpp), [python3](./leetcode/368.largest-divisible-subset.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-370. Range Addition](https://leetcode.com/problems/range-addition/description/) | [c++](./leetcode/370.range-addition.cpp), [python3](./leetcode/370.range-addition.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/description/) | [c++](./leetcode/377.combination-sum-iv.cpp), [python3](./leetcode/377.combination-sum-iv.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-378. Kth Smallest Element In A Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/) | [c++](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.cpp), [python3](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-387. First Unique Character In A String](https://leetcode.com/problems/first-unique-character-in-a-string/description/) | [c++](./leetcode/387.first-unique-character-in-a-string.cpp), [python3](./leetcode/387.first-unique-character-in-a-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-388. Longest Absolute File Path](https://leetcode.com/problems/longest-absolute-file-path/description/) | [c++](./leetcode/388.longest-absolute-file-path.cpp), [python3](./leetcode/388.longest-absolute-file-path.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-393. Utf 8 Validation](https://leetcode.com/problems/utf-8-validation/description/) | [c++](./leetcode/393.utf-8-validation.cpp), [python3](./leetcode/393.utf-8-validation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-394. Decode String](https://leetcode.com/problems/decode-string/description/) | [c++](./leetcode/394.decode-string.cpp), [python3](./leetcode/394.decode-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-403. Frog Jump](https://leetcode.com/problems/frog-jump/description/) | [c++](./leetcode/403.frog-jump.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-407. Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/description/) | [c++](./leetcode/407.trapping-rain-water-ii.cpp), [python3](./leetcode/407.trapping-rain-water-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-408. Valid Word Abbreviation](https://leetcode.com/problems/valid-word-abbreviation/description/) | [c++](./leetcode/408.valid-word-abbreviation.cpp), [python3](./leetcode/408.valid-word-abbreviation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-425. Word Squares](https://leetcode.com/problems/word-squares/description/) | [c++](./leetcode/425.word-squares.cpp), [python3](./leetcode/425.word-squares.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-433. Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/description/) | [c++](./leetcode/433.minimum-genetic-mutation.cpp), [python3](./leetcode/433.minimum-genetic-mutation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-444. Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/description/) | [c++](./leetcode/444.sequence-reconstruction.cpp), [python3](./leetcode/444.sequence-reconstruction.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-447. Number Of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/description/) | [c++](./leetcode/447.number-of-boomerangs.cpp), [python3](./leetcode/447.number-of-boomerangs.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-454. 4Sum II](https://leetcode.com/problems/4sum-ii/description/) | [c++](./leetcode/454.4sum-ii.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-463. Island Perimeter](https://leetcode.com/problems/island-perimeter/description/) | [python3](./leetcode/463.island-perimeter.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/) | [c++](./leetcode/485.max-consecutive-ones.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-498. Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description/) | [c++](./leetcode/498.diagonal-traverse.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/) | [c++](./leetcode/516.longest-palindromic-subsequence.cpp), [python3](./leetcode/516.longest-palindromic-subsequence.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-527. Word Abbreviation](https://leetcode.com/problems/word-abbreviation/description/) | [c++](./leetcode/527.word-abbreviation.cpp), [python3](./leetcode/527.word-abbreviation.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-532. K Diff Pairs In An Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/) | [c++](./leetcode/532.k-diff-pairs-in-an-array.cpp), [python3](./leetcode/532.k-diff-pairs-in-an-array.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-535. Encode And Decode Tinyurl](https://leetcode.com/problems/encode-and-decode-tinyurl/description/) | [python3](./leetcode/535.encode-and-decode-tinyurl.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-561. Array Partition I](https://leetcode.com/problems/array-partition-i/description/) | [c++](./leetcode/561.array-partition-i.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-599. Minimum Index Sum Of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/) | [c++](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/description/) | [c++](./leetcode/654.maximum-binary-tree.cpp), [python3](./leetcode/654.maximum-binary-tree.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-657. Robot Return To Origin](https://leetcode.com/problems/robot-return-to-origin/description/) | [python3](./leetcode/657.robot-return-to-origin.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-674. Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/) | [c++](./leetcode/674.longest-continuous-increasing-subsequence.cpp), [python3](./leetcode/674.longest-continuous-increasing-subsequence.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-677. Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/description/) | [c++](./leetcode/677.map-sum-pairs.cpp), [python3](./leetcode/677.map-sum-pairs.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-683. K Empty Slots](https://leetcode.com/problems/k-empty-slots/description/) | [c++](./leetcode/683.k-empty-slots.cpp), [python3](./leetcode/683.k-empty-slots.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/description/) | [c++](./leetcode/687.longest-univalue-path.cpp), [python3](./leetcode/687.longest-univalue-path.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-702. Search In A Sorted Array Of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/) | [c++](./leetcode/702.search-in-a-sorted-array-of-unknown-size.cpp), [python3](./leetcode/702.search-in-a-sorted-array-of-unknown-size.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-721. Accounts Merge](https://leetcode.com/problems/accounts-merge/description/) | [c++](./leetcode/721.accounts-merge.cpp), [python3](./leetcode/721.accounts-merge.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/description/) | [c++](./leetcode/724.find-pivot-index.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-747. Largest Number At Least Twice Of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/) | [c++](./leetcode/747.largest-number-at-least-twice-of-others.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-751. Ip To Cidr](https://leetcode.com/problems/ip-to-cidr/description/) | [python3](./leetcode/751.ip-to-cidr.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-755. Pour Water](https://leetcode.com/problems/pour-water/description/) | [python3](./leetcode/755.pour-water.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-760. Find Anagram Mappings](https://leetcode.com/problems/find-anagram-mappings/description/) | [python3](./leetcode/760.find-anagram-mappings.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-771. Jewels And Stones](https://leetcode.com/problems/jewels-and-stones/description/) | [c++](./leetcode/771.jewels-and-stones.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-773. Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/description/) | [python3](./leetcode/773.sliding-puzzle.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-796. Rotate String](https://leetcode.com/problems/rotate-string/description/) | [c++](./leetcode/796.rotate-string.cpp), [python3](./leetcode/796.rotate-string.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-815. Bus Routes](https://leetcode.com/problems/bus-routes/description/) | [python3](./leetcode/815.bus-routes.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-832. Flipping An Image](https://leetcode.com/problems/flipping-an-image/description/) | [python3](./leetcode/832.flipping-an-image.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/description/) | [c++](./leetcode/836.rectangle-overlap.cpp), [python3](./leetcode/836.rectangle-overlap.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/description/) | [c++](./leetcode/844.backspace-string-compare.cpp), [python3](./leetcode/844.backspace-string-compare.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-859. Buddy Strings](https://leetcode.com/problems/buddy-strings/description/) | [c++](./leetcode/859.buddy-strings.cpp) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-924. Minimize Malware Spread](https://leetcode.com/problems/minimize-malware-spread/description/) | [python3](./leetcode/924.minimize-malware-spread.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-928. Minimize Malware Spread II](https://leetcode.com/problems/minimize-malware-spread-ii/description/) | [python3](./leetcode/928.minimize-malware-spread-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-929. Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/description/) | [python3](./leetcode/929.unique-email-addresses.py) | Other | \- | \- | \- | - |
| 2023-09 | [Leetcode-933. Number Of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/description/) | [c++](./leetcode/933.number-of-recent-calls.cpp), [python3](./leetcode/933.number-of-recent-calls.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-31. Partition Array](https://www.lintcode.com/problem/partition-array) | [python3](./lintcode/31.partition-array.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-89. K Sum](https://www.lintcode.com/problem/k-sum) | [c++](./lintcode/89.k-sum.cpp), [python3](./lintcode/89.k-sum.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-91. Minimum Adjustment Cost](https://www.lintcode.com/problem/minimum-adjustment-cost) | [c++](./lintcode/91.minimum-adjustment-cost.cpp), [python3](./lintcode/91.minimum-adjustment-cost.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-139. Subarray Sum Closest](https://www.lintcode.com/problem/subarray-sum-closest) | [c++](./lintcode/139.subarray-sum-closest.cpp), [python3](./lintcode/139.subarray-sum-closest.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-144. Interleaving Positive And Negative Numbers](https://www.lintcode.com/problem/interleaving-positive-and-negative-numbers) | [c++](./lintcode/144.interleaving-positive-and-negative-numbers.cpp), [python3](./lintcode/144.interleaving-positive-and-negative-numbers.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-183. Wood Cut](https://www.lintcode.com/problem/wood-cut) | [c++](./lintcode/183.wood-cut.cpp), [python3](./lintcode/183.wood-cut.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-382. Triangle Count](https://www.lintcode.com/problem/triangle-count) | [c++](./lintcode/382.triangle-count.cpp), [python3](./lintcode/382.triangle-count.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-390. Find Peak Element II](https://www.lintcode.com/problem/find-peak-element-ii) | [c++](./lintcode/390.find-peak-element-ii.cpp), [python3](./lintcode/390.find-peak-element-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-391. Number Of Airplanes In The Sky](https://www.lintcode.com/problem/number-of-airplanes-in-the-sky) | [c++](./lintcode/391.number-of-airplanes-in-the-sky.cpp), [python3](./lintcode/391.number-of-airplanes-in-the-sky.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-394. Coins In A Line](https://www.lintcode.com/problem/coins-in-a-line) | [c++](./lintcode/394.coins-in-a-line.cpp), [python3](./lintcode/394.coins-in-a-line.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-396. Coins In A Line III](https://www.lintcode.com/problem/coins-in-a-line-iii) | [c++](./lintcode/396.coins-in-a-line-iii.cpp), [python3](./lintcode/396.coins-in-a-line-iii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-447. Search In A Big Sorted Array](https://www.lintcode.com/problem/search-in-a-big-sorted-array) | [c++](./lintcode/447.search-in-a-big-sorted-array.cpp), [python3](./lintcode/447.search-in-a-big-sorted-array.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-465. Kth Smallest Sum In Two Sorted Arrays](https://www.lintcode.com/problem/kth-smallest-sum-in-two-sorted-arrays) | [c++](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.cpp), [python3](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-526. Load Balancer](https://www.lintcode.com/problem/load-balancer) | [c++](./lintcode/526.load-balancer.cpp), [python3](./lintcode/526.load-balancer.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-543. Kth Largest In N Arrays](https://www.lintcode.com/problem/kth-largest-in-n-arrays) | [c++](./lintcode/543.kth-largest-in-n-arrays.cpp), [python3](./lintcode/543.kth-largest-in-n-arrays.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-563. Backpack V](https://www.lintcode.com/problem/backpack-v) | [c++](./lintcode/563.backpack-v.cpp), [python3](./lintcode/563.backpack-v.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-586. Sqrtx II](https://www.lintcode.com/problem/sqrtx-ii) | [c++](./lintcode/586.sqrtx-ii.cpp), [python3](./lintcode/586.sqrtx-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-589. Connecting Graph](https://www.lintcode.com/problem/connecting-graph) | [c++](./lintcode/589.connecting-graph.cpp), [python3](./lintcode/589.connecting-graph.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-590. Connecting Graph II](https://www.lintcode.com/problem/connecting-graph-ii) | [c++](./lintcode/590.connecting-graph-ii.cpp), [python3](./lintcode/590.connecting-graph-ii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-591. Connecting Graph III](https://www.lintcode.com/problem/connecting-graph-iii) | [c++](./lintcode/591.connecting-graph-iii.cpp), [python3](./lintcode/591.connecting-graph-iii.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-598. Zombie In Matrix](https://www.lintcode.com/problem/zombie-in-matrix) | [c++](./lintcode/598.zombie-in-matrix.cpp), [python3](./lintcode/598.zombie-in-matrix.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-611. Knight Shortest Path](https://www.lintcode.com/problem/knight-shortest-path) | [c++](./lintcode/611.knight-shortest-path.cpp), [python3](./lintcode/611.knight-shortest-path.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-618. Search Graph Nodes](https://www.lintcode.com/problem/search-graph-nodes) | [c++](./lintcode/618.search-graph-nodes.cpp), [python3](./lintcode/618.search-graph-nodes.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-629. Minimum Spanning Tree](https://www.lintcode.com/problem/minimum-spanning-tree) | [c++](./lintcode/629.minimum-spanning-tree.cpp), [python3](./lintcode/629.minimum-spanning-tree.py) | Other | \- | \- | \- | - |
| 2023-09 | [Lintcode-652. Factorization](https://www.lintcode.com/problem/factorization) | [c++](./lintcode/652.factorization.cpp), [python3](./lintcode/652.factorization.py) | Other | \- | \- | \- | - |
| 2023-10 | [Leetcode-1150. Check If A Number Is Majority Element In A Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/) | [c++](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.cpp), [python3](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.py) | Other | \- | \- | \- | - |
| 2023-10 | [Leetcode-652. Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/description/) | [c++](./leetcode/652.find-duplicate-subtrees.cpp) | Other | \- | \- | \- | - |
| 2024-07 | [Leetcode-829. Consecutive Numbers Sum](https://leetcode.com/problems/consecutive-numbers-sum/description/) | [python3](./leetcode/829.consecutive-numbers-sum.py) | Other | \- | \- | \- | - |
| 2024-07 | [Leetcode-6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/) | [python3](./leetcode/6.zigzag-conversion.py) | Other | \- | \- | \- | - |

