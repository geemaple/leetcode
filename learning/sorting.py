import random

###############
# in palce sort
###############

# bubble sort
def bubble_sort(arrs):
    for i in range(len(arrs)):
        for j in reversed(range(i, len(arrs))): # inverse range list using [::-1]
            if arrs[j] < arrs[j - 1]:
                arrs[j], arrs[j - 1] = arrs[j - 1], arrs[j]


# insertion sort (a fast in place sorting algorithm for small input sizes)
def insertion_sort(arrs):
    for i in range(1, len(arrs)): #from 2nd to the end
        target = arrs[i]

        # right shift until appropriate position found
        j = i
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

# heap sort
def heap_sort(arrs):
    def __max_heepify(arrs, size, i):
        l = 2 * i + 1
        r = 2 * i + 2
        largest = i

        # find the largest in the little "triangle", and swap them.
        # since swap may break the heap in child heap, so do it reacursively
        if l < size and arrs[l] > arrs[largest]:
            largest = l
        if r < size and arrs[r] > arrs[largest]:
            largest = r

        if largest != i:
            arrs[i], arrs[largest] = arrs[largest], arrs[i]
            __max_heepify(arrs, size, largest)

    # building a heap using array
    # For 0 index based heap parent = i, left = 2i + 1, right = 2i + 2
    # For 1 index based heap parent = i, left = 2i, right = 2i + 1
    def __build_heap(arrs):
        for i in reversed(range(0, len(arrs)//2)):
            __max_heepify(arrs, len(arrs),  i)

    __build_heap(arrs)
    for i in reversed(range(1, len(arrs))):
        arrs[i], arrs[0] = arrs[0], arrs[i]
        __max_heepify(arrs, i, 0)

# quick sort

##################################
#              k
# [1,2,3,4,5,  6,7,8,9,10]
# k.left <= last  k.right > last

def quick_sort(arrs):
    def __partiion(arrs, start, end):
        last = arrs[end - 1]
        k = start

        for i in range(k, end - 1):
            if arrs[i] <= last:
                arrs[k], arrs[i] = arrs[i], arrs[k]
                k += 1
        arrs[k], arrs[end - 1] = arrs[end - 1], arrs[k]

        return k

    def __quick_sort(arrs, start, end):

        if end - start <= 1:
            return

        k = __partiion(arrs, start, end)
        __quick_sort(arrs, start, k)
        __quick_sort(arrs, k + 1, end)

    __quick_sort(arrs, 0, len(arrs))

######################
# extra memory needed
######################

# merge sort
def merge_sort(arrs):

    def __merge(arrs, start, mid, end):
        L = arrs[start: mid] # left sub problem, this is a copy
        R = arrs[mid: end] # right sub problem, this is a copy
        # merge two already sorted into one
        i = 0
        j = 0
        for k in range(start, end):
            if i >= len(L) or (j < len(R) and L[i] > R[j]):
                arrs[k] = R[j]
                j = j + 1
            else:
                arrs[k] = L[i]
                i = i + 1

    def __divied(arrs, start, end):
        if end - start <= 1:
            return

        mid = start + (end - start) // 2
        __divied(arrs, start, mid) # divide
        __divied(arrs, mid, end) # divide
        __merge(arrs, start, mid, end) # combine

    __divied(arrs, 0, len(arrs))
