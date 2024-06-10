n = int(input("Nhap so "))
A = []
B = []
print("Moi ban nhap so")
for i in range(n):
    so = int(input())
    A.append(so)
for i in range(len(A)):
    if A[i] > 0:
        B.append(A[i])
for i in B:
    print(i)