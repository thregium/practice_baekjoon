'''
문제 : 50자리 이하의 자연수 N을 세 자리 이상인 경우 마지막 자리를 지우고
마지막 자리를 지운 수에서 빼는 방식으로 11의 배수인지 구한다. 이를 T번 반복한다.

해결 방법 : 문제에 주어진대로 마지막 자리를 지우고 마지막 자리를 빼는 것을 반복한다.
이는 나눗셈과 나머지 연산으로 가능하다. 두 자리 이하가 되면 11로 나누어 떨어지는지 확인한다.
그러한 경우 나누어 떨어지는 것이고, 그렇지 않다면 나누어 떨어지지 않는 것이다.

주요 알고리즘 : 수학, 사칙연산, 빅인티저

출처 : CCC 1996 2번
'''
t = int(input())
for i in range(t):
    n = int(input())
    m = n;
    while(m > 99):
        print(m)
        m = m // 10 - m % 10
    print(m)
    if(m % 11 == 0):
        print("The number " + str(n) + " is divisible by 11.\n")
    else:
        print("The number " + str(n) + " is not divisible by 11.\n")
