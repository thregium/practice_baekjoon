#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : ���� ǥ������� ǥ��� ���� N(N <= 100)�� ������ �־��� ��, M(M <= 100)���� ���� ����
���� ������ ������ �� ��� ��� ���� 0���� ������ ��찡 �ִ� �� ���Ѵ�.
�� ������ �ִ� 1���� ���̸�, ������ �ùٸ���. ����, ������ 256���� ���� �������� ���ȴ�.

�ذ� ��� : �켱 ������ �̿��� �� �����ڿ� �ش��ϴ� ��ġ�� �� ���� ��ġ�� ���Ѵ�.
�� ����, ������ �� ���� ���鼭 �� �׸��� ������ ���� �����ذ��鼭 ���̳��� ���α׷����� �Ѵ�.
���� ������ ������ ������ ������ ���� ��� ���ϰ�, �����ڰ� ������ ���� �� ���� ��� ��츦
Ȯ���ϸ鼭, ������ ������ ����س����� ����̴�. ���߿� 0���� ������ ��찡 ����� 0����
������ ��찡 �ִ� ���̴�.

�ֿ� �˰��� : DP, ����

��ó : JAG 2013S3A B��
*/

char vars[128][32];
int vari[128][2];
char tok[128][32];
int ab[128][2], stk[128], mem[128][256];

int main(void) {
    int m, n, top = 0, res = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d %d", vars[i], &vari[i][0], &vari[i][1]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tok[i]);
        if (tok[i][0] == '+' || tok[i][0] == '-' || tok[i][0] == '*' || tok[i][0] == '/') {
            if (top < 2) return 1;
            ab[i][1] = stk[--top];
            ab[i][0] = stk[--top];
            stk[top++] = i;
        }
        else stk[top++] = i;
    }
    if (top != 1) return 1;
    for (int i = 0; i < n; i++) {
        if (tok[i][0] == '+' || tok[i][0] == '-' || tok[i][0] == '*' || tok[i][0] == '/') {
            for (int j = 0; j < 256; j++) {
                if (!mem[ab[i][0]][j]) continue;
                for (int k = 0; k < 256; k++) {
                    if (!mem[ab[i][1]][k]) continue;
                    if (tok[i][0] == '+') mem[i][(j + k) & 255] = 1;
                    if (tok[i][0] == '-') mem[i][(j + 256 - k) & 255] = 1;
                    if (tok[i][0] == '*') mem[i][(j * k) & 255] = 1;
                    if (tok[i][0] == '/') {
                        if (k == 0) {
                            printf("error\n");
                            return 0;
                        }
                        else mem[i][(j / k) & 255] = 1;
                    }
                }
            }
        }
        else if (isdigit(tok[i][0])) {
            mem[i][strtoll(tok[i], NULL, 10)] = 1;
        }
        else {
            for (int j = 0; j < m; j++) {
                if (!strcmp(vars[j], tok[i])) {
                    for (int k = vari[j][0]; k <= vari[j][1]; k++) mem[i][k] = 1;
                }
            }
        }
    }
    printf("correct\n");
    return 0;
}