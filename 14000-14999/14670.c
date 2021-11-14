#include <stdio.h>

/*
���� : N(N <= 100)���� ����� �̿� ���� ���� �־��� ��, R(R <= 100)���� ���� ��Ͽ� ���� ���� ���� ���� �ִ��� ���ϰ�,
�� �ܿ��� �� ���� ���� ����� ����Ѵ�.

�ذ� ��� : �� ���� ���� ���� ȿ���� ���� ����, ���� ����� ���鼭 ����� Ȯ���ϸ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���Ǵ� 2017 A��
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