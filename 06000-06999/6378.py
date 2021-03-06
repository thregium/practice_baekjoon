'''
문제 : 1000자리 이하의 자연수가 주어질 때, 이 수의 각 자릿수를 더하는 것을 반복해 나온 한 자리 수를 구한다.

해결 방법 : 각 자릿수를 계속 더하는 것을 반복해 나온 수는 처음 나온 수를 9로 나눈 나머지와 같다.
단, 0인 경우에는 값이 9가 된다.

주요 알고리즘 : 수학

출처 : GNY 2000 C번
'''

while True:
	n = int(input())
	if(n == 0):
		break
	print((n + 8) % 9 + 1)