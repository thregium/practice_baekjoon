#include <stdio.h>

/*
문제 : K(K <= 200)가 주어질 때, K와 가장 가까우면서 버튼을 오른쪽 아래로 내려가며 누를 수 있는 수를 구한다.

해결 방법 : 각 칸이 전 칸에서 누를 수 있는지 확인하고 각 자리를 구하면서 누르는 것이 가능한 것을 K와의 차이에
오름차순으로 탐색하며 구한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : CERC 2014 H번
*/

const int cango[10][10] =
{ {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
{0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1} };

int main(void) {
    int t, k, l, r;
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2014\\h\\all.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2014\\h\\all_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            l = -1, r = 1;
            for (int j = k + i; j; j /= 10) {
                if (l >= 0) {
                    if (!cango[j % 10][l]) r = 0;
                }
                l = j % 10;
            }
            if (r) {
                printf("%d\n", k + i);
                break;
            }
            l = -1, r = 1;
            for (int j = k - i; j; j /= 10) {
                if (l >= 0) {
                    if (!cango[j % 10][l]) r = 0;
                }
                l = j % 10;
            }
            if (r) {
                printf("%d\n", k - i);
                break;
            }
        }
    }
    return 0;
}