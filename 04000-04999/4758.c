#include <stdio.h>

/*
���� : �� ������ �ӵ�, ������, ���� �־��� ��, �ش� ������ �� �� �ִ� �������� ��� ����Ѵ�.(���� ����)
�� �� �ִ� �������� ���ٸ� "No positions"�� ����Ѵ�.

�ذ� ��� : �� ���� �Է¹ް� ������ ���� �������� ���� ����ϸ� �ȴ�. �������� ������� ���ߴٸ�
"No positions"�� ����Ѵ�. �̶�, �ӵ��� �Ǽ����̹Ƿ� �񱳿� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : MidAtl 2004 A��
*/

int main(void) {
    int wei, str, r;
    double spd;
    while (1) {
        scanf("%lf %d %d", &spd, &wei, &str);
        if (wei == 0) break;
        spd -= 0.001;
        r = 0;
        if (spd <= 4.5 && wei >= 150 && str >= 200) {
            printf("Wide Receiver ");
            r++;
        }
        if (spd <= 6.0 && wei >= 300 && str >= 500) {
            printf("Lineman ");
            r++;
        }
        if (spd <= 5.0 && wei >= 200 && str >= 300) {
            printf("Quarterback");
            r++;
        }
        if (r == 0) printf("No positions");
        printf("\n");
    }
    return 0;
}