#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 일렬로 인접한 칸의 지뢰 개수와 지뢰가 확실히 있는 칸들이 주어질 때,
지뢰의 최대 개수를 구한다. 불가능한 경우는 주어지지 않는다.

해결 방법 : 맨 왼쪽 칸의 지뢰 여부가 고정되면 나머지 칸의 지뢰 여부를 모두 알 수 있기 때문에,
맨 왼쪽 칸의 지뢰가 있는 경우와 없는 경우를 나누어 나머지 칸의 지뢰 여부를 결정한 다음,
답이 맞는 지 확인해보고 맞는 것 가운데 더 지뢰 개수가 많은 것을 선택하면 된다.

주요 알고리즘 : 그리디 알고리즘?, 브루트 포스

출처 : Seoul 2003I D번
*/

char hint[128], mine[128], tmine[128];

int main(void) {
    int t, n, res, valid, minecnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        scanf("%s%s", hint + 1, mine + 1);
        res = -1;
        tmine[1] = '.';
        for (int i = 2; i <= n; i++) {
            if ((hint[i - 1] - '0') - (tmine[i - 2] == '*') - (tmine[i - 1] == '*')) tmine[i] = '*';
            else tmine[i] = '.';
        }
        valid = 1, minecnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mine[i] == '*' && tmine[i] != '*') valid = 0;
            if ((hint[i] - '0') != (tmine[i - 1] == '*') + (tmine[i] == '*') + (tmine[i + 1] == '*')) {
                valid = 0;
            }
            if (tmine[i] == '*') minecnt++;
        }
        if (valid && minecnt > res) res = minecnt;

        tmine[1] = '*';
        for (int i = 2; i <= n; i++) {
            if ((hint[i - 1] - '0') - (tmine[i - 2] == '*') - (tmine[i - 1] == '*')) tmine[i] = '*';
            else tmine[i] = '.';
        }
        valid = 1, minecnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mine[i] == '*' && tmine[i] != '*') valid = 0;
            if ((hint[i] - '0') != (tmine[i - 1] == '*') + (tmine[i] == '*') + (tmine[i + 1] == '*')) {
                valid = 0;
            }
            if (tmine[i] == '*') minecnt++;
        }
        if (valid && minecnt > res) res = minecnt;

        if (res < 0) return 1;
        printf("%d\n", res);

        for (int i = 0; i < 128; i++) tmine[i] = '\0';
    }
    return 0;
}