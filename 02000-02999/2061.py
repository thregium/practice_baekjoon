'''
문제 : 두 수 L(L <= 10^100)과 K(K <= 10^6)가 주어질 때, L이 1이 아니며 K 미만인 수로 나누어 떨어지는지 구한다.

해결 방법 : 2부터 K - 1까지의 값을 확인하며 해당 수로 나누어 떨어지는 경우가 있는지 확인한다.

주요 알고리즘 : 브루트 포스, 빅인티저
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
