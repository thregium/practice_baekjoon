#include <stdio.h>
#include <stdlib.h>

/*
문제 : 좌표평면상에 N(N <= 50000)개의 점이 주어질 때, 모든 점을 최대 3개의 수평선 또는 수직선으로 덮을 수 있는지 구한다.
수평선과 수직선을 섞어서 써도 되며, 좌표의 범위는 +-10^9이다.

해결 방법 : 각 점들을 X축 방향으로 정렬한 후, 각 X축 좌표마다 해당하는 점의 개수를 배열에 따로 저장한다.
이를 다시 Y축 방향에도 똑같이 한다. 그러면 나오는 두 배열을 큰 순서대로 정렬한다.
만약 모든 점을 3개의 수평선 또는 수직선으로 덮을 수 있다면 두 배열 중 하나의 크기가 3 이하일 것이므로 간단히 해결 가능하다.
2개의 수평선과 1개의 수직선 또는 그 반대인 경우는 X축 배열에서 2위가 2 이하, Y축 배열에서 3위가 1 이하일 것이다.
이를 X와 Y를 바꾸어서 해보면 이 경우도 해결 가능하다. 위 조건 가운데 하나라도 만족한다면 덮을 수 있는 것이고,
모두 만족하지 않는다면 덮을 수 없는 것이다.

주요 알고리즘 : 기하학, 정렬

출처 : USACO 2012O B2번
*/

int pos[51200][2], hor[51200], ver[51200];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2012_04\\3lines\\20.in", "r", stdin);
    int n, c = 1, hp = 0, vp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }

    qsort(pos, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        if (pos[i][0] != pos[i - 1][0]) {
            hor[hp++] = c;
            c = 1;
        }
        else c++;
    }
    hor[hp++] = c;

    qsort(pos, n, sizeof(int) * 2, cmp2);
    c = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i][1] != pos[i - 1][1]) {
            ver[vp++] = c;
            c = 1;
        }
        else c++;
    }
    ver[vp++] = c;

    qsort(hor, hp, sizeof(int), cmp1);
    qsort(ver, vp, sizeof(int), cmp1);

    if (vp <= 3 || hp <= 3 || (ver[1] <= 2 && hor[2] <= 1) || (hor[1] <= 2 && ver[2] <= 1)) printf("1");
    else printf("0");
    return 0;
}