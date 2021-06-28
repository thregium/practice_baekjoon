'''
문제 : 두 정수 A, B가 주어질 때, A / B를 상대오차 10^(-1000) 이내로 구한다.

해결 방법 : 임의 정밀도 라이브러리인 decimal을 통해 구한다.

주요 알고리즘 : 임의 정밀도, 수학
'''

from decimal import *

getcontext().prec = 1280
a, b = input().split(' ')
a = Decimal(a)
b = Decimal(b)
print(a / b)
