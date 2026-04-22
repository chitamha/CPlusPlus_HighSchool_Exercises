import sys

def findMinPair(m, arr):
    stMin, ndMin = 1000000000, 1000000000
    for i in range(m):
        if stMin > arr[i]:
            ndMin = stMin
            stMin = arr[i]
        elif stMin == arr[i]:
            ndMin = arr[i]
        elif ndMin > arr[i]:
            ndMin = arr[i]
    
    return (ndMin, stMin)

def solution(n, infoQuery):
    ans = 0
    minPairs = []
    for i in range(n):
        minPairs.append(findMinPair(len(infoQuery[i]), infoQuery[i]))

    minPairs.sort()
    ans = 0
    finalMin = minPairs[0][1]
    for i in range(1, n):
        ans += minPairs[i][0]
        finalMin = min(finalMin, minPairs[i][1])
    ans += finalMin

    sys.stdout.write(f"{ans}\n")

def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        infoQueries = []
        for _ in range(n):
            m = int(sys.stdin.readline())
            aux = list(map(int, sys.stdin.readline().split()))
            infoQueries.append(aux)

        solution(n, infoQueries)

if __name__ == "__main__":
    main()