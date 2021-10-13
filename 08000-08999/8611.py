'''
문제 : 10^1000 이하의 10진법으로 표시된 자연수가 주어질 때, 2진법부터 10진법까지 가운데
해당 진법으로 나타냈을 때 팰린드롬인 것이 있는지 찾고 있다면 그러한 것을 전부 구한다.
없다면 "NIE"를 출력한다.

해결 방법 : 2진법부터 10진법까지의 각 진법으로 자연수를 표시해보고, 뒤집어 표시한 것과 비교한다.
만약 둘이 같은 경우에는 해당하는 자연수와 진법을 표시한다.
같은 경우가 나오지 않으면 "NIE"를 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : JPOI 2009 20번
'''

n = int(input())
chk = 0
for i in range(2, 11):
    bi = []
    x = n
    while(x > 0):
        bi.append(x % i)
        x //= i
    if(bi[::] == bi[::-1]):
        res = ""
        for j in bi[::-1]:
            res += (str(j))
        print(str(i) + " " + res)
        chk = 1

if(chk == 0):
    print("NIE")
