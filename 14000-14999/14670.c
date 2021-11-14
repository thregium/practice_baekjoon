#include <stdio.h>

/*
문제 : N(N <= 100)개의 증상과 이에 대한 약이 주어질 때, R(R <= 100)개의 증상 목록에 대해 약이 없는 것이 있는지 구하고,
그 외에는 각 증상에 대한 약들을 출력한다.

해결 방법 : 각 증상에 대한 약의 효능을 구한 다음, 증상 목록을 보면서 약들을 확인하며 출력하면 된다.

주요 알고리즘 : 구현

출처 : 숭실대 2017 A번
*/

int medic[128], symp[128];

int main(void) {
    int n, a, b, r;
    scanf("%d", &n);
    for (int i = 0; i <= 100; i++) {
        medic[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        medic[a] = b;
    }
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        scanf("%d", &a);
        b = 0;
        for (int j = 0; j < a; j++) {
            scanf("%d", &symp[j]);
            if (medic[symp[j]] < 0) b = 1;
        }
        if (b) {
            printf("YOU DIED\n");
            continue;
        }
        for (int j = 0; j < a; j++) {
            printf("%d ", medic[symp[j]]);
        }
        printf("\n");
    }
    return 0;
}