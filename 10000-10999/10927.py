'''
문제 : 주어진 문자열의 MD5 해시값을 구한다.

해결 방법 : hashlib 라이브러리를 이용한다.

주요 알고리즘 : 문자열, 해싱
'''

import hashlib
m = hashlib.md5()
m.update(input().encode())
print(m.hexdigest())
