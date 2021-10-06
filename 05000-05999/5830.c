#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���� N(N <= 1000)ȸ�� �������� �־��� ��, ��� �������� ��ġ�� ���ؼ� �ʿ��� ���簢�� ������ �ּ� ũ�⸦ ���Ѵ�.
���� ������ ���� ���� ��ģ ��� �������� ��ĥ �� ����, -1�� ����ؾ� �Ѵ�.
�� �̵����� �������� Ư���� ���� ���� �ٶ󺸴� ������ ��, ������, ��, ���� �� �� ������ �̵���Ű�ų�
�� ���� �߽����� �ð�������� ���� 90�� ������ �� �� �ϳ���.

�ذ� ��� : ���� �������� �ùķ��̼��Ѵ�. �� �������� ���� �� ���� �ִ� ������ �����ϵ��� �ϰ�,
���� ��ġ���� ���ε� Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ������

��ó : USACO 2013O B1��
*/

char buff[8];
int foot[4][2] = { {1, 0}, {1, 1}, {0, 0}, {0, 1} }; //FL, FR, RL, RR
int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("ballet.in", "r");
        fo = fopen("ballet.out", "w");
    }

    int n, d = 0, m = 0, xl = 0, xh = 1, yl = 0, yh = 1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        //�� Ȯ��
        if (buff[0] == 'F' && buff[1] == 'L') m = 0;
        else if (buff[0] == 'F' && buff[1] == 'R') m = 1;
        else if (buff[0] == 'R' && buff[1] == 'L') m = 2;
        else if (buff[0] == 'R' && buff[1] == 'R') m = 3;
        else return 1;

        //���� ������ ����
        if (buff[2] == 'F') {
            foot[m][0] += dxy[d][0];
            foot[m][1] += dxy[d][1];
        }
        else if (buff[2] == 'R') {
            foot[m][0] += dxy[(d + 1) & 3][0];
            foot[m][1] += dxy[(d + 1) & 3][1];
        }
        else if (buff[2] == 'B') {
            foot[m][0] += dxy[(d + 2) & 3][0];
            foot[m][1] += dxy[(d + 2) & 3][1];
        }
        else if (buff[2] == 'L') {
            foot[m][0] += dxy[(d + 3) & 3][0];
            foot[m][1] += dxy[(d + 3) & 3][1];
        }
        else if (buff[2] == 'P') {
            //ȸ����
            for (int j = 0; j < 4; j++) {
                t = foot[j][0];
                foot[j][0] = (foot[m][1] - foot[j][1]) + foot[m][0];
                foot[j][1] = (t - foot[m][0]) + foot[m][1];
            }
            d = ((d + 1) & 3); //���� ����
        }
        else return 3;

        /*
        for (int j = 0; j < 4; j++) {
            printf("%d,%d ", foot[j][0], foot[j][1]);
        }
        printf("%c", '\n');
        */

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                if (foot[j][0] == foot[k][0] && foot[j][1] == foot[k][1]) {
                    //���� ĭ�� ���� ��� ���
                    printf("%d", -1);
                    return 0;
                }
            }
            if (foot[j][0] < xl) xl = foot[j][0];
            else if (foot[j][0] > xh) xh = foot[j][0];
            if (foot[j][1] < yl) yl = foot[j][1];
            else if (foot[j][1] > yh) yh = foot[j][1];
            //�ִ� ����
        }
        
    }
    printf("%d", (xh - xl + 1) * (yh - yl + 1));
    return 0;
}