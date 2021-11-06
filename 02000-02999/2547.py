'''
문제 : N(N <= 100000)개의 음이 아닌 정수(<= 10^18)가 주어질 때,
이 정수의 합이 N으로 나누어 떨어지는지 여부를 확인한다.

해결 방법 : N개의 수의 합을 구하고 나누어 떨어지는지 여부를 확인하면 된다.
이때, 합이 64비트 정수에 들어가지 않으므로 빅인티저 또는 128비트 정수를 사용해야 한다.

주요 알고리즘 : 수학, 빅인티저
'''

t = int(input())
for tt in range(t):
    input()
    n = int(input())
    s = 0
    for i in range(n):
        s += int(input())
    if(s % n == 0):
        print("YES")
    else:
        print("NO")
