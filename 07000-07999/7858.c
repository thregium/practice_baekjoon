#include <stdio.h>
#include <ctype.h>

/*
���� : ��ϵ��� ���� ���°� N(N <= 50) * 20 ũ�⿡ �־��� ��, ����� ���� ������ ������ �� �� ���� ���������� ���� ���� ���Ѵ�.
����� ���ĺ� �빮�ڷ� �־�����.

�ذ� ��� : �� ��ϵ� �� ���Ʒ��� ���� �ٸ� ����� ������ ��츦 ã��, �Ʒ� ��Ͽ��� �� ������� �̵��ϴ� �������� �����Ѵ�.
�� ����, ���������� �ϸ� ���������� 0�� �湮���� ���� ���� �� ���� ���������� ���� ������ ���ʷ� �湮�ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : NEERC_FE 2002 B��
*/

char tetr[64][32];
int adj[32][32], ins[32], exist[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tetr[i]);
        for (int j = 0; j < 20; j++) {
            if (isupper(tetr[i][j])) exist[tetr[i][j] - 'A'] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            if (isupper(tetr[i][j]) && isupper(tetr[i - 1][j])) {
                if (tetr[i][j] == tetr[i - 1][j]) continue;
                if (adj[tetr[i][j] - 'A'][tetr[i - 1][j] - 'A']) continue;
                adj[tetr[i][j] - 'A'][tetr[i - 1][j] - 'A'] = 1;
                ins[tetr[i - 1][j] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (ins[j] || !exist[j]) continue;
            printf("%c", 'A' + j);
            for (int k = 0; k < 26; k++) {
                if (adj[j][k]) ins[k]--;
            }
            exist[j] = 0;
            break;
        }
    }
    return 0;
}