'''
문제 : 1 / 2^N(N <= 250)을 정확히 계산한다.

해결 방법 : Decimal 모듈을 이용한다.

주요 알고리즘 : 임의 정밀도
'''

from decimal import *
getcontext().prec = MAX_PREC

n = Decimal(input())
print('{0:f}'.format(1 / 2 ** n))
