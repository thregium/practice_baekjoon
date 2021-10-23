'''
문제 : 800자리 이하의 자연수 N이 주어질 때, N의 양의 제곱근을 구한다.
N의 제곱근은 항상 정수이다.

해결 방법 : 매개 변수 탐색을 이용해 제곱근을 구한다.

주요 알고리즘 : 수학, 파라메트릭, 빅인티저
'''

n = int(input())
lo = 0
hi = n + 1
while(True):
    mid = (lo + hi) >> 1
    if(mid * mid > n):
        hi = mid - 1
    elif(mid * mid < n):
        lo = mid + 1
    else:
        break
print(mid)
