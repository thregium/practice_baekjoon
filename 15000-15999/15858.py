'''
문제 : 세 자연수 A, B, C(A, B, C <= 10^9)가 주어질 때, A * B / C의 값을
절대오차 10^-6 이내로 출력한다.

해결 방법 : 일반적인 실수형 연산으로는 최고 정확도를 얻기 어려우므로
임의 정밀도 연산인 decimal 모듈을 통해 해결한다.

주요 알고리즘 : 수학, 사칙연산, 임의 정밀도

출처 : BtOI 2018 PA번
'''

from decimal import *

getcontext().prec = 41
a, b, c = input().split(' ')
a = Decimal(a)
b = Decimal(b)
c = Decimal(c)
print('{0:f}'.format(a * b / c))
