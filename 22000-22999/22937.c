#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 소수점 9자리까지 주어지는 두 실수가 주어질 때, 두 실수의 곱을 오차 없이 구한다. 두 실수는 -4 이상 4 이하다.
맨 뒷자리가 0이더라도 생략하지 않는다.

해결 방법 : 두 실수를 뒷자리부터 차례로 계산해가며 각 자리의 값을 구한다. 먼저 각 위치의 합을 구한 다음,
캐리를 적용해 전체 자릿수의 값을 구하면 된다. 두 실수가 뒤에서부터 보면 항상 자릿수가 고정되어 있음을 이용한다.

주요 알고리즘 : 수학, 구현, 문자열, 임의 정밀도

출처 : 중앙대 2021N C번
*/

char a[16], b[16], r[32];
int dr[32];

int main(void) {
    int n, al, bl, c, p;
    scanf("%d", &n);
    r[3] = '.';
    for (int i = 0; i < n; i++) {
        scanf("%s %s", a, b);
        al = strlen(a) - 1;
        bl = strlen(b) - 1;
        c = 0;
        p = 2;
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) dr[18 - j - k] += (a[al - j] - '0') * (b[bl - k] - '0');
            dr[18 - j - 9] += (a[al - j] - '0') * (b[bl - 10] - '0');
        }
        for (int k = 0; k < 9; k++) dr[18 - 9 - k] += ((a[al - 10] - '0') * (b[bl - k] - '0') + c);
        dr[0] = ((a[al - 10] - '0') * (b[bl - 10] - '0') + c);

        for (int j = 18; j > 0; j--) {
            r[j + 3] = (c + dr[j]) % 10 + '0';
            c = (c + dr[j]) / 10;
            dr[j] = 0;
        }
        r[2] = (c + dr[0]) % 10 + '0';
        c = (c + dr[0]) / 10;
        if (c) {
            p--;
            r[p] = c + '0';
        }
        if ((al - 10) ^ (bl - 10)) printf("-%s\n", &r[p]);
        else printf("%s\n", &r[p]);
    }
    return 0;
}
