#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : 9�� ������ ���ڿ� N + 1(N <= 1000)���� �־�����. �� ���ڿ��� ���ĺ��� ���ڷ� �̷���� �ִ�.
�̶�, 2��°���� �� ���ڿ����� ù ��° ���ڿ����� ���� ������ �տ� ���� �� ���Ѵ�.
���� ������ ���ڿ� ���ڸ� ���� ���� ������� �� ���ڿ��� ���ڴ� 1����, ���ڴ� ������ �� ������ �ٲ� ����,
�տ������� ���ʷ� ���鼭 ���� �ٸ� ���� ������ ���� ã�´�. ���� �ٸ� ���� ������ ������
�ϳ��� ��, �ٸ� �ϳ��� ������ ��� ���� �ִ� ���� ��, �� �� ���� ��� ���� ���� ���� ���� ��,
�� �� ������ ��� ���� �� �񱳸� �Ѵ�. �ϳ��� ����ٸ� �� ���� �տ� �´�.

�ذ� ��� : ���ڿ����� �־��� ������ �ڸ� ����, �տ������� ���� ������.
������ ���Ǵ�� ���ϸ� �ȴ�. �� �񱳴� ���̰� ª�� ������ strtoll() �Լ��� �̿��� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : Yokohama 2018 A��
*/

char s0[16], frag0[16][16], s1[16], frag1[16][16];

int isdc(char c) {
    if (isdigit(c)) return 0;
    else if (isalpha(c)) return 1;
    else return -1;
}

int main(void) {
    int n, p1 = 0, p2 = 0, p3 = 0, p4 = 0, r;
    scanf("%d", &n);
    scanf("%s", s0);
    for (int i = 0; s0[i]; i++) {
        if (i == 0 || !(isdc(s0[i]) || isdc(s0[i - 1]))) frag0[p1][p2++] = s0[i];
        else {
            p2 = 0;
            frag0[++p1][p2++] = s0[i];
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", s1);
        p3 = 0, p4 = 0;
        for (int j = 0; s1[j]; j++) {
            if (j == 0 || !(isdc(s1[j]) || isdc(s1[j - 1]))) frag1[p3][p4++] = s1[j];
            else {
                p4 = 0;
                frag1[++p3][p4++] = s1[j];
            }
        }

        r = 0;
        for (int j = 0;; j++) {
            if (j > p3 && j <= p1) {
                r = -1;
                break;
            }
            else if (j > p1) {
                r = 1;
                break;
            }
            if (isdc(frag0[j][0]) != isdc(frag1[j][0])) {
                r = isdc(frag1[j][0]) - isdc(frag0[j][0]);
                break;
            }
            if (isdc(frag0[j][0])) {
                r = strcmp(frag1[j], frag0[j]);
                if (r != 0) break;
            }
            else {
                if (strtoll(frag1[j], NULL, 10) > strtoll(frag0[j], NULL, 10)) {
                    r = 1;
                    break;
                }
                else if (strtoll(frag1[j], NULL, 10) < strtoll(frag0[j], NULL, 10)) {
                    r = -1;
                    break;
                }
            }
        }
        printf("%c\n", r > 0 ? '+' : '-');


        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) frag1[j][k] = 0;
        }
    }
    return 0;
}