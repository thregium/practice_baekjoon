#include <stdio.h>
#include <string.h>

/*
���� : �� ���� ���� �� ���� �Է¹��� ���� '#'�� ������ ����(���� ����)�� ������ % ������ ���Ѵ�.
�Ҽ��� �� �ڸ� ������ ����ϵ�, �� ���� ������ ������ �������� ��쿡�� ������ ����Ѵ�.

�ذ� ��� : �� ���� fgets�� �Է¹ް� ù ���ڰ� ������ �� �� ���� �� ���ڵ��� Ȯ���Ѵ�.
�� ���ڰ� ������ �ƴ� �ٸ� ���ڶ�� ��ü ������ ���� 1 �ø���, '#'�� �ƴ϶�� �ν��� ������ ���� 1 �ø���.
Ȯ���� ������ ����ϱ� ���� sscanf()�� ���ڿ��� ������ �Ҽ��� �� �ڸ��� ����� ����
������ �ڸ��� 0�̸� ������ �ٲپ� ���, �� �ܿ��� ���� �ϴ� ��� �Ҽ��� �� �ڸ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : CERC 2007 PC��
*/

char buff[128], res[32];

int main(void) {
    int t, a, o;
    scanf("%d", &t);
    getchar();
    for (int tt = 0; tt < t; tt++) {
        a = 0, o = 0;
        while (1) {
            fgets(buff, 120, stdin);
            if (buff[0] == '\n') break;
            for (int i = 0; buff[i]; i++) {
                if (buff[i] == '\n') break;
                a++;
                if (buff[i] != '#') o++;
            }
        }
        if (a == 0) return 1;
        sprintf(res, "%.1f", (double)o / a * 100);
        if (res[strlen(res) - 1] == '0') printf("Efficiency ratio is %.0f%%.\n", (double)o / a * 100);
        else printf("Efficiency ratio is %.1f%%.\n", (double)o / a * 100);
    }
    return 0;
}