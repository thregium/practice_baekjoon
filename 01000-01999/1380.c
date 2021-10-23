#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� �̸��� N * 2 - 1���� �Ͱ��� �м�, ȸ�� ����� �־��� ��, �Ͱ��̸� �������� ���� ����� �̸��� ����Ѵ�.
��, �ѹ� �м��� �Ͱ��̴� �ٽ� �м����� �ʰ�, �м��� �Ŀ� �Ͱ��̸� �����޴´�.

�ذ� ��� : ���������� �����޾Ҵٸ� �Ͱ��̸� �м����ϰ� �������� 2���� ����� ���� ���̴�. ������, �������� ���� ��쿡��
�м��� �������Ƿ� 1���� ��ϸ� ���� ���̴�. ����, ����� ������ Ȯ���ϰ� 1���� ����� �ִ� ����� ã��
�� ����� �̸��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NZPC 2006 E��
*/

char name[128][64];
int cnt[128];

int main(void) {
    int n, x, r;
    char c;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            fgets(name[i], 63, stdin);
            if (name[i][0] == '\n') {
                i--;
                continue;
            }
            if (name[i][strlen(name[i]) - 1] == '\n') name[i][strlen(name[i]) - 1] = '\0';
            cnt[i] = 0;
        }
        for (int i = 1; i < n * 2; i++) {
            scanf("%d %c", &x, &c);
            cnt[x]++;
        }
        r = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                if (r >= 0) return 1;
                r = i;
            }
        }
        if (r < 0) return 2;
        printf("%d %s\n", tt, name[r]);
    }
    return 0;
}