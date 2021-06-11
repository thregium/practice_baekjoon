'''
문제 : 두 정수 A / B(-10^10000 <= A, B <= 10^10000)의 몫과 나머지를 출력한다.

해결 방법 : 미리 //와 %의 결과를 구한 다음 a와 b의 부호에 따라 보정을 해준다.
나머지가 음수인 경우에 대한 처리와 음수로 나누는 경우에 대한 처리이다.

주요 알고리즘 : 수학, 사칙연산, 임의정밀도, 케이스 워크
'''

a, b = input().split(' ')
a = int(a)
b = int(b)

div = a // b
mod = a % b
if(mod < 0):
    if(b < 0):
        mod -= b
    else:
        mod += b

if(mod > 0 and b < 0):
    print(div + 1)
else:
    print(div)

print(mod)
