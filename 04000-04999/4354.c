#include <stdio.h>

/*
���� : ���� 10^6 ������ ���ĺ� �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� �ִ� �ݺ� Ƚ���� ���Ѵ�.

�ذ� ��� : ������ ����� �Ǵ� ������ ���ݱ��� �� �ּ� ���̱��� Ȯ���� ������ ���� �ݺ��ϸ� ���� �� Ȯ���� ������.
�̸� �ݺ��Ͽ� �ּ� ���̿����� �ݺ� Ƚ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ���ڿ�

��ó : Waterloo 20020601 D��
*/

char s[1048576];

int main(void) {
    int j, m, n;
    //freopen("E:\\PS\\Contest\\waterloo\\20020601\\data\\D.0.dat", "r", stdin);
    while (1) {
        fgets(s, 1030000, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (!strcmp(s, ".")) break;
        n = strlen(s);
        m = n;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                for (j = 0; j < m - m / i && s[j] == s[j + m / i]; j++);
                if (j == m - m / i) m /= i;
            }
        }
        printf("%d\n", strlen(s) / m);
    }
}
