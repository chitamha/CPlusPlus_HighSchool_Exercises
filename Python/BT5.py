def scp(n):
    dem = 0
    for i in range(0, n+1):
        if n**0.5 == i:
            dem += 1
    if dem == 1:
        return True
    else:
        return False
n = int(input())
print(scp(n))