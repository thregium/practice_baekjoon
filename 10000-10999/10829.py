'''
문제 : 자연수 N(N <= 10^15)을 이진수로 바꿔 출력한다.

해결 방법 : 파이썬의 서식을 이용한다.

주요 알고리즘 : 구현
'''
n = int(input())
print("{:b}".format(n))
