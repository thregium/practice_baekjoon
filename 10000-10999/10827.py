'''
문제 : a^b를 정확히 구한다. a는 100 이하의 소숫점 9자리 이하 양수이고
b는 100 이하의 자연수이다.

해결 방법 : 파이썬 Decimal 모듈과 포매팅을 이용한다.

주요 알고리즘 : 수학, 구현, 임의정밀도
'''

from decimal import *
getcontext().prec = MAX_PREC

a, b = input().split(' ')
a = Decimal(a)
b = Decimal(b)
print('{0:f}'.format(a ** b))
