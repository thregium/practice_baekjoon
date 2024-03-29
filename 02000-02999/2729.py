'''
문제 : 두 이진수 A, B(A, B <= 2^80)를 입력받은 후 A + B를 이진수로 출력한다.

해결 방법 : 파이썬의 서식을 이용한다.

주요 알고리즘 : 수학, 빅인티저, 사칙연산
'''

t = int(input())
for tt in range(t):
    a, b = input().split(' ')
    a = int(a, 2)
    b = int(b, 2)
    print(format(a + b, 'b'))
