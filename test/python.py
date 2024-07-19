def binary_search(dp, val):
    left, right = 0, len(dp) - 1
    while left <= right:
        mid = (left + right) // 2
        if dp[mid][1] < val:
            left = mid + 1
        else:
            right = mid - 1
    return left

def max_length_of_pair_chain(pairs):
    # Step 1: Sort the pairs by their first element
    pairs.sort(key=lambda pair: pair[0])

    # Step 2: Initialize the dp array
    dp = []

    # Step 3: Iterate over the pairs
    for pair in pairs:
        # Use binary search to find the correct position
        i = binary_search(dp, pair[0])
        # If i is equal to the length of dp, append the pair
        if i == len(dp):
            dp.append(pair)
        else:
            # Update the dp array if the current pair has a smaller second element
            if dp[i][1] > pair[1]:
                dp[i] = pair

    # Step 5: The length of the dp array is the length of the longest chain
    return len(dp)

# Test cases
print(max_length_of_pair_chain([[1,2], [2,3], [3,4]]))  # Output: 2
print(max_length_of_pair_chain([[1,2], [7,8], [4,5]]))  # Output: 3