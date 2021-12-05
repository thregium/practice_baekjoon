'''
문제 : N(N <= 15)개의 자연수(< 10^51)가 주어진다. 각 자연수들을 무작위로 이어붙인 순열이 K(K <= 100)로 나누어 떨어질 확률을
기약분수 형태로 출력한다. 0인 경우 0/1로 출력하고, 1인 경우 1/1로 출력한다.

해결 방법 : 각 자연수들을 K로 나눈 나머지와 10의 해당 수의 길이의 제곱에서 K를 나눈 나머지를 구한다.
그 후 선택한 자연수들의 목록을 비트마스킹한 후 K로 나눈 나머지를 기준으로 개수를 비트마스킹DP한다.
매번 자연수들을 이어붙여가며 개수를 세 나가면 된다.

개수를 전부 센 이후에는 모든 비트가 1인 값의 나머지가 0인 값 / N!을 유클리드 호제법을 통해 기약분수 형태로 바꾼 후 출력하면 된다.

주요 알고리즘 : DP, 비트DP, 수학, 정수론, 빅인티저 

출처 : SRM 440 D2C
'''

def gcd(x, y):
    if(x == 0):
        return y
    if(y == 0):
        return x
    if x > y:
        return gcd(x % y, y)
    else:
        return gcd(x, y % x)

md = []
ln = []
n = int(input())
for i in range(n):
    x = input()
    ln.append(len(x))
    md.append(int(x))
k = int(input())
mem = [[0] * k for i in range(1 << n)]

for i in range(n):
    md[i] %= k
    ln[i] = (10 ** ln[i]) % k
mem[0][0] = 1
for i in range((1 << n) - 1):
    for j in range(k):
        for l in range(n):
            if((i & (1 << l)) > 0):
                continue
            mem[i | (1 << l)][(j * ln[l] + md[l]) % k] += mem[i][j]
sm = 0
res = 0
for i in range(k):
    sm += mem[(1 << n) - 1][i]
res = mem[(1 << n) - 1][0]
if(res == 0):
    print("0/1")
elif(res == sm):
    print("1/1")
else:
    g = gcd(sm, res)
    print(str(res // g) + '/' + str(sm // g))
