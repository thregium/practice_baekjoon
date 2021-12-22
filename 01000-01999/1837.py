'''
문제 : P(P <= 10^100)와 K(K <= 10^6)가 주어질 때, P가 K보다 작은 소수로
나누어 떨어지는지 확인하고 나누어 떨어진다면 그 수 중 가장 작은 수를 출력한다.

해결 방법 : 2부터 K - 1까지 나누어 보며 나누어 떨어지는 경우가 있다면
그 수를 출력하고, 끝까지 나오지 않는다면 나누어 떨어지지 않는 것이다.

주요 알고리즘 : 브루트 포스, 빅인티저

출처 : NCPC 2005 D번
'''


k, l = input().split(' ')
k = int(k)
l = int(l)
r = 0
for i in range(l - 2):
    if k % (i + 2) == 0:
        print("BAD " + str(i + 2))
        r = 1
        break
if r == 0:
    print("GOOD")