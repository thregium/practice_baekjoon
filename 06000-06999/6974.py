'''
문제 : N(N <= 20)개의 80자리 이하 자연수 쌍이 주어질 때,
앞의 수를 뒤의 수로 나눈 몫과 나머지를 출력한다.

해결 방법 : 반복문을 사용하며 몫과 나머지를 구하면 된다.

주요 알고리즘 : 수학, 사칙연산, 빅인티저

출처 : CCC 1997 5번
'''

n = int(input())
for i in range(n):
    a = int(input())
    b = int(input())
    print(a // b)
    print(a % b)
    print()
