'''
문제 : 100000 자리 이하의 16진수가 주어질 때, 8진수로 바꾼 값을 출력한다.

해결 방법 : int()함수를 이용하여 10진수로 바꾼 후, oct()함수를 이용해 8진수로 바꾼다.
단, 문자열 슬라이싱을 통해 3번째 문자부터 출력해야 한다.

주요 알고리즘 : 수학, 빅인티저

출처 : USACO 2010M B2번
'''

n = int(input(), 16)
print(oct(n)[2:])
