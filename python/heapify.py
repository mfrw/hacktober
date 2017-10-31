global l
def max_heapify(M, i):
    global l
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < l and M[left] > M[largest]:
        largest = left
    if right < l and M[right] > M[largest]:
        largest = right
    if largest != i:
        M[i], M[largest] = M[largest], M[i]
        max_heapify(M, largest)
    if left < l and right < l and M[left] > M[right]:
        M[left], M[right]= M[right], M[left]
        max_heapify(M, left)


def build_max_heap(M):
    global leng
    for i in range(l // 2, -1, -1):
        max_heapify(M, i)


def pop(M, n):
    global l
    for i in range(l):
         if n == M[i]:
          x = M[i];
          M[i] = M[l-1]
          M[l-1]= x
          l = l - 1
          build_max_heap(M)



M= [100,70,90,40,101]
l = len(M)
build_max_heap(M)
print(M)
n = int(input("Enter number to be deleted  "))
pop(M,n)
print(M)
M.pop(l)
print(M)
