'''
문제 : 격자판의 맨 왼쪽 위에서 오른쪽 아래까지 갈 때, 격자판에 쓰인 칸씩
오른쪽 또는 아래쪽으로 간다면 오른쪽 아래에 가는 방법의 가짓수를 구한다.
단, 0인 칸에 가는 경우 더 이동할 수 없다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결한다.
이때 0인 경우에는 그곳에서 멈춰야 하고 첫 칸에서는 1을 넣어둬야 한다.

주요 알고리즘 : DP, 빅인티저

출처 : BtOI 2006 6번
'''

a = []
mem = []

n = int(input())
x = 0
for i in range(n):
    a.append(input().split(' '))
    mem.append([])
    for j in range(n):
        mem[i].append(0)

for i in range(n):
    for j in range(n):
        if(i == 0 and j == 0):
            mem[i][j] = 1
        x = int(a[i][j])
        if(x == 0):
            continue
        if(i + x < n):
            mem[i + x][j] += mem[i][j]
        if(j + x < n):
            mem[i][j + x] += mem[i][j]
print(mem[n - 1][n - 1])
