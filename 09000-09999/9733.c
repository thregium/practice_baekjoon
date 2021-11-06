#include <stdio.h>
#include <string.h>

/*
���� : 24�� ������ ��ҹ��� 2�ڷ� �̷���� Ȱ���� �־��� ��, ������ �־��� 7���� Ȱ���� Ƚ���� ������ ����Ѵ�.
7���� ���� Ȱ���� �־��� �� �ִ�. �ٸ� Ȱ���鵵 ��ü Ȱ���� ���Եȴ�.

�ذ� ��� : �� Ȱ���� � Ȱ�������� ã�Ƽ� �� Ȱ���� Ƚ���� ����, ��ü Ȱ���� Ƚ���� ����.
��ü Ȱ���� �� �������� �� Ȱ���� Ƚ���� ����ϰ� ��ü Ȱ���� Ƚ���� �ش� Ȱ���� Ƚ������ ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�

��ó : Phili 2013P A��
*/

char wk[4];
int cnt[7];
const char* pt[7] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };

int main(void) {
    int tot = 0;
    while (scanf("%s", wk) != EOF) {
        tot++;
        for (int i = 0; i < 7; i++) {
            if (!strcmp(wk, pt[i])) cnt[i]++;
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%s %d %.2f\n", pt[i], cnt[i], cnt[i] / (double)tot);
    }
    printf("Total %d 1.00", tot);
    return 0;
}