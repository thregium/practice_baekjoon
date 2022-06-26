#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : ������ ��¥�� �־��� ��, �� ��¥ ������ ù �Ӹ���� ��¥�� ���Ѵ�.
�Ӹ���� ��¥�� ��¥�� �ٿ��� ��(��, ���� 0 ����) ȸ���� �Ǵ� ��¥�̴�.
�־����� ������ 2^31���� ���� �ڿ����̰� ������ �����ϴ� ��¥�̴�.

�ذ� ��� : ������ 3�ڸ� ������ ��� ��� ȸ���� �õ��� ���� �������� ������ ��¥�� �Ǵ� ȸ���� ã�´�.
4�ڸ� �̻��� ��� �� �� 4�ڸ��� ������ ���� ��¥�� �Ǵ� ���� ���� ã�� ����,
�� ���� ���� ������ ����� ������. ���� ó���� �����Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ, �׸��� �˰���, ���Ʈ ����

��ó : SEERC 2011 E��
*/

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int torev[10000];
char s[32], s2[32];

int ispal(char* s) {
    //�־��� ���ڿ��� ȸ���� �� Ȯ���Ѵ�.
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int isleap(long long y) {
    //�־��� ������ ������ �� Ȯ���Ѵ�.
    if (y & 3) return 0;
    else if (y % 100) return 1;
    else if (y % 400) return 0;
    else return 1;
}

int isdate(long long x) {
    //�־��� ���� ��¥�� ��ȯ�� �� �ִ� �� Ȯ���Ѵ�.
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
    //�־��� �� �̻��� �� ��� ���� ln�� ���� ���� ȸ���� ���Ѵ�.
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
        //3�ڸ� ���� ������ ���� ó��(���Ʈ ����)
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
        //������ �� 4�ڸ� Ȯ��
        if (rdate > 9290) {
            //���� �ڸ����� �Ѿ�� �ϴ� ����� ó��
            rdate = 10100;
            for (int i = 1; s[i]; i++) s[i] = '0';
            s[0] = '1';
            s[3] = '1';
            x = strtoll(s, NULL, 10);
            printf("01/10/%lld\n", x / 10000);
            continue;
        }
        if (isdate(torev[rdate])) {
            //�ش� ��¥�� ������ ���
            fnal = 1;
            for (int i = 5; s[i + 4]; i++) {
                if (s[i] != '9') fnal = 0;
            }
            if (fnal) {
                //���� �Ʒ� �κ��� ���� 9�� ���
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
                //���⿡ ���� ó��
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
                //�� �� �ش� ��¥�� ������ ��� ���� �Ӹ���� ������ ���
                midy = strtoll(s + 5, NULL, 10) / 10000;
                if (x % 10000 > torev[rdate]) midy++;
                x = x / 10000 * 10000 + 10000;
                midy = nextpal(midy, strlen(s + 1) - 8);
                printf("%02d/%02d/%lld%s\n", torev[rdate] % 100, torev[rdate] / 100, rdate, s2);
                continue;
            }
        }
        if (rdate > 9290) {
            //�������� ó���� ���� ���� �ڸ����� �Ѿ�� �ϴ� ���
            rdate = 10100;
            for (int i = 1; s[i]; i++) s[i] = '0';
            s[0] = '1';
            s[3] = '1';
            x = strtoll(s, NULL, 10);
            printf("01/10/%lld\n", x / 10000);
            continue;
        }

        //�� �� �Ϲ����� ���(���� �� 4�ڸ��� �ٲ�� �ϴ� ���)
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