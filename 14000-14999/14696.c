#include <stdio.h>

/*
���� : 4, 3, 2, 1�� ���� ������ ������ŭ ���� ī�� 2���� �־��� ��, ū ������ ���ؼ� ������ �ٸ� ���, �� ���� ���� �̱�ٰ� �Ѵ�.
�̶�, �̱�� ���� ã�´�. ��� ���� ���ٸ� ����.

�ذ� ��� : ������ ���δ�� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : ���� 2017 ��1��
*/

int ac[8], bc[8];

int main(void) {
    int n, a, b, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i <= 4; i++) {
            ac[i] = 0;
            bc[i] = 0;
        }
        scanf("%d", &a);
        for (int j = 0; j < a; j++) {
            scanf("%d", &x);
            ac[x]++;
        }
        scanf("%d", &b);
        for (int j = 0; j < b; j++) {
            scanf("%d", &x);
            bc[x]++;
        }
        if (ac[4] > bc[4]) printf("A");
        else if (ac[4] < bc[4]) printf("B");
        else if (ac[3] > bc[3]) printf("A");
        else if (ac[3] < bc[3]) printf("B");
        else if (ac[2] > bc[2]) printf("A");
        else if (ac[2] < bc[2]) printf("B");
        else if (ac[1] > bc[1]) printf("A");
        else if (ac[1] < bc[1]) printf("B");
        else printf("D");
        printf("\n");
    }
    return 0;
}