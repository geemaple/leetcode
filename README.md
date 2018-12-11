# Algorithm
My personal leetcode answers<br/>
This is a **continually updated, open source** project.

📢📢📢 

1. Add **S--** **S++** **SSS** notations to further **level** algorithm monsters
2. Add **dollar($)** before question number **means** you may check **discussion** for alternative (usually better) answer
3. Add **C++** runtime grades: **Perfect**(>=95%) **Awesome**(>=80) **Great**(>=70%) **Cool**(>=50%) **Bad**(<50%) 

# Milestone
🎉🎉🎉 Finished 100 / 808 questions on 2018-05-28<br/>
🎉🎉🎉 Finished 150 / 824 questions on 2018-06-29<br/>
🎑🎑🎑 Finished 200 / 905 questions on 2018-09-24<br/> 
🎉🎉🎉 Finished 250 / 917 questions on 2018-10-15<br/>

# [References](./learning/README.md)

☝️Hey!!!, its clickable. references are moved💦

- [Leetcode](#leetcode)
    - [Math](#math)
    - [Bit](#bit)
    - [Design](#design)
    - [Array and String](#array-and-string)
    - [Two Pointers](#two-pointers)
    - [Linked List](#linked-list)
    - [Binary Search](#binary-search)
    - [Divide and Conquer](#divide-and-conquer)
    - [Tree Traversal](#tree-traversal)
    - [Graph Traversal](#graph-traversal)
    - [Backtracking](#backtracking)
    - [Hash Table](#hash-table)
    - [Queue](#queue)
    - [Heap](#heap)
    - [Stack](#stack)
    - [Sweep Line](#sweep-line)
    - [Dynamic Programming](#dynamic-programming)
    - [Red Black Tree](#red-black-tree)
    - [Greedy](#greedy)
    - [Union Find](#union-find)
    - [Trie](#trie)
    - [Other](#other)
    

- [Lintcode](#lintcode)

# Leetcode

## Math

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 002.add-two-numbers | [cpp](./leetcode/2.add-two-numbers.cpp), [python](./leetcode/2.add-two-numbers.py) | O(N) | O(1) | Medium/S--
| 007.reverse-integer | [cpp](./leetcode/7.reverse-integer.cpp), [python](./leetcode/7.reverse-integer.py) | O(L) | O(1) | Easy/S--
| 009.palindrome-number | [python](./leetcode/9.palindrome-number.py) | O(N) | O(1) | Easy | 
| 012.integer-to-roman | [cpp](./leetcode/12.integer-to-roman.cpp), [python](./leetcode/12.integer-to-roman.py) | O(N) | Medium | N = length of results
| 013.roman-to-integer | [cpp](./leetcode/13.roman-to-integer.cpp), [python](./leetcode/13.roman-to-integer.py) | O(N) | Easy
| 043.multiply-strings | [cpp](./leetcode/43.multiply-strings.cpp), [python](./leetcode/43.multiply-strings.py) | O(M*N) | O(M+N)  | Medium/S++
| 048.rotate-image | [cpp](./leetcode/48.rotate-image.cpp), [python](./leetcode/48.rotate-image.py) | O(MN) | O(1) | Medium/S++
| 050.powx-n | [cpp](./leetcode/50.powx-n.cpp), [python](./leetcode/50.powx-n.py) | O(logN) | O(1) | Medium/S++
| 067.add-binary | [cpp](./leetcode/67.add-binary,cpp), [python](./leetcode/67.add-binary.py) | O(N) | O(1) | Easy |
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy
| 273.integer-to-english-words | [python](./leetcode/273.integer-to-english-words.py) | O(N) | O(N) | Hard
| 311.sparse-matrix-multiplication | [cpp](./leetcode/311.sparse-matrix-multiplication.cpp), [python](./leetcode/311.sparse-matrix-multiplication.py) | O(N^3) | O(N^2) | Medium/S-- | 
| 326.power-of-three | [python](./leetcode/326.power-of-three.py) | O(1) | O(1) | Easy/S++
| 342.power-of-four | [python](./leetcode/342.power-of-four.py) | O(1) | O(1) | Easy/S++
| 415.add-strings | [cpp](./leetcode/415.add-strings.cpp), [python](./leetcode/415.add-strings.py) | O(N) | O(1) | Easy |
| 829.consecutive-numbers-sum | [python](./leetcode/829.consecutive-numbers-sum.py) | O(sqrt(N)) | O(1) | Hard
| 836.rectangle-overlap | [cpp](./leetcode/836.rectangle-overlap.cpp), [python](./leetcode/836.rectangle-overlap.py) | O(1) | O(1) | Easy

## Bit

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 136.single-number | [cpp](./leetcode/136.single-number.cpp), [python](./leetcode/136.single-number.py) | O(N) | O(1) | Easy | xor | Perfect
| 231.power-of-two | [python](./leetcode/231.power-of-two.py) | O(1) | O(1) | Easy
| 318.maximum-product-of-word-lengths | [cpp](./leetcode/318.maximum-product-of-word-lengths.cpp), [python](./leetcode/318.maximum-product-of-word-lengths.py) | O(N^2) | O(N) | Medium/S++ | mask | Great
| 393.utf-8-validation | [cpp](./leetcode/393.utf-8-validation.cpp), [python](./leetcode/393.utf-8-validation.py) | O(N) |O(1) | Medium/S-- | | Perfect
| 751.ip-to-cidr | [python](./leetcode/751.ip-to-cidr.py) | O(N) | O(1) | Easy/SSS

## Design

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 535.encode-and-decode-tinyurl | [python](./leetcode/535.encode-and-decode-tinyurl.py) | O(1) | O(N) | Medium

## Array and String

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 041.first-missing-positive | [python](./leetcode/41.first-missing-positive.py) | O(N) | O(1) | Hard
| 042.trapping-rain-water | [cpp](./leetcode/42.trapping-rain-water.cpp), [python](./leetcode/42.trapping-rain-water.py) | O(N) | O(N) | Hard | Scan Twice | Perfect | 
| 056.merge-intervals | [cpp](./leetcode/56.merge-intervals.cpp), [python](./leetcode/56.merge-intervals.py) | O(N * logN) | O(1) | Medium | Sort | N = number of intervals
| 057.insert-interval | [cpp](./leetcode/57.insert-interval.cpp), [python](./leetcode/57.insert-interval.py) | O(N) | O(1) | Hard | Sort | N = number of intervals
| 066.plus-one | [cpp](./leetcode/66.plus-one.cpp), [python](./leetcode/66.plus-one.py) | O(N) | O(1) | Easy
| 068.text-justification | [python](./leetcode/68.text-justification.py) | O(N) | O(N) | Hard |
| 118.pascals-triangle | [cpp](./leetcode/118.pascals-triangle.cpp), [python](./leetcode/118.pascals-triangle.py) | O(N^2) | O(1) | Easy || Perfect
| 119.pascals-triangle-ii | [cpp](./leetcode/119.pascals-triangle-ii.cpp), [python](./leetcode/119.pascals-triangle-ii.py) | O(N^2) | O(1) | Easy || Perfect
| 157.read-n-characters-given-read4 | [cpp](./leetcode/157.read-n-characters-given-read4.cpp), [python](./leetcode/157.read-n-characters-given-read4.py) | O(N) | O(1) | Easy | String
| 161.one-edit-distance | [cpp](./leetcode/161.one-edit-distance.cpp), [python](./leetcode/161.one-edit-distance.py) | O(N) | O(1) | Medium | String | Perfect |
| 163.missing-ranges | [cpp](./leetcode/163.missing-ranges.cpp), [python](./leetcode/163.missing-ranges.py) | O(N) | O(1) | Medium | Array | Mind int overflow
| 215.kth-largest-element-in-an-array | [cpp](./leetcode/215.kth-largest-element-in-an-array.cpp), [python](./leetcode/215.kth-largest-element-in-an-array.py) | O(N) | O(1) | Medium/S-- | quick-select | best = O(N), worst = O(N^2)
| 228.summary-ranges |[python](./leetcode/228.summary-ranges.py) | O(N) | O(1) | Medium
| 240.search-a-2d-matrix-ii | [cpp](./leetcode/240.search-a-2d-matrix-ii.cpp), [python](./leetcode/240.search-a-2d-matrix-ii.py) | O(N + M) | O(1) | Medium
| 251.flatten-2d-vector | [python](./leetcode/251.flatten-2d-vector.py) | - | O(N) | Medium
| 271.encode-and-decode-strings | [cpp](./leetcode/271.encode-and-decode-strings.cpp), [python](./leetcode/271.encode-and-decode-strings.py) | O(N) | O(1) | Easy | String | N = count of chars
| 277.find-the-celebrity | [cpp](./leetcode/277.find-the-celebrity.cpp), [python](./leetcode/277.find-the-celebrity.py) | O(N) | O(1) | Medium |
| 280.wiggle-sort | [python](./leetcode/280.wiggle-sort.py) | O(N) | O(1) | Medium
| 289.game-of-life | [python](./leetcode/289.game-of-life.py) | O(MN) | O(1) | Medium
| $324.wiggle-sort-ii | [python](./leetcode/324.wiggle-sort-ii.py) | O(NLogN) | O(N) | Medium | Follow up
| 388.longest-absolute-file-path | [cpp](./leetcode/388.longest-absolute-file-path.cpp), [python](./leetcode/388.longest-absolute-file-path.py) | O(N) | O(N) | Medium | String |
| 408.valid-word-abbreviation | [cpp](./leetcode/408.valid-word-abbreviation.cpp), [python](./leetcode/408.valid-word-abbreviation.py) | O(N) | O(1) | Easy
| 448.find-all-numbers-disappeared-in-an-array | [python](./leetcode/448.find-all-numbers-disappeared-in-an-array.py) | O(N) | O(1) | Easy/SSS
| 463.island-perimeter | [python](./leetcode/463.island-perimeter.py) | O(N) | O(1) | Easy/S++
| 527.word-abbreviation | [cpp](./leetcode/527.word-abbreviation.cpp), [python](./leetcode/527.word-abbreviation.py) | O(N * L) | O(N) | Hard | L = avg word length
| 560.subarray-sum-equals-k | [cpp](./leetcode/560.subarray-sum-equals-k.cpp), [python](./leetcode/560.subarray-sum-equals-k.py) | O(N) | O(N) | Medium || Great
| 657.robot-return-to-origin | [python](./leetcode/657.robot-return-to-origin.py) | O(N) | O(1) | Easy
| 674.longest-continuous-increasing-subsequence |[cpp](./leetcode/674.longest-continuous-increasing-subsequence.cpp), [python](./leetcode/674.longest-continuous-increasing-subsequence.py) | O(N) | O(1) | Easy || Perfect
| 755.pour-water | [python](./leetcode/755.pour-water.py) | O(N^2) | O(1) | Medium/S-- 
| 796.rotate-string | [cpp](./leetcode/796.rotate-string.cpp), [python](./leetcode/796.rotate-string.py) | O(N) | O(1) | Easy | string | | Awesome
| 929.unique-email-addresses |[python](./leetcode/929.unique-email-addresses.py) | O(N) | O(N) | Easy |

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 54.spiral-matrix | [cpp](./leetcode/54.spiral-matrix.cpp) | O(N) | Medium
| 350.intersection-of-two-arrays-ii | [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(N * logN) | Easy
| 485.max-consecutive-ones | [cpp](./leetcode/485.max-consecutive-ones.cpp) | O(N) | Easy
| 498.diagonal-traverse | [cpp](./leetcode/498.diagonal-traverse.cpp) | O(MN) | Medium
| 561.array-partition-i | [cpp](./leetcode/561.array-partition-i.cpp) | O(N * logN) | Easy
| 724.find-pivot-index | [cpp](./leetcode/724.find-pivot-index.cpp) | O(N) | Easy
| 747.largest-number-at-least-twice-of-others | [cpp](./leetcode/747.largest-number-at-least-twice-of-others) | O(N) |Easy
| 832.flipping-an-image | [python](./leetcode/832.flipping-an-image.py) | O(N) | O(N) | Easy
| 859.buddy-strings | [cpp](./leetcode/859.buddy-strings.cpp) | O(N) | Easy | string |

## Two Pointers

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 003.longest-substring-without-repeating-characters | [cpp](./leetcode/3.longest-substring-without-repeating-characters.cpp), [python](./leetcode/3.longest-substring-without-repeating-characters.py) | O(N) | O(N) | Medium
| 011.container-with-most-water | [python](./leetcode/11.container-with-most-water.py) | O(N) | O(1) | Medium 
| 015.3sum | [cpp](./leetcode/15.3sum.cpp), [python](./leetcode/15.3sum.py) | O(N^2) | O(1) | Medium/S++ | | Awesome
| 016.3sum-closest | [cpp](./leetcode/16.3sum-closest.cpp), [python](./leetcode/16.3sum-closest.py) | O(N^2) | O(1) | Medium || Cool
| 018.4sum | [cpp](./leetcode/18.4sum.cpp), [python](./leetcode/18.4sum.py) | O(N^3) | O(1) | Medium || Awesome
| 019.remove-nth-node-from-end-of-list | [cpp](./leetcode/19.remove-nth-node-from-end-of-list.cpp), [python](./leetcode/19.remove-nth-node-from-end-of-list.py) | O(N) | O(1) | Medium || Perfect
| 026.remove-duplicates-from-sorted-array | [cpp](./leetcode/26.remove-duplicates-from-sorted-array.cpp), [python](./leetcode/26.remove-duplicates-from-sorted-array.py) | O(N) | O(1) | Easy || Perfect
| 027.remove-element | [cpp](./leetcode/27.remove-element.cpp), [python](./leetcode/27.remove-element.py) | O(N) | O(1) | Easy
| 028.implement-strstr | [cpp](./leetcode/28.implement-strstr.cpp), [python](./leetcode/28.implement-strstr.py) | O(M + N) | O(1) | Easy | Pattern Searching | KMP
| 042.trapping-rain-water | [cpp](./leetcode/42.trapping-rain-water.cpp), [python](./leetcode/42.trapping-rain-water.py) | O(N) | O(1) | Hard | Two Pointers | 
| 075.sort-colors | [cpp](./leetcode/75.sort-colors.cpp) [python](./leetcode/75.sort-colors.py) | O(N) | O(1) | Medium | counting-sort || Perfect
| 076.minimum-window-substring | [cpp](./leetcode/76.minimum-window-substring.cpp), [python](./leetcode/76.minimum-window-substring.py) | O(N) | O(N) | Hard
| 088.merge-sorted-array | [cpp](./leetcode/88.merge-sorted-array.cpp), [python](./leetcode/88.merge-sorted-array.py) | O(N + M) | O(1) | Easy | | Perfect
| 125.valid-palindrome | [cpp](./leetcode/125.valid-palindrome.cpp), [python](./leetcode/125.valid-palindrome.py) | O(N) | O(1) | Easy || Perfect
| 159.longest-substring-with-at-most-two-distinct-characters | [cpp](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.cpp), [python](./leetcode/159.longest-substring-with-at-most-two-distinct-characters.py) | O(N) | O(N) | Hard |
| 167.two-sum-ii-input-array-is-sorted | [cpp](./leetcode/167.two-sum-ii-input-array-is-sorted.cpp), [python](./leetcode/167.two-sum-ii-input-array-is-sorted.py) | O(N) | O(1) | Easy || Perfect
| 209.minimum-size-subarray-sum | [cpp](./leetcode/209.minimum-size-subarray-sum.cpp), [python](./leetcode/209.minimum-size-subarray-sum.py) | O(N) | O(1) | Medium |
| 234.palindrome-linked-list | [cpp](./leetcode/234.palindrome-linked-list.cpp), [python](./leetcode/234.palindrome-linked-list.py) | O(N) | O(1) | Easy | | maybe Harder
| 283.move-zeroes | [cpp](./leetcode/283.move-zeroes.cpp), [python](./leetcode/283.move-zeroes.py) | O(N) | O(1) | Easy || Perfect
| 340.longest-substring-with-at-most-k-distinct-characters | [cpp](./leetcode/340.longest-substring-with-at-most-k-distinct-characters.cpp), [python](./leetcode/340.longest-substring-with-at-most-k-distinct-characters.py) | O(N) | O(N) | Hard | | Cool |
| 344.reverse-string | [cpp](./leetcode/344.reverse-string.cpp), [python](./leetcode/344.reverse-string.py) | O(N) | O(1) | Easy
| 345.reverse-vowels-of-a-string | [cpp](./leetcode/345.reverse-vowels-of-a-string.cpp), [python](./leetcode/345.reverse-vowels-of-a-string.py) | O(N) | O(1) | Easy
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp), [python](./leetcode/350.intersection-of-two-arrays-ii.py) | O(K * logK), k = max(M, N) | O(1) | Easy | hash, binary-search
| 532.k-diff-pairs-in-an-array | [cpp](./leetcode/532.k-diff-pairs-in-an-array.cpp), [python](./leetcode/532.k-diff-pairs-in-an-array.py) | O(N * logN) | O(1) | Easy | Hash |
| 844.backspace-string-compare | [cpp](./leetcode/844.backspace-string-compare.cpp), [python](./leetcode/844.backspace-string-compare.py) | O(N) | O(1) | Easy | stack

## Linked List

> There is actually no algorithm in linked list question, but is really tricky to get one right

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 021.merge-two-sorted-lists | [cpp](./leetcode/21.merge-two-sorted-lists.cpp), [python](./leetcode/21.merge-two-sorted-lists.py) | O(N) | O(1) | Easy || Perfect
| 025.reverse-nodes-in-k-group | [cpp](./leetcode/25.reverse-nodes-in-k-group.cpp), [python](./leetcode/25.reverse-nodes-in-k-group.py) | O(N) | O(1) | Hard/S-- | | Perfect
| 086.partition-list | [cpp](./leetcode/86.partition-list.cpp), [python](./leetcode/86.partition-list.py) | O(N) | O(1) | Medium || Perfect
| 092.reverse-linked-list-ii | [cpp](./leetcode/92.reverse-linked-list-ii.cpp), [python](./leetcode/92.reverse-linked-list-ii.py) | O(N) | O(1) | Medium || Perfect
| 141.linked-list-cycle | [cpp](./leetcode/141.linked-list-cycle.cpp), [python](./leetcode/141.linked-list-cycle.py) | O(N) | O(1) | Easy || perfect
| 142.linked-list-cycle-ii | [cpp](./leetcode/142.linked-list-cycle-ii.cpp), [python](./leetcode/142.linked-list-cycle-ii.py) | O(N) | O(1) | Medium/S++ || Perfect
| 160.intersection-of-two-linked-lists | [cpp](./leetcode/160.intersection-of-two-linked-lists.cpp), [python](./leetcode/160.intersection-of-two-linked-lists.py) | O(N + M) | Easy | two-pointers | Perfect
| 206.reverse-linked-list | [cpp](./leetcode/206.reverse-linked-list.cpp), [python](./leetcode/206.reverse-linked-list.py) | O(N) | O(1) | Easy/S++ || Perfect

| Problem    | Solution    | Time    | Difficulty    | Tag    | Note    |
| -----------| ------------| --------| --------------| -------| --------|
| 61.rotate-list | [python](./leetcode/61.rotate-list.py) | O(N) | Medium |
| 143.reorder-list | [python](./leetcode/143.reorder-list.py) | O(N) | Medium |
| 138.copy-list-with-random-pointer | [python](./leetcode/138.copy-list-with-random-pointer.py) | O(N) | Medium
| 148.sort-list | [python](./leetcode/148.sort-list.py) | O(N * logN) | Medium |
| 203.remove-linked-list-elements | [python](./leetcode/203.remove-linked-list-elements.py) | O(N) | Easy
| 237.delete-node-in-a-linked-list | [python](./leetcode/237.delete-node-in-a-linked-list.py) | O(1) | Easy
| 328.odd-even-linked-list | [python](./leetcode/328.odd-even-linked-list.py) | O(N) | Medium

## Binary Search

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 029.divide-two-integers | [cpp](./leetcode/29.divide-two-integers.cpp), [python](./leetcode/29.divide-two-integers.py) | O(logN) | O(1) | Medium/S++ | Math
| $033.search-in-rotated-sorted-array | [cpp](./leetcode/33.search-in-rotated-sorted-array.cpp), [python](./leetcode/33.search-in-rotated-sorted-array.py) | O(logN) | O(1) | Medium/S++ | | Perfect
| 034.find-first-and-last-position-of-element-in-sorted-array | [cpp](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.cpp), [python](./leetcode/34.find-first-and-last-position-of-element-in-sorted-array.py) | O(LogN) | O(1) | Medium | | Perfect
| $069.sqrtx | [cpp](./leetcode/69.sqrtx.cpp), [python](./leetcode/69.sqrtx.py) | O(logN) | O(1) | Easy | | Perfect
| 074.search-a-2d-matrix | [cpp](./leetcode/74.search-a-2d-matrix.cpp),  [python](./leetcode/74.search-a-2d-matrix.py) | O(logN) | O(1) | Medium | N = row * col
| 081.search-in-rotated-sorted-array-ii | [cpp](./leetcode/81.search-in-rotated-sorted-array-ii.cpp), [python](./leetcode/81.search-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | O(1) | Medium/S++ |
| 153.find-minimum-in-rotated-sorted-array | [cpp](./leetcode/153.find-minimum-in-rotated-sorted-array.cpp), [python](./leetcode/153.find-minimum-in-rotated-sorted-array.py) | O(logN) | O(1) | Medium | | Perfect
| 154.find-minimum-in-rotated-sorted-array-ii | [cpp](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.cpp), [python](./leetcode/154.find-minimum-in-rotated-sorted-array-ii.py) | O(logN) ~ O(N) | O(1) | Hard
| 162.find-peak-element | [cpp](./leetcode/162.find-peak-element.cpp), [python](./leetcode/162.find-peak-element.py) | O(logN) | O(1) | Medium | | Perfect
| 270.closest-binary-search-tree-value | [cpp](./leetcode/270.closest-binary-search-tree-value.cpp), [python](./leetcode/270.closest-binary-search-tree-value.py) | O(LogN) | O(1) | Easy | | Perfect
| 278.first-bad-version | [cpp](./leetcode/278.first-bad-version.cpp), [python](./leetcode/278.first-bad-version.py) | O(logN) | O(1) | Easy | | Perfect
| 302.smallest-rectangle-enclosing-black-pixels | [cpp](./leetcode/302.smallest-rectangle-enclosing-black-pixels.cpp), [python](./leetcode/302.smallest-rectangle-enclosing-black-pixels.py) | O(MLogN + NLogM) | O(1) | Hard/SSS || Perfect
| 367.valid-perfect-square | [cpp](./leetcode/367.valid-perfect-square.cpp), [python](./leetcode/367.valid-perfect-square.py) | O(LogN) | O(1) | Easy || Perfect
| 374.guess-number-higher-or-lower | [cpp](./leetcode/374.guess-number-higher-or-lower.cpp), [python](./leetcode/374.guess-number-higher-or-lower.py) | O(LogN) | O(1) | Easy | | Perfect
| $658.find-k-closest-elements | [cpp](./leetcode/658.find-k-closest-elements.cpp), [python](./leetcode/658.find-k-closest-elements.py) | Log(N - K) | O(1) | Medium/S++ | | Awesome
| 702.search-in-a-sorted-array-of-unknown-size | [cpp](./leetcode/702.search-in-a-sorted-array-of-unknown-size.cpp), [python](./leetcode/702.search-in-a-sorted-array-of-unknown-size.py) | O(LogN) | O(1) | Medium | | Perfect
| 704.binary-search | [cpp](./leetcode/704.binary-search.cpp), [python](./leetcode/704.binary-search.py) | O(logN) | O(1) | Easy | | Perfect 
| 852.peak-index-in-a-mountain-array | [cpp](./leetcode/852.peak-index-in-a-mountain-array.cpp), [python](./leetcode/852.peak-index-in-a-mountain-array.py) | O(logN) | O(1) | Easy | Golden-section search |

## Divide and Conquer

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 004.median-of-two-sorted-arrays | [cpp](./leetcode/4.median-of-two-sorted-arrays.cpp), [python](./leetcode/4.median-of-two-sorted-arrays.py) | O(log(K)) | O(1) |Hard/SSS | binary-search | Perfect
| 098.validate-binary-search-tree | [cpp](./leetcode/98.validate-binary-search-tree.cpp), [python](./leetcode/98.validate-binary-search-tree.py) | O(N) | O(1) | Medium || Cool
| 104.maximum-depth-of-binary-tree | [cpp](./leetcode/104.maximum-depth-of-binary-tree.cpp), [python](./leetcode/104.maximum-depth-of-binary-tree.py) | O(N) | O(1) | Easy || Perfect
| 110.balanced-binary-tree | [cpp](./leetcode/110.balanced-binary-tree.cpp), [python](./leetcode/110.balanced-binary-tree.py) | O(N) | O(1) | Easy || Perfect
| 236.lowest-common-ancestor-of-a-binary-tree | [cpp](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.cpp), [python](./leetcode/236.lowest-common-ancestor-of-a-binary-tree.py) | O(N) | O(1) | Medium || Perfect
| 273.integer-to-english-words | [python](./leetcode/273.integer-to-english-words.py) | O(N) | O(N) | Hard
| 282.expression-add-operators | [cpp](./leetcode/282.expression-add-operators.cpp), [python](./leetcode/282.expression-add-operators.py) | O(2 ^ N) | O(N) | Hard/SSS | DFS | N = length of input
| 687.longest-univalue-path | [cpp](./leetcode/687.longest-univalue-path.cpp), [python](./leetcode/687.longest-univalue-path.py) | O(N) | O(1) | Easy/S++ || Perfect

## Tree Traversal

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 94.binary-tree-inorder-traversal | [cpp](./leetcode/94.binary-tree-inorder-traversal.cpp), [python](./leetcode/94.binary-tree-inorder-traversal.py) | O(N) | O(1) | Medium/S++ || Perfect
| 102.binary-tree-level-order-traversal | [cpp](./leetcode/102.binary-tree-level-order-traversal.cpp), [python](./leetcode/102.binary-tree-level-order-traversal.py) | O(N) | O(H) | Medium | | Perfect
| 103.binary-tree-zigzag-level-order-traversal | [cpp](./leetcode/103.binary-tree-zigzag-level-order-traversal.cpp), [python](./leetcode/103.binary-tree-zigzag-level-order-traversal.py) | O(N) | O(N) | Medium || Perfect
| 107.binary-tree-level-order-traversal-ii | [cpp](./leetcode/107.binary-tree-level-order-traversal-ii.cpp), [python](./leetcode/107.binary-tree-level-order-traversal-ii.py) | O(N) | O(N) | Easy || Perfect
| 114.flatten-binary-tree-to-linked-list | [cpp](./leetcode/114.flatten-binary-tree-to-linked-list.cpp), [python](./leetcode/114.flatten-binary-tree-to-linked-list.py) | O(N) | O(1) | Medium || Cool
| 130.surrounded-regions | [cpp](./leetcode/130.surrounded-regions.cpp), [python](./leetcode/130.surrounded-regions.py) | O(MN) | O(M & N) | Medium | BFS
| 144.binary-tree-preorder-traversal | [cpp](./leetcode/144.binary-tree-preorder-traversal.cpp), [python](./leetcode/144.binary-tree-preorder-traversal.py) | O(N) | O(1) | Medium/S-- || Perfect
| 145.binary-tree-postorder-traversal | [cpp](./leetcode/145.binary-tree-postorder-traversal.cpp), [python](./leetcode/145.binary-tree-postorder-traversal.py) | O(N) | O(1) | Hard/SSS || Perfect
| 156.binary-tree-upside-down | [cpp](./leetcode/156.binary-tree-upside-down.cpp), [python](./leetcode/156.binary-tree-upside-down.py) | O(V) | O(1) | Medium
| 173.binary-search-tree-iterator | [cpp](./leetcode/173.binary-search-tree-iterator.cpp), [python](./leetcode/173.binary-search-tree-iterator.py) | O(1) | O(H) | Medium/S-- || Perfect
| 257.binary-tree-paths | [cpp](./leetcode/257.binary-tree-paths.cpp), [python](./leetcode/257.binary-tree-paths.py) | O(N) | O(1) | Easy || Perfect
| 285.inorder-successor-in-bst | [cpp](./leetcode/285.inorder-successor-in-bst.cpp), [python](./leetcode/285.inorder-successor-in-bst.py) | O(H) | O(1) | Medium | BST | H = height of the tree
| 286.walls-and-gates | [cpp](./leetcode/286.walls-and-gates.cpp), [python](./leetcode/286.walls-and-gates.py) | O(MN) | O(MN) | Medium | BFS
| 297.serialize-and-deserialize-binary-tree | [cpp](./leetcode/297.serialize-and-deserialize-binary-tree.cpp), [python](./leetcode/297.serialize-and-deserialize-binary-tree.py) | O(N) | O(N) | Hard || Cool
| 314.binary-tree-vertical-order-traversal | [cpp](./leetcode/314.binary-tree-vertical-order-traversal.cpp), [python](./leetcode/314.binary-tree-vertical-order-traversal.py) | O(V) | O(V) | Medium
| 366.find-leaves-of-binary-tree | [cpp](./leetcode/366.find-leaves-of-binary-tree.cpp), [python](./leetcode/366.find-leaves-of-binary-tree.py) | O(V) | O(V) | Medium
| 426.convert-binary-search-tree-to-sorted-doubly-linked-list | [cpp](./leetcode/426.convert-binary-search-tree-to-sorted-doubly-linked-list.cpp), [python](./leetcode/426.convert-binary-search-tree-to-sorted-doubly-linked-list.py) | O(N) | O(1) | Medium || Perfect
| 538.convert-bst-to-greater-tree | [cpp](./leetcode/538.convert-bst-to-greater-tree.cpp), [python](./leetcode/538.convert-bst-to-greater-tree.py) | O(V) | O(1) | Easy 

## Graph Traversal

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 127.word-ladder | [cpp](./leetcode/127.word-ladder.cpp), [python](./leetcode/127.word-ladder.py) | O(N^2 * L^2) | O(N) | Medium/S++ | BFS | Bad |
| 133.clone-graph | [cpp](./leetcode/133.clone-graph.cpp), [python](./leetcode/133.clone-graph.py) | O(V + E) | O(N) | Medium || Great
| 200.number-of-islands | [cpp](./leetcode/200.number-of-islands.cpp), [python](./leetcode/200.number-of-islands.py) | O(MN) | O(MN) | Medium | BFS/DFS | union-find | Bad
| 207.course-schedule | [cpp](./leetcode/207.course-schedule.cpp), [python](./leetcode/207.course-schedule.py) | O(V + E) | O(V + E) | Medium | | Perfect
| 210.course-schedule-ii | [cpp](./leetcode/210.course-schedule-ii.cpp), [python](./leetcode/210.course-schedule-ii.py) | O(V + E) | O(V) | Medium | topological-sort | Awesome
| 269.alien-dictionary | [python](./leetcode/269.alien-dictionary.py) | O(V + E) | O(V + E) | Hard 
| 323.number-of-connected-components-in-an-undirected-graph | [cpp](./leetcode/323.number-of-connected-components-in-an-undirected-graph.cpp), [python](./leetcode/323.number-of-connected-components-in-an-undirected-graph.py) | O(V+E) | O(V+E) | Medium | union-find | Bad
| 433.minimum-genetic-mutation | [cpp](./leetcode/433.minimum-genetic-mutation.cpp), [python](./leetcode/433.minimum-genetic-mutation.py) | O(V + E) | O(N) | Medium | | |
| 444.sequence-reconstruction | [cpp](./leetcode/444.sequence-reconstruction.cpp), [python](./leetcode/444.sequence-reconstruction.py) | O(V+E) | O(V) | Medium | topological-sort || Bad
| 773.sliding-puzzle | [python](./leetcode/773.sliding-puzzle.py) | O(V + E) | O(N) | Hard/SSS |
| 815.bus-routes | [python](./leetcode/815.bus-routes.py) | O(V + E) | O(N) | Hard/SSS |

## Backtracking

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 017.letter-combinations-of-a-phone-number | [cpp](./leetcode/17.letter-combinations-of-a-phone-number.cpp), [python](./leetcode/17.letter-combinations-of-a-phone-number.py) | O(2 ^ N) | O(N) | Medium ||
| 022.generate-parentheses | [python](./leetcode/22.generate-parentheses.py) | O(ans) | O(N) | Medium
| 039.combination-sum | [cpp](./leetcode/39.combination-sum.cpp), [python](./leetcode/39.combination-sum.py) | O(N^K), k=target/min | O(K) | Medium | DFS | Perfect
| 040.combination-sum-ii | [cpp](./leetcode/40.combination-sum-ii.cpp), [python](./leetcode/40.combination-sum-ii.py) | O(2^K), k=target/min | O(K) | Medium/S-- | DFS  | Perfect
| 046.permutations | [cpp](./leetcode/46.permutations.cpp), [python](./leetcode/46.permutations.py) | O(N * N!) | O(N) | Medium | DFS | Perfect
| 047.permutations-ii | [cpp](./leetcode/47.permutations-ii.cpp), [python](./leetcode/47.permutations-ii.py) | O(N * N!) | O(N) | Medium/S++ | DFS | Perfect
| 051.n-queens | [cpp](./leetcode/51.n-queens.cpp), [python](./leetcode/51.n-queens.py) | O(N^N) | O(N) | Hard | DFS | Awesome
| 052.n-queens-ii | [cpp](./leetcode/52.n-queens-ii.cpp), [python](./leetcode/52.n-queens-ii.py) | O(N^N) | O(N) | Hard | DFS | Perfect
| 078.subsets | [cpp](./leetcode/78.subsets.cpp), [python](./leetcode/78.subsets.py) | O(N * 2^N) | O(N) | Medium | DFS/Bit | Perfect
| 079.word-search | [cpp](./leetcode/79.word-search.cpp), [python](./leetcode/79.word-search.py) | O(MN * L^2), L = length of words | O(MN) | Medium | DFS |
| 090.subsets-ii | [cpp](./leetcode/90.subsets-ii.cpp), [python](./leetcode/90.subsets-ii.py) | O(N * 2^N) | O(N) | Medium/S-- | DFS | Perfect
| 126.word-ladder-ii | [cpp](./leetcode/126.word-ladder-ii.cpp), [python](./leetcode/126.word-ladder-ii.py) | - | O(N) | Hard/SSS | DFS Pruning | Awesome
| 131.palindrome-partitioning | [cpp](./leetcode/131.palindrome-partitioning.cpp), [python](./leetcode/131.palindrome-partitioning.py) | O(2^N) | O(N) | Medium | DFS | Perfect

## Hash Table
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 001.two-sum | [cpp](./leetcode/1.two-sum.cpp), [python](./leetcode/1.two-sum.py) | O(N) | O(N) | Easy || Perfect
| 36.valid-sudoku | [cpp](./leetcode/36.valid-sudoku.cpp) | O(N ^ 2) | Medium | array-indexes
| 49.group-anagrams | [cpp](./leetcode/49.group-anagrams.cpp) | O(N * k * Logk) | Medium
| 170.two-sum-iii-data-structure-design | [cpp](./leetcode/170.two-sum-iii-data-structure-design.cpp), [python](./leetcode/170.two-sum-iii-data-structure-design.py) | O(N) | O(N) | Easy || Awesome
| 202.happy-number | [cpp](./leetcode/202.happy-number.cpp), [python](./leetcode/202.happy-number.py) | O(N) | Easy
| 217.contains-duplicate | [cpp](./leetcode/217.contains-duplicate.cpp) | O(N) | Easy
| 219.contains-duplicate-ii | [cpp](./leetcode/219.contains-duplicate-ii.cpp) | O(N) | Easy
| 249.group-shifted-strings | [cpp](./leetcode/249.group-shifted-strings.cpp) | O(N * K) | Medium
| 347.top-k-frequent-elements | [cpp](./leetcode/347.top-k-frequent-elements.cpp) | O(N * LogN) | Medium | TODO: quick-sort, bucket-sort
| 350.intersection-of-two-arrays-ii | [cpp](./leetcode/350.intersection-of-two-arrays-ii.cpp) | O(MN) | Easy
| 359.logger-rate-limiter | [cpp](./leetcode/359.logger-rate-limiter.cpp) | O(1) | Easy | [amortized](https://stackoverflow.com/questions/200384/constant-amortized-time)
| 380.insert-delete-getrandom-o1 | [cpp](./leetcode/380.insert-delete-getrandom-o1.cpp) | O(1) | Medium
| 454.4sum-ii | [cpp](./leetcode/454.4sum-ii.cpp) | O(N ^ 2) | Medium
| 599.minimum-index-sum-of-two-lists | [cpp](./leetcode/599.minimum-index-sum-of-two-lists.cpp) | O(M + N) | Easy
| 652.find-duplicate-subtrees | [cpp](./leetcode/652.find-duplicate-subtrees.cpp) | O(N) | Medium
| 760.find-anagram-mappings | [python](./leetcode/760.find-anagram-mappings.py) | O(N) | O(N) | Easy
| 771.jewels-and-stones | [cpp](./leetcode/771.jewels-and-stones.cpp) | O(M + N) | Easy


| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 128.longest-consecutive-sequence | [cpp](./leetcode/128.longest-consecutive-sequence.cpp), [python](./leetcode/128.longest-consecutive-sequence.py) | O(N) | O(N) | Hard/S++ | Union-find
| 205.isomorphic-strings | [cpp](./leetcode/205.isomorphic-strings.cpp), [python](./leetcode/205.isomorphic-strings.py) | O(N) | O(N) | Easy
| 246.strobogrammatic-number | [cpp](./leetcode/246.strobogrammatic-number.cpp), [python](./leetcode/246.strobogrammatic-number.py) | O(N) | O(1) | Easy |
| 288.unique-word-abbreviation | [cpp](./leetcode/288.unique-word-abbreviation.cpp), [python](./leetcode/288.unique-word-abbreviation.py) | O(1) | O(N) | Medium
| 349.intersection-of-two-arrays | [cpp](./leetcode/349.intersection-of-two-arrays.cpp), [python](./leetcode/349.intersection-of-two-arrays.py) | O(K * logK), k = max(M, N) | O(1) | Easy | two-pointers, binary-search | perfect
| 387.first-unique-character-in-a-string | [cpp](./leetcode/387.first-unique-character-in-a-string.cpp), [python](./leetcode/387.first-unique-character-in-a-string.py) | O(N) | O(N) | Easy
| 438.find-all-anagrams-in-a-string | [cpp](./leetcode/438.find-all-anagrams-in-a-string.cpp), [python](./leetcode/438.find-all-anagrams-in-a-string.py) | O(N) | O(N) | Easy

## queue
| Problem    | Solution    | Time    | Space    |  Difficulty    | Node   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 346.moving-average-from-data-stream | [cpp](./leetcode/346.moving-average-from-data-stream.cpp), [python](./leetcode/346.moving-average-from-data-stream.py) | O(1) | O(N) | Easy | | Perfect 

## Heap
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| $023.merge-k-sorted-lists | [cpp](./leetcode/23.merge-k-sorted-lists.cpp), [python](./leetcode/23.merge-k-sorted-lists.py) | O(N * LogK) | O(K) | Hard | | Perfect
| 295.find-median-from-data-stream | [cpp](./leetcode/295.find-median-from-data-stream.cpp), [python](./leetcode/295.find-median-from-data-stream.py) | O(NLogN) | O(N) | Medium | | Cool
| 378.kth-smallest-element-in-a-sorted-matrix | [cpp](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.cpp), [python](./leetcode/378.kth-smallest-element-in-a-sorted-matrix.py) | O((K + M) * LogM) | O(M) | Medium | TODO: binary-search, O(N) solution |
| 407.trapping-rain-water-ii | [cpp](./leetcode/407.trapping-rain-water-ii.cpp), [python](./leetcode/407.trapping-rain-water-ii.py) | O(M * N * Log(M + N)) | O(M + N) | Hard/SSS | | Bad

## Stack
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 020.valid-parentheses | [cpp](./leetcode/20.valid-parentheses.cpp), [python](./leetcode/20.valid-parentheses.py) | O(N) | O(N) | Easy | | Perfect
| 084.largest-rectangle-in-histogram | [cpp](./leetcode/84.largest-rectangle-in-histogram.cpp), [python](./leetcode/84.largest-rectangle-in-histogram.py) | O(N) | O(N) | Hard/S++ || Perfect
| 085.maximal-rectangle | [cpp](./leetcode/85.maximal-rectangle.cpp), [python](./leetcode/85.maximal-rectangle.py) | O(MN) | O(N) | Hard/SSS || Perfect
| 155.min-stack | [cpp](./leetcode/155.min-stack.cpp), [python](./leetcode/155.min-stack.py) | O(1) | O(N) | Easy/S-- | | Cool
| 341.flatten-nested-list-iterator | [python](./leetcode/341.flatten-nested-list-iterator.py) | - | O(N) | Medium/S++
| 394.decode-string | [cpp](./leetcode/394.decode-string.cpp), [python](./leetcode/394.decode-string.py) | O(N) | O(N) | Medium | | Perfect
| 654.maximum-binary-tree | [cpp](./leetcode/654.maximum-binary-tree.cpp), [python](./leetcode.654.maximum-binary-tree.py) | O(N) | O(N) | Hard/SSS || Perfect
| 739.daily-temperatures | [python](./leetcode/739.daily-temperatures.py) | O(N) | O(N) | Medium

## Sweep Line
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| $253.meeting-rooms-ii | [cpp](./leetcode/253.meeting-rooms-ii.cpp), [python](./leetcode/253.meeting-rooms-ii.py) | O(NlogN) | O(N) | Medium || Perfect

## Dynamic Programming
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 005.longest-palindromic-substring | [python](./leetcode/5.longest-palindromic-substring.py) | O(N^2) | O(1) | Medium
| 010.regular-expression-matching | [cpp](./leetcode/10.regular-expression-matching.cpp), [python](./leetcode/10.regular-expression-matching.py) | O(MN) | O(MN) | Hard/S++ | Sequence
| 044.wildcard-matching | [cpp](./leetcode/44.wildcard-matching.cpp), [python](./leetcode/44.wildcard-matching.py) | O(MN) | O(MN) | Hard | Sequence
| 053.maximum-subarray | [cpp](./leetcode/53.maximum-subarray.cpp), [python](./leetcode/53.maximum-subarray.py) | O(N) | O(1) | Easy | | Perfect
| 062.unique-paths | [cpp](./leetcode/62.unique-paths.cpp), [python](./leetcode/62.unique-paths.py) | O(MN) | O(MN) | Medium | Coordinates
| 063.unique-paths-ii | [cpp](./leetcode/63.unique-paths-ii.cpp), [python](./leetcode/63.unique-paths-ii.py) | O(MN) | O(MN) | Medium | Coordinates
| 064.minimum-path-sum | [cpp](./leetcode/64.minimum-path-sum.cpp), [python](./leetcode/64.minimum-path-sum.py) | O(MN) | O(MN) | Medium | Coordinates
| 070.climbing-stairs | [cpp](./leetcode/70.climbing-stairs.cpp), [python](./leetcode/70.climbing-stairs.py) | O(N) | O(1) | Easy | Coordinates | Perfect
| 072.edit-distance | [cpp](./leetcode/72.edit-distance.cpp), [python](./leetcode/72.edit-distance.py) | O(MN) | O(N) | Hard/S-- | Sequence || Perfect
| 087.scramble-string | [cpp](./leetcode/87.scramble-string.cpp), [python](./leetcode/87.scramble-string.py) | O(N^4) | O(N^3) | Hard/SSS | Range
| 091.decode-ways | [cpp](./leetcode/91.decode-ways.cpp), [python](./leetcode/91.decode-ways.py) | O(N) | O(N) | Medium/S++ | Partition
| 097.interleaving-string | [cpp](./leetcode/97.interleaving-string.cpp), [python](./leetcode/97.interleaving-string.py) | O(MN) | O(MN) | Hard/S-- | Sequence
| 115.distinct-subsequences | [cpp](./leetcode/115.distinct-subsequences.cpp), [python](./leetcode/115.distinct-subsequences.py) | O(MN) | O(MN) | Hard/S-- | Sequence
| 120.triangle | [cpp](./leetcode/120.triangle.cpp), [python](./leetcode/120.triangle.py) | O(N^2) | O(N) | Medium | Coordinates | Perfect
| 132.palindrome-partitioning-ii | [cpp](./leetcode/132.palindrome-partitioning-ii.cpp), [python](./leetcode/132.palindrome-partitioning-ii.py) | O(N^2) | O(N^2) | Hard | Partition
| 188.best-time-to-buy-and-sell-stock-iv | [cpp](./leetcode/188.best-time-to-buy-and-sell-stock-iv.cpp), [python](./leetcode/188.best-time-to-buy-and-sell-stock-iv.py) | O(N*K) | O(N * K) | Hard/SSS
| 198.house-robber | [cpp](./leetcode/198.house-robber.cpp), [python](./leetcode/198.house-robber.py) | O(N) | O(1) | Easy | Sequence | Perfect
| 121.best-time-to-buy-and-sell-stock | [cpp](./leetcode/121.best-time-to-buy-and-sell-stock.cpp), [python](./leetcode/121.best-time-to-buy-and-sell-stock.py) | O(N) | O(1) | Easy | Coordinates
| 123.best-time-to-buy-and-sell-stock-iii | [cpp](./leetcode/123.best-time-to-buy-and-sell-stock-iii.cpp), [python](./leetcode/123.best-time-to-buy-and-sell-stock-iii.py) | O(N) | O(N) | Hard/SSS 
| 213.house-robber-ii | [cpp](./leetcode/213.house-robber-ii.cpp), [python](./leetcode/213.house-robber-ii.py) | O(N) | O(1) | Medium/S-- | Sequence | Perfect
| 221.maximal-square | [cpp](./leetcode/221.maximal-square.cpp), [python](./leetcode/221.maximal-square.py) | O(MN) | O(N) | Medium/S-- | Coordinates | Perfect
| 256.paint-house | [cpp](./leetcode/256.paint-house.cpp), [python](./leetcode/256.paint-house.py) | O(N) | O(N) | Easy/S-- | Sequence
| 265.paint-house-ii | [cpp](./leetcode/265.paint-house-ii.cpp), [python](./leetcode/265.paint-house-ii.py) | O(MN) | O(MN) | Hard | Sequence
| 276.paint-fence | [cpp](./leetcode/276.paint-fence.cpp), [python](./leetcode/276.paint-fence.py) | O(N) | O(1) | Easy/SSS | | Perfect
| 279.perfect-squares | [cpp](./leetcode/279.perfect-squares.cpp), [python](./leetcode/279.perfect-squares.py) | O(N ^ 1.5) | O(N) | Medium | Partition
| 300.longest-increasing-subsequence | [cpp](./leetcode/300.longest-increasing-subsequence.cpp), [python](./leetcode/300.longest-increasing-subsequence.py) | O(NlogN) | O(N) | Medium/SSS | Binary-search / DP | Perfect
| 312.burst-balloons | [cpp](./leetcode/312.burst-balloons.cpp), [python](./leetcode/312.burst-balloons.py) | O(N^3) | O(N^2) | Hard/S-- | Range
| 322.coin-change | [cpp](./leetcode/322.coin-change.cpp), [python](./leetcode/322.coin-change.py) | O(L*N) | O(N) | Medium | N = amount, L = len(coins)
| 338.counting-bits | [cpp](./leetcode/338.counting-bits.cpp), [python](./leetcode/338.counting-bits.py) | O(N) | O(1) | Medium/S-- | Bit-manipulation
| 354.russian-doll-envelopes | [cpp](./leetcode/354.russian-doll-envelopes.cpp), [python](./leetcode/354.russian-doll-envelopes.py) | O(N*logN) | O(N) | Hard/S-- | Coordinates |
| $361.bomb-enemy | [cpp](./leetcode/361.bomb-enemy.cpp), [python](./leetcode/361.bomb-enemy.py) | O(MN) | O(MN) | Medium/S++ | Coordinates
| $368.largest-divisible-subset | [cpp](./leetcode/368.largest-divisible-subset.cpp), [python](./leetcode/368.largest-divisible-subset.py) | O(N^2) | O(N) | Medium/S++ | Coordinates | Awesome
| 377.combination-sum-iv | [cpp](./leetcode/377.combination-sum-iv.cpp), [python](./leetcode/377.combination-sum-iv.py) | O(M*N) | O(N) | Medium | Backpack
| 474.ones-and-zeroes | [cpp](./leetcode/474.ones-and-zeroes.cpp), [python](./leetcode/474.ones-and-zeroes.py) | O(LMN) | O(LMN) | Medium | Sequence |
| 516.longest-palindromic-subsequence | [cpp](./leetcode/516.longest-palindromic-subsequence.cpp), [python](./leetcode/516.longest-palindromic-subsequence.py) | O(N^2) | O(N^2) | Medium |
| 787.cheapest-flights-within-k-stops | [python](./leetcode/787.cheapest-flights-within-k-stops.py) | O(K * E) | O(N) | Hard/SSS |


## Red Black Tree

> Since python got no built-in AVL data-structure, these questions written in python may perform worse

| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| $683.k-empty-slots | [cpp](./leetcode/683.k-empty-slots.cpp), [python](./leetcode/683.k-empty-slots.py) | O(NLogN) | O(N) | Hard/SSS | Min Queue | Bad

## Greedy
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 45.jump-game-ii | [cpp](./leetcode/45.jump-game-ii.cpp), [python](./leetcode/45.jump-game-ii.py) | O(N) | O(1) | Hard |
| 055.jump-game | [cpp](./leetcode/55.jump-game.cpp), [python](./leetcode/55.jump-game.py) | O(N) | O(1) | Medium | dynamic-programming
| 122.best-time-to-buy-and-sell-stock-ii | [cpp](./leetcode/122.best-time-to-buy-and-sell-stock-ii.cpp), [python](./leetcode/122.best-time-to-buy-and-sell-stock-ii.py) | O(N) | O(1) | Easy
| $406.queue-reconstruction-by-height | [cpp](./leetcode/406.queue-reconstruction-by-height.cpp), [python](./leetcode/406.queue-reconstruction-by-height.py) | O(N^2) | O(1) | Medium/S++ | Sort Multiple Keys

## Union Find
| Problem    | Solution    | Time    | Space    |  Difficulty    | Note   | Grade   |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 261.graph-valid-tree | [cpp](./leetcode/261.graph-valid-tree.cpp), [python](./leetcode/261.graph-valid-tree.py) | O(E) | O(N) | Medium | BFS/DFS | Perfect
| 305.number-of-islands-ii | [cpp](./leetcode/305.number-of-islands-ii.cpp), [python](./leetcode/305.number-of-islands-ii.py) | O(N) | O(MN) | Hard | | N = len(positions)
| 721.accounts-merge | [cpp](./leetcode/721.accounts-merge.cpp), [python](./leetcode/721.accounts-merge.py) | O(MN) | O(MN) | Medium |
| 924.minimize-malware-spread | [python](./leetcode/924.minimize-malware-spread.py) | O(N^2) | O(N) | Hard | TODO | Bad
 
## Trie
| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 208.implement-trie-prefix-tree | [cpp](./leetcode/208.implement-trie-prefix-tree.cpp), [python](./leetcode/208.implement-trie-prefix-tree.py) | O(L) | O(N * L) | Medium | - | L = len(word), N = number of words |
| 211.add-and-search-word-data-structure-design | [cpp](./leetcode/211.add-and-search-word-data-structure-design.cpp), [python](./leetcode/211.add-and-search-word-data-structure-design.py) | add = O(L), find >=  O(L) | O(N * L) | Medium/S-- | DFS | L = len(word), N = count(words)
| 212.word-search-ii | [cpp](./leetcode/212.word-search-ii.cpp), [python](./leetcode/212.word-search-ii.py) | O(M * N * L * L) | MAX(O(MN), O(K * L)) | Hard | DFS | K = number of words, L = avg length of words
| 336.palindrome-pairs | [python](./leetcode/336.palindrome-pairs.py) | O(N * L^2) | O(N) | Hard/SSS
| 425.word-squares | [cpp](./leetcode/425.word-squares.cpp), [python](./leetcode/425.word-squares.py) | O(-) | O(NL) | Hard/SSS | DFS Pruning | | L = len(word), N = count(word)
| 677.map-sum-pairs | [cpp](./leetcode/677.map-sum-pairs.cpp), [python](./leetcode/677.map-sum-pairs.py) | O(L), O(KL) | O(N * L) | Medium | | L = length of input, k = number of items found|

## Other
| Problem    | Solution    |  Difficulty    | Tag    | Note    |
| -----------| ------------| ---------------| -------| --------|
| 175.combine-two-tables | [sql](./leetcode/175.combine-two-tables.sql) | Easy | SQL |

# Lintcode

> Below are Lintcode questions that worth trying 

| Problem    | Solution    | Time    | Space    |  Difficulty    | Tag    | Note    |
| -----------| ------------| --------| ---------| ---------------| -------| --------|
| 039.recover-rotated-sorted-array | [cpp](./lintcode/39.recover-rotated-sorted-array.cpp), [python](./lintcode/39.recover-rotated-sorted-array.py) | O(N) | O(1) | Easy/S++ | Binary-search, Two-pointers|
| 077.longest-common-subsequence | [cpp](./lintcode/77.longest-common-subsequence.cpp), [python](./lintcode/77.longest-common-subsequence.py) | O(M*N) | O(M*N) | Medium | dynamic-programming |
| 081.find-median-from-data-stream | [cpp](./lintcode/81.find-median-from-data-stream.cpp), [python](./lintcode/81.find-median-from-data-stream.py) | O(N * LogN) | O(N) | Hard | Heap |
| 089.k-sum | [cpp](./lintcode/89.k-sum.cpp), [python](./lintcode/89.k-sum.py) | O(NKT) | O(NKT) | Hard | dynamic-programming
| 091.minimum-adjustment-cost | [cpp](./lintcode/91.minimum-adjustment-cost.cpp), [python](./lintcode/91.minimum-adjustment-cost.py) | O((100^2)N) | O(100N) | Medium | dynamic-programming
| 092.backpack | [cpp](./lintcode/92.backpack.cpp), [python](./lintcode/92.backpack.py) | O(M*N) | O(M) | Medium | dynamic-programming
| 125.backpack-ii | [cpp](./lintcode/125.backpack-ii.cpp), [python](./lintcode/125.backpack-ii.py) | O(M*N) | O(M) | Medium/S++ | dynamic-programming
| 139.subarray-sum-closest | [cpp](./lintcode/139.subarray-sum-closest.cpp), [python](./lintcode/139.subarray-sum-closest.py) | O(NlogN) | O(N) | Medium | Subarray 
| 144.interleaving-positive-and-negative-numbers | [cpp](./lintcode/144.interleaving-positive-and-negative-numbers.cpp), [python](./lintcode/144.interleaving-positive-and-negative-numbers.py) | O(N) | O(1) | Medium | two-pointers
| 183.wood-cut | [cpp](./lintcode/183.wood-cut.cpp), [python](./lintcode/183.wood-cut.py) | O(N * LogN) | O(1) | Medium/S-- | binary-search
| 382.triangle-count | [cpp](./lintcode/382.triangle-count.cpp), [python](./lintcode/382.triangle-count.py) | O(N^2) | O(1) | Medium | two-pointers
| 390.find-peak-element-ii | [cpp](./lintcode/390.find-peak-element-ii.cpp), [python](./lintcode/390.find-peak-element-ii.py) | O(M + N) | O(1) | Hard/SSS | binary-search
| 391.number-of-airplanes-in-the-sky | [cpp](./lintcode/391.number-of-airplanes-in-the-sky.cpp), [python](./lintcode/391.number-of-airplanes-in-the-sky.py) | O(NlogN) | O(N) | Medium | sweep-line |
| 394.coins-in-a-line | [cpp](./lintcode/394.coins-in-a-line.cpp), [python](./lintcode/394.coins-in-a-line.py) | O(N) | O(N) | Medium | dynamic-programming |
| 396.coins-in-a-line-iii | [cpp](./lintcode/396.coins-in-a-line-iii.cpp), [python](./lintcode/396.coins-in-a-line-iii.py) | O(N^2) | O(N^2) | Hard/SSS | dynamic-programming |
| 437.copy-books | [cpp](./lintcode/437.copy-books.cpp), [python](./lintcode/437.copy-books.py) | O(K * N^2) / O(N * LogA) | O(NK) | Hard/SSS | dynamic-programming / binary-search |
| 440.backpack-iii |[cpp](./lintcode/440.backpack-iii.cpp), [python](./lintcode/440.backpack-iii.py) | O(MN) | O(M) | Hard/SSS | dynamic-programming
| 447.search-in-a-big-sorted-array | [cpp](./lintcode/447.search-in-a-big-sorted-array.cpp), [python](./lintcode/447.search-in-a-big-sorted-array.py) | O(LogK) | O(1) | binary-search | Medium/S++
| 465.kth-smallest-sum-in-two-sorted-arrays | [cpp](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.cpp), [python](./lintcode/465.kth-smallest-sum-in-two-sorted-arrays.py) | O((K + N) * LogN) | O(N) | Hard | heap | N = B.size()
| 543.kth-largest-in-n-arrays | [cpp](./lintcode/543.kth-largest-in-n-arrays.cpp), [python](./lintcode/543.kth-largest-in-n-arrays.py) | O(M * N * LogK) | O(K) | Easy | heap |
| 526.load-balancer | [cpp](./lintcode/526.load-balancer.cpp), [python](./lintcode/526.load-balancer.py) | O(1) | O(N) | Medium | Hash + Array
| 563.backpack-v | [cpp](./lintcode/563.backpack-v.cpp), [python](./lintcode/563.backpack-v.py) | O(M*N) | O(M) | Medium | dynamic-programming
| 586.sqrtx-ii | [cpp](./lintcode/586.sqrtx-ii.cpp), [python](./lintcode/586.sqrtx-ii.py) | O(logN) | O(N) | Medium | binary-search
| 589.connecting-graph | [cpp](./lintcode/589.connecting-graph.cpp), [python](./lintcode/589.connecting-graph.py) | O(1) | O(N) | Medium | union-find
| 590.connecting-graph-ii | [cpp](./lintcode/590.connecting-graph-ii.cpp), [python](./lintcode/590.connecting-graph-ii.py) | O(1) | O(N) | Medium | union-find
| 591.connecting-graph-iii | [cpp](./lintcode/591.connecting-graph-iii.cpp), [python](./lintcode/591.connecting-graph-iii.py) | O(1) | O(N) | Medium | union-find
| 598.zombie-in-matrix | [cpp](./lintcode/598.zombie-in-matrix.cpp), [python](./lintcode/598.zombie-in-matrix.py) | O(MN) | O(MN) | Medium | graph-traversal
| 611.knight-shortest-path | [cpp](./lintcode/611.knight-shortest-path.cpp), [python](./lintcode/611.knight-shortest-path.py) | O(MN) | O(MN) | Medium | graph-traversal
| 618.search-graph-nodes | [cpp](./lintcode/618.search-graph-nodes.cpp), [python](./lintcode/618.search-graph-nodes.py) | O(V + E) | O(V) | Medium | tree-traversal
| 629.minimum-spanning-tree | [cpp](./lintcode/629.minimum-spanning-tree.cpp), [python](./lintcode/629.minimum-spanning-tree.py) | O(N * logN) | O(N) | Hard | union-find | Prim, Kruskal
| 652.factorization | [cpp](./lintcode/652.factorization.cpp), [python](./lintcode/652.factorization.py) | O(N) | O(LogN) | Medium/S++ | N = input number