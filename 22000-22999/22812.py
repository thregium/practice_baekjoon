'''
문제 : H * W(H + W <= 70) 크기의 격자에 숫자 또는 알파벳 대문자가 적혀있다.
이때, 임의의 점에서 시작해 오른쪽 또는 아래로 한 칸씩 이동하는 동안 숫자만 거쳐오며 만들 수 있는
가장 큰 수를 구한다. 주어진 격자에 숫자는 최소한 1개 이상 있다.

해결 방법 : 격자의 각 칸에 대해 그 지점에서 끝내면 만들 수 있는 가장 큰 수를 저장한다.
그리고 맨 위에서 오른쪽 아래로 차례로 이동하며 위 또는 왼쪽이 숫자인 경우
그곳에 저장된 가장 큰 수에서 이번 칸으로 이동하며 만들 수 있는 가장 큰 값으로 해당 칸의 값을 갱신한다.
이를 반복하며 모든 칸에 저장된 값들 가운데 가장 큰 값을 구하면 된다.

주요 알고리즘 : DP, 빅인티저

출처 : JDC 2003 C번
'''

c = []
mem = []

def big(a, b):
	if(a > b):
		return a
	else:
		return b

while True:
	w, h = input().split(' ')
	w = int(w)
	h = int(h)
	r = 0
	if(w == 0):
		break
	for i in range(h):
		c.append(input())
	for i in range(h):
		mem.append([])
		for j in range(w):
			mem[i].append(0)
			if('0' <= c[i][j] and c[i][j] <= '9'):
				mem[i][j] = int(c[i][j])
			else:
				continue
			if(i > 0):
				mem[i][j] = big(mem[i][j], mem[i - 1][j] * 10 + int(c[i][j]))
			if(j > 0):
				mem[i][j] = big(mem[i][j], mem[i][j - 1] * 10 + int(c[i][j]))
			r = big(r, mem[i][j])
	c = []
	mem = []
	print(r)