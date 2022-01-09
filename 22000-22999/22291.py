'''
문제 : 100000개 이하의 길이인 배열에서 소수번째 수 가운데 제곱수인 것의 합을 구한다. 배열은 0번째부터 시작한다. 배열의 각 수는 절댓값이 10^6 이하인 정수이다.

해결 방법 : 배열의 매 원소마다 소수번째인지 여부를 확인한다. 이는 x를 2부터 sqrt(x)까지 나눠본 다음 전부 나누어 떨어지지 않고 1이나 0이 아니라면 소수임을 판단 가능하다.
그리고 다시 제곱수 여부를 확인한다. 이는 0.5 제곱을 한 다음, 곱하여 원래 수가 나오는지로 확인 가능하다.
둘 다인 경우를 전부 더하면 답이 된다.

주요 알고리즘 : 수학, 소수 판정

출처 : 한과영 2021S 2번
'''

def isPrime(n):
    i = 2
    if(n <= 1):
    	return False
    while(i * i <= n):
    	if(n % i == 0):
    		return False
    	i += 1
    return True

def isSquare(n):
    if(n < 0):
        return False
    a = int(n ** 0.5)
    if(a * a == n or (a + 1) * (a + 1) == n):
    	return True
    else:
    	return False

def P2(A):
    n = len(A)
    r = 0
    for i in range(n):
    	if(isPrime(i) and isSquare(A[i])):
    		r += A[i]
    return r
