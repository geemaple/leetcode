import random

# bubble sort
def bubble_sort(arrs):
    for i in range(len(arrs)):
        for j in range(i, len(arrs))[::-1]: # inverse range list using [::-1]
            if arrs[j] < arrs[j - 1]:
                arrs[j], arrs[j - 1] = arrs[j - 1], arrs[j]

# incremental approach
# insertion sort
def insertion_sort(arrs):
    for i in range(1, len(arrs)): #from 2nd to the end
        target = arrs[i]

        # right shift until appropriate position found
        j = i;
        while j > 0 and target < arrs[j - 1]:
            arrs[j] = arrs[j - 1]
            j -= 1

        arrs[j] = target

# selection sort
def selection_sort(arrs):
    for i in range(0, len(arrs)):
        min_index = i

        # find the smallest element from (i+1)th to the last
        for j in range(i + 1, len(arrs)):
            if arrs[j] < arrs[min_index]:
                min_index = j

        if min_index != i:
            arrs[i], arrs[min_index] = arrs[min_index], arrs[i]

# divide and conquer approach
# merge sort
def merge_sort(arrs):

    def __merge(arrs, start, mid, end):
        L = arrs[start: mid] # slicing copy value
        R = arrs[mid: end] # slicing copy value

        i = 0
        j = 0
        for k in range(start, end):
            if i >= len(L) or (j < len(R) and L[i] > R[j]):
                arrs[k] = R[j]
                j = j + 1
            else:
                arrs[k] = L[i]
                i = i + 1

    def __merge_sort(arrs, p, r):
        if r - p > 1:
            mid = (p + r) / 2;
            __merge_sort(arrs, p, mid)
            __merge_sort(arrs, mid, r)
            __merge(arrs, p, mid, r)


    __merge_sort(arrs, 0, len(arrs))
