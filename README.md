# Algorithm
My personal leetcode answers<br/>
This is a **continually updated, open source** project.

📢📢📢 
add **star(*)** before question number **means** you should check **discussion** for alternative (usually better) answer
Add **S--** **S++** **SSS** notations to further **level** algorithm monsters, notions are just designed for unique search results

# Milestone
🎉🎉🎉 Finished 100 / 808 questions on 2018-05-28<br/>
🎉🎉🎉 Finished 150 / 824 questions on 2018-06-29<br/>
🎑🎑🎑 Finished 200 / 905 questions on 2018-09-24<br/> 

# [References](./learning/README.md)

☝️Hey!!!, its clickable. references are moved💦

- [Leetcode](#leetcode)
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
    - [Heap](#heap)
    - [Stack](#stack)
    - [Dynamic Programming](#dynamic-programming)
    - [Greedy](#greedy)
    - [Union Find](#union-find)
    - [Trie](#trie)
    - [Other](#other)

- [Lintcode](#lintcode)

# Leetcode

## Math
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 012.integer-to-roman | [cpp](./leetcode/12.integer-to-roman.cpp), [python](./leetcode/12.integer-to-roman.py) | O(N) | O(1) | Medium | N = length of results
| 013.roman-to-integer | [cpp](./leetcode/13.roman-to-integer.cpp), [python](./leetcode/13.roman-to-integer.py) | O(N) | O(1) | Easy
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 002.add-two-numbers | [cpp](./leetcode/2.add-two-numbers.cpp), [python](./leetcode/2.add-two-numbers.py) | O(N) | O(1) | Medium/S--
| 043.multiply-strings | [cpp](./leetcode/43.multiply-strings.cpp), [python](./leetcode/43.multiply-strings.py) | O(M*N) | O(M+N)  | Medium/S++
| 048.rotate-image | [cpp](./leetcode/48.rotate-image.cpp), [python](./leetcode/48.rotate-image.py) | O(M * N) | O(1) | Medium/S++
| 50.powx-n | [cpp](./leetcode/50.powx-n.cpp), [python](./leetcode/50.powx-n.py) | O(logN) | O(1) | Medium/S++
| 067.add-binary | [cpp](./leetcode/67.add-binary,cpp), [python](./leetcode/67.add-binary.py) | O(N) | O(1) | Easy |
| 311.sparse-matrix-multiplication | [cpp](./leetcode/311.sparse-matrix-multiplication.cpp), [python](./leetcode/311.sparse-matrix-multiplication.py) | O(N^3) | O(N^2) | Medium/S-- | 
| 415.add-strings | [cpp](./leetcode/415.add-strings.cpp), [python](./leetcode/415.add-strings.py) | O(N) | O(1) | Easy |
| 836.rectangle-overlap | [cpp](./leetcode/836.rectangle-overlap.cpp), [python](./leetcode/836.rectangle-overlap.py) | O(1) | O(1) | Easy

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
| 350.intersection-of-two-arrays-ii | [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(N * logN) | Easy
| 485.max-consecutive-ones | [cpp](./leetcode/485.max-consecutive-ones.cpp) | O(N) | Easy
| 498.diagonal-traverse | [cpp](./leetcode/498.diagonal-traverse.cpp) | O(M * N) | Medium
| 560.subarray-sum-equals-k | [python](./leetcode/560.subarray-sum-equals-k.py) | O(N) | Medium
| 561.array-partition-i | [cpp](./leetcode/561.array-partition-i.cpp) | O(N * logN) | Easy
| 724.find-pivot-index | [cpp](./leetcode/724.find-pivot-index.cpp) | O(N) | Easy
| 747.largest-number-at-least-twice-of-others | [cpp](./leetcode/747.largest-number-at-least-twice-of-others) | O(N) |Easy
| 796.rotate-string | [cpp](./leetcode/796.rotate-string.cpp), [python](./leetcode/796.rotate-string.py) | O(N^2) | Easy | string | TODO: Rabin-Karp Algorithm, KMP algorithm
| 859.buddy-strings | [cpp](./leetcode/859.buddy-strings.cpp) | O(N) | Easy | string |

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 042.trapping-rain-water | [cpp](./leetcode/42.trapping-rain-water.cpp), [python](./leetcode/42.trapping-rain-water.py) | O(N) | O(N) | Hard | Scan Twice | 
| 056.merge-intervals | [cpp](./leetcode/56.merge-intervals.cpp), [python](./leetcode/56.merge-intervals.py) | O(N * logN) | O(1) | Medium | Sort | N = number of intervals
| 057.insert-interval | [cpp](./leetcode/57.insert-interval.cpp), [python](./leetcode/57.insert-interval.py) | O(N) | O(1) | Hard | Sort | N = number of intervals
| 157.read-n-characters-given-read4 | [cpp](./leetcode/157.read-n-characters-given-read4.cpp), [python](./leetcode/157.read-n-characters-given-read4.py) | O(N) | O(1) | Easy | String
| 161.one-edit-distance | [cpp](./leetcode/161.one-edit-distance.cpp), [python](./leetcode/161.one-edit-distance.py) | O(N) | O(1) | Medium | String |
| 163.missing-ranges | [cpp](./leetcode/163.missing-ranges.cpp), [python](./leetcode/163.missing-ranges.py) | O(N) | O(1) | Medium | Array | Mind int overflow
| 240.search-a-2d-matrix-ii | [cpp](./leetcode/240.search-a-2d-matrix-ii.cpp), [python](./leetcode/240.search-a-2d-matrix-ii.py) | O(N + M) | O(1) | Medium
| 271.encode-and-decode-strings | [cpp](./leetcode/271.encode-and-decode-strings.cpp), [python](./leetcode/271.encode-and-decode-strings.py) | O(N) | O(1) | Easy | String | N = count of chars
| 277.find-the-celebrity | [cpp](./leetcode/277.find-the-celebrity.cpp), [python](./leetcode/277.find-the-celebrity.py) | O(N) | O(1) | Medium |
| 346.moving-average-from-data-stream | [cpp](./leetcode/346.moving-average-from-data-stream.cpp), [python](./leetcode/346.moving-average-from-data-stream.py) | O(N) | O(K) | Easy | Queue(Circular array) |
| 388.longest-absolute-file-path | [cpp](./leetcode/388.longest-absolute-file-path.cpp), [python](./leetcode/388.longest-absolute-file-path.py) | O(N) | O(N) | Medium | String |
| 408.valid-word-abbreviation | [cpp](./leetcode/408.valid-word-abbreviation.cpp), [python](./leetcode/408.valid-word-abbreviation.py) | O(N) | O(1) | Easy
| 527.word-abbreviation | [cpp](./leetcode/527.word-abbreviation.cpp), [python](./leetcode/527.word-abbreviation.py) | O(N * L) | O(N) | HARD | L = avg word length

## Two Pointers

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 003.longest-substring-without-repeating-characters | [cpp](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python](./leetcode/3.longest-substring-without-repeating-characters.py) | O(N) | O(N) | Medium
| 026.remove-duplicates-from-sorted-array | [cpp](./leetcode/26.remove-duplicates-from-sorted-array.cpp), [python](./leetcode/26.remove-duplicates-from-sorted-array.py) | O(N) | O(1) | Easy
| 027.remove-element | [cpp](./leetcode/27.remove-element.cpp), [python](./leetcode/27.remove-element.py) | O(N) | O(1) | Easy
| 028.implement-strstr | [cpp](./leetcode/28.implement-strstr.cpp), [python](./leetcode/28.implement-strstr.py) | O(N^2) | O(1) | Easy | | TODO: string, KMP, rolling hash?
| 042.trapping-rain-water | [cpp](./leetcode/42.trapping-rain-water.cpp), [python](./leetcode/42.trapping-rain-water.py) | O(N) | O(1) | Hard | Two Pointers | 
| 076.minimum-window-substring | [cpp](./leetcode/76.minimum-window-substring.cpp), [python](./leetcode/76.minimum-window-substring.py) | O(N) | O(N) | Hard
| 088.merge-sorted-array | [cpp](./leetcode/88.merge-sorted-array.cpp), [python](./leetcode/88.merge-sorted-array.py) | O(N + M) | O(1) | Easy |
| 125.valid-palindrome | [cpp](./leetcode/125.valid-palindrome.cpp), [python](./leetcode/125.valid-palindrome.py) | O(N) | O(1) | Easy
| 141.linked-list-cycle | [cpp](./leetcode/141.linked-list-cycle.cpp), [python](./leetcode/141.linked-list-cycle.py) | O(N) | O(1) | Easy
| 159.longest-substring-with-at-most-two-distinct-characters | [cpp](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.cpp), [python](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.py) | O(N) | O(N) | HARD |
| 167.two-sum-ii-input-array-is-sorted | [cpp](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O(N) | O(1) | Easy |
| 209.minimum-size-subarray-sum | [cpp](./leetcode/209.minimum-size-subarray-sum.cpp), [python](./leetcode/209.minimum-size-subarray-sum.py) | O(N) | O(1) | Medium |
| 234.palindrome-linked-list | [cpp](./leetcode/234.palindrome-linked-list.cpp), [python](./leetcode/234.palindrome-linked-list.py) | O(N) | O(1) | Easy | | maybe harder
| 283.move-zeroes | [cpp](./leetcode/283.move-zeroes.cpp), [python](./leetcode/283.move-zeroes.py) | O(N) | O(1) | Easy
| 340.longest-substring-with-at-most-k-distinct-characters | [cpp](./leetcode/340.longest-substring-with-at-most-k-distinct-characters.cpp), [python](./leetcode/340.longest-substring-with-at-most-k-distinct-characters.py) | O(N) | O(N) | HARD |
| 344.reverse-string | [cpp](./leetcode/344.reverse-string.cpp), [python](./leetcode/344.reverse-string.py) | O(N) | O(1) | Easy
| 345.reverse-vowels-of-a-string | [cpp](./leetcode/345.reverse-vowels-of-a-string.cpp), [python](./leetcode/345.reverse-vowels-of-a-string.py) | O(N) | O(1) | Easy
| 349.intersection-of-two-arrays | [cpp](./leetcode/349.intersection-of-two-arrays.cpp), [python](./leetcode/349.intersection-of-two-arrays.py) | O(K * logK), k = max(M, N) | O(1) | Easy | hash, binary-search
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(K * logK), k = max(M, N) | O(1) | Easy | hash, binary-search
| 532.k-diff-pairs-in-an-array | [cpp](./leetcode/532.k-diff-pairs-in-an-array.cpp), [python](./leetcode/532.k-diff-pairs-in-an-array.py) | O(N * logN) | O(1) | Easy | Hash |
| 844.backspace-string-compare | [cpp](./leetcode/844.backspace-string-compare.cpp), [python](./leetcode/844.backspace-string-compare.py) | O(N) | O(1) | Easy | stack

## Two Pointers(legacy)

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 15.3sum | [cpp](./leetcode/15.3sum.cpp), [python](./leetcode/15.3sum.py) | O(N^2) | Medium | 
| 16.3sum-closest | [cpp](./leetcode/16.3sum-closest.cpp), [python](./leetcode/16.3sum-closest.py) | O(N^2) | Medium |
| 18.4sum | [cpp](./leetcode/18.4sum.cpp), [python](./leetcode/18.4sum.py) | O(N^3) | Medium |
| 19.remove-nth-node-from-end-of-list | [cpp](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python](./leetcode/19.remove-nth-node-from-end-of-list.py) | O(N) | Medium
| 75.sort-colors | [cpp](./leetcode/75.sort-colors.cpp) [python](./leetcode/75.sort-colors.py) | O(N) | Medium | counting-sort
| 142.linked-list-cycle-ii | [python](./leetcode/142.linked-list-cycle-ii.py) | O(N) | Medium | linked-list
| 160.intersection-of-two-linked-lists | [python](./leetcode/160.intersection-of-two-linked-lists.py) | O(N + M) | Easy | linked-list


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
| 74.search-a-2d-matrix | [cpp](./leetcode/74.search-a-2d-matrix.cpp),  [python](./leetcode/74.search-a-2d-matrix.py) | O(logN) | Medium | N = row * column
| 81.search-in-rotated-sorted-array-ii | [cpp](./leetcode/81.search-in-rotated-sorted-array-ii.cpp), [python](./leetcode/81.search-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | Medium |
| 153.find-minimum-in-rotated-sorted-array | [cpp](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | O(logN) | Medium
| 154.find-minimum-in-rotated-sorted-array-ii | [cpp](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp), [python](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | Hard
| 162.find-peak-element | [cpp](./leetcode/162.find-peak-element.cpp) | O(logN) | Meidum
| 302.smallest-rectangle-enclosing-black-pixels | [cpp](./leetcode/302.smallest-rectangle-enclosing-black-pixels.cpp) | O(M * N) / O(N * LogN) | Hard |

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 034.find-first-and-last-position-of-element-in-sorted-array | [cpp](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp), [python](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.py) | O(LogN) | O(1) | Medium |
| 069.sqrtx | [cpp](./leetcode/69.sqrtx.cpp), [python](./leetcode/69.sqrtx.py) | O(logN) | O(1) | Easy | | | Newton
| 278.first-bad-version | [cpp](./leetcode/278.first-bad-version.cpp), [python](./leetcode/278.first-bad-version.py) | O(logN) | O(1) | Easy
| 374.guess-number-higher-or-lower | [cpp](./leetcode/374.guess-number-higher-or-lower.cpp), [python](./leetcode/374.guess-number-higher-or-lower.py) | O(LogN) | O(1) | Easy
| 704.binary-search | [cpp](./leetcode/704.binary-search.cpp), [python](./leetcode/704.binary-search.py) | O(logN) | O(1) | Easy
| 852.peak-index-in-a-mountain-array | [cpp](./leetcode/852.peak-index-in-a-mountain-array.cpp), [python](./leetcode/852.peak-index-in-a-mountain-array.py) | O(logN) | O(1) | Easy | | Golden-section search |

## Divide and Conquer

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 4.median-of-two-sorted-arrays | [cpp](./leetcode/4.median-of-two-sorted-arrays.cpp), [python](./leetcode/4.median-of-two-sorted-arrays.py) | O(log(M + N)) | Hard |
| 98.validate-binary-search-tree | [cpp](./leetcode/98.validate-binary-search-tree.cpp), [python](./leetcode/98.validate-binary-search-tree.py) | O(N) | Medium | | TODO: inorder-traversal |
| 104.maximum-depth-of-binary-tree | [cpp](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python](./leetcode/104.maximum-depth-of-binary-tree.py) | O(N) | Easy
| 110.balanced-binary-tree | [cpp](./leetcode/110.balanced-binary-tree.cpp), [python](./leetcode/110.balanced-binary-tree.py) | O(N) | Easy
| 236.lowest-common-ancestor-of-a-binary-tree | [cpp](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp), [python](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | O(N) | Medium



| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 282.expression-add-operators | [cpp](./leetcode/282.expression-add-operators.cpp), [python](./leetcode/282.expression-add-operators.py) | O(2 ^ N) | O(N) | HARD/SSS | DFS | N = length of input

## Tree Traversal

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 94.binary-tree-inorder-traversal | [cpp](./leetcode/94.binary-tree-inorder-traversal.cpp) | O(N) | Medium |
| 102.binary-tree-level-order-traversal | [cpp](./leetcode/102.binary-tree-level-order-traversal.cpp) | O(N) | Medium |
| 107.binary-tree-level-order-traversal-ii | [cpp](./leetcode/107.binary-tree-level-order-traversal-ii.cpp) | O(N) | Easy |
| 144.binary-tree-preorder-traversal | [cpp](./leetcode/144.binary-tree-preorder-traversal.cpp) | O(N) | Medium


| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 130.surrounded-regions | [cpp](./leetcode/130.surrounded-regions.cpp), [python](./leetcode/130.surrounded-regions.py) | O(M * N) | O(M & N) | Medium | BFS
| 156.binary-tree-upside-down | [cpp](./leetcode/156.binary-tree-upside-down.cpp), [python](./leetcode/156.binary-tree-upside-down.py) | O(V) | O(1) | Medium
| 285.inorder-successor-in-bst | [cpp](./leetcode/285.inorder-successor-in-bst.cpp), [python](./leetcode/285.inorder-successor-in-bst.py) | O(H) | O(1) | Medium | BST | H = height of the tree
| 286.walls-and-gates | [cpp](./leetcode/286.walls-and-gates.cpp), [python](./leetcode/286.walls-and-gates.py) | O(M * N) | O(M * N) | Medium | BFS
| 314.binary-tree-vertical-order-traversal | [cpp](./leetcode/314.binary-tree-vertical-order-traversal.cpp), [python](./leetcode/314.binary-tree-vertical-order-traversal.py) | O(V) | O(V) | Medium
| 366.find-leaves-of-binary-tree | [cpp](./leetcode/366.find-leaves-of-binary-tree.cpp), [python](./leetcode/366.find-leaves-of-binary-tree.py) | O(V) | O(V) | Medium
| 433.minimum-genetic-mutation | [cpp](./leetcode/433.minimum-genetic-mutation.cpp), [python](./leetcode/433.minimum-genetic-mutation.py) | O(V + E) | O(N) | Medium | | |
| 538.convert-bst-to-greater-tree | [cpp](./leetcode/538.convert-bst-to-greater-tree.cpp), [python](./leetcode/538.convert-bst-to-greater-tree.py) | O(V) | O(1) | Easy 

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
| 126.word-ladder-ii | [python](./leetcode/126.word-ladder-ii.py) | O((V+E) * L^2) | Hard | BFS + DFS |
| 131.palindrome-partitioning | [python](./leetcode/131.palindrome-partitioning.py) | ??? | Medium | DFS

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 17.letter-combinations-of-a-phone-number | [cpp](./leetcode/17.letter-combinations-of-a-phone-number.cpp), [python](./leetcode/17.letter-combinations-of-a-phone-number.py) | O(2 ^ N) | O(N) | Medium | Time in [3 ^ N, 4 ^ N]
| 079.word-search | [cpp](./leetcode/79.word-search.cpp), [python](./leetcode/79.word-search.py) | O(M * N * L * L) | O(M * N) | Medium | DFS | L = length of words

## Hash Table
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 1.two-sum | [cpp](./leetcode/1.two-sum.cpp), [python](./leetcode/1.two-sum.py) | O(N) | Easy |
| 36.valid-sudoku | [cpp](./leetcode/36.valid-sudoku.cpp) | O(N ^ 2) | Medium | array-indexes
| 49.group-anagrams | [cpp](./leetcode/49.group-anagrams.cpp) | O(N * k * Logk) | Medium
| 170.two-sum-iii-data-structure-design | [cpp](./leetcode/170.two-sum-iii-data-structure-design.cpp), [python](./leetcode/170.two-sum-iii-data-structure-design.py) | O(N) | Easy
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy
| 217.contains-duplicate | [cpp](./leetcode/217.contains-duplicate.cpp) | O(N) | Easy
| 219.contains-duplicate-ii | [cpp](./leetcode/219.contains-duplicate-ii.cpp) | O(N) | Easy
| 249.group-shifted-strings | [cpp](./leetcode/249.group-shifted-strings.cpp) | O(N * K) | Medium
| 347.top-k-frequent-elements | [cpp](./leetcode/347.top-k-frequent-elements.cpp) | O(N * LogN) | Medium | TODO: quick-sort, bucket-sort
| 349.intersection-of-two-arrays | [cpp](./leetcode/349.intersection-of-two-arrays.cpp) | O(M + N) | Easy
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp) | O(M * N) | Easy
| 359.logger-rate-limiter | [cpp](./leetcode/359.logger-rate-limiter.cpp) | O(1) | Easy | [amortized](https://stackoverflow.com/questions/200384/constant-amortized-time)
| 380.insert-delete-getrandom-o1 | [cpp](./leetcode/380.insert-delete-getrandom-o1.cpp) | O(1) | Medium
| 454.4sum-ii | [cpp](./leetcode/454.4sum-ii.cpp) | O(N ^ 2) | Medium
| 599.minimum-index-sum-of-two-lists | [cpp](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | O(M + N) | Easy
| 652.find-duplicate-subtrees | [cpp](./leetcode/652.find-duplicate-subtrees.cpp) | O(N) | Medium
| 771.jewels-and-stones | [cpp](./leetcode/771.jewels-and-stones.cpp) | O(M + N) | Easy


| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 128.longest-consecutive-sequence | [cpp](./leetcode/128.longest-consecutive-sequence.cpp), [python](./leetcode/128.longest-consecutive-sequence.py) | O(N) | O(N) | Hard | Union-find
| 205.isomorphic-strings | [cpp](./leetcode/205.isomorphic-strings.cpp), [python](./leetcode/205.isomorphic-strings.py) | O(N) | O(N) | Easy
| 246.strobogrammatic-number | [cpp](./leetcode/246.strobogrammatic-number.cpp), [python](./leetcode/246.strobogrammatic-number.py) | O(N) | O(1) | Easy |
| 288.unique-word-abbreviation | [cpp](./leetcode/288.unique-word-abbreviation.cpp), [python](./leetcode/288.unique-word-abbreviation.py) | O(1) | O(N) | Medium
| 387.first-unique-character-in-a-string | [cpp](./leetcode/387.first-unique-character-in-a-string.cpp), [python](./leetcode/387.first-unique-character-in-a-string.py) | O(N) | O(N) | Easy
| 438.find-all-anagrams-in-a-string | [cpp](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python](./leetcode/438.find-all-anagrams-in-a-string.py) | O(N) | O(N) | Easy

## Heap
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 23.merge-k-sorted-lists | [cpp](./leetcode/23.merge-k-sorted-lists.cpp) | O(N * LogK) | - | Hard | TODO: merge-sort, bottom-up
| 378.kth-smallest-element-in-a-sorted-matrix | [cpp](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.cpp), [python](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.py) | O((K + M) * LogM) | O(M) | Medium | TODO: binary-search, O(N) solution |
| 407.trapping-rain-water-ii | [cpp](./leetcode/407.trapping-rain-water-ii.cpp), [python](./leetcode/407.trapping-rain-water-ii.py) | O(M * N * Log(M + N)) | O(M + N) | Hard | |

## Stack
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 20.valid-parentheses | [cpp](./leetcode/20.valid-parentheses.cpp), [python](./leetcode/20.valid-parentheses.py) | O(N) | O(N) | Easy

## Dynamic Programming
| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 63.unique-paths-ii | [python](./leetcode/63.unique-paths-ii.py) | O(M * N) | Medium | Coordinates
| 64.minimum-path-sum | [python](./leetcode/64.minimum-path-sum.py) | O(M * N) | Medium | Coordinates
| 70.climbing-stairs | [cpp](./leetcode/70.climbing-stairs.cpp), [python](./leetcode/70.climbing-stairs.py) | O(N) | Easy | Coordinates
| 120.triangle | [cpp](./leetcode/120.triangle.cpp), [python](./leetcode/120.triangle.py) | O(N^2) | Medium | Coordinates
| 300.longest-increasing-subsequence | [cpp](./leetcode/300.longest-increasing-subsequence.cpp), [python](./leetcode/300.longest-increasing-subsequence.py) | O(N^2) | Medium |  | follow-up is tricky
| 354.russian-doll-envelopes | [cpp](./leetcode/354.russian-doll-envelopes.cpp), [python](./leetcode/354.russian-doll-envelopes.py) | O(N^2) | Hard | TODO: Python Version Time Limit Exceeded
| 368.largest-divisible-subset | [cpp](./leetcode/368.largest-divisible-subset.cpp) | O(N^2) | Medium |
| 403.frog-jump | [cpp](./leetcode/403.frog-jump.cpp) | O(N^2) | Hard

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 062.unique-paths | [cpp](./leetcode/62.unique-paths.cpp), [python](./leetcode/62.unique-paths.py) | O(M * N) | O(M * N) | Medium | Coordinates
| 091.decode-ways | [cpp](./leetcode/91.decode-ways.cpp), [python](./leetcode/91.decode-ways.py) | O(N) | O(N) | Medium/S++ | conditional-climbing-stairs
| 322.coin-change | [cpp](./leetcode/322.coin-change.cpp), [python](./leetcode/322.coin-change.py) | O(L*N) | O(N) | Medium | N = amount, L = len(coins)

## Greedy
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 45.jump-game-ii | [cpp](./leetcode/45.jump-game-ii.cpp), [python](./leetcode/45.jump-game-ii.py) | O(N) | O(1) | Hard |
| 055.jump-game | [cpp](./leetcode/55.jump-game.cpp), [python](./leetcode/55.jump-game.py) | O(N) | O(1) | Medium | dynamic-programming
| 122.best-time-to-buy-and-sell-stock-ii | [cpp](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | O(N) | O(1) | Easy
| *406.queue-reconstruction-by-height | [cpp](./leetcode/406.queue-reconstruction-by-height.cpp), [python](./leetcode/406.queue-reconstruction-by-height.py) | O(N^2) | O(1) | Medium/S++ | Sort Multiple Keys

## Union Find
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 261.graph-valid-tree | [cpp](./leetcode/261.graph-valid-tree.cpp), [python](./leetcode/261.graph-valid-tree.py) | O(N) | O(N) | Medium | BFS/DFS | | N = len(edges)
| 305.number-of-islands-ii | [cpp](./leetcode/305.number-of-islands-ii.cpp), [python](./leetcode/305.number-of-islands-ii.py) | O(N) | O(M * N) | Hard | | N = len(positions)
| 721.accounts-merge | [cpp](./leetcode/721.accounts-merge.cpp), [python](./leetcode/721.accounts-merge.py) | O(M * N) | O(M * N) | Medium |

## Trie
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 208.implement-trie-prefix-tree | [cpp](./leetcode/208.implement-trie-prefix-tree.cpp), [python](./leetcode/208.implement-trie-prefix-tree.py) | O(L) | O(N * L) | Medium | - | L = len(word), N = number of words |
| 211.add-and-search-word-data-structure-design | [cpp](./leetcode/211.add-and-search-word-data-structure-design.cpp), [python](./leetcode/211.add-and-search-word-data-structure-design.py) | add = O(L), find >=  O(L) | O(N * L) | Medium/S-- | DFS | L = len(word), N = count(words)
| 212.word-search-ii | [cpp](./leetcode/212.word-search-ii.cpp), [python](./leetcode/212.word-search-ii.py) | O(M * N * L * L) | MAX(O(M * N), O(K * L)) | HARD | DFS | K = number of words, L = avg length of words
| 425.word-squares | [cpp](./leetcode/425.word-squares.cpp), [python](./leetcode/425.word-squares.py) | O(2^N) | O(NL) | Hard/SSS | DFS Pruning | | L = len(word), N = count(word)
| 677.map-sum-pairs | [cpp](./leetcode/677.map-sum-pairs.cpp), [python](./leetcode/677.map-sum-pairs.py) | O(L), O(KL) | O(N * L) | Medium | | L = length of input, k = number of items found|

## Other
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 215.kth-largest-element-in-an-array | [cpp](./leetcode/215.kth-largest-element-in-an-array.cpp), [python](./leetcode/215.kth-largest-element-in-an-array.py) | O(N) | O(1) | Medium | quick-select | best = O(N), worst = O(N^2)

# Lintcode

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 81.find-median-from-data-stream | [cpp](./lintcode/81.find-median-from-data-stream.cpp), [python](./lintcode/81.find-median-from-data-stream.py) | O(N * LogN) | O(N) | Hard | Heap |
| 465.kth-smallest-sum-in-two-sorted-arrays | [cpp](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.cpp), [python](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.py) | O((K + N) * LogN) | O(N) | Hard | heap | N = B.size()
| 543.kth-largest-in-n-arrays | [cpp](./lintcode/543.kth-largest-in-n-arrays.cpp), [python](./lintcode/543.kth-largest-in-n-arrays.py) | O(M * N * LogK) | O(K) | Easy | heap |
| 526.load-balancer | [cpp](./lintcode/526.load-balancer.cpp), [python](./lintcode/526.load-balancer.py) | O(1) | O(N) | Medium | Hash + Array
| 589.connecting-graph | [cpp](./lintcode/589.connecting-graph.cpp), [python](./lintcode/589.connecting-graph.py) | O(1) | O(N) | Medium | union-find
| 590.connecting-graph-ii | [cpp](./lintcode/590.connecting-graph-ii.cpp), [python](./lintcode/590.connecting-graph-ii.py) | O(1) | O(N) | Medium | union-find
| 591.connecting-graph-iii | [cpp](./lintcode/591.connecting-graph-iii.cpp), [python](./lintcode/591.connecting-graph-iii.py) | O(1) | O(N) | Medium | union-find
| 629.minimum-spanning-tree | [cpp](./lintcode/629.minimum-spanning-tree.cpp), [python](./lintcode/629.minimum-spanning-tree.py) | O(N * logN) | O(N) | Hard | union-find, Kruskal | Prim
| 652.factorization | [cpp](./lintcode/652.factorization.cpp), [python](./lintcode/652.factorization.py) | O(N) | O(LogN) | Medium/S++ | N = input number