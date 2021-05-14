'''
문제 : N(N <= 100)이 주어질 때, 하노이 탑을 옮기기 위해 필요한 최소 이동 횟수를 구한다.
그리고 N이 20 이하인 경우 이동 방법도 구해야 한다.

해결 방법 : 이동 횟수는 2 ^ n - 1과 같다. 이동 방법은 위의 모든 원판을 다른 원판에 옮긴 다음
해당 원판을 목표 위치로 옮기고 위에 있는 원판들을 다시 목표 위치로 옮기면 되고, 이는 재귀를 통해 표현 가능하다.

주요 알고리즘 : 재귀, 임의 정밀도
'''
def other(a, b):
    if(not (a == 1 or b == 1)):
        return 1
    elif(not (a == 2 or b == 2)):
        return 2
    else:
        return 3

def rec(lv, cur, targ):
    if(lv == 0):
        return
    rec(lv - 1, cur, other(cur, targ))
    print(cur, targ)
    rec(lv - 1, other(cur, targ), targ)

n = int(input())
print(2 ** n - 1)
if(n <= 20):
    rec(n, 1, 3)
