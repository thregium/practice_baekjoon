#include <stdio.h>

/*
문제 : 두 명의 사람이 N개의 라운드를 진행하며 i번째 라운드에 이긴 사람이 i점을 얻는 게임을 했다.
이때, 두 사람의 최종 점수가 X점과 Y(X, Y <= 10^12)점이 될 수 있는 지 구하고,
가능한 경우 X점을 얻은 사람이 이겨야 하는 최소 라운드 수를 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : 두 사람의 점수 합이 1부터 N까지 차례로 합한 값이 될 수 없다면 -1을 출력한다.
그 외의 경우 1부터 N까지의 모든 값들이 있기 때문에 큰 수부터 가능한만큼 더해나가더라도 sum(1, N)
이하의 모든 자연수를 만들 수 있다. 따라서, 큰 수부터 차례로 더해나간 다음 더해나간 수의
개수를 구하면 답이 된다.

주요 알고리즘 : 수학, 그리디 알고리즘

출처 : SRM 639 ?번
*/

int main(void) {
    long long x, y, r, s = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = 1;; i++) {
        s += i;
        if (s > x + y) {
            printf("-1");
            break;
        }
        else if (s == x + y) {
            r = 0, s = 0;
            for (int j = i; j > 0; j--) {
                if (s + j > x) continue;
                else {
                    s += j;
                    r++;
                }
            }
            printf("%d", r);
            break;
        }
    }
    return 0;
}