'''
문제 : N(N <= 10)개의 수와 +, -, *, /로 이루어진 수식을 계산한다.
연산자의 우선순위를 신경써야 한다. 각 수는 -10^100 이상 10^100 이하의 정수이다.

해결 방법 : 매번 +나 -가 나오기 전까지 수들을 저장하면서
임시 수를 곱셈, 나눗셈해간다. +나 -가 나오면 마지막 연산자에 따라
그 수를 더하거나 빼 준 다음 이를 반복하면 된다. 마지막에도 한번 더 해줘야 함에 주의한다.

주요 알고리즘 : 구현, 빅인티저
'''

n = int(input())
x = 0
z = int(input())
md = 0
for i in range(n - 1):
    c = input()
    y = int(input())
    if(c == '+'):
        if(md == 1):
            x -= z
        else:
            x += z
        md = 0
        z = y
    elif(c == '-'):
        if(md == 1):
            x -= z
        else:
            x += z
        md = 1
        z = y
    elif(c == '*'):
        z *= y
    else:
        z //= y

if(md == 1):
    x -= z
else:
    x += z
print(x)
