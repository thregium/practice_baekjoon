#include <stdio.h>
#include <string.h>

/*
���� : 60 * 60 ũ���� �ǿ� ���ڵ��� �߰��ϴ� ��ɾ���� �־�����. ��ɾ ������ ��ü ���� ���¸� ����Ѵ�.

�ذ� ��� : ������ ������� �����Ѵ�. ũ�� 5�� ���ڵ��� �ϵ��ڵ��� �δ� ���� ����.

�ֿ� �˰��� : ����, �Ľ�, ��Ʈ����ŷ, ��ó��

��ó : SCUSA 1995 4��
*/

const int c5[] = { 289797198, 256177231, 503583838, 256185423, 520384607, 17068127, 239439966, 289797201,
521158943, 103055900, 287601233, 520360001, 289756881, 291853521, 239408206, 17101903, 509940814,
287634511, 255909982, 235947359, 239408209, 69772369, 292377681, 287851153, 68174481, 520634911 };
//ū ���ĺ����� �ϵ��ڵ��صд�.
char op[8], csz[8], str[128], res[64][64], toprint[8][512];

int main(void) {
    int row = -1, col = -1, pr, pc;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) res[i][j] = '.';
    }
    while (1) {
        if (scanf("%s", op) == EOF) break;
        if (!strcmp(op, ".EOP")) {
            //���� ����ϰ� �ʱ�ȭ�Ѵ�
            for (int i = 0; i < 60; i++) {
                printf("%s\n", res[i]);
            }
            printf("\n");
            for (int i = 0; i < 60; i++) printf("-");
            printf("\n\n");
            for (int i = 0; i < 60; i++) {
                for (int j = 0; j < 60; j++) res[i][j] = '.';
            }
            continue;
        }
        scanf("%s %d ", csz, &row);
        row--;
        if (!strcmp(op, ".P")) {
            //���� ��ġ
            scanf("%d ", &col);
            col--;
        }
        if (!strcmp(op, ".L")) col = 0; //���� ����
        fgets(str, 100, stdin);
        if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

        memset(toprint, 0, sizeof(toprint));
        pr = csz[1] - '0', pc = 0;
        if (csz[1] == '1') {
            //ũ�� 1�� ������ ���
            for (int i = 1; str[i] != '|'; i++) {
                toprint[0][i - 1] = str[i];
                if (str[i] == ' ') toprint[0][i - 1] = '.';
            }
            pc = strlen(str) - 2;
        }
        else {
            //ũ�� 5�� ������ ���
            for (int i = 1; str[i] != '|'; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 6; k++) {
                        //��Ʈ����ŷ�� ���� ������ �߰��� ������.
                        if (str[i] == ' ') toprint[j][(i - 1) * 6 + k] = '.';
                        else toprint[j][(i - 1) * 6 + k] =
                            ((c5[str[i] - 'A'] >> (j * 6 + k)) & 1) ? '*' : '.';
                    }
                }
            }
            pc = (strlen(str) - 2) * 6;
        }

        if (!strcmp(op, ".R")) col = 60 - pc; //���� ����
        if (!strcmp(op, ".C")) col = 30 - (pc >> 1); //��� ����

        for (int i = 0; i < pr; i++) {
            for (int j = 0; j < pc; j++) {
                //���ڵ��� ������ �߰��Ѵ�. ���� �Ǵ� ���ڰ� ���� ĭ�� �߰����� �ʵ��� �Ѵ�.
                if (i + row >= 60 || j + col >= 60 || i + row < 0 || j + col < 0) continue;
                if (toprint[i][j] != '.') res[i + row][j + col] = toprint[i][j];
            }
        }
    }
    return 0;
}