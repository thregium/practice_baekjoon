#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �ۿ� ���� �켱������ �±׵�(<= 100)�� �־��� ��, �±��� ��ȣ�� �־��� �� ����
�׷��� �±װ� �ִ� ���� ��ȣ�� �켱���� ������ ����Ѵ�.

�ذ� ��� : �� �۵��� �±׵�� �켱����, ��ȣ�� �迭�� �ְ� �켱���� ������ �����Ѵ�.
�� ��, �±� ��ȣ�� �־��� �� ���� �۵��� ���ʷ� ���鼭 �±װ� �ִ� �۵��� ã�Ƽ� ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ���Ʈ ����

��ó : ���� 4ȸ G��
*/

int kw[128][128];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 127);
    int bi = *((int*)b + 127);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, q, x, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &kw[i][127]);
        kw[i][126] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &kw[i][0]);
        for (int j = 1; j <= kw[i][0]; j++) {
            scanf("%d", &kw[i][j]);
        }
    }
    qsort(kw + 1, n, sizeof(int) * 128, cmp1);
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        c = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= kw[j][0]; k++) {
                if (kw[j][k] == x) {
                    printf("%d ", kw[j][126]);
                    c++;
                    break;
                }
            }
        }
        if (c == 0) printf("-1\n");
        else printf("\n");
    }
    return 0;
}