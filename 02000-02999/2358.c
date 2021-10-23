#include <stdio.h>
#include <stdlib.h>

/*
문제 : 좌표평면 상에 N(N <= 100000)개의 점이 주어질 때, 점들을 이어 만들 수 있는 X축 또는 Y축에 평행한 직선의 개수를 구한다.
단, 같은 점끼리 연결한 것도 직선으로 생각한다. 또한, 중복된 직선은 세지 않는다.

해결 방법 : 각 X좌표 또는 Y좌표에 2개 이상의 점이 있다면 해당 좌표축으로 직선을 그을 수 있다.
X좌표와 Y좌표를 독립적으로 정렬한 다음, 각 수의 개수를 세서 2개 이상인 수의 개수를 더하면 답이 된다.

주요 알고리즘 : 기하학, 정렬
*/

int xpos[103000], ypos[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xpos[i], &ypos[i]);
    }
    qsort(xpos, n, sizeof(int), cmp1);
    qsort(ypos, n, sizeof(int), cmp1);
    c = 1;
    for (int i = 1; i < n; i++) {
        if (xpos[i] == xpos[i - 1]) c++;
        else {
            if (c >= 2) r++;
            c = 1;
        }
    }
    if (c >= 2) r++;
    c = 1;
    for (int i = 1; i < n; i++) {
        if (ypos[i] == ypos[i - 1]) c++;
        else {
            if (c >= 2) r++;
            c = 1;
        }
    }
    if (c >= 2) r++;
    printf("%d", r);
    return 0;
}