# Leetcode
My personal leetcode answers<br/>
This is a **continually updated, open source** project.

🎉🎉🎉 Finished 100 questions on 2018-05-28<br/>
🎉🎉🎉 Finished 150 questions on 2018-06-29<br/>

# [References](./learning/README.md)

☝️Hey!!!, its clickable. references are moved💦

# Tags
- [Leetcode](#leetcode)
- [References](#references)
- [Tags](#tags)
    - [Math](#math)
    - [Bit Manipulation](#bit-manipulation)
    - [Array and String](#array-and-string)
    - [Two Pointers](#two-pointers)
    - [Linked List](#linked-list)
    - [Binary Search](#binary-search)
    - [Divide and Conquer](#divide-and-conquer)
    - [Tree Traversal](#tree-traversal)
    - [Graph Traversal](#graph-traversal)
    - [Backtracking](#backtracking)
    - [Hash Table](#hash-table)
    - [heap](#heap)
    - [Dynamic Programming](#dynamic-programming)
    - [Greedy](#greedy)
    - [Union Find](#union-find)

## Math
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy
| 836.rectangle-overlap | [cpp](./leetcode/836.rectangle-overlap.cpp) | O(1) | Easy

## Bit Manipulation
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 136.single-number | [cpp](./leetcode/136.single-number.cpp) | O(N) | Easy


## Array and String

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 53.maximum-subarray | [python](./leetcode/53.maximum-subarray.py) | O(N) | Easy 
| 54.spiral-matrix | [cpp](./leetcode/54.spiral-matrix.cpp) | O(N) | Medium
| 66.plus-one | [cpp](./leetcode/66.plus-one.cpp) | O(N) | Easy
| 118.pascals-triangle | [cpp](./leetcode/118.pascals-triangle.cpp) | O(N^2) | Easy
| 240.search-a-2d-matrix-ii | [cpp](./leetcode/240.search-a-2d-matrix-ii.cpp), [python](./leetcode/240.search-a-2d-matrix-ii.py) | O(N + M) | Medium
| 349.intersection-of-two-arrays | [python](./leetcode/349.intersection-of-two-arrays.py) | O(N + M) | Easy
| 350.intersection-of-two-arrays-ii | [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(N * logN) | Easy
| 485.max-consecutive-ones | [cpp](./leetcode/485.max-consecutive-ones.cpp) | O(N) | Easy
| 498.diagonal-traverse | [cpp](./leetcode/498.diagonal-traverse.cpp) | O(M * N) | Medium
| 560.subarray-sum-equals-k | [python](./leetcode/560.subarray-sum-equals-k.py) | O(N) | Medium
| 561.array-partition-i | [cpp](./leetcode/561.array-partition-i.cpp) | O(N * logN) | Easy
| 724.find-pivot-index | [cpp](./leetcode/724.find-pivot-index.cpp) | O(N) | Easy
| 747.largest-number-at-least-twice-of-others | [cpp](./leetcode/747.largest-number-at-least-twice-of-others) | O(N) |Easy
| 796.rotate-string | [cpp](./leetcode/796.rotate-string.cpp), [python](./leetcode/796.rotate-string.py) | O(N^2) | Easy | string | TODO: Rabin-Karp Algorithm, KMP algorithm
| 859.buddy-strings | [cpp](./leetcode/859.buddy-strings.cpp) | O(N) | Easy | string |

## Two Pointers

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 15.3sum | [cpp](./leetcode/15.3sum.cpp), [python](./leetcode/15.3sum.py) | O(N^2) | Medium | 
| 16.3sum-closest | [cpp](./leetcode/16.3sum-closest.cpp), [python](./leetcode/16.3sum-closest.py) | O(N^2) | Medium |
| 18.4sum | [cpp](./leetcode/18.4sum.cpp), [python](./leetcode/18.4sum.py) | O(N^3) | Medium |
| 19.remove-nth-node-from-end-of-list | [cpp](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python](./leetcode/19.remove-nth-node-from-end-of-list.py) | O(N) | Medium
| 75.sort-colors | [cpp](./leetcode/75.sort-colors.cpp) [python](./leetcode/75.sort-colors.py) | O(N) | Medium | counting-sort
| 76.minimum-window-substring | [cpp](./leetcode/76.minimum-window-substring.cpp) | O(N) | Hard
| 125.valid-palindrome | [python](./leetcode/125.valid-palindrome.py) | O(N) | Easy
| 142.linked-list-cycle-ii | [python](./leetcode/142.linked-list-cycle-ii.py) | O(N) | Medium | linked-list
| 160.intersection-of-two-linked-lists | [python](./leetcode/160.intersection-of-two-linked-lists.py) | O(N + M) | Easy | linked-list
| 209.minimum-size-subarray-sum | [cpp](./leetcode/209.minimum-size-subarray-sum.cpp) | O(N) | Medium |


| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| --------------| -------| --------|
| 026.remove-duplicates-from-sorted-array | [cpp](./leetcode/26.remove-duplicates-from-sorted-array.cpp), [python](./leetcode/26.remove-duplicates-from-sorted-array.py) | O(N) | O(1) | Easy
| 027.remove-element | [cpp](./leetcode/27.remove-element.cpp), [python](./leetcode/27.remove-element.py) | O(N) | O(1) | Easy
| 028.implement-strstr | [cpp](./leetcode/28.implement-strstr.cpp), [python](./leetcode/28.implement-strstr.py) | O(N^2) | O(1) | Easy | | TODO: string, KMP, rolling hash?
| 088.merge-sorted-array | [cpp](./leetcode/88.merge-sorted-array.cpp), [python](./leetcode/88.merge-sorted-array.py) | O(N + M) | O(1) | Easy |
| 141.linked-list-cycle | [cpp](./leetcode/141.linked-list-cycle.cpp), [python](./leetcode/141.linked-list-cycle.py) | O(N) | O(1) | Easy
| 167.two-sum-ii-input-array-is-sorted | [cpp](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O(N) | O(1) | Easy |
| 234.palindrome-linked-list | [cpp](./leetcode/234.palindrome-linked-list.cpp), [python](./leetcode/234.palindrome-linked-list.py) | O(N) | O(1) | Easy | | maybe harder
| 283.move-zeroes | [cpp](./leetcode/283.move-zeroes.cpp), [python](./leetcode/283.move-zeroes.py) | O(N) | O(1) | Easy
| 344.reverse-string | [cpp](./leetcode/344.reverse-string.cpp), [python](./leetcode/344.reverse-string.py) | O(N) | O(1) | Easy
| 345.reverse-vowels-of-a-string | [cpp](./leetcode/345.reverse-vowels-of-a-string.cpp), [python](./leetcode/345.reverse-vowels-of-a-string.py) | O(N) | O(1) | Easy
| 349.intersection-of-two-arrays | [cpp](./leetcode/349.intersection-of-two-arrays.cpp), [python](./leetcode/349.intersection-of-two-arrays.py) | O(K * logK), k = max(M, N) | O(1) | Easy | hash, binary-search
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(K * logK), k = max(M, N) | O(1) | Easy | hash, binary-search
| 532.k-diff-pairs-in-an-array | [cpp](./leetcode/532.k-diff-pairs-in-an-array.cpp), [python](./leetcode/532.k-diff-pairs-in-an-array.py) | O(N * logN) | O(1) | Easy | Hash |
| 844.backspace-string-compare | [cpp](./leetcode/844.backspace-string-compare.cpp), [python](./leetcode/844.backspace-string-compare.py) | O(N) | O(1) | Easy | stack

## Linked List

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 21.merge-two-sorted-lists | [cpp](./leetcode/21.merge-two-sorted-lists.cpp), [python](./leetcode/21.merge-two-sorted-lists.py) | O(N) | Easy |
| 25.reverse-nodes-in-k-group | [python](./leetcode/25.reverse-nodes-in-k-group.py) | O(N) | Hard |
| 61.rotate-list | [python](./leetcode/61.rotate-list.py) | O(N) | Medium |
| 86.partition-list | [python](./leetcode/86.partition-list.py) | O(N) | Medium |
| 92.reverse-linked-list-ii | [python](./leetcode/92.reverse-linked-list-ii.py) | O(N) | Medium |
| 138.copy-list-with-random-pointer | [python](./leetcode/138.copy-list-with-random-pointer.py) | O(N) | Medium
| 143.reorder-list | [python](./leetcode/143.reorder-list.py) | O(N) | Medium |
| 148.sort-list | [python](./leetcode/148.sort-list.py) | O(N * logN) | Medium |
| 203.remove-linked-list-elements | [python](./leetcode/203.remove-linked-list-elements.py) | O(N) | Easy
| 206.reverse-linked-list | [python](./leetcode/206.reverse-linked-list.py) | O(N) | Easy |
| 237.delete-node-in-a-linked-list | [python](./leetcode/237.delete-node-in-a-linked-list.py) | O(1) | Easy
| 328.odd-even-linked-list | [python](./leetcode/328.odd-even-linked-list.py) | O(N) | Medium

## Binary Search
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 33.search-in-rotated-sorted-array | [cpp](./leetcode/33.search-in-rotated-sorted-array.cpp), [python](./leetcode/33.search-in-rotated-sorted-array.py) | O(logN) | Medium |
| 34.find-first-and-last-position-of-element-in-sorted-array | [cpp](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp) | Medium |
| 74.search-a-2d-matrix | [cpp](./leetcode/74.search-a-2d-matrix.cpp),  [python](./leetcode/74.search-a-2d-matrix.py) | O(logN) | Medium | N = row * column
| 81.search-in-rotated-sorted-array-ii | [cpp](./leetcode/81.search-in-rotated-sorted-array-ii.cpp), [python](./leetcode/81.search-in-rotated-sorted-array-ii.py | O(logN) ~ O(N) | Medium |
| 153.find-minimum-in-rotated-sorted-array | [cpp](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | O(logN) | Medium
| 154.find-minimum-in-rotated-sorted-array-ii | [cpp](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp), [python](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | Hard
| 162.find-peak-element | [cpp](./leetcode/162.find-peak-element.cpp) | O(logN) | Meidum
| 278.first-bad-version | [cpp](./leetcode/278.first-bad-version.cpp), [python](./leetcode/278.first-bad-version.py) | O(logN) | Easy
| 302.smallest-rectangle-enclosing-black-pixels | [cpp](./leetcode/302.smallest-rectangle-enclosing-black-pixels.cpp) | O(M * N) / O(N * LogN) | Hard |

## Divide and Conquer

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 4.median-of-two-sorted-arrays | [cpp](./leetcode/4.median-of-two-sorted-arrays.cpp), [python](./leetcode/4.median-of-two-sorted-arrays.py) | O(log(M + N)) | Hard |
| 98.validate-binary-search-tree | [cpp](./leetcode/98.validate-binary-search-tree.cpp), [python](./leetcode/98.validate-binary-search-tree.py) | O(N) | Medium | | TODO: inorder-traversal |
| 104.maximum-depth-of-binary-tree | [cpp](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python](./leetcode/104.maximum-depth-of-binary-tree.py) | O(N) | Easy
| 110.balanced-binary-tree | [cpp](./leetcode/110.balanced-binary-tree.cpp), [python](./leetcode/110.balanced-binary-tree.py) | O(N) | Easy
| 215.kth-largest-element-in-an-array | [cpp](./leetcode/215.kth-largest-element-in-an-array.cpp), [python](./leetcode/215.kth-largest-element-in-an-array.py) | O(N) ~ O(N^2) | Medium | quick-select
| 236.lowest-common-ancestor-of-a-binary-tree | [cpp](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp), [python](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | O(N) | Medium

## Tree Traversal

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 94.binary-tree-inorder-traversal | [cpp](./leetcode/94.binary-tree-inorder-traversal.cpp) | O(N) | Medium |
| 102.binary-tree-level-order-traversal | [cpp](./leetcode/102.binary-tree-level-order-traversal.cpp) | O(N) | Medium |
| 107.binary-tree-level-order-traversal-ii | [cpp](./leetcode/107.binary-tree-level-order-traversal-ii.cpp) | O(N) | Easy |
| 144.binary-tree-preorder-traversal | [cpp](./leetcode/144.binary-tree-preorder-traversal.cpp) | O(N) | Medium

## Graph Traversal

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 127.word-ladder | [python](./leetcode/127.word-ladder.py) | O(N * L^2) | Medium | BFS |
| 200.number-of-islands | [python](./leetcode/200.number-of-islands.py) | O(M x N) | Medium | BFS/DFS | union-find
| 207.course-schedule | [cpp](./leetcode/207.course-schedule.cpp) | O(V + E) | Medium |
| 210.course-schedule-ii | [cpp](./leetcode/210.course-schedule-ii.cpp) | O(V + E) | Medium | topological-sort
| 444.sequence-reconstruction | [cpp](./leetcode.444.sequence-reconstruction.cpp), [python](./leetcode/444.sequence-reconstruction.py) | O(V+E) | Medium | topological-sort

## Backtracking
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 39.combination-sum | [python](./leetcode/39.combination-sum.py) | ??? | Medium | DFS |
| 40.combination-sum-ii | [python](./leetcode/40.combination-sum-ii.py) | ??? | Medium | DFS |
| 46.permutations | [python](./leetcode/46.permutations.py) | ??? | Medium | DFS |
| 47.permutations-ii | [python](./leetcode/47.permutations-ii.py) | ??? | Medium | DFS |
| 51.n-queens | [python](./leetcode/51.n-queens.py) | ??? | Hard | DFS |
| 52.n-queens-ii | [python](./leetcode/52.n-queens-ii.py) | ??? | Hard | DFS |
| 78.subsets | [cpp](./leetcode/78.subsets.cpp), [python](./leetcode/78.subsets.py) | O(N * 2^N) | Medium | DFS | bit-manipulation / iterative
| 90.subsets-ii | [cpp](./leetcode/90.subsets-ii.cpp), [python](./leetcode/90.subsets-ii.py) | O(N * 2^N) | Medium | DFS |  bit-manipulation
| 126.word-ladder-ii | [python](./leetcode/126.word-ladder-ii.py) | O((V+E) * L^2) | Hard | BFS+DFS |
| 131.palindrome-partitioning | [python](./leetcode/131.palindrome-partitioning.py) | ??? | Medium | DFS

## Hash Table
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 1.two-sum | [cpp](./leetcode/1.two-sum.cpp), [python](./leetcode/1.two-sum.py) | O(N) | Easy |
| 3.longest-substring-without-repeating-characters | [cpp](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python](./leetcode/3.longest-substring-without-repeating-characters.py) | O(N) | Medium
| 36.valid-sudoku | [cpp](./leetcode/36.valid-sudoku.cpp) | O(N ^ 2) | Medium | array-indexes
| 49.group-anagrams | [cpp](./leetcode/49.group-anagrams.cpp) | O(N * k * Logk) | Medium
| 170.two-sum-iii-data-structure-design | [cpp](./leetcode/170.two-sum-iii-data-structure-design.cpp), [python](./leetcode/170.two-sum-iii-data-structure-design.py) | O(N) | Easy
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy
| 205.isomorphic-strings | [cpp](./leetcode/205.isomorphic-strings.cpp), [python](./leetcode/205.isomorphic-strings.py) | O(N) | Easy
| 217.contains-duplicate | [cpp](./leetcode/217.contains-duplicate.cpp) | O(N) | Easy
| 219.contains-duplicate-ii | [cpp](./leetcode/219.contains-duplicate-ii.cpp) | O(N) | Easy
| 249.group-shifted-strings | [cpp](./leetcode/249.group-shifted-strings.cpp) | O(N * K) | Medium
| 288.unique-word-abbreviation | [cpp](./leetcode/288.unique-word-abbreviation.cpp) | - | Medium
| 347.top-k-frequent-elements | [cpp](./leetcode/347.top-k-frequent-elements.cpp) | O(N * LogN) | Medium | TODO: quick-sort, bucket-sort
| 349.intersection-of-two-arrays | [cpp](./leetcode/349.intersection-of-two-arrays.cpp) | O(M + N) | Easy
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp) | O(M * N) | Easy
| 359.logger-rate-limiter | [cpp](./leetcode/359.logger-rate-limiter.cpp) | O(1) | Easy | [amortized](https://stackoverflow.com/questions/200384/constant-amortized-time)
| 380.insert-delete-getrandom-o1 | [cpp](./leetcode/380.insert-delete-getrandom-o1.cpp) | O(1) | Medium
| 454.4sum-ii | [cpp](./leetcode/454.4sum-ii.cpp) | O(N ^ 2) | Medium
| 599.minimum-index-sum-of-two-lists | [cpp](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | O(M + N) | Easy
| 652.find-duplicate-subtrees | [cpp](./leetcode/652.find-duplicate-subtrees.cpp) | O(N) | Medium
| 771.jewels-and-stones | [cpp](./leetcode/771.jewels-and-stones.cpp) | O(M + N) | Easy

## heap
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 23.merge-k-sorted-lists | [cpp](./leetcode/23.merge-k-sorted-lists.cpp) | O(N * LogK) | Hard | TODO: merge-sort, bottom-up

## Dynamic Programming
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 62.unique-paths | [python](./leetcode/62.unique-paths.py) | O(M * N) | Medium | Coordinates
| 63.unique-paths-ii | [python](./leetcode/63.unique-paths-ii.py) | O(M * N) | Medium | Coordinates
| 64.minimum-path-sum | [python](./leetcode/64.minimum-path-sum.py) | O(M * N) | Medium | Coordinates
| 70.climbing-stairs | [cpp](./leetcode/70.climbing-stairs.cpp), [python](./leetcode/70.climbing-stairs.py) | O(N) | Easy | Coordinates
| 91.decode-ways | [cpp](./leetcode/91.decode-ways.cpp) | O(N) | Medium  | conditional-climbing-stairs
| 120.triangle | [cpp](./leetcode/120.triangle.cpp), [python](./leetcode/120.triangle.py) | O(N^2) | Medium | Coordinates
| 300.longest-increasing-subsequence | [cpp](./leetcode/300.longest-increasing-subsequence.cpp), [python](./leetcode/300.longest-increasing-subsequence.py) | O(N^2) | Medium |  | follow-up is tricky
| 354.russian-doll-envelopes | [cpp](./leetcode/354.russian-doll-envelopes.cpp), [python](./leetcode/354.russian-doll-envelopes.py) | O(N^2) | Hard | TODO: Python Version Time Limit Exceeded
| 368.largest-divisible-subset | [cpp](./leetcode/368.largest-divisible-subset.cpp) | O(N^2) | Medium |
| 403.frog-jump | [cpp](./leetcode/403.frog-jump.cpp) | O(N^2) | Hard

## Greedy
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 45.jump-game-ii | [cpp](./leetcode/45.jump-game-ii.cpp), [python](./leetcode/45.jump-game-ii.py) | O(N) | Hard |
| 55.jump-game | [cpp](./leetcode/55.jump-game.cpp), [python](./leetcode/55.jump-game.py) | O(N) | Medium | dynamic-programming

## Union Find
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 128.longest-consecutive-sequence | [cpp](./leetcode/128.longest-consecutive-sequence.cpp) | O(N) | Hard
| 261.graph-valid-tree | [python](./leetcode/261.graph-valid-tree.py) | O(E) | Medium | BFS/DFS | E = len(edges)
| 305.number-of-islands-ii | [python](./leetcode/305.number-of-islands-ii.py) | O(N) | Hard | | N = len(positions) |
