'''
문제 : nCk의 값을 구한다. 답과 n, k는 2^31보다 작다. 

해결 방법 : 곱을 이용해 계산하되, k가 매우 클 수 있으므로, n - k가 더 작다면
n - k로 적용해준다. 그 외에는 답이 커지므로 정답이 2^31 미만인 경우에서는 생각하지 않아도 된다.

주요 알고리즘 : 수학, 조합론

출처 : Ulm 1997 B번
'''

while(True):
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    if a == 0 and b == 0:
        break
    if b > a - b:
        b = a - b
    r = 1
    for i in range(b):
        r *= (a - i)
    for i in range(b):
        r //= (i + 1)
    print(r)
