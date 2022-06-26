#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 10000)���� K(K <= 26)��° �̳��� �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��,
�� ���ڿ����� M(M <= 100)�� �̳��� K��° �̳��� �ҹ��ڷ� �̷���� ���ڿ� ��� �־��� ���ڿ���
�κ� ���ڿ��� �ƴ� ���ڿ��� ���Ѵ�. �׷��� ���ڿ��� �ִ� ��츸 �־�����.

�ذ� ��� : ���� �ٸ� M���� �κ� ���ڿ��� ���ƾ� N - M + 1�ڸ��̰�, ã�� �� ���� ���ڿ��� �����ϴ� ��츸
�־����� ������, aaaa...aaa���� ���ʷ� ��� ���ڿ��� ����� ���� N - M + 1�� �Ǵ� K^M�� �̳���
�׷��� ���ڿ��� ã�� �� �ִ�. �׷��� ���ڿ��� ã�Ƽ� ����ϸ� �ȴ�.

�ֿ� �˰����� : ���ڿ�, ���Ʈ ����

��ó : GCPC 2010 E��
*/

char s[10240], r[128];

int main(void) {
    int t, n, m, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%s", s);
        for (int i = 0; i < m; i++) r[i] = 'a';
        r[m] = '\0';
        while (strstr(s, r)) {
            r[0]++;
            for (int i = 0; r[i] >= 'a' + k; i++) {
                r[i] = 'a';
                r[i + 1]++;
            }
            r[m] = '\0';
        }
        printf("%s\n", r);
    }
    return 0;
}