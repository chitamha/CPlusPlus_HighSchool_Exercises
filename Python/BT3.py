n = int(input("Moi ban nhap n: "))
A = [0, 1]
if n == 0:
    print(A[0])
elif n == 1:
    print(A[0])
    print(A[1])
elif n >= 2:
    for i in range(2, n+1):
        a = int(A[i-1]) + int(A[i-2])
        A.append(str(a))
    for ch in A:
        print(ch)
else:
    print("Ban nhap loi")