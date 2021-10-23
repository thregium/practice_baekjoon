#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * M(N, M <= 1000) 크기의 배열에 '1'이 2개 있다. 두 '1' 사이 맨해튼 거리를 구한다.

해결 방법 : 두 '1'의 위치를 구한 다음, 두 위치의 X좌표 차이와 Y좌표 차이를 더하면 답이 된다.

주요 알고리즘 : 기하학, 수학

출처 : 전북대 2019 D번
*/

int main(void) {
    int n, m, t, c = 0, x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            if (t) {
                c++;
                if (c == 1) {
                    x1 = i;
                    y1 = j;
                }
                else if (c == 2) {
                    x2 = i;
                    y2 = j;
                }
                else return 1;
            }
        }
    }
    if (c != 2) return 2;
    printf("%d", abs(x1 - x2) + abs(y1 - y2));
    return 0;
}