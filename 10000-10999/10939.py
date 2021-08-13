'''
문제 : 주어진 BASE32로 된 문자열을 디코딩한다.

해결 방법 : 파이썬 BASE64 모듈을 이용한다.

주요 알고리즘 : 문자열, 해싱
'''

import base64
b = base64.b32decode(input().encode())
b = str(b)[2:-1]
print(b)
