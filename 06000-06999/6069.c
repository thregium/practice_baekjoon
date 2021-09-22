#include <stdio.h>

/*
���� : N(N <= 500)���� ������ ��� ���� ���·� �ִ�. M(M <= 2000)���� ������ �����Ѵ�.
0. [S, E]�� �ش��ϴ� ������ ���¸� ������Ų��.
1. [S, E]���� ���� ������ ������ ���Ѵ�.

�ذ� ��� : N�� M�� ũ�Ⱑ �����Ƿ� ������ ������ ������ �ùķ��̼��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : USACO 2008N B1��
*/

int lights[512];

int main(void) {
    int n, m, o, s, e, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &s, &e);
        if (o) {
            r = 0;
            for (int j = s; j <= e; j++) r += lights[j];
            printf("%d\n", r);
        }
        else {
            for (int j = s; j <= e; j++) lights[j] = !lights[j];
        }
    }
    return 0;
}