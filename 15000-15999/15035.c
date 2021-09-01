#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 10)���� �� ��� T(T <= 3000)�� ������ ���� �������� ���� ��(<= 500) �� �ϳ��� ã�´�.

�ذ� ��� : �� ������ ������ �ּڰ��� �� ���� �����ذ��� Ǯ�� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : UKIEPC 2017 I��
*/

int height[16];

int main(void) {
    int n, t, best = INF, bestnum = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < n; i++) {
        if (t % height[i] < best) {
            best = t % height[i];
            bestnum = i;
        }
    }
    if (bestnum < 0) return 1;
    printf("%d", height[bestnum]);
    return 0;
}