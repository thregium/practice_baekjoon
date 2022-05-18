#include <stdio.h>

char cust[128];
char salon[32], vis[26];

/*
���� : N(N <= 20)���� �ڸ��� �ִ� �´׼� ������ �´�. ������ 'A'���� 'Z'������ ���ĺ�����
�־�����, ���� ������ �Ͱ� ������ ���� �� ���̰�, �� ���ĺ��� �� �ֱ����� �־�����.
�̶�, ������ �� �ڸ��� ������ �״�� ���ư��ٸ�, ���ư��� ���� ���� ���Ѵ�.

�ذ� ��� : �� ���� �� ������ �� ���� ���� �ڸ��� ã��, ���� �� ���� �� ���� ã�Ƽ�
������ �Ѵ�. ���� �ڸ��� ������ ��츦 ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 2002 F��
*/

int main(void) {
    int n, r, ok;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", cust);
        for (int i = 0; i < n; i++) salon[i] = '\0';
        for (int i = 0; i < 26; i++) vis[i] = 0;
        r = 0;

        for (int i = 0; cust[i]; i++) {
            if (vis[cust[i] - 'A']) {
                for (int j = 0; j < n; j++) {
                    if (salon[j] == cust[i]) salon[j] = '\0';
                }
            }
            else {
                ok = 0;
                for (int j = 0; j < n; j++) {
                    if (salon[j] == '\0') {
                        salon[j] = cust[i];
                        ok = 1;
                        break;
                    }
                }
                if (!ok) r++;
            }
            vis[cust[i] - 'A'] = 1;
        }
        
        if (!r) printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n", r);
    }
    return 0;
}