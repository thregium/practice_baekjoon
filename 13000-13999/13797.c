#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ ���� ��ȣ�� �ش� ��ȣ�� ������ �־�����. Q(Q <= 1000)���� ������ ����
��ȣ�� �� �� �ִ� �� Ȯ���ϰ� �׷��ϴٸ� �׶��� ��ȣ�� �� ��ȣ�� ������ ����Ѵ�. �� �� ���ٸ� Unknown�� ����Ѵ�.
���� ��ȣ�� ������ �ϳ����� �־�����.

�ذ� ��� : �켱 �� ��ȣ�� ������ ���� �������� �����Ѵ�. �׸��� Q���� ������ ���� �־��� �� ����
��ȣ�� ����� ���ʺ��� ���쳪����. ���� ���� ������ ���� ���� ��ȣ�� ���س� ������ ��� �ش� ��ȣ�� ���� ��
Ȯ���Ѵ�. ���ٸ� �� ��ȣ�� ��ȣ�� ������ ����ϰ�, ���� �ʴ´ٸ� �̹� �� �ظ� ���������Ƿ� Unknown�� ����Ѵ�.
������ �׷��� ��ȣ�� �������� �� �� ���� ����̹Ƿ� Unknown�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : JAG 2010P A��
*/

typedef struct era {
    char s[32];
    int by;
    int wy;
} era;

era e[1024];

int cmp1(const void* a, const void* b) {
    era ai = *(era*)a;
    era bi = *(era*)b;
    return ai.wy > bi.wy ? 1 : ai.wy == bi.wy ? 0 : -1;
}

int main(void) {
    int n, q, y, r;
    while (1) {
        scanf("%d %d", &n, &q);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", e[i].s, &e[i].by, &e[i].wy);
        }
        qsort(e, n, sizeof(era), cmp1);
        for (int i = 0; i < q; i++) {
            scanf("%d", &y);
            r = 0;
            for (int j = 0; j < n; j++) {
                if (y <= e[j].wy) {
                    if (y > e[j].wy - e[j].by) printf("%s %d\n", e[j].s, e[j].by - (e[j].wy - y));
                    else printf("Unknown\n");
                    r = 1;
                    break;
                }
            }
            if (!r) printf("Unknown\n");
        }
    }
    return 0;
}