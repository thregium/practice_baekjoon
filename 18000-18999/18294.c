#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 200000)������ ���� ������ �־�����. �̶�, �� ������ ��ü�� ������ �Ѵ��� Ȯ���ϰ�,
�Ѵ´ٸ� �� ������ �̸���, ���� �ʴ´ٸ� "NONE"�� ����Ѵ�.

�ذ� ��� : ��� ������ �̸��� ������ ����, �� ���� �׷��� ���� ����. �� �� ��ü�� ������ �Ѵ� ���� ������
�� ������ �̸��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : SWERC 2019 B��
*/

char anim[204800][24];

int main(void) {
    int n, cnt = 1, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", anim[i]);
    }
    qsort(anim, n, sizeof(char) * 24, strcmp);
    for (int i = 1; i < n; i++) {
        if (strcmp(anim[i], anim[i - 1])) {
            if (cnt * 2 > n) {
                printf("%s", anim[i - 1]);
                r = 1;
            }
            cnt = 1;
        }
        else cnt++;
    }
    if (cnt * 2 > n) {
        printf("%s", anim[n - 1]);
        r = 1;
    }
    if (!r) printf("NONE");
    return 0;
}