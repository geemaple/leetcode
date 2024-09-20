# 算法/Algorithm

LeetCode解题报告，记录自己的leetcode成长之路

LeetCode solutions, written in python and cpp

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

## 列表/List

| Status | List | Progress | Notes |
| ----- | ----- | ----- | ----- |
| [--] | [9c-advanced.md](./list/9c-advanced.md) | 59/87 | 2 vips |
| [--] | [9c-basic.md](./list/9c-basic.md) | 80/129 | - |
| [--] | [9c-top.md](./list/9c-top.md) | 25/48 | - |
| [--] | [lee215.md](./list/lee215.md) | 2/34 | - |
| [✅] | [geekbang.md](./list/geekbang.md) | 55/55 | - |
| [✅] | [leetcode101.md](./list/leetcode101.md) | 183/184 | 1 vip |
| [🔲] | [9c-dp.md](./list/9c-dp.md) | 38/44 | 2 vips |

**Solved**: 435 problems

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

| Link | Problem(19) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-415](https://leetcode.com/problems/add-strings/) | Add Strings | [c++](./leetcode/415.add-strings.cpp), [python3](./leetcode/415.add-strings.py) | Math | O\(N\) | O\(1\) | \- | - |
| [leetcode-504](https://leetcode.com/problems/base-7/) | Base 7 | [c++](./leetcode/504.base-7.cpp), [python3](./leetcode/504.base-7.py) | Math | O\(N\) | O\(1\) | \- | - |
| [leetcode-227](https://leetcode.com/problems/basic-calculator-ii/) | Basic Calculator II | [c++](./leetcode/227.basic-calculator-ii.cpp), [python3](./leetcode/227.basic-calculator-ii.py) | Math | O\(N\) | O\(N\) | \- | - |
| [leetcode-932](https://leetcode.com/problems/beautiful-array/) | Beautiful Array | [c++](./leetcode/932.beautiful-array.cpp), [python3](./leetcode/932.beautiful-array.py) | Math | O\(N\) | O\(N\) | dp | - |
| [leetcode-3274](https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/) | Check If Two Chessboard Squares Have The Same Color | [c++](./leetcode/3274.check-if-two-chessboard-squares-have-the-same-color.cpp), [python3](./leetcode/3274.check-if-two-chessboard-squares-have-the-same-color.py) | Math | O\(1\) | O\(1\) | \- | - |
| [leetcode-3280](https://leetcode.com/problems/convert-date-to-binary/) | Convert Date To Binary | [c++](./leetcode/3280.convert-date-to-binary.cpp), [python3](./leetcode/3280.convert-date-to-binary.py) | Math | O\(1\) | O\(1\) | \- | - |
| [leetcode-204](https://leetcode.com/problems/count-primes/) | Count Primes | [c++](./leetcode/204.count-primes.cpp), [python3](./leetcode/204.count-primes.py) | Math | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-168](https://leetcode.com/problems/excel-sheet-column-title/) | Excel Sheet Column Title | [c++](./leetcode/168.excel-sheet-column-title.cpp), [python3](./leetcode/168.excel-sheet-column-title.py) | Math | O\(logN\) | O\(1\) | \- | - |
| [leetcode-172](https://leetcode.com/problems/factorial-trailing-zeroes/) | Factorial Trailing Zeroes | [c++](./leetcode/172.factorial-trailing-zeroes.cpp), [python3](./leetcode/172.factorial-trailing-zeroes.py) | Math | O\(logN\) | O\(1\) | \- | - |
| [leetcode-202](https://leetcode.com/problems/happy-number/) | Happy Number | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Math | O\(S\) | O\(1\) | \- | - |
| [leetcode-149](https://leetcode.com/problems/max-points-on-a-line/) | Max Points On A Line | [c++](./leetcode/149.max-points-on-a-line.cpp), [python3](./leetcode/149.max-points-on-a-line.py) | Math | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-462](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | Minimum Moves To Equal Array Elements II | [c++](./leetcode/462.minimum-moves-to-equal-array-elements-ii.cpp), [python3](./leetcode/462.minimum-moves-to-equal-array-elements-ii.py) | Math | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-326](https://leetcode.com/problems/power-of-three/) | Power Of Three | [c++](./leetcode/326.power-of-three.cpp), [python3](./leetcode/326.power-of-three.py) | Math | O\(1\) | O\(1\) | \- | - |
| [leetcode-50](https://leetcode.com/problems/powx-n/) | Powx N | [c++](./leetcode/50.powx-n.cpp), [python3](./leetcode/50.powx-n.py) | Math | O\(logN\) | O\(1\) | \- | - |
| [leetcode-48](https://leetcode.com/problems/rotate-image/) | Rotate Image | [c++](./leetcode/48.rotate-image.cpp), [python3](./leetcode/48.rotate-image.py) | Math | O\(N^2\) | O\(1\) | \- | - |
| [leetcode-69](https://leetcode.com/problems/sqrtx/) | Sqrtx | [c++](./leetcode/69.sqrtx.cpp), [python3](./leetcode/69.sqrtx.py) | Math | N\(logN\) | O\(1\) | \- | - |
| [leetcode-633](https://leetcode.com/problems/sum-of-square-numbers/) | Sum Of Square Numbers | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Math | O\(N\) | O\(1\) | \- | - |
| [leetcode-263](https://leetcode.com/problems/ugly-number/) | Ugly Number | [c++](./leetcode/263.ugly-number.cpp), [python3](./leetcode/263.ugly-number.py) | Math | O\(k\) | O\(1\) | \- | - |
| [leetcode-367](https://leetcode.com/problems/valid-perfect-square/) | Valid Perfect Square | [c++](./leetcode/367.valid-perfect-square.cpp), [python3](./leetcode/367.valid-perfect-square.py) | Math | O\(logN\) | O\(1\) | \- | - |

## Probability

| Link | Problem(5) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-470](https://leetcode.com/problems/implement-rand10-using-rand7/) | Implement Rand10 Using Rand7 | [c++](./leetcode/470.implement-rand10-using-rand7.cpp), [python3](./leetcode/470.implement-rand10-using-rand7.py) | Probability | O\(1\) | O\(1\) | \- | - |
| [leetcode-380](https://leetcode.com/problems/insert-delete-getrandom-o1/) | Insert Delete Getrandom O1 | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Probability | O\(1\) | O\(N\) | \- | - |
| [leetcode-382](https://leetcode.com/problems/linked-list-random-node/) | Linked List Random Node | [c++](./leetcode/382.linked-list-random-node.cpp), [python3](./leetcode/382.linked-list-random-node.py) | Probability | O\(N\) | O\(1\) | \- | - |
| [leetcode-528](https://leetcode.com/problems/random-pick-with-weight/) | Random Pick With Weight | [c++](./leetcode/528.random-pick-with-weight.cpp), [python3](./leetcode/528.random-pick-with-weight.py) | Probability | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-384](https://leetcode.com/problems/shuffle-an-array/) | Shuffle An Array | [c++](./leetcode/384.shuffle-an-array.cpp), [python3](./leetcode/384.shuffle-an-array.py) | Probability | O\(N\) | O\(N\) | \- | - |

## Bit Manipulation

| Link | Problem(15) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-67](https://leetcode.com/problems/add-binary/) | Add Binary | [c++](./leetcode/67.add-binary.cpp), [python3](./leetcode/67.add-binary.py) | Bit Manipulation | O\(M\+N\) | O\(1\) | \- | - |
| [leetcode-693](https://leetcode.com/problems/binary-number-with-alternating-bits/) | Binary Number With Alternating Bits | [c++](./leetcode/693.binary-number-with-alternating-bits.cpp), [python3](./leetcode/693.binary-number-with-alternating-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-338](https://leetcode.com/problems/counting-bits/) | Counting Bits | [c++](./leetcode/338.counting-bits.cpp), [python3](./leetcode/338.counting-bits.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| [leetcode-287](https://leetcode.com/problems/find-the-duplicate-number/) | Find The Duplicate Number | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| [leetcode-461](https://leetcode.com/problems/hamming-distance/) | Hamming Distance | [c++](./leetcode/461.hamming-distance.cpp), [python3](./leetcode/461.hamming-distance.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-318](https://leetcode.com/problems/maximum-product-of-word-lengths/) | Maximum Product Of Word Lengths | [c++](./leetcode/318.maximum-product-of-word-lengths.cpp), [python3](./leetcode/318.maximum-product-of-word-lengths.py) | Bit Manipulation | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-268](https://leetcode.com/problems/missing-number/) | Missing Number | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| [leetcode-476](https://leetcode.com/problems/number-complement/) | Number Complement | [c++](./leetcode/476.number-complement.cpp), [python3](./leetcode/476.number-complement.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-191](https://leetcode.com/problems/number-of-1-bits/) | Number Of 1 Bits | [c++](./leetcode/191.number-of-1-bits.cpp), [python3](./leetcode/191.number-of-1-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-342](https://leetcode.com/problems/power-of-four/) | Power Of Four | [c++](./leetcode/342.power-of-four.cpp), [python3](./leetcode/342.power-of-four.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-231](https://leetcode.com/problems/power-of-two/) | Power Of Two | [c++](./leetcode/231.power-of-two.cpp), [python3](./leetcode/231.power-of-two.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-190](https://leetcode.com/problems/reverse-bits/) | Reverse Bits | [c++](./leetcode/190.reverse-bits.cpp), [python3](./leetcode/190.reverse-bits.py) | Bit Manipulation | O\(1\) | O\(1\) | \- | - |
| [leetcode-3276](https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/) | Select Cells In Grid With Maximum Score | [c++](./leetcode/3276.select-cells-in-grid-with-maximum-score.cpp), [python3](./leetcode/3276.select-cells-in-grid-with-maximum-score.py) | Bit Manipulation | O\(NM\*2^N\) | O\(2^N\) | \- | - |
| [leetcode-136](https://leetcode.com/problems/single-number/) | Single Number | [c++](./leetcode/136.single-number.cpp), [python3](./leetcode/136.single-number.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |
| [leetcode-260](https://leetcode.com/problems/single-number-iii/) | Single Number III | [c++](./leetcode/260.single-number-iii.cpp), [python3](./leetcode/260.single-number-iii.py) | Bit Manipulation | O\(N\) | O\(1\) | \- | - |

## Simulation

| Link | Problem(7) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-67](https://leetcode.com/problems/add-binary/) | Add Binary | [c++](./leetcode/67.add-binary.cpp), [python3](./leetcode/67.add-binary.py) | Simulation | O\(M\+N\) | O\(1\) | \- | - |
| [leetcode-415](https://leetcode.com/problems/add-strings/) | Add Strings | [c++](./leetcode/415.add-strings.cpp), [python3](./leetcode/415.add-strings.py) | Simulation | O\(N\) | O\(1\) | \- | - |
| [leetcode-566](https://leetcode.com/problems/reshape-the-matrix/) | Reshape The Matrix | [c++](./leetcode/566.reshape-the-matrix.cpp), [python3](./leetcode/566.reshape-the-matrix.py) | Simulation | O\(MN\) | O\(1\) | \- | - |
| [leetcode-874](https://leetcode.com/problems/walking-robot-simulation/) | Walking Robot Simulation | [c++](./leetcode/874.walking-robot-simulation.cpp), [python3](./leetcode/874.walking-robot-simulation.py) | Simulation | O\(N\) | O\(K\) | \- | - |
| [lintcode-849](https://www.lintcode.com/problem/basic-calculator-iii/) | Basic Calculator III | [c++](./lintcode/849.basic-calculator-iii.cpp), [python3](./lintcode/849.basic-calculator-iii.py) | Simulation | O\(N\) | O\(1\) | Leetcode\-772 | - |
| [lintcode-553](https://www.lintcode.com/problem/bomb-enemy/) | Bomb Enemy | [c++](./lintcode/553.bomb-enemy.cpp), [python3](./lintcode/553.bomb-enemy.py) | Simulation | O\(NM\) | O\(NM\) | Leetcode\-361 | - |
| [lintcode-39](https://www.lintcode.com/problem/recover-rotated-sorted-array/) | Recover Rotated Sorted Array | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python3](./lintcode/39.recover-rotated-sorted-array.py) | Simulation | O\(N\) | O\(1\) | Rotated | - |

## Design

| Link | Problem(13) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-432](https://leetcode.com/problems/all-oone-data-structure/) | All Oone Data Structure | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Design | O\(1\) | O\(N\) | \- | - |
| [leetcode-173](https://leetcode.com/problems/binary-search-tree-iterator/) | Binary Search Tree Iterator | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Design | O\(1\) | O\(H\) | InOrder | - |
| [leetcode-232](https://leetcode.com/problems/implement-queue-using-stacks/) | Implement Queue Using Stacks | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Design | O\(\*1\) | O\(N\) | \- | - |
| [leetcode-225](https://leetcode.com/problems/implement-stack-using-queues/) | Implement Stack Using Queues | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Design | O\(N\) | O\(N\) | \- | - |
| [leetcode-208](https://leetcode.com/problems/implement-trie-prefix-tree/) | Implement Trie Prefix Tree | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Design | O\(N\) | O\(L\) | \- | - |
| [leetcode-380](https://leetcode.com/problems/insert-delete-getrandom-o1/) | Insert Delete Getrandom O1 | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Design | O\(1\) | O\(N\) | \- | - |
| [leetcode-703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | Kth Largest Element In A Stream | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Design | O\(logN\) | O\(N\) | \- | - |
| [leetcode-146](https://leetcode.com/problems/lru-cache/) | Lru Cache | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Design | O\(1\) | O\(N\) | \- | - |
| [leetcode-155](https://leetcode.com/problems/min-stack/) | Min Stack | [c++](./leetcode/155.min-stack.cpp), [python3](./leetcode/155.min-stack.py) | Design | O\(1\) | O\(N\) | \- | - |
| [leetcode-304](https://leetcode.com/problems/range-sum-query-2d-immutable/) | Range Sum Query 2D Immutable | [c++](./leetcode/304.range-sum-query-2d-immutable.cpp), [python3](./leetcode/304.range-sum-query-2d-immutable.py) | Design | O\(\*1\) | O\(MN\) | \- | - |
| [leetcode-303](https://leetcode.com/problems/range-sum-query-immutable/) | Range Sum Query Immutable | [c++](./leetcode/303.range-sum-query-immutable.cpp), [python3](./leetcode/303.range-sum-query-immutable.py) | Design | O\(\*1\) | O\(N\) | \- | - |
| [leetcode-307](https://leetcode.com/problems/range-sum-query-mutable/) | Range Sum Query Mutable | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Design | O\(logN\) | O\(N\) | \- | - |
| [leetcode-297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | Serialize And Deserialize Binary Tree | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Design | O\(N\) | O\(N\) | Serialization | - |

## Greedy

| Link | Problem(21) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-870](https://leetcode.com/problems/advantage-shuffle/) | Advantage Shuffle | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-455](https://leetcode.com/problems/assign-cookies/) | Assign Cookies | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Greedy | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-122](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | Best Time To Buy And Sell Stock II | [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python3](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-714](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | Best Time To Buy And Sell Stock With Transaction Fee | [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp), [python3](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-605](https://leetcode.com/problems/can-place-flowers/) | Can Place Flowers | [c++](./leetcode/605.can-place-flowers.cpp), [python3](./leetcode/605.can-place-flowers.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-135](https://leetcode.com/problems/candy/) | Candy | [c++](./leetcode/135.candy.cpp), [python3](./leetcode/135.candy.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-3048](https://leetcode.com/problems/earliest-second-to-mark-indices-i/) | Earliest Second To Mark Indices I | [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp), [python3](./leetcode/3048.earliest-second-to-mark-indices-i.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-55](https://leetcode.com/problems/jump-game/) | Jump Game | [c++](./leetcode/55.jump-game.cpp), [python3](./leetcode/55.jump-game.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-860](https://leetcode.com/problems/lemonade-change/) | Lemonade Change | [c++](./leetcode/860.lemonade-change.cpp), [python3](./leetcode/860.lemonade-change.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-409](https://leetcode.com/problems/longest-palindrome/) | Longest Palindrome | [c++](./leetcode/409.longest-palindrome.cpp), [python3](./leetcode/409.longest-palindrome.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-769](https://leetcode.com/problems/max-chunks-to-make-sorted/) | Max Chunks To Make Sorted | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-3281](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/) | Maximize Score Of Numbers In Ranges | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Greedy | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |
| [leetcode-646](https://leetcode.com/problems/maximum-length-of-pair-chain/) | Maximum Length Of Pair Chain | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Greedy | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-452](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | Minimum Number Of Arrows To Burst Balloons | [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp), [python3](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py) | Greedy | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-435](https://leetcode.com/problems/non-overlapping-intervals/) | Non Overlapping Intervals | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Greedy | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-763](https://leetcode.com/problems/partition-labels/) | Partition Labels | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-3282](https://leetcode.com/problems/reach-end-of-array-with-max-score/) | Reach End Of Array With Max Score | [c++](./leetcode/3282.reach-end-of-array-with-max-score.cpp), [python3](./leetcode/3282.reach-end-of-array-with-max-score.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-680](https://leetcode.com/problems/valid-palindrome-ii/) | Valid Palindrome II | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python3](./leetcode/680.valid-palindrome-ii.py) | Greedy | O\(N\) | O\(1\) | \- | - |
| [leetcode-376](https://leetcode.com/problems/wiggle-subsequence/) | Wiggle Subsequence | [c++](./leetcode/376.wiggle-subsequence.cpp), [python3](./leetcode/376.wiggle-subsequence.py) | Greedy | O\(N\) | O\(N\) | \- | - |
| [leetcode-44](https://leetcode.com/problems/wildcard-matching/) | Wildcard Matching | [c++](./leetcode/44.wildcard-matching.cpp), [python3](./leetcode/44.wildcard-matching.py) | Greedy | O\(NM\) | O\(NM\) | \- | - |
| [lintcode-3672](https://www.lintcode.com/problem/connecting-cities-with-minimum-cost/) | Connecting Cities With Minimum Cost | [c++](./lintcode/3672.connecting-cities-with-minimum-cost.cpp), [python3](./lintcode/3672.connecting-cities-with-minimum-cost.py) | Greedy | O\(ElogE\) | O\(E\+V\) | Leetcode\-1135 | - |

## Dynamic Programming

| Link | Problem(64) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-542](https://leetcode.com/problems/01-matrix/) | 01 Matrix | [c++](./leetcode/542.01-matrix.cpp), [python3](./leetcode/542.01-matrix.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-650](https://leetcode.com/problems/2-keys-keyboard/) | 2 Keys Keyboard | [c++](./leetcode/650.2-keys-keyboard.cpp), [python3](./leetcode/650.2-keys-keyboard.py) | Dynamic Programming | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-413](https://leetcode.com/problems/arithmetic-slices/) | Arithmetic Slices | [c++](./leetcode/413.arithmetic-slices.cpp), [python3](./leetcode/413.arithmetic-slices.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Best Time To Buy And Sell Stock | [c++](./leetcode/121.best-time-to-buy-and-sell-stock.cpp), [python3](./leetcode/121.best-time-to-buy-and-sell-stock.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-122](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | Best Time To Buy And Sell Stock II | [c++](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python3](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-123](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | Best Time To Buy And Sell Stock III | [c++](./leetcode/123.best-time-to-buy-and-sell-stock-iii.cpp), [python3](./leetcode/123.best-time-to-buy-and-sell-stock-iii.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-188](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | Best Time To Buy And Sell Stock IV | [c++](./leetcode/188.best-time-to-buy-and-sell-stock-iv.cpp), [python3](./leetcode/188.best-time-to-buy-and-sell-stock-iv.py) | Dynamic Programming | O\(NK\) | O\(NK\) | \- | - |
| [leetcode-309](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | Best Time To Buy And Sell Stock With Cooldown | [c++](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp), [python3](./leetcode/309.best-time-to-buy-and-sell-stock-with-cooldown.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-714](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | Best Time To Buy And Sell Stock With Transaction Fee | [c++](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp), [python3](./leetcode/714.best-time-to-buy-and-sell-stock-with-transaction-fee.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-312](https://leetcode.com/problems/burst-balloons/) | Burst Balloons | [c++](./leetcode/312.burst-balloons.cpp), [python3](./leetcode/312.burst-balloons.py) | Dynamic Programming | O\(N^3\) | O\(N^2\) | \- | - |
| [leetcode-787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Cheapest Flights Within K Stops | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Dynamic Programming | O\(ElogV\) | O\(E\+V\) | \- | - |
| [leetcode-70](https://leetcode.com/problems/climbing-stairs/) | Climbing Stairs | [c++](./leetcode/70.climbing-stairs.cpp), [python3](./leetcode/70.climbing-stairs.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-322](https://leetcode.com/problems/coin-change/) | Coin Change | [c++](./leetcode/322.coin-change.cpp), [python3](./leetcode/322.coin-change.py) | Dynamic Programming | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| [leetcode-338](https://leetcode.com/problems/counting-bits/) | Counting Bits | [c++](./leetcode/338.counting-bits.cpp), [python3](./leetcode/338.counting-bits.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-91](https://leetcode.com/problems/decode-ways/) | Decode Ways | [c++](./leetcode/91.decode-ways.cpp), [python3](./leetcode/91.decode-ways.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-583](https://leetcode.com/problems/delete-operation-for-two-strings/) | Delete Operation For Two Strings | [c++](./leetcode/583.delete-operation-for-two-strings.cpp), [python3](./leetcode/583.delete-operation-for-two-strings.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-241](https://leetcode.com/problems/different-ways-to-add-parentheses/) | Different Ways To Add Parentheses | [c++](./leetcode/241.different-ways-to-add-parentheses.cpp), [python3](./leetcode/241.different-ways-to-add-parentheses.py) | Dynamic Programming | \- | \- | \- | - |
| [leetcode-115](https://leetcode.com/problems/distinct-subsequences/) | Distinct Subsequences | [c++](./leetcode/115.distinct-subsequences.cpp), [python3](./leetcode/115.distinct-subsequences.py) | Dynamic Programming | O\(NM\) | O\(NM\) | \- | - |
| [leetcode-72](https://leetcode.com/problems/edit-distance/) | Edit Distance | [c++](./leetcode/72.edit-distance.cpp), [python3](./leetcode/72.edit-distance.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-403](https://leetcode.com/problems/frog-jump/) | Frog Jump | [c++](./leetcode/403.frog-jump.cpp), [python3](./leetcode/403.frog-jump.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-22](https://leetcode.com/problems/generate-parentheses/) | Generate Parentheses | [c++](./leetcode/22.generate-parentheses.cpp), [python3](./leetcode/22.generate-parentheses.py) | Dynamic Programming | O\(2^N\) | O\(N\) | Catalan Number | - |
| [leetcode-375](https://leetcode.com/problems/guess-number-higher-or-lower-ii/) | Guess Number Higher Or Lower II | [c++](./leetcode/375.guess-number-higher-or-lower-ii.cpp), [python3](./leetcode/375.guess-number-higher-or-lower-ii.py) | Dynamic Programming | O\(N^3\) | O\(N^2\) | DP\(Index\) | - |
| [leetcode-198](https://leetcode.com/problems/house-robber/) | House Robber | [c++](./leetcode/198.house-robber.cpp), [python3](./leetcode/198.house-robber.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-213](https://leetcode.com/problems/house-robber-ii/) | House Robber II | [c++](./leetcode/213.house-robber-ii.cpp), [python3](./leetcode/213.house-robber-ii.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-343](https://leetcode.com/problems/integer-break/) | Integer Break | [c++](./leetcode/343.integer-break.cpp), [python3](./leetcode/343.integer-break.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-97](https://leetcode.com/problems/interleaving-string/) | Interleaving String | [c++](./leetcode/97.interleaving-string.cpp), [python3](./leetcode/97.interleaving-string.py) | Dynamic Programming | O\(NM\) | O\(M\) | Prove \|n \- m\| <= 1 | - |
| [leetcode-55](https://leetcode.com/problems/jump-game/) | Jump Game | [c++](./leetcode/55.jump-game.cpp), [python3](./leetcode/55.jump-game.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-1143](https://leetcode.com/problems/longest-common-subsequence/) | Longest Common Subsequence | [c++](./leetcode/1143.longest-common-subsequence.cpp), [python3](./leetcode/1143.longest-common-subsequence.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-300](https://leetcode.com/problems/longest-increasing-subsequence/) | Longest Increasing Subsequence | [c++](./leetcode/300.longest-increasing-subsequence.cpp), [python3](./leetcode/300.longest-increasing-subsequence.py) | Dynamic Programming | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| [leetcode-516](https://leetcode.com/problems/longest-palindromic-subsequence/) | Longest Palindromic Subsequence | [c++](./leetcode/516.longest-palindromic-subsequence.cpp), [python3](./leetcode/516.longest-palindromic-subsequence.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-5](https://leetcode.com/problems/longest-palindromic-substring/) | Longest Palindromic Substring | [c++](./leetcode/5.longest-palindromic-substring.cpp), [python3](./leetcode/5.longest-palindromic-substring.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-221](https://leetcode.com/problems/maximal-square/) | Maximal Square | [c++](./leetcode/221.maximal-square.cpp), [python3](./leetcode/221.maximal-square.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-646](https://leetcode.com/problems/maximum-length-of-pair-chain/) | Maximum Length Of Pair Chain | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Dynamic Programming | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-152](https://leetcode.com/problems/maximum-product-subarray/) | Maximum Product Subarray | [c++](./leetcode/152.maximum-product-subarray.cpp), [python3](./leetcode/152.maximum-product-subarray.py) | Dynamic Programming | O\(N\) | O\(1\) | \- | - |
| [leetcode-53](https://leetcode.com/problems/maximum-subarray/) | Maximum Subarray | [c++](./leetcode/53.maximum-subarray.cpp), [python3](./leetcode/53.maximum-subarray.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-3277](https://leetcode.com/problems/maximum-xor-score-subarray-queries/) | Maximum Xor Score Subarray Queries | [c++](./leetcode/3277.maximum-xor-score-subarray-queries.cpp), [python3](./leetcode/3277.maximum-xor-score-subarray-queries.py) | Dynamic Programming | O\(N^2 \+ M\) | O\(N^2\) | \- | - |
| [leetcode-64](https://leetcode.com/problems/minimum-path-sum/) | Minimum Path Sum | [c++](./leetcode/64.minimum-path-sum.cpp), [python3](./leetcode/64.minimum-path-sum.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-435](https://leetcode.com/problems/non-overlapping-intervals/) | Non Overlapping Intervals | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Dynamic Programming | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-474](https://leetcode.com/problems/ones-and-zeroes/) | Ones And Zeroes | [c++](./leetcode/474.ones-and-zeroes.cpp), [python3](./leetcode/474.ones-and-zeroes.py) | Dynamic Programming | O\(KMN\) | O\(MN\) | \- | - |
| [leetcode-132](https://leetcode.com/problems/palindrome-partitioning-ii/) | Palindrome Partitioning II | [c++](./leetcode/132.palindrome-partitioning-ii.cpp), [python3](./leetcode/132.palindrome-partitioning-ii.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-647](https://leetcode.com/problems/palindromic-substrings/) | Palindromic Substrings | [c++](./leetcode/647.palindromic-substrings.cpp), [python3](./leetcode/647.palindromic-substrings.py) | Dynamic Programming | O\(N^2\) | O\(1\) | DP Slow | - |
| [leetcode-416](https://leetcode.com/problems/partition-equal-subset-sum/) | Partition Equal Subset Sum | [c++](./leetcode/416.partition-equal-subset-sum.cpp), [python3](./leetcode/416.partition-equal-subset-sum.py) | Dynamic Programming | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-279](https://leetcode.com/problems/perfect-squares/) | Perfect Squares | [c++](./leetcode/279.perfect-squares.cpp), [python3](./leetcode/279.perfect-squares.py) | Dynamic Programming | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-10](https://leetcode.com/problems/regular-expression-matching/) | Regular Expression Matching | [c++](./leetcode/10.regular-expression-matching.cpp), [python3](./leetcode/10.regular-expression-matching.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-354](https://leetcode.com/problems/russian-doll-envelopes/) | Russian Doll Envelopes | [c++](./leetcode/354.russian-doll-envelopes.cpp), [python3](./leetcode/354.russian-doll-envelopes.py) | Dynamic Programming | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-87](https://leetcode.com/problems/scramble-string/) | Scramble String | [c++](./leetcode/87.scramble-string.cpp), [python3](./leetcode/87.scramble-string.py) | Dynamic Programming | O\(N^4\) | O\(N^3\) | \- | - |
| [leetcode-3276](https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/) | Select Cells In Grid With Maximum Score | [c++](./leetcode/3276.select-cells-in-grid-with-maximum-score.cpp), [python3](./leetcode/3276.select-cells-in-grid-with-maximum-score.py) | Dynamic Programming | O\(NM\*2^N\) | O\(2^N\) | \- | - |
| [leetcode-313](https://leetcode.com/problems/super-ugly-number/) | Super Ugly Number | [c++](./leetcode/313.super-ugly-number.cpp), [python3](./leetcode/313.super-ugly-number.py) | Dynamic Programming | O\(NlogK\) | O\(N\+K\) | K\-Linked\-List\(dup\) | - |
| [leetcode-494](https://leetcode.com/problems/target-sum/) | Target Sum | [c++](./leetcode/494.target-sum.cpp), [python3](./leetcode/494.target-sum.py) | Dynamic Programming | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |
| [leetcode-120](https://leetcode.com/problems/triangle/) | Triangle | [c++](./leetcode/120.triangle.cpp), [python3](./leetcode/120.triangle.py) | Dynamic Programming | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-62](https://leetcode.com/problems/unique-paths/) | Unique Paths | [c++](./leetcode/62.unique-paths.cpp), [python3](./leetcode/62.unique-paths.py) | Dynamic Programming | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-63](https://leetcode.com/problems/unique-paths-ii/) | Unique Paths II | [c++](./leetcode/63.unique-paths-ii.cpp), [python3](./leetcode/63.unique-paths-ii.py) | Dynamic Programming | O\(NM\) | O\(NM\) | \- | - |
| [leetcode-376](https://leetcode.com/problems/wiggle-subsequence/) | Wiggle Subsequence | [c++](./leetcode/376.wiggle-subsequence.cpp), [python3](./leetcode/376.wiggle-subsequence.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [leetcode-44](https://leetcode.com/problems/wildcard-matching/) | Wildcard Matching | [c++](./leetcode/44.wildcard-matching.cpp), [python3](./leetcode/44.wildcard-matching.py) | Dynamic Programming | O\(NM\) | O\(NM\) | \- | - |
| [leetcode-139](https://leetcode.com/problems/word-break/) | Word Break | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Dynamic Programming | O\(MN\) | O\(N\) | \- | - |
| [lintcode-92](https://www.lintcode.com/problem/backpack/) | Backpack | [c++](./lintcode/92.backpack.cpp), [python3](./lintcode/92.backpack.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [lintcode-125](https://www.lintcode.com/problem/backpack-ii/) | Backpack II | [c++](./lintcode/125.backpack-ii.cpp), [python3](./lintcode/125.backpack-ii.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [lintcode-440](https://www.lintcode.com/problem/backpack-iii/) | Backpack III | [c++](./lintcode/440.backpack-iii.cpp), [python3](./lintcode/440.backpack-iii.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [lintcode-562](https://www.lintcode.com/problem/backpack-iv/) | Backpack IV | [c++](./lintcode/562.backpack-iv.cpp), [python3](./lintcode/562.backpack-iv.py) | Dynamic Programming | O\(N^2\) | O\(N^2\) | \- | - |
| [lintcode-563](https://www.lintcode.com/problem/backpack-v/) | Backpack V | [c++](./lintcode/563.backpack-v.cpp), [python3](./lintcode/563.backpack-v.py) | Dynamic Programming | O\(N^2\) | O\(N\) | \- | - |
| [lintcode-394](https://www.lintcode.com/problem/coins-in-a-line/) | Coins In A Line | [c++](./lintcode/394.coins-in-a-line.cpp), [python3](./lintcode/394.coins-in-a-line.py) | Dynamic Programming | O\(N\) | O\(N\) | \- | - |
| [lintcode-437](https://www.lintcode.com/problem/copy-books/) | Copy Books | [c++](./lintcode/437.copy-books.cpp), [python3](./lintcode/437.copy-books.py) | Dynamic Programming | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| [lintcode-515](https://www.lintcode.com/problem/paint-house/) | Paint House | [c++](./lintcode/515.paint-house.cpp), [python3](./lintcode/515.paint-house.py) | Dynamic Programming | O\(N\) | O\(N\) | Leetcode\-256 | - |
| [lintcode-516](https://www.lintcode.com/problem/paint-house-ii/) | Paint House II | [c++](./lintcode/516.paint-house-ii.cpp), [python3](./lintcode/516.paint-house-ii.py) | Dynamic Programming | O\(NM\) | O\(NM\) | Leetcode\-265 | - |

## Binary Search

| Link | Problem(33) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-704](https://leetcode.com/problems/binary-search/) | Binary Search | [c++](./leetcode/704.binary-search.cpp), [python3](./leetcode/704.binary-search.py) | Binary Search | O\(logN\) | O\(1\) | Standard; | [Video](https://youtu.be/oxWpJtUGG_0) |
| [leetcode-3048](https://leetcode.com/problems/earliest-second-to-mark-indices-i/) | Earliest Second To Mark Indices I | [c++](./leetcode/3048.earliest-second-to-mark-indices-i.cpp), [python3](./leetcode/3048.earliest-second-to-mark-indices-i.py) | Binary Search | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-1901](https://leetcode.com/problems/find-a-peak-element-ii/) | Find A Peak Element II | [c++](./leetcode/1901.find-a-peak-element-ii.cpp), [python3](./leetcode/1901.find-a-peak-element-ii.py) | Binary Search | O\(N \* logM\) | O\(1\) | Mountain; | - |
| [leetcode-34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | Find First And Last Position Of Element In Sorted Array | [c++](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp), [python3](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound; | [Video](https://youtu.be/y6OT8heV-30) |
| [leetcode-658](https://leetcode.com/problems/find-k-closest-elements/) | Find K Closest Elements | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Binary Search | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [leetcode-153](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | Find Minimum In Rotated Sorted Array | [c++](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python3](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | Rotated; | [Video](https://youtu.be/GsecRZC5to4) |
| [leetcode-154](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) | Find Minimum In Rotated Sorted Array II | [c++](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp), [python3](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | Binary Search | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| [leetcode-162](https://leetcode.com/problems/find-peak-element/) | Find Peak Element | [c++](./leetcode/162.find-peak-element.cpp), [python3](./leetcode/162.find-peak-element.py) | Binary Search | O\(logN\) | O\(1\) | Mountain; | [Video](https://youtu.be/bexO0N9eP1I) |
| [leetcode-287](https://leetcode.com/problems/find-the-duplicate-number/) | Find The Duplicate Number | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-278](https://leetcode.com/problems/first-bad-version/) | First Bad Version | [c++](./leetcode/278.first-bad-version.cpp), [python3](./leetcode/278.first-bad-version.py) | Binary Search | O\(logN\) | O\(1\) | Range; | [Video](https://youtu.be/xNzBpfqzYSg) |
| [leetcode-374](https://leetcode.com/problems/guess-number-higher-or-lower/) | Guess Number Higher Or Lower | [c++](./leetcode/374.guess-number-higher-or-lower.cpp), [python3](./leetcode/374.guess-number-higher-or-lower.py) | Binary Search | O\(logN\) | O\(1\) | Standard | - |
| [leetcode-300](https://leetcode.com/problems/longest-increasing-subsequence/) | Longest Increasing Subsequence | [c++](./leetcode/300.longest-increasing-subsequence.cpp), [python3](./leetcode/300.longest-increasing-subsequence.py) | Binary Search | O\(N\*logN\) | O\(N\) | LIS \| std::lower\_bound | - |
| [leetcode-3281](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/) | Maximize Score Of Numbers In Ranges | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Binary Search | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |
| [leetcode-2529](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) | Maximum Count Of Positive Integer And Negative Integer | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python3](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound | - |
| [leetcode-4](https://leetcode.com/problems/median-of-two-sorted-arrays/) | Median Of Two Sorted Arrays | [c++](./leetcode/4.median-of-two-sorted-arrays.cpp), [python3](./leetcode/4.median-of-two-sorted-arrays.py) | Binary Search | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| [leetcode-268](https://leetcode.com/problems/missing-number/) | Missing Number | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-1631](https://leetcode.com/problems/path-with-minimum-effort/) | Path With Minimum Effort | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Binary Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| [leetcode-852](https://leetcode.com/problems/peak-index-in-a-mountain-array/) | Peak Index In A Mountain Array | [c++](./leetcode/852.peak-index-in-a-mountain-array.cpp), [python3](./leetcode/852.peak-index-in-a-mountain-array.py) | Binary Search | O\(logN\) | O\(1\) | Mountain | - |
| [leetcode-528](https://leetcode.com/problems/random-pick-with-weight/) | Random Pick With Weight | [c++](./leetcode/528.random-pick-with-weight.cpp), [python3](./leetcode/528.random-pick-with-weight.py) | Binary Search | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-354](https://leetcode.com/problems/russian-doll-envelopes/) | Russian Doll Envelopes | [c++](./leetcode/354.russian-doll-envelopes.cpp), [python3](./leetcode/354.russian-doll-envelopes.py) | Binary Search | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-74](https://leetcode.com/problems/search-a-2d-matrix/) | Search A 2D Matrix | [c++](./leetcode/74.search-a-2d-matrix.cpp), [python3](./leetcode/74.search-a-2d-matrix.py) | Binary Search | O\(log\(m \* n\)\) | O\(1\) | Matrix; | - |
| [leetcode-240](https://leetcode.com/problems/search-a-2d-matrix-ii/) | Search A 2D Matrix II | [c++](./leetcode/240.search-a-2d-matrix-ii.cpp), [python3](./leetcode/240.search-a-2d-matrix-ii.py) | Binary Search | O\(M \+ N\) | O\(1\) | Matrix | - |
| [leetcode-33](https://leetcode.com/problems/search-in-rotated-sorted-array/) | Search In Rotated Sorted Array | [c++](./leetcode/33.search-in-rotated-sorted-array.cpp), [python3](./leetcode/33.search-in-rotated-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | Rotated; | - |
| [leetcode-81](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | Search In Rotated Sorted Array II | [c++](./leetcode/81.search-in-rotated-sorted-array-ii.cpp), [python3](./leetcode/81.search-in-rotated-sorted-array-ii.py) | Binary Search | O\(logN\) ~ O\(N\) | O\(1\) | Rotated; | - |
| [leetcode-35](https://leetcode.com/problems/search-insert-position/) | Search Insert Position | [c++](./leetcode/35.search-insert-position.cpp), [python3](./leetcode/35.search-insert-position.py) | Binary Search | O\(logN\) | O\(1\) | std::lower\_bound | - |
| [leetcode-540](https://leetcode.com/problems/single-element-in-a-sorted-array/) | Single Element In A Sorted Array | [c++](./leetcode/540.single-element-in-a-sorted-array.cpp), [python3](./leetcode/540.single-element-in-a-sorted-array.py) | Binary Search | O\(logN\) | O\(1\) | \- | - |
| [leetcode-2468](https://leetcode.com/problems/split-message-based-on-limit/) | Split Message Based On Limit | [c++](./leetcode/2468.split-message-based-on-limit.cpp), [python3](./leetcode/2468.split-message-based-on-limit.py) | Binary Search | O\(logN \+ K\) | O\(1\) | Answer \| Bruteforce | - |
| [leetcode-69](https://leetcode.com/problems/sqrtx/) | Sqrtx | [c++](./leetcode/69.sqrtx.cpp), [python3](./leetcode/69.sqrtx.py) | Binary Search | N\(logN\) | O\(1\) | \- | - |
| [leetcode-633](https://leetcode.com/problems/sum-of-square-numbers/) | Sum Of Square Numbers | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Two Sum Ii Input Array Is Sorted | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python3](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | Binary Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-367](https://leetcode.com/problems/valid-perfect-square/) | Valid Perfect Square | [c++](./leetcode/367.valid-perfect-square.cpp), [python3](./leetcode/367.valid-perfect-square.py) | Binary Search | O\(logN\) | O\(1\) | \- | - |
| [lintcode-437](https://www.lintcode.com/problem/copy-books/) | Copy Books | [c++](./lintcode/437.copy-books.cpp), [python3](./lintcode/437.copy-books.py) | Binary Search | O\(N\*logP\) | O\(1\) | Answer \| DP | - |
| [lintcode-600](https://www.lintcode.com/problem/smallest-rectangle-enclosing-black-pixels/) | Smallest Rectangle Enclosing Black Pixels | [c++](./lintcode/600.smallest-rectangle-enclosing-black-pixels.cpp), [python3](./lintcode/600.smallest-rectangle-enclosing-black-pixels.py) | Binary Search | O\(N \* logM \+ M \* logN\) | O\(1\) | Graph \| Leetcode\-302 | - |

## Linked List

| Link | Problem(19) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-432](https://leetcode.com/problems/all-oone-data-structure/) | All Oone Data Structure | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Linked List | O\(1\) | O\(N\) | \- | - |
| [leetcode-109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | Convert Sorted List To Binary Search Tree | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Linked List | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-114](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | Flatten Binary Tree To Linked List | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Linked List | O\(N\) | O\(H\) | PreOrder | - |
| [leetcode-160](https://leetcode.com/problems/intersection-of-two-linked-lists/) | Intersection Of Two Linked Lists | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-141](https://leetcode.com/problems/linked-list-cycle/) | Linked List Cycle | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-142](https://leetcode.com/problems/linked-list-cycle-ii/) | Linked List Cycle II | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-382](https://leetcode.com/problems/linked-list-random-node/) | Linked List Random Node | [c++](./leetcode/382.linked-list-random-node.cpp), [python3](./leetcode/382.linked-list-random-node.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-146](https://leetcode.com/problems/lru-cache/) | Lru Cache | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Linked List | O\(1\) | O\(N\) | \- | - |
| [leetcode-23](https://leetcode.com/problems/merge-k-sorted-lists/) | Merge K Sorted Lists | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Linked List | O\(NlogK\) | O\(K\) | \- | - |
| [leetcode-21](https://leetcode.com/problems/merge-two-sorted-lists/) | Merge Two Sorted Lists | [c++](./leetcode/21.merge-two-sorted-lists.cpp), [python3](./leetcode/21.merge-two-sorted-lists.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-328](https://leetcode.com/problems/odd-even-linked-list/) | Odd Even Linked List | [c++](./leetcode/328.odd-even-linked-list.cpp), [python3](./leetcode/328.odd-even-linked-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-234](https://leetcode.com/problems/palindrome-linked-list/) | Palindrome Linked List | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | Remove Duplicates From Sorted List | [c++](./leetcode/83.remove-duplicates-from-sorted-list.cpp), [python3](./leetcode/83.remove-duplicates-from-sorted-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | Remove Nth Node From End Of List | [c++](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python3](./leetcode/19.remove-nth-node-from-end-of-list.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-206](https://leetcode.com/problems/reverse-linked-list/) | Reverse Linked List | [c++](./leetcode/206.reverse-linked-list.cpp), [python3](./leetcode/206.reverse-linked-list.py) | Linked List | O\(N\) | O\(N\) | \- | - |
| [leetcode-25](https://leetcode.com/problems/reverse-nodes-in-k-group/) | Reverse Nodes In K Group | [c++](./leetcode/25.reverse-nodes-in-k-group.cpp), [python3](./leetcode/25.reverse-nodes-in-k-group.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [leetcode-148](https://leetcode.com/problems/sort-list/) | Sort List | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Linked List | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-24](https://leetcode.com/problems/swap-nodes-in-pairs/) | Swap Nodes In Pairs | [c++](./leetcode/24.swap-nodes-in-pairs.cpp), [python3](./leetcode/24.swap-nodes-in-pairs.py) | Linked List | O\(N\) | O\(1\) | \- | - |
| [lintcode-1534](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list/) | Convert Binary Search Tree To Sorted Doubly Linked List | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Linked List | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |

## Hash Table

| Link | Problem(39) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-432](https://leetcode.com/problems/all-oone-data-structure/) | All Oone Data Structure | [c++](./leetcode/432.all-oone-data-structure.cpp), [python3](./leetcode/432.all-oone-data-structure.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| [leetcode-106](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | Construct Binary Tree From Inorder And Postorder Traversal | [c++](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.cpp), [python3](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | Construct Binary Tree From Preorder And Inorder Traversal | [c++](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp), [python3](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-889](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | Construct Binary Tree From Preorder And Postorder Traversal | [c++](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.cpp), [python3](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-217](https://leetcode.com/problems/contains-duplicate/) | Contains Duplicate | [c++](./leetcode/217.contains-duplicate.cpp), [python3](./leetcode/217.contains-duplicate.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-697](https://leetcode.com/problems/degree-of-an-array/) | Degree Of An Array | [c++](./leetcode/697.degree-of-an-array.cpp), [python3](./leetcode/697.degree-of-an-array.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-1110](https://leetcode.com/problems/delete-nodes-and-return-forest/) | Delete Nodes And Return Forest | [c++](./leetcode/1110.delete-nodes-and-return-forest.cpp), [python3](./leetcode/1110.delete-nodes-and-return-forest.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | Find All Anagrams In A String | [c++](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python3](./leetcode/438.find-all-anagrams-in-a-string.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | Find All Numbers Disappeared In An Array | [c++](./leetcode/448.find-all-numbers-disappeared-in-an-array.cpp), [python3](./leetcode/448.find-all-numbers-disappeared-in-an-array.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-49](https://leetcode.com/problems/group-anagrams/) | Group Anagrams | [c++](./leetcode/49.group-anagrams.cpp), [python3](./leetcode/49.group-anagrams.py) | Hash Table | O\(NL\) | O\(N\) | \- | - |
| [leetcode-202](https://leetcode.com/problems/happy-number/) | Happy Number | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Hash Table | O\(S\) | O\(1\) | \- | - |
| [leetcode-208](https://leetcode.com/problems/implement-trie-prefix-tree/) | Implement Trie Prefix Tree | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Hash Table | O\(N\) | O\(L\) | \- | - |
| [leetcode-380](https://leetcode.com/problems/insert-delete-getrandom-o1/) | Insert Delete Getrandom O1 | [c++](./leetcode/380.insert-delete-getrandom-o1.cpp), [python3](./leetcode/380.insert-delete-getrandom-o1.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| [leetcode-160](https://leetcode.com/problems/intersection-of-two-linked-lists/) | Intersection Of Two Linked Lists | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-205](https://leetcode.com/problems/isomorphic-strings/) | Isomorphic Strings | [c++](./leetcode/205.isomorphic-strings.cpp), [python3](./leetcode/205.isomorphic-strings.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-141](https://leetcode.com/problems/linked-list-cycle/) | Linked List Cycle | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-142](https://leetcode.com/problems/linked-list-cycle-ii/) | Linked List Cycle II | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-128](https://leetcode.com/problems/longest-consecutive-sequence/) | Longest Consecutive Sequence | [c++](./leetcode/128.longest-consecutive-sequence.cpp), [python3](./leetcode/128.longest-consecutive-sequence.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-594](https://leetcode.com/problems/longest-harmonious-subsequence/) | Longest Harmonious Subsequence | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-409](https://leetcode.com/problems/longest-palindrome/) | Longest Palindrome | [c++](./leetcode/409.longest-palindrome.cpp), [python3](./leetcode/409.longest-palindrome.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Longest Substring Without Repeating Characters | [c++](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python3](./leetcode/3.longest-substring-without-repeating-characters.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-146](https://leetcode.com/problems/lru-cache/) | Lru Cache | [c++](./leetcode/146.lru-cache.cpp), [python3](./leetcode/146.lru-cache.py) | Hash Table | O\(1\) | O\(N\) | \- | - |
| [leetcode-169](https://leetcode.com/problems/majority-element/) | Majority Element | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-149](https://leetcode.com/problems/max-points-on-a-line/) | Max Points On A Line | [c++](./leetcode/149.max-points-on-a-line.cpp), [python3](./leetcode/149.max-points-on-a-line.py) | Hash Table | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-76](https://leetcode.com/problems/minimum-window-substring/) | Minimum Window Substring | [c++](./leetcode/76.minimum-window-substring.cpp), [python3](./leetcode/76.minimum-window-substring.py) | Hash Table | O\(M\) | O\(N\) | Hash \+ TP | - |
| [leetcode-268](https://leetcode.com/problems/missing-number/) | Missing Number | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-763](https://leetcode.com/problems/partition-labels/) | Partition Labels | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-451](https://leetcode.com/problems/sort-characters-by-frequency/) | Sort Characters By Frequency | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-560](https://leetcode.com/problems/subarray-sum-equals-k/) | Subarray Sum Equals K | [c++](./leetcode/560.subarray-sum-equals-k.cpp), [python3](./leetcode/560.subarray-sum-equals-k.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-572](https://leetcode.com/problems/subtree-of-another-tree/) | Subtree Of Another Tree | [c++](./leetcode/572.subtree-of-another-tree.cpp), [python3](./leetcode/572.subtree-of-another-tree.py) | Hash Table | O\(NM\) | O\(H\) | \- | - |
| [leetcode-37](https://leetcode.com/problems/sudoku-solver/) | Sudoku Solver | [c++](./leetcode/37.sudoku-solver.cpp), [python3](./leetcode/37.sudoku-solver.py) | Hash Table | O\(N^\(N^2\)\) | O\(N\) | \- | - |
| [leetcode-347](https://leetcode.com/problems/top-k-frequent-elements/) | Top K Frequent Elements | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Hash Table | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [leetcode-1](https://leetcode.com/problems/two-sum/) | Two Sum | [c++](./leetcode/1.two-sum.cpp), [python3](./leetcode/1.two-sum.py) | Hash Table | O\(N\) | O\(N\) | \- | - |
| [leetcode-653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | Two Sum Iv Input Is A Bst | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Hash Table | O\(NH\) | O\(H\) | \- | - |
| [leetcode-242](https://leetcode.com/problems/valid-anagram/) | Valid Anagram | [c++](./leetcode/242.valid-anagram.cpp), [python3](./leetcode/242.valid-anagram.py) | Hash Table | O\(N\) | O\(1\) | \- | - |
| [leetcode-36](https://leetcode.com/problems/valid-sudoku/) | Valid Sudoku | [c++](./leetcode/36.valid-sudoku.cpp), [python3](./leetcode/36.valid-sudoku.py) | Hash Table | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-874](https://leetcode.com/problems/walking-robot-simulation/) | Walking Robot Simulation | [c++](./leetcode/874.walking-robot-simulation.cpp), [python3](./leetcode/874.walking-robot-simulation.py) | Hash Table | O\(N\) | O\(K\) | \- | - |
| [leetcode-139](https://leetcode.com/problems/word-break/) | Word Break | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Hash Table | O\(MN\) | O\(N\) | \- | - |
| [leetcode-126](https://leetcode.com/problems/word-ladder-ii/) | Word Ladder II | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Hash Table | O\(\(N\*L\)^C\) | O\(N\) | \- | - |

## Stack

| Link | Problem(15) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-227](https://leetcode.com/problems/basic-calculator-ii/) | Basic Calculator II | [c++](./leetcode/227.basic-calculator-ii.cpp), [python3](./leetcode/227.basic-calculator-ii.py) | Stack | O\(N\) | O\(N\) | \- | - |
| [leetcode-173](https://leetcode.com/problems/binary-search-tree-iterator/) | Binary Search Tree Iterator | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Stack | O\(1\) | O\(H\) | InOrder | - |
| [leetcode-94](https://leetcode.com/problems/binary-tree-inorder-traversal/) | Binary Tree Inorder Traversal | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python3](./leetcode/94.binary-tree-inorder-traversal.py) | Stack | O\(N\) | O\(H\) | InOrder | - |
| [leetcode-145](https://leetcode.com/problems/binary-tree-postorder-traversal/) | Binary Tree Postorder Traversal | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python3](./leetcode/145.binary-tree-postorder-traversal.py) | Stack | O\(N\) | O\(H\) | PostOrder | - |
| [leetcode-144](https://leetcode.com/problems/binary-tree-preorder-traversal/) | Binary Tree Preorder Traversal | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python3](./leetcode/144.binary-tree-preorder-traversal.py) | Stack | O\(N\) | O\(H\) | PreOrder | - |
| [leetcode-114](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | Flatten Binary Tree To Linked List | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Stack | O\(N\) | O\(H\) | PreOrder | - |
| [leetcode-232](https://leetcode.com/problems/implement-queue-using-stacks/) | Implement Queue Using Stacks | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Stack | O\(\*1\) | O\(N\) | \- | - |
| [leetcode-225](https://leetcode.com/problems/implement-stack-using-queues/) | Implement Stack Using Queues | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Stack | O\(N\) | O\(N\) | \- | - |
| [leetcode-897](https://leetcode.com/problems/increasing-order-search-tree/) | Increasing Order Search Tree | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Stack | O\(N\) | O\(H\) | \- | - |
| [leetcode-155](https://leetcode.com/problems/min-stack/) | Min Stack | [c++](./leetcode/155.min-stack.cpp), [python3](./leetcode/155.min-stack.py) | Stack | O\(1\) | O\(N\) | \- | - |
| [leetcode-1249](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) | Minimum Remove To Make Valid Parentheses | [c++](./leetcode/1249.minimum-remove-to-make-valid-parentheses.cpp), [python3](./leetcode/1249.minimum-remove-to-make-valid-parentheses.py) | Stack | O\(N\) | O\(N\) | \- | - |
| [leetcode-234](https://leetcode.com/problems/palindrome-linked-list/) | Palindrome Linked List | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Stack | O\(N\) | O\(1\) | \- | - |
| [leetcode-20](https://leetcode.com/problems/valid-parentheses/) | Valid Parentheses | [c++](./leetcode/20.valid-parentheses.cpp), [python3](./leetcode/20.valid-parentheses.py) | Stack | O\(N\) | O\(N\) | \- | - |
| [lintcode-849](https://www.lintcode.com/problem/basic-calculator-iii/) | Basic Calculator III | [c++](./lintcode/849.basic-calculator-iii.cpp), [python3](./lintcode/849.basic-calculator-iii.py) | Stack | O\(N\) | O\(1\) | Leetcode\-772 | - |
| [lintcode-859](https://www.lintcode.com/problem/max-stack/) | Max Stack | [c++](./lintcode/859.max-stack.cpp), [python3](./lintcode/859.max-stack.py) | Stack | \- | O\(N\) | Leetcode\-716 | - |

## Monotonic Stack

| Link | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-739](https://leetcode.com/problems/daily-temperatures/) | Daily Temperatures | [c++](./leetcode/739.daily-temperatures.cpp), [python3](./leetcode/739.daily-temperatures.py) | Monotonic Stack | O\(N\) | O\(N\) | \- | - |
| [leetcode-769](https://leetcode.com/problems/max-chunks-to-make-sorted/) | Max Chunks To Make Sorted | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Monotonic Stack | O\(N\) | O\(1\) | \- | - |
| [leetcode-503](https://leetcode.com/problems/next-greater-element-ii/) | Next Greater Element II | [c++](./leetcode/503.next-greater-element-ii.cpp), [python3](./leetcode/503.next-greater-element-ii.py) | Monotonic Stack | O\(N\) | O\(N\) | \- | - |

## Queue

| Link | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-232](https://leetcode.com/problems/implement-queue-using-stacks/) | Implement Queue Using Stacks | [c++](./leetcode/232.implement-queue-using-stacks.cpp), [python3](./leetcode/232.implement-queue-using-stacks.py) | Queue | O\(\*1\) | O\(N\) | \- | - |
| [leetcode-225](https://leetcode.com/problems/implement-stack-using-queues/) | Implement Stack Using Queues | [c++](./leetcode/225.implement-stack-using-queues.cpp), [python3](./leetcode/225.implement-stack-using-queues.py) | Queue | O\(N\) | O\(N\) | \- | - |

## Monotonic Queue

| Link | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-239](https://leetcode.com/problems/sliding-window-maximum/) | Sliding Window Maximum | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Monotonic Queue | O\(N\) | O\(K\) | \- | - |

## Heap

| Link | Problem(14) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Cheapest Flights Within K Stops | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Heap | O\(ElogV\) | O\(E\+V\) | \- | - |
| [leetcode-658](https://leetcode.com/problems/find-k-closest-elements/) | Find K Closest Elements | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Heap | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [leetcode-3275](https://leetcode.com/problems/k-th-nearest-obstacle-queries/) | K Th Nearest Obstacle Queries | [c++](./leetcode/3275.k-th-nearest-obstacle-queries.cpp), [python3](./leetcode/3275.k-th-nearest-obstacle-queries.py) | Heap | O\(NlogK\) | O\(K\) | \- | - |
| [leetcode-703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | Kth Largest Element In A Stream | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Heap | O\(logN\) | O\(N\) | \- | - |
| [leetcode-215](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Kth Largest Element In An Array | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Heap | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [leetcode-23](https://leetcode.com/problems/merge-k-sorted-lists/) | Merge K Sorted Lists | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Heap | O\(NlogK\) | O\(K\) | \- | - |
| [leetcode-743](https://leetcode.com/problems/network-delay-time/) | Network Delay Time | [c++](./leetcode/743.network-delay-time.cpp), [python3](./leetcode/743.network-delay-time.py) | Heap | O\(ElogE\) | O\(E\+V\) | \- | - |
| [leetcode-1514](https://leetcode.com/problems/path-with-maximum-probability/) | Path With Maximum Probability | [c++](./leetcode/1514.path-with-maximum-probability.cpp), [python3](./leetcode/1514.path-with-maximum-probability.py) | Heap | O\(VlogE\) | O\(V\+E\) | \- | - |
| [leetcode-1631](https://leetcode.com/problems/path-with-minimum-effort/) | Path With Minimum Effort | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Heap | O\(NMlogNM\) | O\(NM\) | \- | - |
| [leetcode-882](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/) | Reachable Nodes In Subdivided Graph | [c++](./leetcode/882.reachable-nodes-in-subdivided-graph.cpp), [python3](./leetcode/882.reachable-nodes-in-subdivided-graph.py) | Heap | O\(ElogE\) | O\(V\+E\) | \- | - |
| [leetcode-239](https://leetcode.com/problems/sliding-window-maximum/) | Sliding Window Maximum | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Heap | O\(N\) | O\(K\) | \- | - |
| [leetcode-451](https://leetcode.com/problems/sort-characters-by-frequency/) | Sort Characters By Frequency | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Heap | O\(N\) | O\(N\) | \- | - |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Heap | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-347](https://leetcode.com/problems/top-k-frequent-elements/) | Top K Frequent Elements | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Heap | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |

## Two Pointers

| Link | Problem(25) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-15](https://leetcode.com/problems/3sum/) | 3Sum | [c++](./leetcode/15.3sum.cpp), [python3](./leetcode/15.3sum.py) | Two Pointers | O\(N^2\) | O\(1\) | \- | - |
| [leetcode-18](https://leetcode.com/problems/4sum/) | 4Sum | [c++](./leetcode/18.4sum.cpp), [python3](./leetcode/18.4sum.py) | Two Pointers | O\(N^3\) | O\(1\) | \- | - |
| [leetcode-870](https://leetcode.com/problems/advantage-shuffle/) | Advantage Shuffle | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Two Pointers | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-455](https://leetcode.com/problems/assign-cookies/) | Assign Cookies | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Two Pointers | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-696](https://leetcode.com/problems/count-binary-substrings/) | Count Binary Substrings | [c++](./leetcode/696.count-binary-substrings.cpp), [python3](./leetcode/696.count-binary-substrings.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-287](https://leetcode.com/problems/find-the-duplicate-number/) | Find The Duplicate Number | [c++](./leetcode/287.find-the-duplicate-number.cpp), [python3](./leetcode/287.find-the-duplicate-number.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-28](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | Find The Index Of The First Occurrence In A String | [c++](./leetcode/28.find-the-index-of-the-first-occurrence-in-a-string.cpp), [python3](./leetcode/28.find-the-index-of-the-first-occurrence-in-a-string.py) | Two Pointers | O\(M \+ N\) | O\(N\) | \- | - |
| [leetcode-202](https://leetcode.com/problems/happy-number/) | Happy Number | [c++](./leetcode/202.happy-number.cpp), [python3](./leetcode/202.happy-number.py) | Two Pointers | O\(S\) | O\(1\) | \- | - |
| [leetcode-160](https://leetcode.com/problems/intersection-of-two-linked-lists/) | Intersection Of Two Linked Lists | [c++](./leetcode/160.intersection-of-two-linked-lists.cpp), [python3](./leetcode/160.intersection-of-two-linked-lists.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-141](https://leetcode.com/problems/linked-list-cycle/) | Linked List Cycle | [c++](./leetcode/141.linked-list-cycle.cpp), [python3](./leetcode/141.linked-list-cycle.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-142](https://leetcode.com/problems/linked-list-cycle-ii/) | Linked List Cycle II | [c++](./leetcode/142.linked-list-cycle-ii.cpp), [python3](./leetcode/142.linked-list-cycle-ii.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-5](https://leetcode.com/problems/longest-palindromic-substring/) | Longest Palindromic Substring | [c++](./leetcode/5.longest-palindromic-substring.cpp), [python3](./leetcode/5.longest-palindromic-substring.py) | Two Pointers | O\(N\) | O\(N\) | \- | - |
| [leetcode-524](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | Longest Word In Dictionary Through Deleting | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python3](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | Two Pointers | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| [leetcode-88](https://leetcode.com/problems/merge-sorted-array/) | Merge Sorted Array | [c++](./leetcode/88.merge-sorted-array.cpp), [python3](./leetcode/88.merge-sorted-array.py) | Two Pointers | O\(M \+ N\) | O\(1\) | \- | - |
| [leetcode-234](https://leetcode.com/problems/palindrome-linked-list/) | Palindrome Linked List | [c++](./leetcode/234.palindrome-linked-list.cpp), [python3](./leetcode/234.palindrome-linked-list.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-647](https://leetcode.com/problems/palindromic-substrings/) | Palindromic Substrings | [c++](./leetcode/647.palindromic-substrings.cpp), [python3](./leetcode/647.palindromic-substrings.py) | Two Pointers | O\(N^2\) | O\(1\) | DP Slow | - |
| [leetcode-763](https://leetcode.com/problems/partition-labels/) | Partition Labels | [c++](./leetcode/763.partition-labels.cpp), [python3](./leetcode/763.partition-labels.py) | Two Pointers | O\(N\) | O\(N\) | \- | - |
| [leetcode-19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | Remove Nth Node From End Of List | [c++](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python3](./leetcode/19.remove-nth-node-from-end-of-list.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-75](https://leetcode.com/problems/sort-colors/) | Sort Colors | [c++](./leetcode/75.sort-colors.cpp), [python3](./leetcode/75.sort-colors.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-148](https://leetcode.com/problems/sort-list/) | Sort List | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Two Pointers | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-633](https://leetcode.com/problems/sum-of-square-numbers/) | Sum Of Square Numbers | [c++](./leetcode/633.sum-of-square-numbers.cpp), [python3](./leetcode/633.sum-of-square-numbers.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Two Sum Ii Input Array Is Sorted | [c++](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python3](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [leetcode-653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | Two Sum Iv Input Is A Bst | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Two Pointers | O\(NH\) | O\(H\) | \- | - |
| [leetcode-680](https://leetcode.com/problems/valid-palindrome-ii/) | Valid Palindrome II | [c++](./leetcode/680.valid-palindrome-ii.cpp), [python3](./leetcode/680.valid-palindrome-ii.py) | Two Pointers | O\(N\) | O\(1\) | \- | - |
| [lintcode-386](https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/) | Longest Substring With At Most K Distinct Characters | [c++](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.cpp), [python3](./lintcode/386.longest-substring-with-at-most-k-distinct-characters.py) | Two Pointers | O\(N\) | O\(K\) | Leetcode\-340 | - |

## Sliding Window

| Link | Problem(6) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | Find All Anagrams In A String | [c++](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python3](./leetcode/438.find-all-anagrams-in-a-string.py) | Sliding Window | O\(N\) | O\(1\) | \- | - |
| [leetcode-658](https://leetcode.com/problems/find-k-closest-elements/) | Find K Closest Elements | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Sliding Window | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [leetcode-594](https://leetcode.com/problems/longest-harmonious-subsequence/) | Longest Harmonious Subsequence | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Sliding Window | O\(N\) | O\(N\) | \- | - |
| [leetcode-3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Longest Substring Without Repeating Characters | [c++](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python3](./leetcode/3.longest-substring-without-repeating-characters.py) | Sliding Window | O\(N\) | O\(N\) | \- | - |
| [leetcode-76](https://leetcode.com/problems/minimum-window-substring/) | Minimum Window Substring | [c++](./leetcode/76.minimum-window-substring.cpp), [python3](./leetcode/76.minimum-window-substring.py) | Sliding Window | O\(M\) | O\(N\) | Hash \+ TP | - |
| [leetcode-239](https://leetcode.com/problems/sliding-window-maximum/) | Sliding Window Maximum | [c++](./leetcode/239.sliding-window-maximum.cpp), [python3](./leetcode/239.sliding-window-maximum.py) | Sliding Window | O\(N\) | O\(K\) | \- | - |

## Sorting

| Link | Problem(24) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-15](https://leetcode.com/problems/3sum/) | 3Sum | [c++](./leetcode/15.3sum.cpp), [python3](./leetcode/15.3sum.py) | Sorting | O\(N^2\) | O\(1\) | \- | - |
| [leetcode-18](https://leetcode.com/problems/4sum/) | 4Sum | [c++](./leetcode/18.4sum.cpp), [python3](./leetcode/18.4sum.py) | Sorting | O\(N^3\) | O\(1\) | \- | - |
| [leetcode-870](https://leetcode.com/problems/advantage-shuffle/) | Advantage Shuffle | [c++](./leetcode/870.advantage-shuffle.cpp), [python3](./leetcode/870.advantage-shuffle.py) | Sorting | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-455](https://leetcode.com/problems/assign-cookies/) | Assign Cookies | [c++](./leetcode/455.assign-cookies.cpp), [python3](./leetcode/455.assign-cookies.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-217](https://leetcode.com/problems/contains-duplicate/) | Contains Duplicate | [c++](./leetcode/217.contains-duplicate.cpp), [python3](./leetcode/217.contains-duplicate.py) | Sorting | O\(N\) | O\(N\) | \- | - |
| [leetcode-658](https://leetcode.com/problems/find-k-closest-elements/) | Find K Closest Elements | [c++](./leetcode/658.find-k-closest-elements.cpp), [python3](./leetcode/658.find-k-closest-elements.py) | Sorting | O\(Log\(N \- K\)\) | O\(1\) | Range | - |
| [leetcode-49](https://leetcode.com/problems/group-anagrams/) | Group Anagrams | [c++](./leetcode/49.group-anagrams.cpp), [python3](./leetcode/49.group-anagrams.py) | Sorting | O\(NL\) | O\(N\) | \- | - |
| [leetcode-215](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Kth Largest Element In An Array | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Sorting | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [leetcode-524](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | Longest Word In Dictionary Through Deleting | [c++](./leetcode/524.longest-word-in-dictionary-through-deleting.cpp), [python3](./leetcode/524.longest-word-in-dictionary-through-deleting.py) | Sorting | O\(N\*logN \+ M \* N\) | O\(1\) | \- | - |
| [leetcode-769](https://leetcode.com/problems/max-chunks-to-make-sorted/) | Max Chunks To Make Sorted | [c++](./leetcode/769.max-chunks-to-make-sorted.cpp), [python3](./leetcode/769.max-chunks-to-make-sorted.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| [leetcode-3281](https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/) | Maximize Score Of Numbers In Ranges | [c++](./leetcode/3281.maximize-score-of-numbers-in-ranges.cpp), [python3](./leetcode/3281.maximize-score-of-numbers-in-ranges.py) | Sorting | O\(NlogN \+ NlogD\) | O\(1\) | \- | - |
| [leetcode-646](https://leetcode.com/problems/maximum-length-of-pair-chain/) | Maximum Length Of Pair Chain | [c++](./leetcode/646.maximum-length-of-pair-chain.cpp), [python3](./leetcode/646.maximum-length-of-pair-chain.py) | Sorting | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-23](https://leetcode.com/problems/merge-k-sorted-lists/) | Merge K Sorted Lists | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Sorting | O\(NlogK\) | O\(K\) | \- | - |
| [leetcode-88](https://leetcode.com/problems/merge-sorted-array/) | Merge Sorted Array | [c++](./leetcode/88.merge-sorted-array.cpp), [python3](./leetcode/88.merge-sorted-array.py) | Sorting | O\(M \+ N\) | O\(1\) | \- | - |
| [leetcode-462](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | Minimum Moves To Equal Array Elements II | [c++](./leetcode/462.minimum-moves-to-equal-array-elements-ii.cpp), [python3](./leetcode/462.minimum-moves-to-equal-array-elements-ii.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-452](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | Minimum Number Of Arrows To Burst Balloons | [c++](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.cpp), [python3](./leetcode/452.minimum-number-of-arrows-to-burst-balloons.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-268](https://leetcode.com/problems/missing-number/) | Missing Number | [c++](./leetcode/268.missing-number.cpp), [python3](./leetcode/268.missing-number.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| [leetcode-435](https://leetcode.com/problems/non-overlapping-intervals/) | Non Overlapping Intervals | [c++](./leetcode/435.non-overlapping-intervals.cpp), [python3](./leetcode/435.non-overlapping-intervals.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-406](https://leetcode.com/problems/queue-reconstruction-by-height/) | Queue Reconstruction By Height | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Sorting | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-354](https://leetcode.com/problems/russian-doll-envelopes/) | Russian Doll Envelopes | [c++](./leetcode/354.russian-doll-envelopes.cpp), [python3](./leetcode/354.russian-doll-envelopes.py) | Sorting | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-75](https://leetcode.com/problems/sort-colors/) | Sort Colors | [c++](./leetcode/75.sort-colors.cpp), [python3](./leetcode/75.sort-colors.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| [leetcode-148](https://leetcode.com/problems/sort-list/) | Sort List | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Sorting | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-242](https://leetcode.com/problems/valid-anagram/) | Valid Anagram | [c++](./leetcode/242.valid-anagram.cpp), [python3](./leetcode/242.valid-anagram.py) | Sorting | O\(N\) | O\(1\) | \- | - |
| [lintcode-39](https://www.lintcode.com/problem/recover-rotated-sorted-array/) | Recover Rotated Sorted Array | [c++](./lintcode/39.recover-rotated-sorted-array.cpp), [python3](./lintcode/39.recover-rotated-sorted-array.py) | Sorting | O\(N\) | O\(1\) | Rotated | - |

## Counting

| Link | Problem(5) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-594](https://leetcode.com/problems/longest-harmonious-subsequence/) | Longest Harmonious Subsequence | [c++](./leetcode/594.longest-harmonious-subsequence.cpp), [python3](./leetcode/594.longest-harmonious-subsequence.py) | Counting | O\(N\) | O\(N\) | \- | - |
| [leetcode-169](https://leetcode.com/problems/majority-element/) | Majority Element | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Counting | O\(N\) | O\(1\) | \- | - |
| [leetcode-2529](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) | Maximum Count Of Positive Integer And Negative Integer | [c++](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.cpp), [python3](./leetcode/2529.maximum-count-of-positive-integer-and-negative-integer.py) | Counting | O\(logN\) | O\(1\) | std::lower\_bound | - |
| [leetcode-451](https://leetcode.com/problems/sort-characters-by-frequency/) | Sort Characters By Frequency | [c++](./leetcode/451.sort-characters-by-frequency.cpp), [python3](./leetcode/451.sort-characters-by-frequency.py) | Counting | O\(N\) | O\(N\) | \- | - |
| [leetcode-347](https://leetcode.com/problems/top-k-frequent-elements/) | Top K Frequent Elements | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Counting | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |

## Quickselect

| Link | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-215](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Kth Largest Element In An Array | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Quickselect | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [leetcode-347](https://leetcode.com/problems/top-k-frequent-elements/) | Top K Frequent Elements | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Quickselect | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |

## Divide and Conquer

| Link | Problem(18) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-932](https://leetcode.com/problems/beautiful-array/) | Beautiful Array | [c++](./leetcode/932.beautiful-array.cpp), [python3](./leetcode/932.beautiful-array.py) | Divide and Conquer | O\(N\) | O\(N\) | dp | - |
| [leetcode-106](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | Construct Binary Tree From Inorder And Postorder Traversal | [c++](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.cpp), [python3](./leetcode/106.construct-binary-tree-from-inorder-and-postorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| [leetcode-105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | Construct Binary Tree From Preorder And Inorder Traversal | [c++](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp), [python3](./leetcode/105.construct-binary-tree-from-preorder-and-inorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| [leetcode-889](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | Construct Binary Tree From Preorder And Postorder Traversal | [c++](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.cpp), [python3](./leetcode/889.construct-binary-tree-from-preorder-and-postorder-traversal.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| [leetcode-109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | Convert Sorted List To Binary Search Tree | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Divide and Conquer | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-215](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Kth Largest Element In An Array | [c++](./leetcode/215.kth-largest-element-in-an-array.cpp), [python3](./leetcode/215.kth-largest-element-in-an-array.py) | Divide and Conquer | O\(N\) ～ O\(N^2\) | O\(1\) | QuickSelection | - |
| [leetcode-169](https://leetcode.com/problems/majority-element/) | Majority Element | [c++](./leetcode/169.majority-element.cpp), [python3](./leetcode/169.majority-element.py) | Divide and Conquer | O\(N\) | O\(1\) | \- | - |
| [leetcode-53](https://leetcode.com/problems/maximum-subarray/) | Maximum Subarray | [c++](./leetcode/53.maximum-subarray.cpp), [python3](./leetcode/53.maximum-subarray.py) | Divide and Conquer | O\(N\) | O\(N\) | \- | - |
| [leetcode-4](https://leetcode.com/problems/median-of-two-sorted-arrays/) | Median Of Two Sorted Arrays | [c++](./leetcode/4.median-of-two-sorted-arrays.cpp), [python3](./leetcode/4.median-of-two-sorted-arrays.py) | Divide and Conquer | O\(log\(min\(M, N\)\)\) | O\(1\) | \- | - |
| [leetcode-23](https://leetcode.com/problems/merge-k-sorted-lists/) | Merge K Sorted Lists | [c++](./leetcode/23.merge-k-sorted-lists.cpp), [python3](./leetcode/23.merge-k-sorted-lists.py) | Divide and Conquer | O\(NlogK\) | O\(K\) | \- | - |
| [leetcode-191](https://leetcode.com/problems/number-of-1-bits/) | Number Of 1 Bits | [c++](./leetcode/191.number-of-1-bits.cpp), [python3](./leetcode/191.number-of-1-bits.py) | Divide and Conquer | O\(1\) | O\(1\) | \- | - |
| [leetcode-190](https://leetcode.com/problems/reverse-bits/) | Reverse Bits | [c++](./leetcode/190.reverse-bits.cpp), [python3](./leetcode/190.reverse-bits.py) | Divide and Conquer | O\(1\) | O\(1\) | \- | - |
| [leetcode-240](https://leetcode.com/problems/search-a-2d-matrix-ii/) | Search A 2D Matrix II | [c++](./leetcode/240.search-a-2d-matrix-ii.cpp), [python3](./leetcode/240.search-a-2d-matrix-ii.py) | Divide and Conquer | O\(M \+ N\) | O\(1\) | Matrix | - |
| [leetcode-148](https://leetcode.com/problems/sort-list/) | Sort List | [c++](./leetcode/148.sort-list.cpp), [python3](./leetcode/148.sort-list.py) | Divide and Conquer | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Divide and Conquer | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-347](https://leetcode.com/problems/top-k-frequent-elements/) | Top K Frequent Elements | [c++](./leetcode/347.top-k-frequent-elements.cpp), [python3](./leetcode/347.top-k-frequent-elements.py) | Divide and Conquer | O\(N\), O\(C\*logK\) | O\(N\) | \- | - |
| [lintcode-1534](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list/) | Convert Binary Search Tree To Sorted Doubly Linked List | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Divide and Conquer | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |
| [lintcode-11](https://www.lintcode.com/problem/search-range-in-binary-search-tree/) | Search Range In Binary Search Tree | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Divide and Conquer | O\(N\) | O\(H\) | InOrder | - |

## Breadth-First Search

| Link | Problem(25) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-542](https://leetcode.com/problems/01-matrix/) | 01 Matrix | [c++](./leetcode/542.01-matrix.cpp), [python3](./leetcode/542.01-matrix.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-637](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | Average Of Levels In Binary Tree | [c++](./leetcode/637.average-of-levels-in-binary-tree.cpp), [python3](./leetcode/637.average-of-levels-in-binary-tree.py) | Breadth-First Search | O\(N\) | O\(N\) | \- | - |
| [leetcode-102](https://leetcode.com/problems/binary-tree-level-order-traversal/) | Binary Tree Level Order Traversal | [c++](./leetcode/102.binary-tree-level-order-traversal.cpp), [python3](./leetcode/102.binary-tree-level-order-traversal.py) | Breadth-First Search | O\(N\) | O\(Width\) | Level | - |
| [leetcode-322](https://leetcode.com/problems/coin-change/) | Coin Change | [c++](./leetcode/322.coin-change.cpp), [python3](./leetcode/322.coin-change.py) | Breadth-First Search | O\(K \* N\) | O\(N\) | Index | [Video](https://youtu.be/EjMjlFjLRiM) |
| [leetcode-513](https://leetcode.com/problems/find-bottom-left-tree-value/) | Find Bottom Left Tree Value | [c++](./leetcode/513.find-bottom-left-tree-value.cpp), [python3](./leetcode/513.find-bottom-left-tree-value.py) | Breadth-First Search | O\(N\) | O\(W\) | \- | - |
| [leetcode-226](https://leetcode.com/problems/invert-binary-tree/) | Invert Binary Tree | [c++](./leetcode/226.invert-binary-tree.cpp), [python3](./leetcode/226.invert-binary-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-785](https://leetcode.com/problems/is-graph-bipartite/) | Is Graph Bipartite | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Breadth-First Search | O\(E\+V\) | O\(W\) | \- | - |
| [leetcode-695](https://leetcode.com/problems/max-area-of-island/) | Max Area Of Island | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Maximum Depth Of Binary Tree | [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python3](./leetcode/104.maximum-depth-of-binary-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | Recursion | - |
| [leetcode-617](https://leetcode.com/problems/merge-two-binary-trees/) | Merge Two Binary Trees | [c++](./leetcode/617.merge-two-binary-trees.cpp), [python3](./leetcode/617.merge-two-binary-trees.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-530](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | Minimum Absolute Difference In Bst | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | Minimum Depth Of Binary Tree | [c++](./leetcode/111.minimum-depth-of-binary-tree.cpp), [python3](./leetcode/111.minimum-depth-of-binary-tree.py) | Breadth-First Search | O\(N\) | O\(W\) | \- | - |
| [leetcode-200](https://leetcode.com/problems/number-of-islands/) | Number Of Islands | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-547](https://leetcode.com/problems/number-of-provinces/) | Number Of Provinces | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Breadth-First Search | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-417](https://leetcode.com/problems/pacific-atlantic-water-flow/) | Pacific Atlantic Water Flow | [c++](./leetcode/417.pacific-atlantic-water-flow.cpp), [python3](./leetcode/417.pacific-atlantic-water-flow.py) | Breadth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-1631](https://leetcode.com/problems/path-with-minimum-effort/) | Path With Minimum Effort | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Breadth-First Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| [leetcode-279](https://leetcode.com/problems/perfect-squares/) | Perfect Squares | [c++](./leetcode/279.perfect-squares.cpp), [python3](./leetcode/279.perfect-squares.py) | Breadth-First Search | O\(NlogN\) | O\(N\) | \- | - |
| [leetcode-684](https://leetcode.com/problems/redundant-connection/) | Redundant Connection | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Breadth-First Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | Serialize And Deserialize Binary Tree | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Breadth-First Search | O\(N\) | O\(N\) | Serialization | - |
| [leetcode-934](https://leetcode.com/problems/shortest-bridge/) | Shortest Bridge | [c++](./leetcode/934.shortest-bridge.cpp), [python3](./leetcode/934.shortest-bridge.py) | Breadth-First Search | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-404](https://leetcode.com/problems/sum-of-left-leaves/) | Sum Of Left Leaves | [c++](./leetcode/404.sum-of-left-leaves.cpp), [python3](./leetcode/404.sum-of-left-leaves.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-130](https://leetcode.com/problems/surrounded-regions/) | Surrounded Regions | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Breadth-First Search | O\(MN\) | O\(1\) | \- | - |
| [leetcode-101](https://leetcode.com/problems/symmetric-tree/) | Symmetric Tree | [c++](./leetcode/101.symmetric-tree.cpp), [python3](./leetcode/101.symmetric-tree.py) | Breadth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | Two Sum Iv Input Is A Bst | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Breadth-First Search | O\(NH\) | O\(H\) | \- | - |
| [leetcode-126](https://leetcode.com/problems/word-ladder-ii/) | Word Ladder II | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Breadth-First Search | O\(\(N\*L\)^C\) | O\(N\) | \- | - |

## Depth-First Search

| Link | Problem(38) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-637](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | Average Of Levels In Binary Tree | [c++](./leetcode/637.average-of-levels-in-binary-tree.cpp), [python3](./leetcode/637.average-of-levels-in-binary-tree.py) | Depth-First Search | O\(N\) | O\(N\) | \- | - |
| [leetcode-110](https://leetcode.com/problems/balanced-binary-tree/) | Balanced Binary Tree | [c++](./leetcode/110.balanced-binary-tree.cpp), [python3](./leetcode/110.balanced-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| [leetcode-94](https://leetcode.com/problems/binary-tree-inorder-traversal/) | Binary Tree Inorder Traversal | [c++](./leetcode/94.binary-tree-inorder-traversal.cpp), [python3](./leetcode/94.binary-tree-inorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | InOrder | - |
| [leetcode-145](https://leetcode.com/problems/binary-tree-postorder-traversal/) | Binary Tree Postorder Traversal | [c++](./leetcode/145.binary-tree-postorder-traversal.cpp), [python3](./leetcode/145.binary-tree-postorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | PostOrder | - |
| [leetcode-144](https://leetcode.com/problems/binary-tree-preorder-traversal/) | Binary Tree Preorder Traversal | [c++](./leetcode/144.binary-tree-preorder-traversal.cpp), [python3](./leetcode/144.binary-tree-preorder-traversal.py) | Depth-First Search | O\(N\) | O\(H\) | PreOrder | - |
| [leetcode-538](https://leetcode.com/problems/convert-bst-to-greater-tree/) | Convert Bst To Greater Tree | [c++](./leetcode/538.convert-bst-to-greater-tree.cpp), [python3](./leetcode/538.convert-bst-to-greater-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-1110](https://leetcode.com/problems/delete-nodes-and-return-forest/) | Delete Nodes And Return Forest | [c++](./leetcode/1110.delete-nodes-and-return-forest.cpp), [python3](./leetcode/1110.delete-nodes-and-return-forest.py) | Depth-First Search | O\(N\) | O\(N\) | \- | - |
| [leetcode-543](https://leetcode.com/problems/diameter-of-binary-tree/) | Diameter Of Binary Tree | [c++](./leetcode/543.diameter-of-binary-tree.cpp), [python3](./leetcode/543.diameter-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-513](https://leetcode.com/problems/find-bottom-left-tree-value/) | Find Bottom Left Tree Value | [c++](./leetcode/513.find-bottom-left-tree-value.cpp), [python3](./leetcode/513.find-bottom-left-tree-value.py) | Depth-First Search | O\(N\) | O\(W\) | \- | - |
| [leetcode-114](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | Flatten Binary Tree To Linked List | [c++](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python3](./leetcode/114.flatten-binary-tree-to-linked-list.py) | Depth-First Search | O\(N\) | O\(H\) | PreOrder | - |
| [leetcode-897](https://leetcode.com/problems/increasing-order-search-tree/) | Increasing Order Search Tree | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-226](https://leetcode.com/problems/invert-binary-tree/) | Invert Binary Tree | [c++](./leetcode/226.invert-binary-tree.cpp), [python3](./leetcode/226.invert-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-785](https://leetcode.com/problems/is-graph-bipartite/) | Is Graph Bipartite | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Depth-First Search | O\(E\+V\) | O\(W\) | \- | - |
| [leetcode-235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | Lowest Common Ancestor Of A Binary Search Tree | [c++](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.cpp), [python3](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Lowest Common Ancestor Of A Binary Tree | [c++](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp), [python3](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| [leetcode-695](https://leetcode.com/problems/max-area-of-island/) | Max Area Of Island | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Maximum Depth Of Binary Tree | [c++](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python3](./leetcode/104.maximum-depth-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(H\) | Recursion | - |
| [leetcode-617](https://leetcode.com/problems/merge-two-binary-trees/) | Merge Two Binary Trees | [c++](./leetcode/617.merge-two-binary-trees.cpp), [python3](./leetcode/617.merge-two-binary-trees.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-530](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | Minimum Absolute Difference In Bst | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | Minimum Depth Of Binary Tree | [c++](./leetcode/111.minimum-depth-of-binary-tree.cpp), [python3](./leetcode/111.minimum-depth-of-binary-tree.py) | Depth-First Search | O\(N\) | O\(W\) | \- | - |
| [leetcode-200](https://leetcode.com/problems/number-of-islands/) | Number Of Islands | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-547](https://leetcode.com/problems/number-of-provinces/) | Number Of Provinces | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Depth-First Search | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-417](https://leetcode.com/problems/pacific-atlantic-water-flow/) | Pacific Atlantic Water Flow | [c++](./leetcode/417.pacific-atlantic-water-flow.cpp), [python3](./leetcode/417.pacific-atlantic-water-flow.py) | Depth-First Search | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-437](https://leetcode.com/problems/path-sum-iii/) | Path Sum III | [c++](./leetcode/437.path-sum-iii.cpp), [python3](./leetcode/437.path-sum-iii.py) | Depth-First Search | O\(N^2\) | O\(H\) | \- | - |
| [leetcode-1631](https://leetcode.com/problems/path-with-minimum-effort/) | Path With Minimum Effort | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Depth-First Search | O\(NMlogNM\) | O\(NM\) | \- | - |
| [leetcode-332](https://leetcode.com/problems/reconstruct-itinerary/) | Reconstruct Itinerary | [c++](./leetcode/332.reconstruct-itinerary.cpp), [python3](./leetcode/332.reconstruct-itinerary.py) | Depth-First Search | O\(ElogE\) | O\(E\+V\) | Containers | - |
| [leetcode-99](https://leetcode.com/problems/recover-binary-search-tree/) | Recover Binary Search Tree | [c++](./leetcode/99.recover-binary-search-tree.cpp), [python3](./leetcode/99.recover-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-684](https://leetcode.com/problems/redundant-connection/) | Redundant Connection | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Depth-First Search | O\(N\) | O\(1\) | \- | - |
| [leetcode-297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | Serialize And Deserialize Binary Tree | [c++](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python3](./leetcode/297.serialize-and-deserialize-binary-tree.py) | Depth-First Search | O\(N\) | O\(N\) | Serialization | - |
| [leetcode-934](https://leetcode.com/problems/shortest-bridge/) | Shortest Bridge | [c++](./leetcode/934.shortest-bridge.cpp), [python3](./leetcode/934.shortest-bridge.py) | Depth-First Search | O\(N^2\) | O\(N^2\) | \- | - |
| [leetcode-572](https://leetcode.com/problems/subtree-of-another-tree/) | Subtree Of Another Tree | [c++](./leetcode/572.subtree-of-another-tree.cpp), [python3](./leetcode/572.subtree-of-another-tree.py) | Depth-First Search | O\(NM\) | O\(H\) | \- | - |
| [leetcode-404](https://leetcode.com/problems/sum-of-left-leaves/) | Sum Of Left Leaves | [c++](./leetcode/404.sum-of-left-leaves.cpp), [python3](./leetcode/404.sum-of-left-leaves.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-130](https://leetcode.com/problems/surrounded-regions/) | Surrounded Regions | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Depth-First Search | O\(MN\) | O\(1\) | \- | - |
| [leetcode-101](https://leetcode.com/problems/symmetric-tree/) | Symmetric Tree | [c++](./leetcode/101.symmetric-tree.cpp), [python3](./leetcode/101.symmetric-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-669](https://leetcode.com/problems/trim-a-binary-search-tree/) | Trim A Binary Search Tree | [c++](./leetcode/669.trim-a-binary-search-tree.cpp), [python3](./leetcode/669.trim-a-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | \- | - |
| [leetcode-653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | Two Sum Iv Input Is A Bst | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Depth-First Search | O\(NH\) | O\(H\) | \- | - |
| [leetcode-98](https://leetcode.com/problems/validate-binary-search-tree/) | Validate Binary Search Tree | [c++](./leetcode/98.validate-binary-search-tree.cpp), [python3](./leetcode/98.validate-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | BST | - |
| [lintcode-11](https://www.lintcode.com/problem/search-range-in-binary-search-tree/) | Search Range In Binary Search Tree | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Depth-First Search | O\(N\) | O\(H\) | InOrder | - |

## Topological Sort

| Link | Problem(2) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-210](https://leetcode.com/problems/course-schedule-ii/) | Course Schedule II | [c++](./leetcode/210.course-schedule-ii.cpp), [python3](./leetcode/210.course-schedule-ii.py) | Topological Sort | O\(E\+V\) | O\(E\+V\) | \- | - |
| [leetcode-310](https://leetcode.com/problems/minimum-height-trees/) | Minimum Height Trees | [c++](./leetcode/310.minimum-height-trees.cpp), [python3](./leetcode/310.minimum-height-trees.py) | Topological Sort | O\(N\) | O\(N\) | \- | - |

## Shortest Path

| Link | Problem(4) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-787](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Cheapest Flights Within K Stops | [c++](./leetcode/787.cheapest-flights-within-k-stops.cpp), [python3](./leetcode/787.cheapest-flights-within-k-stops.py) | Shortest Path | O\(ElogV\) | O\(E\+V\) | \- | - |
| [leetcode-743](https://leetcode.com/problems/network-delay-time/) | Network Delay Time | [c++](./leetcode/743.network-delay-time.cpp), [python3](./leetcode/743.network-delay-time.py) | Shortest Path | O\(ElogE\) | O\(E\+V\) | \- | - |
| [leetcode-1514](https://leetcode.com/problems/path-with-maximum-probability/) | Path With Maximum Probability | [c++](./leetcode/1514.path-with-maximum-probability.cpp), [python3](./leetcode/1514.path-with-maximum-probability.py) | Shortest Path | O\(VlogE\) | O\(V\+E\) | \- | - |
| [leetcode-882](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/) | Reachable Nodes In Subdivided Graph | [c++](./leetcode/882.reachable-nodes-in-subdivided-graph.cpp), [python3](./leetcode/882.reachable-nodes-in-subdivided-graph.py) | Shortest Path | O\(ElogE\) | O\(V\+E\) | \- | - |

## Backtracking

| Link | Problem(13) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-257](https://leetcode.com/problems/binary-tree-paths/) | Binary Tree Paths | [c++](./leetcode/257.binary-tree-paths.cpp), [python3](./leetcode/257.binary-tree-paths.py) | Backtracking | O\(N\) | O\(H\) | \- | - |
| [leetcode-40](https://leetcode.com/problems/combination-sum-ii/) | Combination Sum II | [c++](./leetcode/40.combination-sum-ii.cpp), [python3](./leetcode/40.combination-sum-ii.py) | Backtracking | O\(2^N\) | O\(N\) | \- | - |
| [leetcode-77](https://leetcode.com/problems/combinations/) | Combinations | [c++](./leetcode/77.combinations.cpp), [python3](./leetcode/77.combinations.py) | Backtracking | O\(k \* C\(n, k\)\) | O\(K\) | \- | - |
| [leetcode-22](https://leetcode.com/problems/generate-parentheses/) | Generate Parentheses | [c++](./leetcode/22.generate-parentheses.cpp), [python3](./leetcode/22.generate-parentheses.py) | Backtracking | O\(2^N\) | O\(N\) | Catalan Number | - |
| [leetcode-51](https://leetcode.com/problems/n-queens/) | N Queens | [c++](./leetcode/51.n-queens.cpp), [python3](./leetcode/51.n-queens.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| [leetcode-52](https://leetcode.com/problems/n-queens-ii/) | N Queens II | [c++](./leetcode/52.n-queens-ii.cpp), [python3](./leetcode/52.n-queens-ii.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| [leetcode-46](https://leetcode.com/problems/permutations/) | Permutations | [c++](./leetcode/46.permutations.cpp), [python3](./leetcode/46.permutations.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| [leetcode-47](https://leetcode.com/problems/permutations-ii/) | Permutations II | [c++](./leetcode/47.permutations-ii.cpp), [python3](./leetcode/47.permutations-ii.py) | Backtracking | O\(N\!\) | O\(N\) | \- | - |
| [leetcode-37](https://leetcode.com/problems/sudoku-solver/) | Sudoku Solver | [c++](./leetcode/37.sudoku-solver.cpp), [python3](./leetcode/37.sudoku-solver.py) | Backtracking | O\(N^\(N^2\)\) | O\(N\) | \- | - |
| [leetcode-494](https://leetcode.com/problems/target-sum/) | Target Sum | [c++](./leetcode/494.target-sum.cpp), [python3](./leetcode/494.target-sum.py) | Backtracking | O\(N \* Sum\) | O\(N \* Sum\) | \- | - |
| [leetcode-126](https://leetcode.com/problems/word-ladder-ii/) | Word Ladder II | [c++](./leetcode/126.word-ladder-ii.cpp), [python3](./leetcode/126.word-ladder-ii.py) | Backtracking | O\(\(N\*L\)^C\) | O\(N\) | \- | - |
| [leetcode-79](https://leetcode.com/problems/word-search/) | Word Search | [c++](./leetcode/79.word-search.cpp), [python3](./leetcode/79.word-search.py) | Backtracking | O\(MN\*4^L\) | O\(MN\) | \- | - |
| [leetcode-212](https://leetcode.com/problems/word-search-ii/) | Word Search II | [c++](./leetcode/212.word-search-ii.cpp), [python3](./leetcode/212.word-search-ii.py) | Backtracking | O\(NM\*4^L\) | O\(MN \+ KL\) | \- | - |

## Line Sweep

| Link | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Line Sweep | O\(NlogN\) | O\(N\) | \- | - |

## Ordered Set

| Link | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Ordered Set | O\(NlogN\) | O\(N\) | \- | - |

## Binary Search Tree

| Link | Problem(16) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-173](https://leetcode.com/problems/binary-search-tree-iterator/) | Binary Search Tree Iterator | [c++](./leetcode/173.binary-search-tree-iterator.cpp), [python3](./leetcode/173.binary-search-tree-iterator.py) | Binary Search Tree | O\(1\) | O\(H\) | InOrder | - |
| [leetcode-538](https://leetcode.com/problems/convert-bst-to-greater-tree/) | Convert Bst To Greater Tree | [c++](./leetcode/538.convert-bst-to-greater-tree.cpp), [python3](./leetcode/538.convert-bst-to-greater-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | Convert Sorted List To Binary Search Tree | [c++](./leetcode/109.convert-sorted-list-to-binary-search-tree.cpp), [python3](./leetcode/109.convert-sorted-list-to-binary-search-tree.py) | Binary Search Tree | O\(NlogN\) | O\(logN\) | \- | - |
| [leetcode-450](https://leetcode.com/problems/delete-node-in-a-bst/) | Delete Node In A Bst | [c++](./leetcode/450.delete-node-in-a-bst.cpp), [python3](./leetcode/450.delete-node-in-a-bst.py) | Binary Search Tree | O\(H\) | O\(H\) | Delete | - |
| [leetcode-897](https://leetcode.com/problems/increasing-order-search-tree/) | Increasing Order Search Tree | [c++](./leetcode/897.increasing-order-search-tree.cpp), [python3](./leetcode/897.increasing-order-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-701](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | Insert Into A Binary Search Tree | [c++](./leetcode/701.insert-into-a-binary-search-tree.cpp), [python3](./leetcode/701.insert-into-a-binary-search-tree.py) | Binary Search Tree | O\(H\) | O\(H\) | Insert | - |
| [leetcode-703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | Kth Largest Element In A Stream | [c++](./leetcode/703.kth-largest-element-in-a-stream.cpp), [python3](./leetcode/703.kth-largest-element-in-a-stream.py) | Binary Search Tree | O\(logN\) | O\(N\) | \- | - |
| [leetcode-235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | Lowest Common Ancestor Of A Binary Search Tree | [c++](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.cpp), [python3](./leetcode/235.lowest-common-ancestor-of-a-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-530](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | Minimum Absolute Difference In Bst | [c++](./leetcode/530.minimum-absolute-difference-in-bst.cpp), [python3](./leetcode/530.minimum-absolute-difference-in-bst.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-99](https://leetcode.com/problems/recover-binary-search-tree/) | Recover Binary Search Tree | [c++](./leetcode/99.recover-binary-search-tree.cpp), [python3](./leetcode/99.recover-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-669](https://leetcode.com/problems/trim-a-binary-search-tree/) | Trim A Binary Search Tree | [c++](./leetcode/669.trim-a-binary-search-tree.cpp), [python3](./leetcode/669.trim-a-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | \- | - |
| [leetcode-653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | Two Sum Iv Input Is A Bst | [c++](./leetcode/653.two-sum-iv-input-is-a-bst.cpp), [python3](./leetcode/653.two-sum-iv-input-is-a-bst.py) | Binary Search Tree | O\(NH\) | O\(H\) | \- | - |
| [leetcode-98](https://leetcode.com/problems/validate-binary-search-tree/) | Validate Binary Search Tree | [c++](./leetcode/98.validate-binary-search-tree.cpp), [python3](./leetcode/98.validate-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | BST | - |
| [lintcode-1534](https://www.lintcode.com/problem/convert-binary-search-tree-to-sorted-doubly-linked-list/) | Convert Binary Search Tree To Sorted Doubly Linked List | [c++](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python3](./lintcode/1534.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | Binary Search Tree | O\(N\) | O\(H\) | BST \| Leetcode\-426 | - |
| [lintcode-448](https://www.lintcode.com/problem/inorder-successor-in-bst/) | Inorder Successor In Bst | [c++](./lintcode/448.inorder-successor-in-bst.cpp), [python3](./lintcode/448.inorder-successor-in-bst.py) | Binary Search Tree | O\(H\) | O\(1\) | Successor \| Leetcode\-285 | - |
| [lintcode-11](https://www.lintcode.com/problem/search-range-in-binary-search-tree/) | Search Range In Binary Search Tree | [c++](./lintcode/11.search-range-in-binary-search-tree.cpp), [python3](./lintcode/11.search-range-in-binary-search-tree.py) | Binary Search Tree | O\(N\) | O\(H\) | InOrder | - |

## Binary Indexed Tree

| Link | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-406](https://leetcode.com/problems/queue-reconstruction-by-height/) | Queue Reconstruction By Height | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Binary Indexed Tree | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-307](https://leetcode.com/problems/range-sum-query-mutable/) | Range Sum Query Mutable | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Binary Indexed Tree | O\(logN\) | O\(N\) | \- | - |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Binary Indexed Tree | O\(NlogN\) | O\(N\) | \- | - |

## Segment Tree

| Link | Problem(7) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-406](https://leetcode.com/problems/queue-reconstruction-by-height/) | Queue Reconstruction By Height | [c++](./leetcode/406.queue-reconstruction-by-height.cpp), [python3](./leetcode/406.queue-reconstruction-by-height.py) | Segment Tree | O\(NlogN\) | O\(1\) | \- | - |
| [leetcode-307](https://leetcode.com/problems/range-sum-query-mutable/) | Range Sum Query Mutable | [c++](./leetcode/307.range-sum-query-mutable.cpp), [python3](./leetcode/307.range-sum-query-mutable.py) | Segment Tree | O\(logN\) | O\(N\) | \- | - |
| [leetcode-218](https://leetcode.com/problems/the-skyline-problem/) | The Skyline Problem | [c++](./leetcode/218.the-skyline-problem.cpp), [python3](./leetcode/218.the-skyline-problem.py) | Segment Tree | O\(NlogN\) | O\(N\) | \- | - |
| [lintcode-205](https://www.lintcode.com/problem/interval-minimum-number/) | Interval Minimum Number | [c++](./lintcode/205.interval-minimum-number.cpp), [python3](./lintcode/205.interval-minimum-number.py) | Segment Tree | O\(NlogN\) | O\(N\) | \- | - |
| [lintcode-201](https://www.lintcode.com/problem/segment-tree-build/) | Segment Tree Build | [c++](./lintcode/201.segment-tree-build.cpp), [python3](./lintcode/201.segment-tree-build.py) | Segment Tree | O\(N\) | O\(1\) | \- | - |
| [lintcode-439](https://www.lintcode.com/problem/segment-tree-build-ii/) | Segment Tree Build II | [c++](./lintcode/439.segment-tree-build-ii.cpp), [python3](./lintcode/439.segment-tree-build-ii.py) | Segment Tree | O\(N\) | O\(1\) | \- | - |
| [lintcode-203](https://www.lintcode.com/problem/segment-tree-modify/) | Segment Tree Modify | [c++](./lintcode/203.segment-tree-modify.cpp), [python3](./lintcode/203.segment-tree-modify.py) | Segment Tree | O\(logN\) | O\(1\) | \- | - |

## Union Find

| Link | Problem(9) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-785](https://leetcode.com/problems/is-graph-bipartite/) | Is Graph Bipartite | [c++](./leetcode/785.is-graph-bipartite.cpp), [python3](./leetcode/785.is-graph-bipartite.py) | Union Find | O\(E\+V\) | O\(W\) | \- | - |
| [leetcode-128](https://leetcode.com/problems/longest-consecutive-sequence/) | Longest Consecutive Sequence | [c++](./leetcode/128.longest-consecutive-sequence.cpp), [python3](./leetcode/128.longest-consecutive-sequence.py) | Union Find | O\(N\) | O\(N\) | \- | - |
| [leetcode-695](https://leetcode.com/problems/max-area-of-island/) | Max Area Of Island | [c++](./leetcode/695.max-area-of-island.cpp), [python3](./leetcode/695.max-area-of-island.py) | Union Find | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-200](https://leetcode.com/problems/number-of-islands/) | Number Of Islands | [c++](./leetcode/200.number-of-islands.cpp), [python3](./leetcode/200.number-of-islands.py) | Union Find | O\(MN\) | O\(MN\) | \- | - |
| [leetcode-547](https://leetcode.com/problems/number-of-provinces/) | Number Of Provinces | [c++](./leetcode/547.number-of-provinces.cpp), [python3](./leetcode/547.number-of-provinces.py) | Union Find | O\(N^2\) | O\(N\) | \- | - |
| [leetcode-1631](https://leetcode.com/problems/path-with-minimum-effort/) | Path With Minimum Effort | [c++](./leetcode/1631.path-with-minimum-effort.cpp), [python3](./leetcode/1631.path-with-minimum-effort.py) | Union Find | O\(NMlogNM\) | O\(NM\) | \- | - |
| [leetcode-684](https://leetcode.com/problems/redundant-connection/) | Redundant Connection | [c++](./leetcode/684.redundant-connection.cpp), [python3](./leetcode/684.redundant-connection.py) | Union Find | O\(N\) | O\(1\) | \- | - |
| [leetcode-130](https://leetcode.com/problems/surrounded-regions/) | Surrounded Regions | [c++](./leetcode/130.surrounded-regions.cpp), [python3](./leetcode/130.surrounded-regions.py) | Union Find | O\(MN\) | O\(1\) | \- | - |
| [lintcode-3672](https://www.lintcode.com/problem/connecting-cities-with-minimum-cost/) | Connecting Cities With Minimum Cost | [c++](./lintcode/3672.connecting-cities-with-minimum-cost.cpp), [python3](./lintcode/3672.connecting-cities-with-minimum-cost.py) | Union Find | O\(ElogE\) | O\(E\+V\) | Leetcode\-1135 | - |

## Trie

| Link | Problem(3) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-208](https://leetcode.com/problems/implement-trie-prefix-tree/) | Implement Trie Prefix Tree | [c++](./leetcode/208.implement-trie-prefix-tree.cpp), [python3](./leetcode/208.implement-trie-prefix-tree.py) | Trie | O\(N\) | O\(L\) | \- | - |
| [leetcode-139](https://leetcode.com/problems/word-break/) | Word Break | [c++](./leetcode/139.word-break.cpp), [python3](./leetcode/139.word-break.py) | Trie | O\(MN\) | O\(N\) | \- | - |
| [leetcode-212](https://leetcode.com/problems/word-search-ii/) | Word Search II | [c++](./leetcode/212.word-search-ii.cpp), [python3](./leetcode/212.word-search-ii.py) | Trie | O\(NM\*4^L\) | O\(MN \+ KL\) | \- | - |

## Array

| Link | Problem(4) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-2210](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/) | Count Hills And Valleys In An Array | [c++](./leetcode/2210.count-hills-and-valleys-in-an-array.cpp), [python3](./leetcode/2210.count-hills-and-valleys-in-an-array.py) | Array | O\(N\) | O\(1\) | \- | - |
| [leetcode-674](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | Longest Continuous Increasing Subsequence | [c++](./leetcode/674.longest-continuous-increasing-subsequence.cpp), [python3](./leetcode/674.longest-continuous-increasing-subsequence.py) | Array | O\(N\) | O\(1\) | \- | - |
| [leetcode-665](https://leetcode.com/problems/non-decreasing-array/) | Non Decreasing Array | [c++](./leetcode/665.non-decreasing-array.cpp), [python3](./leetcode/665.non-decreasing-array.py) | Array | O\(N\) | O\(1\) | \- | - |
| [leetcode-238](https://leetcode.com/problems/product-of-array-except-self/) | Product Of Array Except Self | [c++](./leetcode/238.product-of-array-except-self.cpp), [python3](./leetcode/238.product-of-array-except-self.py) | Array | O\(N\) | O\(1\) | \- | - |

## String

| Link | Problem(1) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [lintcode-1790](https://www.lintcode.com/problem/rotate-string-ii/) | Rotate String II | [c++](./lintcode/1790.rotate-string-ii.cpp), [python3](./lintcode/1790.rotate-string-ii.py) | String | O\(N\) | O\(N\) | Simulation | - |

## Other

| Link | Problem(163) | Solution | Tag | Time | Space | Note | Ref |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| [leetcode-16](https://leetcode.com/problems/3sum-closest/) | 3Sum Closest | [c++](./leetcode/16.3sum-closest.cpp), [python3](./leetcode/16.3sum-closest.py) | Other | \- | \- | \- | - |
| [leetcode-454](https://leetcode.com/problems/4sum-ii/) | 4Sum II | [c++](./leetcode/454.4sum-ii.cpp) | Other | \- | \- | \- | - |
| [leetcode-721](https://leetcode.com/problems/accounts-merge/) | Accounts Merge | [c++](./leetcode/721.accounts-merge.cpp), [python3](./leetcode/721.accounts-merge.py) | Other | \- | \- | \- | - |
| [leetcode-211](https://leetcode.com/problems/add-and-search-word-data-structure-design/) | Add And Search Word Data Structure Design | [c++](./leetcode/211.add-and-search-word-data-structure-design.cpp), [python3](./leetcode/211.add-and-search-word-data-structure-design.py) | Other | \- | \- | \- | - |
| [leetcode-2](https://leetcode.com/problems/add-two-numbers/) | Add Two Numbers | [c++](./leetcode/2.add-two-numbers.cpp), [python3](./leetcode/2.add-two-numbers.py) | Other | \- | \- | \- | - |
| [leetcode-269](https://leetcode.com/problems/alien-dictionary/) | Alien Dictionary | [python3](./leetcode/269.alien-dictionary.py) | Other | \- | \- | \- | - |
| [leetcode-561](https://leetcode.com/problems/array-partition-i/) | Array Partition I | [c++](./leetcode/561.array-partition-i.cpp) | Other | \- | \- | \- | - |
| [leetcode-844](https://leetcode.com/problems/backspace-string-compare/) | Backspace String Compare | [c++](./leetcode/844.backspace-string-compare.cpp), [python3](./leetcode/844.backspace-string-compare.py) | Other | \- | \- | \- | - |
| [leetcode-107](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | Binary Tree Level Order Traversal II | [c++](./leetcode/107.binary-tree-level-order-traversal-ii.cpp), [python3](./leetcode/107.binary-tree-level-order-traversal-ii.py) | Other | \- | \- | \- | - |
| [leetcode-156](https://leetcode.com/problems/binary-tree-upside-down/) | Binary Tree Upside Down | [c++](./leetcode/156.binary-tree-upside-down.cpp), [python3](./leetcode/156.binary-tree-upside-down.py) | Other | \- | \- | \- | - |
| [leetcode-314](https://leetcode.com/problems/binary-tree-vertical-order-traversal/) | Binary Tree Vertical Order Traversal | [c++](./leetcode/314.binary-tree-vertical-order-traversal.cpp), [python3](./leetcode/314.binary-tree-vertical-order-traversal.py) | Other | \- | \- | \- | - |
| [leetcode-103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | Binary Tree Zigzag Level Order Traversal | [c++](./leetcode/103.binary-tree-zigzag-level-order-traversal.cpp), [python3](./leetcode/103.binary-tree-zigzag-level-order-traversal.py) | Other | \- | \- | \- | - |
| [leetcode-859](https://leetcode.com/problems/buddy-strings/) | Buddy Strings | [c++](./leetcode/859.buddy-strings.cpp) | Other | \- | \- | \- | - |
| [leetcode-815](https://leetcode.com/problems/bus-routes/) | Bus Routes | [python3](./leetcode/815.bus-routes.py) | Other | \- | \- | \- | - |
| [leetcode-1150](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/) | Check If A Number Is Majority Element In A Sorted Array | [c++](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.cpp), [python3](./leetcode/1150.check-if-a-number-is-majority-element-in-a-sorted-array.py) | Other | \- | \- | \- | - |
| [leetcode-133](https://leetcode.com/problems/clone-graph/) | Clone Graph | [c++](./leetcode/133.clone-graph.cpp), [python3](./leetcode/133.clone-graph.py) | Other | \- | \- | \- | - |
| [leetcode-270](https://leetcode.com/problems/closest-binary-search-tree-value/) | Closest Binary Search Tree Value | [c++](./leetcode/270.closest-binary-search-tree-value.cpp), [python3](./leetcode/270.closest-binary-search-tree-value.py) | Other | \- | \- | \- | - |
| [leetcode-39](https://leetcode.com/problems/combination-sum/) | Combination Sum | [c++](./leetcode/39.combination-sum.cpp), [python3](./leetcode/39.combination-sum.py) | Other | \- | \- | \- | - |
| [leetcode-377](https://leetcode.com/problems/combination-sum-iv/) | Combination Sum IV | [c++](./leetcode/377.combination-sum-iv.cpp), [python3](./leetcode/377.combination-sum-iv.py) | Other | \- | \- | \- | - |
| [leetcode-175](https://leetcode.com/problems/combine-two-tables/) | Combine Two Tables | [sql](./leetcode/175.combine-two-tables.sql) | Other | - | - | - | - |
| [leetcode-829](https://leetcode.com/problems/consecutive-numbers-sum/) | Consecutive Numbers Sum | [python3](./leetcode/829.consecutive-numbers-sum.py) | Other | \- | \- | \- | - |
| [leetcode-11](https://leetcode.com/problems/container-with-most-water/) | Container With Most Water | [python3](./leetcode/11.container-with-most-water.py) | Other | \- | \- | \- | - |
| [leetcode-219](https://leetcode.com/problems/contains-duplicate-ii/) | Contains Duplicate II | [c++](./leetcode/219.contains-duplicate-ii.cpp) | Other | \- | \- | \- | - |
| [leetcode-138](https://leetcode.com/problems/copy-list-with-random-pointer/) | Copy List With Random Pointer | [python3](./leetcode/138.copy-list-with-random-pointer.py) | Other | \- | \- | \- | - |
| [leetcode-38](https://leetcode.com/problems/count-and-say/) | Count And Say | [python3](./leetcode/38.count-and-say.py) | Other | \- | \- | \- | - |
| [leetcode-207](https://leetcode.com/problems/course-schedule/) | Course Schedule | [c++](./leetcode/207.course-schedule.cpp), [python3](./leetcode/207.course-schedule.py) | Other | \- | \- | \- | - |
| [leetcode-394](https://leetcode.com/problems/decode-string/) | Decode String | [c++](./leetcode/394.decode-string.cpp), [python3](./leetcode/394.decode-string.py) | Other | \- | \- | \- | - |
| [leetcode-237](https://leetcode.com/problems/delete-node-in-a-linked-list/) | Delete Node In A Linked List | [python3](./leetcode/237.delete-node-in-a-linked-list.py) | Other | \- | \- | \- | - |
| [leetcode-498](https://leetcode.com/problems/diagonal-traverse/) | Diagonal Traverse | [c++](./leetcode/498.diagonal-traverse.cpp) | Other | \- | \- | \- | - |
| [leetcode-29](https://leetcode.com/problems/divide-two-integers/) | Divide Two Integers | [c++](./leetcode/29.divide-two-integers.cpp), [python3](./leetcode/29.divide-two-integers.py) | Other | \- | \- | \- | - |
| [leetcode-271](https://leetcode.com/problems/encode-and-decode-strings/) | Encode And Decode Strings | [c++](./leetcode/271.encode-and-decode-strings.cpp), [python3](./leetcode/271.encode-and-decode-strings.py) | Other | \- | \- | \- | - |
| [leetcode-535](https://leetcode.com/problems/encode-and-decode-tinyurl/) | Encode And Decode Tinyurl | [python3](./leetcode/535.encode-and-decode-tinyurl.py) | Other | \- | \- | \- | - |
| [leetcode-282](https://leetcode.com/problems/expression-add-operators/) | Expression Add Operators | [c++](./leetcode/282.expression-add-operators.cpp), [python3](./leetcode/282.expression-add-operators.py) | Other | \- | \- | \- | - |
| [leetcode-760](https://leetcode.com/problems/find-anagram-mappings/) | Find Anagram Mappings | [python3](./leetcode/760.find-anagram-mappings.py) | Other | \- | \- | \- | - |
| [leetcode-652](https://leetcode.com/problems/find-duplicate-subtrees/) | Find Duplicate Subtrees | [c++](./leetcode/652.find-duplicate-subtrees.cpp) | Other | \- | \- | \- | - |
| [leetcode-366](https://leetcode.com/problems/find-leaves-of-binary-tree/) | Find Leaves Of Binary Tree | [c++](./leetcode/366.find-leaves-of-binary-tree.cpp), [python3](./leetcode/366.find-leaves-of-binary-tree.py) | Other | \- | \- | \- | - |
| [leetcode-295](https://leetcode.com/problems/find-median-from-data-stream/) | Find Median From Data Stream | [c++](./leetcode/295.find-median-from-data-stream.cpp), [python3](./leetcode/295.find-median-from-data-stream.py) | Other | \- | \- | \- | - |
| [leetcode-724](https://leetcode.com/problems/find-pivot-index/) | Find Pivot Index | [c++](./leetcode/724.find-pivot-index.cpp) | Other | \- | \- | \- | - |
| [leetcode-277](https://leetcode.com/problems/find-the-celebrity/) | Find The Celebrity | [c++](./leetcode/277.find-the-celebrity.cpp), [python3](./leetcode/277.find-the-celebrity.py) | Other | \- | \- | \- | - |
| [leetcode-41](https://leetcode.com/problems/first-missing-positive/) | First Missing Positive | [python3](./leetcode/41.first-missing-positive.py) | Other | \- | \- | \- | - |
| [leetcode-387](https://leetcode.com/problems/first-unique-character-in-a-string/) | First Unique Character In A String | [c++](./leetcode/387.first-unique-character-in-a-string.cpp), [python3](./leetcode/387.first-unique-character-in-a-string.py) | Other | \- | \- | \- | - |
| [leetcode-251](https://leetcode.com/problems/flatten-2d-vector/) | Flatten 2D Vector | [python3](./leetcode/251.flatten-2d-vector.py) | Other | \- | \- | \- | - |
| [leetcode-341](https://leetcode.com/problems/flatten-nested-list-iterator/) | Flatten Nested List Iterator | [python3](./leetcode/341.flatten-nested-list-iterator.py) | Other | \- | \- | \- | - |
| [leetcode-832](https://leetcode.com/problems/flipping-an-image/) | Flipping An Image | [python3](./leetcode/832.flipping-an-image.py) | Other | \- | \- | \- | - |
| [leetcode-289](https://leetcode.com/problems/game-of-life/) | Game Of Life | [python3](./leetcode/289.game-of-life.py) | Other | \- | \- | \- | - |
| [leetcode-261](https://leetcode.com/problems/graph-valid-tree/) | Graph Valid Tree | [c++](./leetcode/261.graph-valid-tree.cpp), [python3](./leetcode/261.graph-valid-tree.py) | Other | \- | \- | \- | - |
| [leetcode-249](https://leetcode.com/problems/group-shifted-strings/) | Group Shifted Strings | [c++](./leetcode/249.group-shifted-strings.cpp) | Other | \- | \- | \- | - |
| [leetcode-57](https://leetcode.com/problems/insert-interval/) | Insert Interval | [c++](./leetcode/57.insert-interval.cpp), [python3](./leetcode/57.insert-interval.py) | Other | \- | \- | \- | - |
| [leetcode-273](https://leetcode.com/problems/integer-to-english-words/) | Integer To English Words | [python3](./leetcode/273.integer-to-english-words.py) | Other | \- | \- | \- | - |
| [leetcode-12](https://leetcode.com/problems/integer-to-roman/) | Integer To Roman | [c++](./leetcode/12.integer-to-roman.cpp), [python3](./leetcode/12.integer-to-roman.py) | Other | \- | \- | \- | - |
| [leetcode-349](https://leetcode.com/problems/intersection-of-two-arrays/) | Intersection Of Two Arrays | [c++](./leetcode/349.intersection-of-two-arrays.cpp), [python3](./leetcode/349.intersection-of-two-arrays.py) | Other | \- | \- | \- | - |
| [leetcode-350](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | Intersection Of Two Arrays II | [c++](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python3](./leetcode/350.intersection-of-two-arrays-ii.py) | Other | \- | \- | \- | - |
| [leetcode-751](https://leetcode.com/problems/ip-to-cidr/) | Ip To Cidr | [python3](./leetcode/751.ip-to-cidr.py) | Other | \- | \- | \- | - |
| [leetcode-463](https://leetcode.com/problems/island-perimeter/) | Island Perimeter | [python3](./leetcode/463.island-perimeter.py) | Other | \- | \- | \- | - |
| [leetcode-771](https://leetcode.com/problems/jewels-and-stones/) | Jewels And Stones | [c++](./leetcode/771.jewels-and-stones.cpp) | Other | \- | \- | \- | - |
| [leetcode-45](https://leetcode.com/problems/jump-game-ii/) | Jump Game II | [c++](./leetcode/45.jump-game-ii.cpp), [python3](./leetcode/45.jump-game-ii.py) | Other | \- | \- | \- | - |
| [leetcode-532](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | K Diff Pairs In An Array | [c++](./leetcode/532.k-diff-pairs-in-an-array.cpp), [python3](./leetcode/532.k-diff-pairs-in-an-array.py) | Other | \- | \- | \- | - |
| [leetcode-683](https://leetcode.com/problems/k-empty-slots/) | K Empty Slots | [c++](./leetcode/683.k-empty-slots.cpp), [python3](./leetcode/683.k-empty-slots.py) | Other | \- | \- | \- | - |
| [leetcode-378](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | Kth Smallest Element In A Sorted Matrix | [c++](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.cpp), [python3](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.py) | Other | \- | \- | \- | - |
| [leetcode-368](https://leetcode.com/problems/largest-divisible-subset/) | Largest Divisible Subset | [c++](./leetcode/368.largest-divisible-subset.cpp), [python3](./leetcode/368.largest-divisible-subset.py) | Other | \- | \- | \- | - |
| [leetcode-747](https://leetcode.com/problems/largest-number-at-least-twice-of-others/) | Largest Number At Least Twice Of Others | [c++](./leetcode/747.largest-number-at-least-twice-of-others.cpp) | Other | \- | \- | \- | - |
| [leetcode-84](https://leetcode.com/problems/largest-rectangle-in-histogram/) | Largest Rectangle In Histogram | [c++](./leetcode/84.largest-rectangle-in-histogram.cpp), [python3](./leetcode/84.largest-rectangle-in-histogram.py) | Other | \- | \- | \- | - |
| [leetcode-17](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | Letter Combinations Of A Phone Number | [c++](./leetcode/17.letter-combinations-of-a-phone-number.cpp), [python3](./leetcode/17.letter-combinations-of-a-phone-number.py) | Other | \- | \- | \- | - |
| [leetcode-359](https://leetcode.com/problems/logger-rate-limiter/) | Logger Rate Limiter | [c++](./leetcode/359.logger-rate-limiter.cpp) | Other | \- | \- | \- | - |
| [leetcode-388](https://leetcode.com/problems/longest-absolute-file-path/) | Longest Absolute File Path | [c++](./leetcode/388.longest-absolute-file-path.cpp), [python3](./leetcode/388.longest-absolute-file-path.py) | Other | \- | \- | \- | - |
| [leetcode-14](https://leetcode.com/problems/longest-common-prefix/) | Longest Common Prefix | [c++](./leetcode/14.longest-common-prefix.cpp), [python3](./leetcode/14.longest-common-prefix.py) | Other | \- | \- | \- | - |
| [leetcode-159](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) | Longest Substring With At Most Two Distinct Characters | [c++](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.cpp), [python3](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.py) | Other | \- | \- | \- | - |
| [leetcode-687](https://leetcode.com/problems/longest-univalue-path/) | Longest Univalue Path | [c++](./leetcode/687.longest-univalue-path.cpp), [python3](./leetcode/687.longest-univalue-path.py) | Other | \- | \- | \- | - |
| [leetcode-229](https://leetcode.com/problems/majority-element-ii/) | Majority Element II | [c++](./leetcode/229.majority-element-ii.cpp), [python3](./leetcode/229.majority-element-ii.py) | Other | \- | \- | \- | - |
| [leetcode-677](https://leetcode.com/problems/map-sum-pairs/) | Map Sum Pairs | [c++](./leetcode/677.map-sum-pairs.cpp), [python3](./leetcode/677.map-sum-pairs.py) | Other | \- | \- | \- | - |
| [leetcode-485](https://leetcode.com/problems/max-consecutive-ones/) | Max Consecutive Ones | [c++](./leetcode/485.max-consecutive-ones.cpp) | Other | \- | \- | \- | - |
| [leetcode-85](https://leetcode.com/problems/maximal-rectangle/) | Maximal Rectangle | [c++](./leetcode/85.maximal-rectangle.cpp), [python3](./leetcode/85.maximal-rectangle.py) | Other | \- | \- | \- | - |
| [leetcode-654](https://leetcode.com/problems/maximum-binary-tree/) | Maximum Binary Tree | [c++](./leetcode/654.maximum-binary-tree.cpp), [python3](./leetcode/654.maximum-binary-tree.py) | Other | \- | \- | \- | - |
| [leetcode-253](https://leetcode.com/problems/meeting-rooms-ii/) | Meeting Rooms II | [c++](./leetcode/253.meeting-rooms-ii.cpp), [python3](./leetcode/253.meeting-rooms-ii.py) | Other | \- | \- | \- | - |
| [leetcode-56](https://leetcode.com/problems/merge-intervals/) | Merge Intervals | [c++](./leetcode/56.merge-intervals.cpp), [python3](./leetcode/56.merge-intervals.py) | Other | \- | \- | \- | - |
| [leetcode-924](https://leetcode.com/problems/minimize-malware-spread/) | Minimize Malware Spread | [python3](./leetcode/924.minimize-malware-spread.py) | Other | \- | \- | \- | - |
| [leetcode-928](https://leetcode.com/problems/minimize-malware-spread-ii/) | Minimize Malware Spread II | [python3](./leetcode/928.minimize-malware-spread-ii.py) | Other | \- | \- | \- | - |
| [leetcode-433](https://leetcode.com/problems/minimum-genetic-mutation/) | Minimum Genetic Mutation | [c++](./leetcode/433.minimum-genetic-mutation.cpp), [python3](./leetcode/433.minimum-genetic-mutation.py) | Other | \- | \- | \- | - |
| [leetcode-599](https://leetcode.com/problems/minimum-index-sum-of-two-lists/) | Minimum Index Sum Of Two Lists | [c++](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | Other | \- | \- | \- | - |
| [leetcode-209](https://leetcode.com/problems/minimum-size-subarray-sum/) | Minimum Size Subarray Sum | [c++](./leetcode/209.minimum-size-subarray-sum.cpp), [python3](./leetcode/209.minimum-size-subarray-sum.py) | Other | \- | \- | \- | - |
| [leetcode-163](https://leetcode.com/problems/missing-ranges/) | Missing Ranges | [c++](./leetcode/163.missing-ranges.cpp), [python3](./leetcode/163.missing-ranges.py) | Other | \- | \- | \- | - |
| [leetcode-283](https://leetcode.com/problems/move-zeroes/) | Move Zeroes | [c++](./leetcode/283.move-zeroes.cpp), [python3](./leetcode/283.move-zeroes.py) | Other | \- | \- | \- | - |
| [leetcode-346](https://leetcode.com/problems/moving-average-from-data-stream/) | Moving Average From Data Stream | [c++](./leetcode/346.moving-average-from-data-stream.cpp), [python3](./leetcode/346.moving-average-from-data-stream.py) | Other | \- | \- | \- | - |
| [leetcode-43](https://leetcode.com/problems/multiply-strings/) | Multiply Strings | [c++](./leetcode/43.multiply-strings.cpp), [python3](./leetcode/43.multiply-strings.py) | Other | \- | \- | \- | - |
| [leetcode-31](https://leetcode.com/problems/next-permutation/) | Next Permutation | [c++](./leetcode/31.next-permutation.cpp), [python3](./leetcode/31.next-permutation.py) | Other | \- | \- | \- | - |
| [leetcode-447](https://leetcode.com/problems/number-of-boomerangs/) | Number Of Boomerangs | [c++](./leetcode/447.number-of-boomerangs.cpp), [python3](./leetcode/447.number-of-boomerangs.py) | Other | \- | \- | \- | - |
| [leetcode-323](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | Number Of Connected Components In An Undirected Graph | [c++](./leetcode/323.number-of-connected-components-in-an-undirected-graph.cpp), [python3](./leetcode/323.number-of-connected-components-in-an-undirected-graph.py) | Other | \- | \- | \- | - |
| [leetcode-305](https://leetcode.com/problems/number-of-islands-ii/) | Number Of Islands II | [c++](./leetcode/305.number-of-islands-ii.cpp), [python3](./leetcode/305.number-of-islands-ii.py) | Other | \- | \- | \- | - |
| [leetcode-933](https://leetcode.com/problems/number-of-recent-calls/) | Number Of Recent Calls | [c++](./leetcode/933.number-of-recent-calls.cpp), [python3](./leetcode/933.number-of-recent-calls.py) | Other | \- | \- | \- | - |
| [leetcode-161](https://leetcode.com/problems/one-edit-distance/) | One Edit Distance | [c++](./leetcode/161.one-edit-distance.cpp), [python3](./leetcode/161.one-edit-distance.py) | Other | \- | \- | \- | - |
| [leetcode-276](https://leetcode.com/problems/paint-fence/) | Paint Fence | [c++](./leetcode/276.paint-fence.cpp), [python3](./leetcode/276.paint-fence.py) | Other | \- | \- | \- | - |
| [leetcode-9](https://leetcode.com/problems/palindrome-number/) | Palindrome Number | [c++](./leetcode/9.palindrome-number.cpp), [python3](./leetcode/9.palindrome-number.py) | Other | \- | \- | \- | - |
| [leetcode-336](https://leetcode.com/problems/palindrome-pairs/) | Palindrome Pairs | [python3](./leetcode/336.palindrome-pairs.py) | Other | \- | \- | \- | - |
| [leetcode-131](https://leetcode.com/problems/palindrome-partitioning/) | Palindrome Partitioning | [c++](./leetcode/131.palindrome-partitioning.cpp), [python3](./leetcode/131.palindrome-partitioning.py) | Other | \- | \- | \- | - |
| [leetcode-86](https://leetcode.com/problems/partition-list/) | Partition List | [c++](./leetcode/86.partition-list.cpp), [python3](./leetcode/86.partition-list.py) | Other | \- | \- | \- | - |
| [leetcode-118](https://leetcode.com/problems/pascals-triangle/) | Pascals Triangle | [c++](./leetcode/118.pascals-triangle.cpp), [python3](./leetcode/118.pascals-triangle.py) | Other | \- | \- | \- | - |
| [leetcode-119](https://leetcode.com/problems/pascals-triangle-ii/) | Pascals Triangle II | [c++](./leetcode/119.pascals-triangle-ii.cpp), [python3](./leetcode/119.pascals-triangle-ii.py) | Other | \- | \- | \- | - |
| [leetcode-66](https://leetcode.com/problems/plus-one/) | Plus One | [c++](./leetcode/66.plus-one.cpp), [python3](./leetcode/66.plus-one.py) | Other | \- | \- | \- | - |
| [leetcode-755](https://leetcode.com/problems/pour-water/) | Pour Water | [python3](./leetcode/755.pour-water.py) | Other | \- | \- | \- | - |
| [leetcode-370](https://leetcode.com/problems/range-addition/) | Range Addition | [c++](./leetcode/370.range-addition.cpp), [python3](./leetcode/370.range-addition.py) | Other | \- | \- | \- | - |
| [leetcode-157](https://leetcode.com/problems/read-n-characters-given-read4/) | Read N Characters Given Read4 | [c++](./leetcode/157.read-n-characters-given-read4.cpp), [python3](./leetcode/157.read-n-characters-given-read4.py) | Other | \- | \- | \- | - |
| [leetcode-836](https://leetcode.com/problems/rectangle-overlap/) | Rectangle Overlap | [c++](./leetcode/836.rectangle-overlap.cpp), [python3](./leetcode/836.rectangle-overlap.py) | Other | \- | \- | \- | - |
| [leetcode-26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Remove Duplicates From Sorted Array | [c++](./leetcode/26.remove-duplicates-from-sorted-array.cpp), [python3](./leetcode/26.remove-duplicates-from-sorted-array.py) | Other | \- | \- | \- | - |
| [leetcode-27](https://leetcode.com/problems/remove-element/) | Remove Element | [c++](./leetcode/27.remove-element.cpp), [python3](./leetcode/27.remove-element.py) | Other | \- | \- | \- | - |
| [leetcode-203](https://leetcode.com/problems/remove-linked-list-elements/) | Remove Linked List Elements | [python3](./leetcode/203.remove-linked-list-elements.py) | Other | \- | \- | \- | - |
| [leetcode-143](https://leetcode.com/problems/reorder-list/) | Reorder List | [python3](./leetcode/143.reorder-list.py) | Other | \- | \- | \- | - |
| [leetcode-7](https://leetcode.com/problems/reverse-integer/) | Reverse Integer | [c++](./leetcode/7.reverse-integer.cpp), [python3](./leetcode/7.reverse-integer.py) | Other | \- | \- | \- | - |
| [leetcode-92](https://leetcode.com/problems/reverse-linked-list-ii/) | Reverse Linked List II | [c++](./leetcode/92.reverse-linked-list-ii.cpp), [python3](./leetcode/92.reverse-linked-list-ii.py) | Other | \- | \- | \- | - |
| [leetcode-344](https://leetcode.com/problems/reverse-string/) | Reverse String | [c++](./leetcode/344.reverse-string.cpp), [python3](./leetcode/344.reverse-string.py) | Other | \- | \- | \- | - |
| [leetcode-345](https://leetcode.com/problems/reverse-vowels-of-a-string/) | Reverse Vowels Of A String | [c++](./leetcode/345.reverse-vowels-of-a-string.cpp), [python3](./leetcode/345.reverse-vowels-of-a-string.py) | Other | \- | \- | \- | - |
| [leetcode-657](https://leetcode.com/problems/robot-return-to-origin/) | Robot Return To Origin | [python3](./leetcode/657.robot-return-to-origin.py) | Other | \- | \- | \- | - |
| [leetcode-13](https://leetcode.com/problems/roman-to-integer/) | Roman To Integer | [c++](./leetcode/13.roman-to-integer.cpp), [python3](./leetcode/13.roman-to-integer.py) | Other | \- | \- | \- | - |
| [leetcode-61](https://leetcode.com/problems/rotate-list/) | Rotate List | [python3](./leetcode/61.rotate-list.py) | Other | \- | \- | \- | - |
| [leetcode-796](https://leetcode.com/problems/rotate-string/) | Rotate String | [c++](./leetcode/796.rotate-string.cpp), [python3](./leetcode/796.rotate-string.py) | Other | \- | \- | \- | - |
| [leetcode-702](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/) | Search In A Sorted Array Of Unknown Size | [c++](./leetcode/702.search-in-a-sorted-array-of-unknown-size.cpp), [python3](./leetcode/702.search-in-a-sorted-array-of-unknown-size.py) | Other | \- | \- | \- | - |
| [leetcode-444](https://leetcode.com/problems/sequence-reconstruction/) | Sequence Reconstruction | [c++](./leetcode/444.sequence-reconstruction.cpp), [python3](./leetcode/444.sequence-reconstruction.py) | Other | \- | \- | \- | - |
| [leetcode-773](https://leetcode.com/problems/sliding-puzzle/) | Sliding Puzzle | [python3](./leetcode/773.sliding-puzzle.py) | Other | \- | \- | \- | - |
| [leetcode-311](https://leetcode.com/problems/sparse-matrix-multiplication/) | Sparse Matrix Multiplication | [c++](./leetcode/311.sparse-matrix-multiplication.cpp), [python3](./leetcode/311.sparse-matrix-multiplication.py) | Other | \- | \- | \- | - |
| [leetcode-54](https://leetcode.com/problems/spiral-matrix/) | Spiral Matrix | [c++](./leetcode/54.spiral-matrix.cpp), [python3](./leetcode/54.spiral-matrix.py) | Other | \- | \- | \- | - |
| [leetcode-8](https://leetcode.com/problems/string-to-integer-atoi/) | String To Integer Atoi | [c++](./leetcode/8.string-to-integer-atoi.cpp), [python3](./leetcode/8.string-to-integer-atoi.py) | Other | \- | \- | \- | - |
| [leetcode-246](https://leetcode.com/problems/strobogrammatic-number/) | Strobogrammatic Number | [c++](./leetcode/246.strobogrammatic-number.cpp), [python3](./leetcode/246.strobogrammatic-number.py) | Other | \- | \- | \- | - |
| [leetcode-78](https://leetcode.com/problems/subsets/) | Subsets | [c++](./leetcode/78.subsets.cpp), [python3](./leetcode/78.subsets.py) | Other | \- | \- | \- | - |
| [leetcode-90](https://leetcode.com/problems/subsets-ii/) | Subsets II | [c++](./leetcode/90.subsets-ii.cpp), [python3](./leetcode/90.subsets-ii.py) | Other | \- | \- | \- | - |
| [leetcode-30](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | Substring With Concatenation Of All Words | [c++](./leetcode/30.substring-with-concatenation-of-all-words.cpp), [python3](./leetcode/30.substring-with-concatenation-of-all-words.py) | Other | \- | \- | \- | - |
| [leetcode-228](https://leetcode.com/problems/summary-ranges/) | Summary Ranges | [python3](./leetcode/228.summary-ranges.py) | Other | \- | \- | \- | - |
| [leetcode-68](https://leetcode.com/problems/text-justification/) | Text Justification | [python3](./leetcode/68.text-justification.py) | Other | \- | \- | \- | - |
| [leetcode-42](https://leetcode.com/problems/trapping-rain-water/) | Trapping Rain Water | [c++](./leetcode/42.trapping-rain-water.cpp), [python3](./leetcode/42.trapping-rain-water.py) | Other | \- | \- | \- | - |
| [leetcode-407](https://leetcode.com/problems/trapping-rain-water-ii/) | Trapping Rain Water II | [c++](./leetcode/407.trapping-rain-water-ii.cpp), [python3](./leetcode/407.trapping-rain-water-ii.py) | Other | \- | \- | \- | - |
| [leetcode-170](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | Two Sum Iii Data Structure Design | [c++](./leetcode/170.two-sum-iii-data-structure-design.cpp), [python3](./leetcode/170.two-sum-iii-data-structure-design.py) | Other | \- | \- | \- | - |
| [leetcode-929](https://leetcode.com/problems/unique-email-addresses/) | Unique Email Addresses | [python3](./leetcode/929.unique-email-addresses.py) | Other | \- | \- | \- | - |
| [leetcode-288](https://leetcode.com/problems/unique-word-abbreviation/) | Unique Word Abbreviation | [c++](./leetcode/288.unique-word-abbreviation.cpp), [python3](./leetcode/288.unique-word-abbreviation.py) | Other | \- | \- | \- | - |
| [leetcode-393](https://leetcode.com/problems/utf-8-validation/) | Utf 8 Validation | [c++](./leetcode/393.utf-8-validation.cpp), [python3](./leetcode/393.utf-8-validation.py) | Other | \- | \- | \- | - |
| [leetcode-125](https://leetcode.com/problems/valid-palindrome/) | Valid Palindrome | [c++](./leetcode/125.valid-palindrome.cpp), [python3](./leetcode/125.valid-palindrome.py) | Other | \- | \- | \- | - |
| [leetcode-408](https://leetcode.com/problems/valid-word-abbreviation/) | Valid Word Abbreviation | [c++](./leetcode/408.valid-word-abbreviation.cpp), [python3](./leetcode/408.valid-word-abbreviation.py) | Other | \- | \- | \- | - |
| [leetcode-286](https://leetcode.com/problems/walls-and-gates/) | Walls And Gates | [c++](./leetcode/286.walls-and-gates.cpp), [python3](./leetcode/286.walls-and-gates.py) | Other | \- | \- | \- | - |
| [leetcode-280](https://leetcode.com/problems/wiggle-sort/) | Wiggle Sort | [python3](./leetcode/280.wiggle-sort.py) | Other | \- | \- | \- | - |
| [leetcode-324](https://leetcode.com/problems/wiggle-sort-ii/) | Wiggle Sort II | [python3](./leetcode/324.wiggle-sort-ii.py) | Other | \- | \- | \- | - |
| [leetcode-527](https://leetcode.com/problems/word-abbreviation/) | Word Abbreviation | [c++](./leetcode/527.word-abbreviation.cpp), [python3](./leetcode/527.word-abbreviation.py) | Other | \- | \- | \- | - |
| [leetcode-127](https://leetcode.com/problems/word-ladder/) | Word Ladder | [c++](./leetcode/127.word-ladder.cpp), [python3](./leetcode/127.word-ladder.py) | Other | \- | \- | \- | - |
| [leetcode-425](https://leetcode.com/problems/word-squares/) | Word Squares | [c++](./leetcode/425.word-squares.cpp), [python3](./leetcode/425.word-squares.py) | Other | \- | \- | \- | - |
| [leetcode-6](https://leetcode.com/problems/zigzag-conversion/) | Zigzag Conversion | [python3](./leetcode/6.zigzag-conversion.py) | Other | \- | \- | \- | - |
| [lintcode-589](https://www.lintcode.com/problem/connecting-graph/) | Connecting Graph | [c++](./lintcode/589.connecting-graph.cpp), [python3](./lintcode/589.connecting-graph.py) | Other | \- | \- | \- | - |
| [lintcode-590](https://www.lintcode.com/problem/connecting-graph-ii/) | Connecting Graph II | [c++](./lintcode/590.connecting-graph-ii.cpp), [python3](./lintcode/590.connecting-graph-ii.py) | Other | \- | \- | \- | - |
| [lintcode-591](https://www.lintcode.com/problem/connecting-graph-iii/) | Connecting Graph III | [c++](./lintcode/591.connecting-graph-iii.cpp), [python3](./lintcode/591.connecting-graph-iii.py) | Other | \- | \- | \- | - |
| [lintcode-652](https://www.lintcode.com/problem/factorization/) | Factorization | [c++](./lintcode/652.factorization.cpp), [python3](./lintcode/652.factorization.py) | Other | \- | \- | \- | - |
| [lintcode-390](https://www.lintcode.com/problem/find-peak-element-ii/) | Find Peak Element II | [c++](./lintcode/390.find-peak-element-ii.cpp), [python3](./lintcode/390.find-peak-element-ii.py) | Other | \- | \- | \- | - |
| [lintcode-144](https://www.lintcode.com/problem/interleaving-positive-and-negative-numbers/) | Interleaving Positive And Negative Numbers | [c++](./lintcode/144.interleaving-positive-and-negative-numbers.cpp), [python3](./lintcode/144.interleaving-positive-and-negative-numbers.py) | Other | \- | \- | \- | - |
| [lintcode-89](https://www.lintcode.com/problem/k-sum/) | K Sum | [c++](./lintcode/89.k-sum.cpp), [python3](./lintcode/89.k-sum.py) | Other | \- | \- | \- | - |
| [lintcode-611](https://www.lintcode.com/problem/knight-shortest-path/) | Knight Shortest Path | [c++](./lintcode/611.knight-shortest-path.cpp), [python3](./lintcode/611.knight-shortest-path.py) | Other | \- | \- | \- | - |
| [lintcode-543](https://www.lintcode.com/problem/kth-largest-in-n-arrays/) | Kth Largest In N Arrays | [c++](./lintcode/543.kth-largest-in-n-arrays.cpp), [python3](./lintcode/543.kth-largest-in-n-arrays.py) | Other | \- | \- | \- | - |
| [lintcode-465](https://www.lintcode.com/problem/kth-smallest-sum-in-two-sorted-arrays/) | Kth Smallest Sum In Two Sorted Arrays | [c++](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.cpp), [python3](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.py) | Other | \- | \- | \- | - |
| [lintcode-526](https://www.lintcode.com/problem/load-balancer/) | Load Balancer | [c++](./lintcode/526.load-balancer.cpp), [python3](./lintcode/526.load-balancer.py) | Other | \- | \- | \- | - |
| [lintcode-91](https://www.lintcode.com/problem/minimum-adjustment-cost/) | Minimum Adjustment Cost | [c++](./lintcode/91.minimum-adjustment-cost.cpp), [python3](./lintcode/91.minimum-adjustment-cost.py) | Other | \- | \- | \- | - |
| [lintcode-629](https://www.lintcode.com/problem/minimum-spanning-tree/) | Minimum Spanning Tree | [c++](./lintcode/629.minimum-spanning-tree.cpp), [python3](./lintcode/629.minimum-spanning-tree.py) | Other | \- | \- | \- | - |
| [lintcode-391](https://www.lintcode.com/problem/number-of-airplanes-in-the-sky/) | Number Of Airplanes In The Sky | [c++](./lintcode/391.number-of-airplanes-in-the-sky.cpp), [python3](./lintcode/391.number-of-airplanes-in-the-sky.py) | Other | \- | \- | \- | - |
| [lintcode-31](https://www.lintcode.com/problem/partition-array/) | Partition Array | [python3](./lintcode/31.partition-array.py) | Other | \- | \- | \- | - |
| [lintcode-618](https://www.lintcode.com/problem/search-graph-nodes/) | Search Graph Nodes | [c++](./lintcode/618.search-graph-nodes.cpp), [python3](./lintcode/618.search-graph-nodes.py) | Other | \- | \- | \- | - |
| [lintcode-447](https://www.lintcode.com/problem/search-in-a-big-sorted-array/) | Search In A Big Sorted Array | [c++](./lintcode/447.search-in-a-big-sorted-array.cpp), [python3](./lintcode/447.search-in-a-big-sorted-array.py) | Other | \- | \- | \- | - |
| [lintcode-586](https://www.lintcode.com/problem/sqrtx-ii/) | Sqrtx II | [c++](./lintcode/586.sqrtx-ii.cpp), [python3](./lintcode/586.sqrtx-ii.py) | Other | \- | \- | \- | - |
| [lintcode-139](https://www.lintcode.com/problem/subarray-sum-closest/) | Subarray Sum Closest | [c++](./lintcode/139.subarray-sum-closest.cpp), [python3](./lintcode/139.subarray-sum-closest.py) | Other | \- | \- | \- | - |
| [lintcode-382](https://www.lintcode.com/problem/triangle-count/) | Triangle Count | [c++](./lintcode/382.triangle-count.cpp), [python3](./lintcode/382.triangle-count.py) | Other | \- | \- | \- | - |
| [lintcode-183](https://www.lintcode.com/problem/wood-cut/) | Wood Cut | [c++](./lintcode/183.wood-cut.cpp), [python3](./lintcode/183.wood-cut.py) | Other | \- | \- | \- | - |
| [lintcode-598](https://www.lintcode.com/problem/zombie-in-matrix/) | Zombie In Matrix | [c++](./lintcode/598.zombie-in-matrix.cpp), [python3](./lintcode/598.zombie-in-matrix.py) | Other | \- | \- | \- | - |

