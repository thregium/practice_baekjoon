'''
문제 : 구간 [a, b](a <= b <= 10^100)에 포함되는 피보나치 수의 개수를 구한다.

해결 방법 : 10000번째 수까지 피보나치 수를 구하고, 이를 매번 전부 돌면서
[a, b] 범위에 있는 피보나치 수의 개수를 구한다.

주요 알고리즘 : DP, 브루트 포스, 빅인티저

출처 : Ulm 2000 F번
'''

mem = [1, 2]
for i in range(10000):
    mem.append(mem[-1] + mem[-2])
while(True):
    a, b = input().split()
    a = int(a)
    b = int(b)
    if b == 0:
        break
    r = 0
    for i in range(10000):
        if mem[i] >= a and mem[i] <= b:
            r += 1
    print(r)
