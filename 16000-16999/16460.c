#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 100000)���� ��� �� ����(����, �Ÿ�(<= 20000))�� �´� ����� �̸��� ���������� ����Ѵ�.
��� ����� �̸��� 10�� ������ ���ĺ����� �־�����.

�ذ� ��� : ��� ������� ���캸�鼭 ���ǿ� �´� �� Ȯ���Ѵ�.
�׷��鼭 ���ǿ� �´� ����� �̸����� �迭�� ������ ������.
�� ����, �迭�� �ִ� �̸��� �����ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ���ڿ�

��ó : �Ѿ�� 5ȸ BB��
*/

char buff1[16], buff2[16], res[103000][16];

int main(void) {
    int n, l, rp = 0, p = 0, x;
    scanf("%s %s %d", buff1, buff2, &l);
    if (strlen(buff2) == 2) p = 3;
    else if (buff2[0] == 'M') p = 1;
    else p = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", buff1, buff2, &x);
        if (((buff2[0] == 'M' && ((p & 1) == 1)) || (buff2[0] == 'F' && ((p & 2) == 2))) && x <= l) {
            strcpy(res[rp++], buff1);
        }
    }
    qsort(res, rp, sizeof(char) * 16, strcmp);
    for (int i = 0; i < rp; i++) {
        printf("%s\n", res[i]);
    }
    if (rp == 0) printf("No one yet");
    return 0;
}