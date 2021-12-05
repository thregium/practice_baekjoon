'''
문제 : 1에서 시작해서 0을 10, 1을 01로 치환하는 것을 반복해서 나온
N(N <= 1000)번째 이진수의 연속한 0 그룹 수를 구한다.

해결 방법 : 직접 작은 수에 대해 해보면 2회 전의 답 * 2 + 1회 전의 답이 규칙임을 알 수 있다.
이를 점화식으로 하여 DP를 시행하면 된다.

주요 알고리즘 : DP, 빅인티저

출처 : SEERC 2005 G번
'''

mem = [0, 1]
for i in range(2, 1000):
    mem.append(mem[-1] + mem[-2] * 2)
while True:
    try:
        n = int(input())
    except:
        break
    print(mem[n])
