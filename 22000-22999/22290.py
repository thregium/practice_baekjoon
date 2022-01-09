'''
문제 : 삼각형의 세 점의 위치가 주어질 때, 삼각형의 둘레에 있는 정수 점의 개수를 구한다. 각 점은 일직선상에 있지 않으며, 절댓값은 2^1024 이하다.

해결 방법 : 삼각형의 각 변마다 변화량을 구하고, 그 값의 X와 Y축 길이의 최대공약수를 구하면 그 변의 정수 점의 개수(꼭짓점 1개 포함)가 된다.
이때, 둘 중 하나가 0인 경우에는 나머지 하나의 값과 같다. 이 값을 각 변마다 더하면 답이 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 기하학

출처 : 한과영 2021S 1번
'''

def abs(a):
	if(a < 0):
		return -a
	else:
		return a

def gcd(a, b):
	if(a == 0):
		return b
	elif(b == 0):
		return a
	elif(a > b):
		return gcd(a % b, b)
	else:
		return gcd(a, b % a)

def P1(x1,y1,x2,y2,x3,y3):
    return gcd(abs(x2 - x1), abs(y2 - y1)) + gcd(abs(x3 - x2), abs(y3 - y2)) + gcd(abs(x1 - x3), abs(y1 - y3))