#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 주어진 체코식 주민번호가 유효한지, 유효하다면 어떤 성별에 해당하는 지를 구한다.

해결 방법 : 경우의 수를 나누어 해결한다(각 경우는 코드 참조)

주요 알고리즘 : 구현, 파싱, 케이스 워크

출처 : CTU 2009 I번
*/

char s[32];
const int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isleap(int x) {
    if (x & 3) return 0;
    else if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else return 1;
}

int main(void) {
    int slash = 0, date, yr, mt, dy;
    long long tnum;
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "end")) break;
        slash = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '/') slash++;
        }
        if (slash != 1 || s[6] != '/') {
            printf("invalid\n");
            continue;
        }
        
        date = strtoll(s, NULL, 10);
        yr = date / 10000;
        mt = date / 100 % 100;
        dy = date % 100;
        if (9 < yr && yr < 20) {
            printf("invalid\n");
            continue;
        }
        if (yr < 10) yr += 100;
        if (!((1 <= mt && mt <= 12) || (51 <= mt && mt <= 62))) {
            printf("invalid\n");
            continue;
        }
        if (!((mt % 50 == 2 && isleap(yr + 1900) && dy == 29) || (dy <= days[mt % 50])) || dy == 0) {
            printf("invalid\n");
            continue;
        }

        if (!((yr <= 53 && strlen(s) == 10) || (yr >= 54 && strlen(s) == 11))) {
            printf("invalid\n");
            continue;
        }
        tnum = date * 10000LL + strtoll(s + 7, NULL, 10);
        if (yr >= 54 && tnum % 11) {
            printf("invalid\n");
            continue;
        }
        
        if (mt >= 50) printf("girl\n");
        else printf("boy\n");
    }
    return 0;
}