#include <stdio.h>

/*
���� : ���ڿ��� �� ������ ������ �־��� ��, �������� ã�´�. �� ������ Ư���� ������ ����, ���� * ��ü���� �ش� ��ü�� �������̴�.

�ذ� ��� : ���ڿ��� �� ���ڸ��� � ������ ã�� ����, ��� ��ü�� �������� ����Ѵ�.
�� ���� ���� �������� ���� ���� ã�Ƽ� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : PLU 2014N 6��
*/

char loc[128], spe[128];

int main(void) {
    int n, b, c, m, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", loc, spe);
        b = 0, c = 0, m = 0, w = 0;
        for (int j = 0; spe[j]; j++) {
            if (spe[j] == 'B') b += 2;
            else if (spe[j] == 'C') c++;
            else if (spe[j] == 'M') m += 4;
            else if (spe[j] == 'W') w += 3;
            else return 1;
        }
        printf("%s: ", loc);
        if (b > c && b > m && b > w) printf("The Bobcat is the dominant species\n");
        else if (c > b && c > m && c > w) printf("The Coyote is the dominant species\n");
        else if (m > b && m > c && m > w) printf("The Mountain Lion is the dominant species\n");
        else if (w > b && w > c && w > m) printf("The Wolf is the dominant species\n");
        else printf("There is no dominant species\n");
    }
    return 0;
}