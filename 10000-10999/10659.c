#include <stdio.h>
#include <string.h>
#define INF 103000

/*
���� : N(N <= 500)���� �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� �ҹ����� ���� ������ �ٲپ�
�־��� ���ڿ����� �������� �ǵ��� �� �� �ִ� �� ���Ѵ�.
�� ���ڿ��� ���̴� 10 ���ϴ�.

�ذ� ��� : �켱 � ���ڿ��� �� �� ���ڿ��� �ٸ��� ���λ��� ��찡 ���� �� Ȯ���Ѵ�.
�׷��� ��찡 �ִٸ� �������� �� �� ����.
�� �ܿ��� �� ������ �������� ���ڵ� ���̸� �������� ���� �� ����Ŭ�� ������ �ʴ� �� Ȯ���ϸ� �ȴ�.
�̴� �÷��̵�-���� �˰����� �̿��� ���� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, �׷��� �̷�, �÷��̵�-����

��ó : JAG 2012P A��
*/

char s[512][16];
int dist[26][26];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            if (i > 0 && strstr(s[i - 1], s[i]) == s[i - 1] && strcmp(s[i - 1], s[i])) r = 0;
        }
        if (r == 0) {
            printf("no\n");
            continue;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) dist[i][j] = INF;
        }
        
        for (int i = 1; i < n; i++) {
            if (!strcmp(s[i], s[i - 1])) continue;
            for (int j = 0; j < 10; j++) {
                if (s[i][j] == ' ' || s[i - 1][j] == ' ' || s[i][j] == '\0' || s[i - 1][j] == '\0') break;
                else if (s[i][j] != s[i - 1][j]) {
                    dist[s[i - 1][j] - 'a'][s[i][j] - 'a'] = 1;
                    break;
                }
            }
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (dist[i][i] != INF) r = 0;
        }
        printf("%s\n", r ? "yes" : "no");
    }
    return 0;
}