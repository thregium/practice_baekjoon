#include <stdio.h>

/*
���� : 20���� ���� �ٸ� ������ ������� �־��� ��, �������Ľ� ��ȯ Ƚ���� ���Ѵ�.

�ذ� ��� : �Ź� �� ���� ���� �� ���� �տ� �ִ� �� ��� �� ū ���� ������ŭ ��ȯ�� �ؾ� �Ѵ�.
����, �� ���� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����?

��ó : GNY 2014 A��
*/

int height[32];

int main(void) {
    int p, t, r = 0;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &t);
        r = 0;
        for (int i = 0; i < 20; i++) {
            scanf("%d", &height[i]);
            for (int j = 0; j < i; j++) {
                if (height[j] > height[i]) r++;
            }
        }
        printf("%d %d\n", t, r);
    }
    return 0;
}