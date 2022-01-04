#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 20)���� �ܾ �־����� �� �ܾ�� ���� $�� �ܾ 1000 ������ �ڿ����� ��Ÿ���� �ܾ ����־�
���� �ܾ�� ��ü ���ĺ� ������ ���� ������ ã�´�. ���� �ִ� ��츸 �־�����.
���� ���� ���� ��� ���� ���� ���� ���� ���� ����Ѵ�.

�ذ� ��� : 1���� 1000������ ��� ���� �ϳ��� ��������� ���� �´� ��츦 ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : COCI 13/14#3 3��
*/

char* ut[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
char* teen[] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char* tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

char wd[32][64];

int main(void) {
    int n, l = -1, tmp = 0;
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest3_testdata\\recenice\\recenice.in.10", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", wd[i]);
        l += strlen(wd[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(wd[i], "$")) {
            for (int j = 1; j <= 999; j++) {
                wd[i][0] = '\0';
                if (j >= 100) {
                    strcat(wd[i], ut[j / 100]);
                    strcat(wd[i], "hundred");
                }
                if (j % 100 >= 20) strcat(wd[i], tens[j / 10 % 10]);
                if (j % 100 < 20 && j % 100 >= 11) strcat(wd[i], teen[j % 100 - 10]);
                else if (j % 100 >= 20 && j % 10 > 0) strcat(wd[i], ut[j % 10]);
                else if (j % 100 <= 10 && j % 100 > 0) strcat(wd[i], ut[j % 100]);

                if (l + strlen(wd[i]) == j) {
                    tmp = 1;
                    break;
                }
            }
        }
    }
    if (tmp == 0) return 1;

    for (int i = 0; i < n; i++) {
        printf("%s ", wd[i]);
    }
    return 0;
}