#include <stdio.h>
#include <string.h>

/*
���� : �־��� �ð����� �ð��� UTC+8�� �ð����� �ٲ۴�. ��, �ð��� 24�ð� �����̰� �ð���� �Ҽ��� �Ʒ� 1�ڸ����� �־��� �� �ִ�.

�ذ� ��� : ���� �ð��� UTC+0 �������� �ű� ���� �ð��뿡 �°� �ð��� �ٲٸ� �ȴ�. ��, �ð���� ���������� �޴� ���� ������,
1�ڸ��� ���� 2�ڸ��� ��쿡 ���� ���� �ٸ��� �����ؾ� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����

��ó : Petro 2018S4 K��
*/

char s[16];

int main(void) {
    int t, a, b, tm, add;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %s", &a, &b, s);
        tm = a * 60 + b - 480;
        if (strlen(s) > 8) return 1;
        add = 0;
        if (strlen(s) == 5) add += (s[4] - '0') * 60;
        else if (strlen(s) == 6) add += (s[4] - '0') * 600 + (s[5] - '0') * 60;
        else if (strlen(s) == 7) add += (s[4] - '0') * 60 + (s[6] - '0') * 6;
        else if (strlen(s) == 8) add += (s[4] - '0') * 600 + (s[5] - '0') * 60 + (s[7] - '0') * 6;
        if (s[3] == '+') tm += add;
        else tm -= add;
        tm %= 1440;
        if (tm < 0) tm += 1440;
        printf("%02d:%02d\n", tm / 60, tm % 60);
    }
    return 0;
}