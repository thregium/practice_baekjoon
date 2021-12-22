#include <stdio.h>

/*
���� : 3���� ������ ����Ⱑ �ִ�. �� ������� ����(<= 100, ���� �ƴ� ����)�� �־��� ��, M(M <= 100, ���� �ƴ� ����)��
���Ϸ� ����⸦ ��� ��� ����� ����Ѵ�. ��, ����⸦ 1���� �̻� ��ƾ� �Ѵ�.

�ذ� ��� : �� ����⸦ 0�������� 100�������� �ѹ��� ��ƺ��� M�� ���ϰ� �ǰ� 1���� �̻� ��Ҵ��� Ȯ���Ѵ�.
�׷��� ��� �� ������ ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : CCC 2009J 2��
*/

int main(void) {
    int a, b, c, m, r = 0;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (i + j + k == 0 || a * i + b * j + c * k > m) continue;
                printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", i, j, k);
                r++;
            }
        }
    }
    printf("Number of ways to catch fish: %d", r);
    return 0;
}