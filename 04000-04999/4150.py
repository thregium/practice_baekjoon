'''
문제 : N(N < 10000)번째 피보나치 수를 구한다.

해결 방법 : 첫 번째 수와 두 번째 수부터 다음 피보나치 수를 구해가며 풀면 된다.

주요 알고리즘 : 수학, DP

출처 : Waterloo 110619 C번
'''


n = int(input())
if(n <= 0):
    while(True):
        print("Error!")
if(n == 1 or n == 2):
    print(1)
else:
    l2 = 1
    l1 = 1
    for i in range(3, n + 1):
        t = l1 + l2
        l2 = l1
        l1 = t
    print(l1)
