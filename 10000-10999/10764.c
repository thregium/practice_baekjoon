#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * M(N, M <= 50) ũ���� ������ �ִ�. �� ���񿡼� �� ���ڵ��� �ٸ� ���ڵ�� ġȯ�ϰ� "MOO"��� ���ڿ���
����, ����, �밢������ ������ ���� ã������ �� �� ã�� �� �ִ� �ִ� ������ ���Ѵ�. ��, ���� ���ڰ�
�� ���� ���ڷ� ġȯ�ǰų� ���ڰ� ġȯ���� �ʴ� ���� �Ұ����ϴ�.

�ذ� ��� : 'M'�� 'O'�� �����Ǵ� ���ڵ��� ���� Ȯ���ذ��� ���񿡼� ã�� �� �ִ� ���ڿ��� ������ ���Ѵ�.
"MOO" ���ڿ��� ������ ���� �迭�� ���� ������ ���� �� �ִ�. �� ���� �� ���� ū ���� ���� �ȴ�.
'M'�� �����Ǵ� ���ڿ� 'O'�� �����Ǵ� ���ڰ� ��ġ�ų� ���� 'M', 'O'�� �� �ȴٴ� ���� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2015O B1��
*/

char puz[64][64];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("moocrypt.in", "r");
        fo = fopen("moocrypt.out", "w");
    }
    int n, m, r = 0, tr;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n + 1; i++) {
        scanf("%s", puz[i] + 2);
    }
    for (char cm = 'A'; cm <= 'Z'; cm++) {
        if (cm == 'M') continue;
        for (char co = 'A'; co <= 'Z'; co++) {
            if (cm == co || co == 'O') continue;
            tr = 0;
            for (int i = 2; i <= n + 1; i++) {
                for (int j = 2; j <= m + 1; j++) {
                    for (int d = 0; d < 8; d++) {
                        if (puz[i][j] == cm && puz[i + dxy[d][0]][j + dxy[d][1]] == co
                            && puz[i + dxy[d][0] * 2][j + dxy[d][1] * 2] == co) tr++;
                    }
                }
            }
            if (tr > r) r = tr;
        }
    }
    printf("%d", r);
    return 0;
}