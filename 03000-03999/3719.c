#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 임의의 날짜가 주어질 때, 그 날짜 이후의 첫 팰린드롬 날짜를 구한다.
팰린드롬 날짜는 날짜를 붙였을 때(월, 일은 0 포함) 회문이 되는 날짜이다.
주어지는 연도는 2^31보다 작은 자연수이고 실제로 존재하는 날짜이다.

해결 방법 : 연도가 3자리 이하인 경우 모든 회문을 시도해 보며 다음으로 가능한 날짜가 되는 회문을 찾는다.
4자리 이상인 경우 맨 앞 4자리를 뒤집은 것이 날짜가 되는 다음 수를 찾은 다음,
그 수에 대한 연도를 계산해 나간다. 윤년 처리에 유의한다.

주요 알고리즘 : 구현, 케이스 워크, 그리디 알고리즘, 브루트 포스

출처 : SEERC 2011 E번
*/

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int torev[10000];
char s[32], s2[32];

int ispal(char* s) {
    //주어진 문자열이 회문인 지 확인한다.
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int isleap(long long y) {
    //주어진 연도가 윤년인 지 확인한다.
    if (y & 3) return 0;
    else if (y % 100) return 1;
    else if (y % 400) return 0;
    else return 1;
}

int isdate(long long x) {
    //주어진 수가 날짜로 변환될 수 있는 지 확인한다.
    long long d = x % 100, m = x / 100 % 100, y = x / 10000;
    if (m > 12 || d > 31 || d == 0 || m == 0) return 0;
    if (isleap(y)) {
        if (d <= days[m]) return 1;
        else if (d == 29 && m == 2) return 1;
        else return 0;
    }
    else {
        if (d <= days[m]) return 1;
        else return 0;
    }
}

long long nextpal(long long x, int ln) {
    //주어진 수 이상의 수 가운데 길이 ln인 가장 작은 회문을 구한다.
    sprintf(s2, "%lld", x);
    int l = strlen(s2), c = 0, md1, md2;
    sprintf(s2 + ln - l, "%lld", x);
    for (int i = 0; i < ln - l; i++) s2[i] = '0';
    l = ln;
    md1 = l / 2, md2 = (l - 1) / 2;
    for (int i = md2 + 1; i < l; i++) {
        if (s2[i] > s2[l - 1 - i]) {
            c = 1;
            break;
        }
        else if(s2[i] < s2[l - 1 - i]) {
            c = -1;
            break;
        }
    }
    for (int i = md2 + 1; i < l; i++) s2[i] = s2[l - 1 - i];
    if (c <= 0) {
        for (int i = (l + 1) / 2; i < l; i++) s2[i] = s2[l - 1 - i];
        return strtoll(s2, NULL, 10);
    }
    s2[md1] = (s2[md1] - '0' + 1) % 10 + '0';
    if (md1 != md2) s2[md2] = (s2[md2] - '0' + 1) % 10 + '0';
    if (s2[md2] == '0') s2[md2 - 1]++;
    for (int i = md1; i > 0; i--) {
        if (s2[i] > '9') {
            s2[i] -= 10;
            s2[i - 1]++;
        }
    }
    for (int i = md1; i < l; i++) {
        s2[i] = s2[l - 1 - i];
    }
    return strtoll(s2, NULL, 10);
}

int main(void) {
    int t;
    long long d, m, y, x, res, pal, rdate, fnal, midy;
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2011\\input\\E_t.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2011\\input\\E_t.out", "w", stdout);
    /*
    while (1) {
        scanf("%lld", &x);
        printf("%lld\n", nextpal(x));
    }
    */

    for (int i = 0; i < 10000; i++) {
        torev[i] = i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000;
    }

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 32; i++) s[i] = '\0';

        scanf("%lld/%lld/%lld", &d, &m, &y);
        x = y * 10000 + m * 100 + d + 1;
        //3자리 이하 연도에 대한 처리(브루트 포스)
        if (x < 100000) {
            if (x > 91219) x = 100000;
            else {
                res = x;
                for (long long i = x / 100; i < 1000; i++) {
                    pal = i * 100 + i / 10 % 10 * 10 + i / 100;
                    if (pal < x) continue;
                    if (isdate(pal)) {
                        res = pal;
                        break;
                    }
                }
                printf("%02lld/%02lld/%lld\n", res % 100, res / 100 % 100, res / 10000);
                continue;
            }
        }
        if (x < 1000000) {
            if (x > 921129) x = 1000000;
            else {
                res = x;
                for (long long i = x / 1000; i < 1000; i++) {
                    pal = i * 1000 + i % 10 * 100 + i / 10 % 10 * 10 + i / 100;
                    if (pal < x) continue;
                    if (isdate(pal)) {
                        res = pal;
                        break;
                    }
                }
                printf("%02lld/%02lld/%lld\n", res % 100, res / 100 % 100, res / 10000);
                continue;
            }
        }
        if (x < 10000000) {
            if (x > 9290929) x = 10000000;
            else {
                res = x;
                for (long long i = x / 10000; i < 10000; i++) {
                    pal = i * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000;
                    if (pal < x) continue;
                    if (isdate(pal)) {
                        res = pal;
                        break;
                    }
                }
                printf("%02lld/%02lld/%lld\n", res % 100, res / 100 % 100, res / 10000);
                continue;
            }
        }

        sprintf(s + 1, "%lld", x);
        rdate = (s[1] - '0') * 1000 + (s[2] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');
        //연도의 앞 4자리 확인
        if (rdate > 9290) {
            //다음 자릿수로 넘어가야 하는 경우의 처리
            rdate = 10100;
            for (int i = 1; s[i]; i++) s[i] = '0';
            s[0] = '1';
            s[3] = '1';
            x = strtoll(s, NULL, 10);
            printf("01/10/%lld\n", x / 10000);
            continue;
        }
        if (isdate(torev[rdate])) {
            //해당 날짜가 가능한 경우
            fnal = 1;
            for (int i = 5; s[i + 4]; i++) {
                if (s[i] != '9') fnal = 0;
            }
            if (fnal) {
                //연도 아랫 부분이 전부 9인 경우
                if (x % 10000 > torev[rdate]) {
                    for (int i = 5; s[i]; i++) s[i] = '0';
                    rdate++;
                }
                else {
                    res = x / 10000 * 10000 + torev[rdate];
                    printf("%02lld/%02lld/%lld\n", res % 100, res / 100 % 100, res / 10000);
                    continue;
                }
            }
            else if(torev[rdate] == 229) {
                //윤년에 대한 처리
                midy = strtoll(s + 5, NULL, 10) / 10000;
                if (x % 10000 > 229) midy++;
                else if (x % 10000 == 229 && !isleap(x / 10000)) midy++;
                x = x / 10000 * 10000 + 10000;
                fnal = 1;
                for (int i = 5; s[i + 5]; i++) {
                    if (s[i] != '9') fnal = 0;
                }
                if (s[strlen(s) - 5] <= '6') fnal = 0;
                if (fnal) {
                    rdate++;
                }
                else {
                    while (1) {
                        midy = nextpal(midy, strlen(s + 1) - 8);
                        if (isleap(midy)) break;
                        midy++;
                    }
                    printf("29/02/9220%s\n", s2);
                    continue;
                }
            }
            else {
                //그 외 해당 날짜가 가능한 경우 다음 팰린드롬 연도를 사용
                midy = strtoll(s + 5, NULL, 10) / 10000;
                if (x % 10000 > torev[rdate]) midy++;
                x = x / 10000 * 10000 + 10000;
                midy = nextpal(midy, strlen(s + 1) - 8);
                printf("%02d/%02d/%lld%s\n", torev[rdate] % 100, torev[rdate] / 100, rdate, s2);
                continue;
            }
        }
        if (rdate > 9290) {
            //위에서의 처리로 인해 다음 자릿수로 넘어가야 하는 경우
            rdate = 10100;
            for (int i = 1; s[i]; i++) s[i] = '0';
            s[0] = '1';
            s[3] = '1';
            x = strtoll(s, NULL, 10);
            printf("01/10/%lld\n", x / 10000);
            continue;
        }

        //그 외 일반적인 경우(연도 앞 4자리를 바꿔야 하는 경우)
        while (!isdate(torev[rdate])) rdate++;
        s[1] = rdate / 1000 + '0';
        s[2] = rdate / 100 % 10 + '0';
        s[3] = rdate / 10 % 10 + '0';
        s[4] = rdate % 10 + '0';
        for (int i = 5; s[i]; i++) s[i] = '0';
        res = strtoll(s + 1, NULL, 10) / 10000 * 10000 + torev[rdate];
        printf("%02lld/%02lld/%lld\n", res % 100, res / 100 % 100, res / 10000);
    }
    return 0;
}