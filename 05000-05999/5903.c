#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10)개의 직사각형이 주어진다. 각 직사각형의 좌표 범위가 -10000 이상 10000 이하일 때,
한 개 이상의 직사각형으로 덮인 부분의 넓이를 구한다.

해결 방법 : 직사각형의 세로선들을 앞부분과 뒷부분으로 분리해서 X좌표 순으로 정렬한다.
그 다음, 직사각형의 Y좌표마다 직사각형이 시작한 곳과 겹친 직사각형의 수들을 체크해둔다.
세로선이 시작하는 곳이면 현재 직사각형이 없는 곳에 대해 현재 X좌표를 시작한 곳에 저장한 후 직사각형의 수들을 1씩 늘린다.
끝나는 곳에서는 현재 직사각형이 1개만 남았다면 직사각형을 0개로 만들며 직사각형이 시작한 곳의 위치와 현재 X좌표를 비교해
그 만큼의 값을 해당하는 Y좌표마다 결괏값에 더한다. 그 다음 직사각형의 수를 1씩 줄인다.
이를 모든 세로선에 대해 반복하면 나온 결괏값이 답이 된다.

주요 알고리즘 : 정렬, 스위핑

출처 : USACO 2012F B2번
*/

int line[64][4], cnt[20480], last[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x1, y1, x2, y2, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        line[i * 2][0] = x1;
        line[i * 2][2] = y2;
        line[i * 2][3] = y1;
        line[i * 2 + 1][0] = x2;
        line[i * 2 + 1][1] = 1;
        line[i * 2 + 1][2] = y2;
        line[i * 2 + 1][3] = y1;
    }
    qsort(line, n * 2, sizeof(int) * 4, cmp1);

    for (int i = 0; i < n * 2; i++) {
        if (line[i][1] == 0) {
            for (int j = line[i][2]; j < line[i][3]; j++) {
                if (cnt[j + 10240] == 0) last[j + 10240] = line[i][0];
                cnt[j + 10240]++;
            }
        }
        else {
            for (int j = line[i][2]; j < line[i][3]; j++) {
                if (cnt[j + 10240] == 1) r += (line[i][0] - last[j + 10240]);
                else if (cnt[j + 10240] == 0) return 1;
                cnt[j + 10240]--;
            }
        }
    }
    printf("%d", r);
    return 0;
}