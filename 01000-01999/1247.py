'''
문제 : 수 N(N <= 10^6)개의 합의 부호를 구한다. 단, 주어지는 수들의 절댓값은 최대 2^64 - 1이다.

해결 방법 : 파이썬을 이용해 빅인티저를 해결한다. 단, 입력 속도 문제로 pypy를 사용해야 한다.

주요 알고리즘 : 빅인티저, 사칙연산
'''

for tt in range(3):
    n = int(input())
    s = 0
    x = 0
    for i in range(n):
        x = int(input())
        s += x
    if(s < 0):
        print("-")
    elif(s == 0):
        print("0")
    else:
        print("+")
