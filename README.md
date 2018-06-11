# Leetcode
My personal leetcode answer in python<br/>
This is a **continually updated, open source** project.


🎉🎉🎉 Finished 100 questions on 2018-05-28

# Reference
- [kdn251/interviews](https://github.com/kdn251/interviews)
- [kamyu104/LeetCode](https://github.com/kamyu104/LeetCode)
- [hiredintech](https://www.hiredintech.com/)
- [highscalability](http://highscalability.com/)

# Tags
- [Leetcode](#leetcode)
- [Reference](#reference)
- [Tags](#tags)
    - [Array](#array)
    - [String](#string)
    - [Two Pointers](#two-pointers)
    - [Linked List](#linked-list)
    - [Binary Search](#binary-search)
    - [Divide and Conquer](#divide-and-conquer)
    - [Tree Traversal](#tree-traversal)
    - [Graph Traversal](#graph-traversal)
    - [Backtracking](#backtracking)
    - [Topological Sort](#topological-sort)
    - [Hash Table](#hash-table)
    - [Dynamic Programming](#dynamic-programming)
    - [Greedy](#greedy)

## Array

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 53.maximum-subarray | [python](./leetcode/53.maximum-subarray.py) | O(N) | Easy 
| 88.merge-sorted-array | [python](./leetcode/88.merge-sorted-array.py) | O(N + M) | Easy |
| 240.search-a-2d-matrix-ii | [python](./leetcode/240.search-a-2d-matrix-ii.py) | O(N + M) | Medium
| 349.intersection-of-two-arrays | [python](./leetcode/349.intersection-of-two-arrays.py) | O(N + M) | Easy
| 350.intersection-of-two-arrays-ii | [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(N * logN) | Easy
| 560.subarray-sum-equals-k | [python](./leetcode/560.subarray-sum-equals-k.py) | O(N) | Medium

## String

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 796.rotate-string | [python](./leetcode/796.rotate-string.py) | O(N^2) | Easy | Rabin-Karp Algorithm, KMP algorithm

## Two Pointers

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 15.3sum | [python](./leetcode/15.3sum.py) | O(N^2) | Medium | 
| 16.3sum-closest | [python](./leetcode/16.3sum-closest.py) | O(N^2) | Medium |
| 18.4sum | [python](./leetcode/18.4sum.py) | O(N^3) | Medium |
| 19.remove-nth-node-from-end-of-list | [python](./leetcode/19.remove-nth-node-from-end-of-list.py) | O(N) | Medium
| 75.sort-colors | [python](./leetcode/75.sort-colors.py) | O(N) | Medium
| 125.valid-palindrome | [python](./leetcode/125.valid-palindrome.py) | O(N) | Easy
| 141.linked-list-cycle | [python](./leetcode/141.linked-list-cycle.py) | O(N) | Easy | linked-list
| 142.linked-list-cycle-ii | [python](./leetcode/142.linked-list-cycle-ii.py) | O(N) | Medium | linked-list
| 160.intersection-of-two-linked-lists | [python](./leetcode/160.intersection-of-two-linked-lists.py) | O(N + M) | Easy | linked-list
| 167.two-sum-ii-input-array-is-sorted | [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O(N) | Easy |
| 283.move-zeroes | [python](./leetcode/283.move-zeroes.py) | O(N) | Easy


## Linked List

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 21.merge-two-sorted-lists | [python](./leetcode/21.merge-two-sorted-lists.py) | O(N) | Easy |
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
| 74.search-a-2d-matrix | [python](./leetcode/74.search-a-2d-matrix.py) | Medium |
| 153.find-minimum-in-rotated-sorted-array | [python](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | O(logN) | Medium
| 154.find-minimum-in-rotated-sorted-array-ii | [python](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | Hard
| 278.first-bad-version | [python](./leetcode/278.first-bad-version.py) | O(logN) | Easy

## Divide and Conquer

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 4.median-of-two-sorted-arrays | [python](./leetcode/4.median-of-two-sorted-arrays.py) | O(log(M + N)) | Hard |
| 98.validate-binary-search-tree | [python](./leetcode/98.validate-binary-search-tree.py) | O(N) | Medium |
| 104.maximum-depth-of-binary-tree | [python](./leetcode/104.maximum-depth-of-binary-tree.py) | O(N) | Easy
| 110.balanced-binary-tree | [python](./leetcode/110.balanced-binary-tree.py) | O(N) | Easy
| 215.kth-largest-element-in-an-array | [python](./leetcode/215.kth-largest-element-in-an-array.py) | O(N) ~ O(N^2) | Medium | quick-select
| 236.lowest-common-ancestor-of-a-binary-tree | [python](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | O(N) | Medium

## Tree Traversal

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|


## Graph Traversal

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 127.word-ladder | [python](./leetcode/127.word-ladder.py) | O(N * L^2) | Medium | BFS |
| 200.number-of-islands | [python](./leetcode/200.number-of-islands.py) | O(M x N) | Medium | BFS/DFS | union-find

## Backtracking
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 39.combination-sum | [python](./leetcode/39.combination-sum.py) | ??? | Medium | DFS |
| 40.combination-sum-ii | [python](./leetcode/40.combination-sum-ii.py) | ??? | Medium | DFS |
| 46.permutations | [python](./leetcode/46.permutations.py) | ??? | Medium | DFS |
| 47.permutations-ii | [python](./leetcode/47.permutations-ii.py) | ??? | Medium | DFS |
| 51.n-queens | [python](./leetcode/51.n-queens.py) | ??? | Hard | DFS |
| 52.n-queens-ii | [python](./leetcode/52.n-queens-ii.py) | ??? | Hard | DFS |
| 78.subsets | [python](./leetcode/78.subsets.py) | O(N * 2^N) | Medium | DFS | bit-manipulation
| 90.subsets-ii | [python](./leetcode/90.subsets-ii.py) | O(N * 2^N) | Medium | DFS |  bit-manipulation
| 126.word-ladder-ii | [python](./leetcode/126.word-ladder-ii.py) | O((V+E) * L^2) | Hard | BFS+DFS |
| 131.palindrome-partitioning | [python](./leetcode/131.palindrome-partitioning.py) | ??? | Medium | DFS | dynamic-programming

## Topological Sort
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 444.sequence-reconstruction | [python](./leetcode/444.sequence-reconstruction.py) | O(V+E) | Medium | BFS/DFS |

## Hash Table
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 1.two-sum | [python](./leetcode/1.two-sum.py) | O(N) | Easy |
| 170.two-sum-iii-data-structure-design | [python](./leetcode/170.two-sum-iii-data-structure-design.py) | O(N) | Easy

## Dynamic Programming
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 62.unique-paths | [python](./leetcode/62.unique-paths.py) | O(M * N) | Medium | Coordinates
| 63.unique-paths-ii | [python](./leetcode/63.unique-paths-ii.py) | O(M * N) | Medium | Coordinates
| 64.minimum-path-sum | [python](./leetcode/64.minimum-path-sum.py) | O(M * N) | Medium | Coordinates
| 70.climbing-stairs | [python](./leetcode/70.climbing-stairs.py) | O(N) | Easy | Coordinates
| 120.triangle | [python](./leetcode/120.triangle.py) | O(N^2) | Medium | Coordinates

## Greedy
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 45.jump-game-ii | [python](./leetcode/45.jump-game-ii.py) | O(N) | Hard |