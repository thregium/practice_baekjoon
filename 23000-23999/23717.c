#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� �� ĭ�� ���ϴ� ������ �־��� ��, ���� �ּ� �� �� ĥ�ؾ� ���ϴ� ���� ������ �� ���Ѵ�.
ĥ�� �� �ִ� ���� ����, ���, �Ķ��̰�, �ѹ��� ������ ĭ���� ĥ�� �� �ִ�. ����, ���� ĭ��
���� ���� ĥ�ϴ� ��� ���� ���̰� �Ǿ� ��Ȳ, �ʷ�, ����, ȸ���� ĥ�� �� �ִ�. ����� ���� ĥ������ ���� ����̴�.

�ذ� ��� : �� ĭ�� �� ������ ĥ�ؾ� �ϴ� ����, ���, �Ķ��� ��Ʈ���� �����Ѵ�.
�׸��� �� ���� ��Ʈ���� ĥ�ϴ� Ƚ���� Ȯ���Ѵ�. ĥ�� ������ ���� ���� ����� �ִ��� �а� ĥ�ϴ� ���� ����.
����, �� ����� ������ ���� �Ǵµ�, �̴� �� ĭ�� ĥ���� �ʰ� �ش� ĭ�� ĥ�ϴ� ����� ������ ���� �ȴ�.
3���� ���� ���� �̸� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ��Ʈ����ŷ

��ó : GKS 2021H B��
*/

char s[103000];
int tonum[26] = { 7, 4, -1, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, 3, 5, -1, 1, -1, -1, 0, -1, -1, -1, 2, -1 };

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        r = 0;
        for (int i = 1; i <= n; i++) s[i] = tonum[s[i] - 'A'];
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                if ((s[j] & (1 << i)) && (~s[j - 1] & (1 << i))) r++;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}