#include <stdio.h>

/*
���� : ���� ���ڿ� ��� ���̰� a(a <= 10^9) * 10^b(b <= 10^6)�� ���� ã�´�. ��, a * 10^b�� 20���� ū ��� �� 17�ڸ� ����Ѵ�.
���� ���ڿ��� -�� ���� �����ư��� �����ϸ�, �����ϴ� ��� ���� ������ �ڸ����� ��ġ�� �� �� ��°�� ���ڿ��̴�.

�ذ� ��� : ����, 20�� �̸��� ����� ���ڿ����� ���� �����ش�. 20�� �̻��� ���ڿ��鿡 ���� ���캸��
a * 10^b�� ���� �ڸ� ���� ��� ���ڿ��� �� �κ��� (�ڸ��� + 1)������ �ݺ����� �� �� �ִ�.
�̸� �̿��� 10^v - v���� 10^v - 1������ ���� ���� ���ڿ��� ������ ���� �̿��� ���ϸ�
10^(v - 1) - v���� 10^(v - 1) - 1������ ���� ���ڿ����� 9 * 10^(v - 1) - 1ĭ��ŭ �������� �ű� ������ �� �� �ִ�.
�̴� 9 * 10^(v - 1) - 1 % v�� ������ �̸� ����س��� �ѹ��� �������� �������ָ� ���� �� �ִ�.
��� v�� ���� 10^(2^i) % v�� ������ �����ص� ���� v - 1�� �ִ� ��Ʈ�� ���� �ش� ������ �����༭ ���ϸ� �ȴ�.
10^v�� 10^v - v�� ���� ����. ���� �� ���� ���ڿ����� �����ؼ� ��Ÿ�� ���̹Ƿ�
�� v�� 3 ���� ���� ���ڿ��� ���� ��ġ�鸸 �����صд�.
�� v�� ���� ������ ������ ������ ������ �Է¹��� ���� �ڸ����� Ȯ���ϰ� �������� ���� ����(������ �ߴ� ��Ĵ��)
�ش� �ڸ����� �������� �´� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ��������

��ó : UCPC 2020�� B��
*/

/*mod10: 10^(2^j) % i�� ��, start: area[i]���� area[i + 1]�� �Ǳ� ���� �������� �ϴ� ĭ ��, 10^i % i, area: 10^i - i���� ����Ͽ�
�� ���� ���ڿ��� �Ǵ� ������ ���� �� �κ�
*/
int mod10[1048576][24], start[1048576][2], area[1048576][3];
char* strs[3] = { "1-3-5-7-10-13-16-", "-2-4-6-8-11-14-17", "1-3-5-7-9-12-15-1" }; //20�� �ʰ��ϴ� ��쿡 ���� ���ڿ�
char* strslong[3] = { "1-3-5-7-9-12-15-18-21", "1-3-5-7-10-13-16-19-22", "-2-4-6-8-11-14-17-20" }; //20�� �̸��� ���� ���ڿ�

int getarea(int base, int md) {
    //������� ���� ������ �������� �ڸ����� ������ ���� �ش��ϴ� ������ ã�´�.
    md = (md - start[base][1]) % (base + 1);
    if (md < 0) md += (base + 1);
    if (area[base][0] < area[base][1] && area[base][0] < area[base][2]) {
        if (md < area[base][0]) return 2;
        else if (md < area[base][1]) return 0;
        else if (md < area[base][2]) return 1;
        else return 2;
    }
    else if (area[base][1] < area[base][0] && area[base][1] < area[base][2]) {
        if (md < area[base][1]) return 0;
        else if (md < area[base][2]) return 1;
        else if (md < area[base][0]) return 2;
        else return 0;
    }
    else {
        if (md < area[base][2]) return 1;
        else if (md < area[base][0]) return 2;
        else if (md < area[base][1]) return 0;
        else return 1;
    }
}

int getdigits(int n) {
    //int n�� �� �ڸ� ������ ���Ѵ�.
    if (n < 10) return 1;
    else if (n < 100) return 2;
    else if (n < 1000) return 3;
    else if (n < 10000) return 4;
    else if (n < 100000) return 5;
    else if (n < 1000000) return 6;
    else if (n < 10000000) return 7;
    else if (n < 100000000) return 8;
    else if (n < 1000000000) return 9;
    else return 10;
}

int main(void) {
    int md, t, a, b, digits; //md: ���ڿ�, digits: a * 10^b�� �ڸ��� + 1
    for (int i = 3; i <= 1024000; i++) {
        md = 10;
        if (md >= i) md %= i;
        mod10[i][0] = md;
        for (int j = 1; j <= 20; j++) {
            mod10[i][j] = ((long long)mod10[i][j - 1] * mod10[i][j - 1]) % i; //10�� (2^j)������ i�� ���� ������ ���Ѵ�.
        }
    }
    for (int i = 2; i <= 1012000; i++) {
        md = 9;
        for (int tmp = i - 1, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[i + 1][j]) % (i + 1);
            }
        }
        start[i][0] = (md + i) % (i + 1);
        md = 1;
        for (int tmp = i - 1, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[i][j]) % i;
            }
        }
        start[i - 1][1] = md;
    }
    area[2][0] = 0;
    area[2][1] = 1;
    area[2][2] = 2;
    for (int i = 3; i <= 1012000; i++) {
        for (int j = 0; j < 3; j++) {
            area[i][j] = (area[i - 1][j] - start[i][0]) % (i + 1);
            if (area[i][j] < 0) area[i][j] += (i + 1);
        }
    }

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        if ((a <= 20 && b == 0) || (a <= 2 && b == 1)) {
            digits = a * (b ? 10 : 1);
            if (digits < 10) {
                if (digits & 1) {
                    for (int i = 0; i < digits; i++) {
                        printf("%c", strslong[0][i]);
                    }
                    printf("\n");
                }
                else {
                    for (int i = 0; i < digits; i++) {
                        printf("%c", strslong[2][i]);
                    }
                    printf("\n");
                }
            }
            else {
                for (int i = 0; i < digits; i++) {
                    printf("%c", strslong[digits % 3][i]);
                }
                printf("\n");
            }
            continue;
        }

        digits = b + getdigits(a) + 1;
        md = a % digits;
        for (int tmp = b, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[digits][j]) % digits;
            }
        }
        printf("%s...\n", strs[getarea(digits - 1, md)]);

    }

    return 0;
}