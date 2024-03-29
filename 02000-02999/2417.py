'''
문제 : N(N < 2^63)의 정수 제곱근(q^2 >= n인 가장 작은 음이 아닌 정수 q)을 구한다.

해결 방법 : 매개 변수 탐색을 이용한다. 중간 값을 기준으로 더 크면 아래쪽 구간(중간값 포함),
더 작으면 위쪽 구간(중간값 미포함)을 남기는 방식이다.

주요 알고리즘 : 수학, 파라메트릭

출처 : BtOI 2006 0번
'''

n = int(input())
ql = 0
qh = n
while(ql < qh):
    qm = (ql + qh) >> 1
    if(qm * qm >= n):
        qh = qm
    else:
        ql = qm + 1
print(ql)
