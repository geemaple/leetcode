import sys
input = sys.stdin.readline

def main():
    t = int(input())
    for _ in range(t):
        n, a, b = map(int, input().split())
        if a > b:
            if (a % 2 == b % 2 and n % 2 == a % 2):
                print("YES")
            else:
                print("NO")
        else:
            if (n % 2 == b % 2):
                print("YES")
            else:
                print("NO")
            
if __name__ == "__main__":
    main()