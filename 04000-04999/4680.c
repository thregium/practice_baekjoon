#include <stdio.h>

/*
���� : N(N <= 12)���� �ڿ����� ������������� �־��� ��, ���� T(T <= 1000)�� �Ǵ� ��츦 ���� ������������ ����Ѵ�.

�ذ� ��� : ��͸� ���� ��� ��츦 �غ���. �̶�, ������ ���� ���� ���� �ʵ��� �Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : MidC 1997 C��
*/

int a[16], chk[16];
int r;

void track(int t, int n, int sel, int stt, int sm) {
    if (sm > t) return;
    else if (sm == t) {
        r++;
        for (int i = 0; i < sel; i++) {
            if (i > 0) printf("+");
            printf("%d", chk[i]);
        }
        printf("\n");
    }

    for (int i = stt; i < n; i++) {
        if (a[i] == chk[sel]) continue;
        chk[sel] = a[i];
        track(t, n, sel + 1, i + 1, sm + a[i]);
        chk[sel + 1] = 0;
    }
}

int main(void) {
    int t, n;
    while (1) {
        scanf("%d", &t);
        if (t == 0) break;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        printf("Sums of %d:\n", t);
        track(t, n, 0, 0, 0);
        if (!r) printf("NONE\n");
        for (int i = 0; i < 16; i++) chk[i] = 0;
    }
    return 0;
}