'''
문제 : A_0은 960002411612632915이고, A_i는 42^x mod (10^18 + 31) = A_(i - 1)을 만족하는 가장 작은 x라고 할 때,
A_N(N <= 10^6)의 값을 구한다.

해결 방법 : 예제에 있던 N = 100만일 때의 값에서 역산해 들어가면 된다.

주요 알고리즘 : 수학, 분할 거듭제곱, 빅인티저

출처 : Petro 2021W5 M번
'''

a = 300
md = 1000000000000000031
mx = []

def mul(x, y):
    r = 1
    for i in range(64):
        if((y >> i) & 1):
            r = (r * mx[i]) % md
    return r

n = int(input())
x = 42
for i in range(64):
    mx.append(x)
    x = (x ** 2) % md
for i in range(1000000 - n):
    a = mul(42, a)
print(a)
