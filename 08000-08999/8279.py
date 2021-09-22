'''
문제 : 자연수 N(N <= 10^18)이 주어질 때, 1!부터 N!까지의 곱의 끝에 0이 몇 개 나오는지 구한다.

해결 방법 : N!의 끝에 붙는 0의 개수는 N / (5의 거듭제곱)을 모두 더한 값이다. 이를 이용해 1부터 N까지에 대한 합을 구하면 되는데,
5의 배수로 떨어지는 수까지 등차수열의 합 공식을 이용해서 0의 개수를 세 준 다음, 남는 수들은 직접 더하는 것을 반복하면 된다.

주요 알고리즘 : 수학, 정수론, 빅인티저

출처 : PA 2011 5-2번
'''

n = int(input())
m = 5
r = 0
while(n >= m):
    x = (n + 1) // m - 1
    r += m * (x * (x + 1) // 2)
    r += ((n + 1) % m) * (n // m)
    m *= 5
print(r)
