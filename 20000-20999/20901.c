#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 블록들이 있다. 이 블록들을 위 블록이 차지하면서 아래 블록이 차지하지 않는 밑면이 없도록 하려고 할 때,
그렇게 하는 방법이 있는지 확인하고 있다면 그러한 방법을 위 블록부터 차례로 출력한다.
각 블록들은 밑 면이 한 변의 길이가 A인 정사각형으로 된 직육면체 또는 반지름이 A인 원기둥이고, A는 1000 이하의 자연수이다.

해결 방법 : 먼저, 각 블록들을 밑면의 지름 또는 한 변의 길이 순으로 정렬한다. 그렇게 하면 같은 블록끼리 또는
직육면체 위에 원기둥이 있는 경우에 대해서는 해결된다. 그리고 이제 원기둥 위에 직육면체가 제대로 있는지 확인하면 된다.
이는 피타고라스 정리를 통해 대각선의 길이가 아래 원의 지름 길이 이상인 경우가 없음을 확인하면 된다.
그러한 경우가 있다면 불가능한 것이고 없다면 가능하므로 해당 순서로 출력하면 된다.

주요 알고리즘 : 기하학, 그리디 알고리즘, 정렬

출처 : GCPC 2020 A번
*/

int shapes[128][2];
char buff[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    int as = *((int*)a + 1);
    int bs = *((int*)b + 1);
    return as > bs ? 1 : as == bs ? 0 : -1;
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &shapes[i][0]);
        if (buff[1] == 'u') shapes[i][1] = 2;
        else {
            shapes[i][1] = 1;
            shapes[i][0] *= 2;
        }
    }
    qsort(shapes, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n - 1; i++) {
        if (shapes[i][1] == 2 && shapes[i + 1][1] == 1) {
            if (shapes[i][0] * shapes[i][0] * 2 > shapes[i + 1][0] * shapes[i + 1][0]) r = 0;
        }
    }
    if (!r) printf("impossible");
    else {
        for (int i = 0; i < n; i++) {
            if (shapes[i][1] == 1) printf("cylinder %d\n", shapes[i][0] / 2);
            else printf("cube %d\n", shapes[i][0]);
        }
    }
    return 0;
}