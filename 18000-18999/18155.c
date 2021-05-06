#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : M(M <= 100)���� ����� �ִ�. N(N <= 100)���� ���ڿ��� ���� ��Ʈ�� �����ؼ� ����� ����ִ��� Ȯ���Ѵ�.
�� ���ڿ��� ���̴� 25�� �̸��̴�.

�ذ� ��� : N���� ���ڿ��� ���� ���� ��Ʈ�� �����Ѵ�. �� �� strstr�� �̿��� ��� ����� ���� ����� ����ִ��� ���θ� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : PacNW U��
*/

char* leet = "OLZE4SBTB9";
char bad[128][32], check[128][32];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", bad[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", check[i]);
        for (int j = 0; check[i][j]; j++) {
            if (isdigit(check[i][j])) {
                check[i][j] = leet[check[i][j] - '0'];
            }
        }
        t = 1;
        for (int j = 0; j < n; j++) {
            if (strstr(check[i], bad[j]) != NULL) {
                t = 0;
                break;
            }
        }
        printf("%s\n", t ? "VALID" : "INVALID");
    }
    return 0;
}