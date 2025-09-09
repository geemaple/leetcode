import sys
input = sys.stdin.readline
def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        for i in range(n):
            arr[i] = arr[i] + k * (arr[i] % (k + 1))

        print(*arr)


import sys
import math
input = sys.stdin.readline
def main1():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))

        for g in range(2, k + 2):
            if math.gcd(k, g) == 1:
                for i in range(n):
                    while (arr[i] % g != 0):
                        arr[i] += k

                print(*arr)
                break

if __name__ == "__main__":
    main1()