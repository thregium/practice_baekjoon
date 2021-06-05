#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 10^6)자리 B(B <= 62, B >= 5)진법 수가 주어지면, 그 수를 B진법 대칭수 3개의 합으로 나타낸다.

해결 방법 : 경우의 수 별로 나누어 각각의 경우에 대해 대칭수를 만든다. 자세한 내용은 https://arxiv.org/abs/1602.06208 를 참조한다.

주요 알고리즘 : 구현, case work, 정수론
*/

char n[1048576], pal1[1048576], pal2[1048576], pal3[1048576];
char b62[128] =
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
-1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1,
-1, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1 };
char* rb62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int innercase;
long long multiplied[64][32]; //i의 j제곱

void getalgorithm(int casenum, int len, int base, char* n);

int ispal(char* p) {
    int len = strlen(p);
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        if (p[i] != p[j]) return 0;
    }
    return 1;
}

int finalcheck(int len, int base) {
    int pos1 = strlen(pal1) - 1, pos2 = strlen(pal2) - 1, pos3 = strlen(pal3) - 1, posn = len - 1;
    int digit = 0, carry = 0;
    while (posn >= 0) {
        digit = carry;
        if (pos1 >= 0) {
            if (pal1[pos1] < 0 || b62[pal1[pos1]] < 0) return 0;
            digit += b62[pal1[pos1]];
        }
        if (pos2 >= 0) {
            if (pal2[pos2] < 0 || b62[pal2[pos2]] < 0) return 0;
            digit += b62[pal2[pos2]];
        }
        if (pos3 >= 0) {
            if (pal3[pos3] < 0 || b62[pal3[pos3]] < 0) return 0;
            digit += b62[pal3[pos3]];
        }
        carry = 0;
        while (digit >= base) {
            carry++;
            digit -= base;
        }
        if (n[posn] != rb62[digit]) return 0;
        pos1--;
        pos2--;
        pos3--;
        posn--;
    }
    return 1;
}

int D(int x, int base) {
    return (x + base * 1000) % base;
}

int getcase(int len, int base, char* n) {
    if (len < 7) return 0;
    

    if (b62[n[1]] > 2) {
        if ((len & 1) == 0 && (n[len >> 1] == '0' || n[(len >> 1) - 1] == '0')) return 21;
        if (D(b62[n[len - 1]] - b62[n[0]] - b62[n[1]] + 1, base)) return 1;
        else return 2;
    }
    else if (b62[n[0]] != 1) {
        if ((len & 1) == 0 && (n[len >> 1] == '0' || n[(len >> 1) - 1] == '0')) return 21;
        if (D(b62[n[len - 1]] - b62[n[0]] + 2, base)) return 3;
        else return 4;
    }
    else if (n[1] == '0' && b62[n[2]] <= 3 && D(b62[n[len - 1]] - b62[n[2]], base)) {
        if ((len & 1) && (n[len >> 1] == '0' || n[(len >> 1) + 1] == '0')) return 21;
        return 5;
    }
    else if (n[1] == '0' && b62[n[2]] <= 2 && D(b62[n[len - 1]] - b62[n[2]], base) == 0) {
        if ((len & 1) && (n[len >> 1] == '0' || n[(len >> 1) + 1] == '0')) return 21;
        return 6;
    }

    if ((len & 1) == 0 && (n[len >> 1] == '0' || n[(len >> 1) - 1] == '0')) return 21;
    else if (n[0] == '1' && b62[n[1]] <= 2 && b62[n[2]] >= 4 && D(b62[n[len - 1]] - b62[n[2]], base)) return 11;
    else if (n[0] == '1' && b62[n[1]] <= 2 && b62[n[2]] >= 3 && D(b62[n[len - 1]] - b62[n[2]], base) == 0) return 12;
    else if (n[0] == '1' && (n[1] == '1' || n[1] == '2') && b62[n[2]] <= 1 && n[len - 1] == '0') return 13;
    else if (n[0] == '1' && (n[1] == '1' || n[1] == '2') && (n[2] == '2' || n[2] == '3') && n[len - 1] == '0') return 14;
    else if (n[0] == '1' && (n[1] == '1' || n[1] == '2') && b62[n[2]] <= 2 && n[len - 1] != '0') return 15;
    else if (n[0] == '1' && (n[1] == '1' || n[1] == '2') && n[2] == '3' && n[len - 1] != '3') return 16;
    else if (n[0] == '1' && (n[1] == '1' || n[1] == '2') && n[2] == '3' && n[len - 1] == '3') return 17;

    return -1;
}

long long makepal(int a, int base, int len) {
    long long r = 0;
    if (a >= multiplied[base][(len - 1) >> 1]) {
        r = a * multiplied[base][len >> 1];
        for (int i = 0; i < (len >> 1); i++) {
            r += a / multiplied[base][((len - 1) >> 1) - i] % base * multiplied[base][i];
        }
    }
    else {
        r = multiplied[base][len - 1] - 1;
    }
    return r;
}

void casesmall_6(int len, int base, char* n) {
    int x1, y1, z1, x2, y2, z2, x3, y3, c1, c2, c3, c4;
    if (n[0] == '1') {
        z1 = D(b62[n[5]] - b62[n[1]] + 1, base);
        if (z1 == 0 && b62[n[2]] == 0) {
            if (b62[n[1]] == 0) {
                if (b62[n[3]]) {
                    pal1[0] = '1';
                    for (int i = 1; i <= 4; i++) pal1[i] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    if (b62[n[3]] == base - 1) {
                        if (b62[n[4]] == 0) {
                            pal2[0] = rb62[b62[n[3]] - 2];
                            pal2[1] = rb62[base - 1];
                            pal2[2] = rb62[b62[n[3]] - 2];
                            pal3[0] = '1';
                            pal3[1] = '1';
                            pal3[2] = '1';
                            pal3[3] = '\0';
                        }
                        else {
                            pal2[0] = n[3];
                            pal2[1] = rb62[b62[n[4]] - 1];
                            pal2[2] = n[3];
                            pal3[0] = rb62[base - 1];
                            pal3[1] = '\0';
                        }
                    }
                    else {
                        pal2[0] = n[3];
                        pal2[1] = n[4];
                        pal2[2] = n[3];
                        pal3[0] = rb62[b62[n[5]] - b62[n[3]] - 1];
                        pal3[1] = '\0';
                    }
                    pal2[3] = '\0';
                }
                else if (b62[n[4]] == 0) {
                    pal1[0] = '1';
                    for (int i = 1; i <= 4; i++) pal1[i] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = rb62[base - 2];
                    pal2[1] = '\0';
                    pal3[0] = '0';
                    pal3[1] = '\0';
                }
                else if (b62[n[4]] == base - 1) {
                    pal1[0] = rb62[base - 1];
                    pal1[1] = '0';
                    pal1[2] = '1';
                    pal1[3] = '0';
                    pal1[4] = rb62[base - 1];
                    pal1[5] = '\0';
                    pal2[0] = rb62[base - 1];
                    pal2[1] = rb62[base - 2];
                    pal2[2] = rb62[base - 2];
                    pal2[3] = rb62[base - 1];
                    pal2[4] = '\0';
                    pal3[0] = '1';
                    pal3[1] = '0';
                    pal3[2] = '1';
                    pal3[3] = '\0';
                }
                else {
                    pal1[0] = '1';
                    for (int i = 1; i <= 4; i++) pal1[i] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = n[4];
                    pal2[1] = n[4];
                    pal2[2] = '\0';
                    pal3[0] = rb62[b62[n[5]] - b62[n[4]] - 1];
                    pal3[1] = '\0';
                }
            }
            else if (b62[n[1]] == 1) {
                if (b62[n[3]] == 0 && b62[n[4]] == 0) {
                    pal1[0] = '1';
                    for (int i = 1; i <= 4; i++) pal1[i] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    for (int i = 0; i <= 3; i++) pal2[i] = rb62[base - 1];
                    pal2[4] = '\0';
                    pal3[0] = '0';
                    pal3[1] = '\0';
                }
                else if (b62[n[3]] == 0 && b62[n[4]] == 1) {
                    pal1[0] = '1';
                    for (int i = 1; i <= 4; i++) pal1[i] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = '1';
                    for (int i = 1; i <= 3; i++) pal2[i] = '0';
                    pal2[4] = '1';
                    pal2[5] = '\0';
                    pal3[0] = rb62[base - 2];
                    pal3[1] = '\0';
                }
                else if (b62[n[3]] == 0) {
                    pal1[0] = '1';
                    pal1[1] = '1';
                    pal1[2] = '0';
                    pal1[3] = '0';
                    pal1[4] = '1';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    if (b62[n[4]] == 2) {
                        pal2[0] = '0';
                        pal2[1] = '\0';
                    }
                    else {
                        pal2[0] = rb62[b62[n[4]] - 2];
                        pal2[1] = rb62[b62[n[4]] - 2];
                        pal2[2] = '\0';
                    }
                    pal3[0] = rb62[base - b62[n[4]] + 1];
                    pal3[1] = '\0';
                }
                else if (b62[n[3]] == 1 && b62[n[4]] == 0) {
                    pal1[0] = '1';
                    pal1[1] = '0';
                    pal1[2] = rb62[base - 1];
                    pal1[3] = rb62[base - 1];
                    pal1[4] = '0';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = '1';
                    pal2[1] = rb62[base - 1];
                    pal2[2] = '1';
                    pal2[3] = '\0';
                    pal3[0] = rb62[base - 2];
                    pal3[1] = '\0';
                }
                else if (b62[n[3]] == 1 && b62[n[4]] == 1) {
                    pal1[0] = '1';
                    pal1[1] = '1';
                    pal1[2] = '0';
                    pal1[3] = '0';
                    pal1[4] = '1';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = rb62[base - 1];
                    pal2[1] = rb62[base - 1];
                    pal2[2] = '\0';
                    pal3[0] = '0';
                    pal3[1] = '\0';
                }
                else {
                    pal1[0] = '1';
                    pal1[1] = '1';
                    pal1[2] = '0';
                    pal1[3] = '0';
                    pal1[4] = '1';
                    pal1[5] = '1';
                    pal1[6] = '\0';

                    if (b62[n[4]] <= 1) {
                        pal2[0] = rb62[b62[n[3]] - 1];
                        pal2[1] = rb62[b62[n[4]] + base - 2];
                        pal2[2] = rb62[b62[n[3]] - 1];
                    }
                    else {
                        pal2[0] = n[3];
                        pal2[1] = rb62[b62[n[4]]  - 2];
                        pal2[2] = n[3];
                    }
                    pal3[0] = rb62[D(b62[n[5]] - b62[pal2[0]] - 1, base)];
                    pal2[3] = '\0';
                    pal3[1] = '\0';
                }
            }
            else if (b62[n[1]] == 2) {
            if (b62[n[3]] == 0 && b62[n[4]] == 0) {
                pal1[0] = '1';
                pal1[1] = '1';
                pal1[2] = rb62[base - 1];
                pal1[3] = rb62[base - 1];
                pal1[4] = '1';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = rb62[base - 2];
                pal2[1] = rb62[base - 2];
                pal2[2] = '\0';
                pal3[0] = '2';
                pal3[1] = '\0';
            }
            else if (b62[n[3]] == 0 && b62[n[4]] == 1) {
                pal1[0] = '1';
                for (int i = 1; i <= 4; i++) pal1[i] = '0';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = '2';
                for (int i = 1; i <= 3; i++) pal2[i] = '0';
                pal2[4] = '2';
                pal2[5] = '\0';
                pal3[0] = rb62[base - 2];
                pal3[1] = '\0';
            }
            else if (b62[n[3]] == 0 && b62[n[4]] == 2) {
                pal1[0] = '1';
                pal1[1] = '1';
                pal1[2] = rb62[base - 1];
                pal1[3] = rb62[base - 1];
                pal1[4] = '1';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = '1';
                pal2[1] = '0';
                pal2[2] = '1';
                pal2[3] = '\0';
                pal3[0] = rb62[base - 1];
                pal3[1] = '\0';
            }
            else if (b62[n[3]] == 0) {
                pal1[0] = '1';
                pal1[1] = '2';
                pal1[2] = '0';
                pal1[3] = '0';
                pal1[4] = '2';
                pal1[5] = '1';
                pal1[6] = '\0';
                if (b62[n[4]] == 3) {
                    pal2[0] = rb62[base - 1];
                    pal2[1] = '\0';
                    pal3[0] = '1';
                }
                else {
                    pal2[0] = rb62[b62[n[4]] - 3];
                    pal2[1] = rb62[b62[n[4]] - 3];
                    pal3[0] = rb62[base - b62[n[4]] + 3];
                    pal2[2] = '\0';
                }
                pal3[1] = '\0';
            }
            else if (b62[n[3]] == 1 && b62[n[4]] == 0) {
                pal1[0] = '1';
                pal1[1] = '1';
                pal1[2] = rb62[base - 1];
                pal1[3] = rb62[base - 1];
                pal1[4] = '1';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = '1';
                pal2[1] = rb62[base - 2];
                pal2[2] = '1';
                pal2[3] = '\0';
                pal3[0] = rb62[base - 1];
                pal3[1] = '\0';
            }
            else if (b62[n[3]] == 1 && b62[n[4]] == 1) {
                pal1[0] = '1';
                pal1[1] = '1';
                pal1[2] = rb62[base - 1];
                pal1[3] = rb62[base - 1];
                pal1[4] = '1';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = '1';
                pal2[1] = rb62[base - 1];
                pal2[2] = '1';
                pal2[3] = '\0';
                pal3[0] = rb62[base - 1];
                pal3[1] = '\0';
            }
            else {
                pal1[0] = '1';
                pal1[1] = '2';
                pal1[2] = '0';
                pal1[3] = '0';
                pal1[4] = '2';
                pal1[5] = '1';
                pal1[6] = '\0';

                if (b62[n[3]] == 1 && b62[n[4]] == 2) {
                    pal2[0] = rb62[base - 1];
                    pal2[1] = rb62[base - 1];
                    pal2[2] = '\0';
                }
                else if (b62[n[4]] <= 2) {
                    pal2[0] = rb62[b62[n[3]] - 1];
                    pal2[1] = rb62[b62[n[4]] + base - 3];
                    pal2[2] = rb62[b62[n[3]] - 1];
                    pal2[3] = '\0';
                }
                else {
                    pal2[0] = n[3];
                    pal2[1] = rb62[b62[n[4]] - 3];
                    pal2[2] = n[3];
                    pal2[3] = '\0';
                }
                pal3[0] = rb62[D(b62[n[5]] - b62[pal2[0]] - 1, base)];
                pal3[1] = '\0';
            }
            }
            else if (b62[n[1]] == 3) {
                y2 = 1;
                while (D(b62[n[4]] - 1 - y2, base) == 0 || D(b62[n[4]] - 1 - y2, base) == base - 1) y2++;
                c1 = (2 + y2 + D(b62[n[4]] - 1 - y2, base) - b62[n[4]]) / base;
                c2 = (base * 2 - y2 - 2 + D(b62[n[3]] + y2 + 2, base) - b62[n[3]]) / base;
                pal1[0] = '1';
                pal1[1] = '0';
                pal1[2] = rb62[base - y2 - 1 - c1];
                pal1[3] = rb62[base - y2 - 1 - c1];
                pal1[4] = '0';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = '2';
                pal2[1] = rb62[y2 - c2 + 1 + c1];
                pal2[2] = rb62[D(b62[n[3]] + y2 + 2, base)];
                pal2[3] = rb62[y2 - c2 + 1 + c1];
                pal2[4] = '2';
                pal2[5] = '\0';
                pal3[0] = rb62[base - 1];
                pal3[1] = rb62[D(b62[n[4]] - 1 - y2, base) + c2 - 1 - c1];
                pal3[2] = rb62[base - 1];
                pal3[3] = '\0';
            }
            else {
                y2 = 1;
                while (D(b62[n[4]] - 1 - y2, base) == 0 || D(b62[n[4]] - 1 - y2, base) == base - 1) y2++;
                c1 = (2 + y2 + D(b62[n[4]] - 1 - y2, base) - b62[n[4]]) / base;
                c2 = (base * 2 - y2 - 2 + D(b62[n[3]] + y2 - 1, base) - b62[n[3]]) / base;
                pal1[0] = '1';
                pal1[1] = '2';
                pal1[2] = rb62[base - y2 - c1];
                pal1[3] = rb62[base - y2 - c1];
                pal1[4] = '2';
                pal1[5] = '1';
                pal1[6] = '\0';
                pal2[0] = rb62[b62[n[1]] - 3];
                pal2[1] = rb62[y2 - c2 + c1];
                pal2[2] = rb62[D(b62[n[3]] + y2 - 1, base)];
                pal2[3] = rb62[y2 - c2 + c1];
                pal2[4] = rb62[b62[n[1]] - 3];
                pal2[5] = '\0';
                pal3[0] = '1';
                pal3[1] = rb62[D(b62[n[4]] - 2 - y2, base) + c2 - c1];
                pal3[2] = '1';
                pal3[3] = '\0';
            }
        }
        else {
            if (z1 && D(b62[n[5]] - b62[n[1]] + 2, base)) {
                if (b62[n[1]]) {
                    x1 = base - 1;
                    y1 = b62[n[1]];
                }
                else {
                    x1 = base - 2;
                    y1 = 1;
                }
                c1 = (x1 + y1 + z1) / base;
                x2 = base - 1;
                y2 = b62[n[2]];
                z2 = D(b62[n[4]] - x2 - y2 - c1, base);
                c2 = (x2 + y2 + z2 + c1 - b62[n[4]]) / base;
                x3 = ((base + b62[n[3]] - c2 - z1) >> 1);
                y3 = base + b62[n[3]] - c2 - z1 - x3;

                pal1[0] = rb62[x1];
                pal1[1] = rb62[x2];
                pal1[2] = rb62[x3];
                pal1[3] = rb62[x2];
                pal1[4] = rb62[x1];
                pal1[5] = '\0';
                pal2[0] = rb62[y1];
                pal2[1] = rb62[y2];
                pal2[2] = rb62[y3];
                pal2[3] = rb62[y2];
                pal2[4] = rb62[y1];
                pal2[5] = '\0';
                pal3[0] = rb62[z1];
                pal3[1] = rb62[z2];
                pal3[2] = rb62[z1];
                pal3[3] = '\0';
            }
            else if (D(b62[n[5]] - b62[n[1]] + 2, base) == 0 && b62[n[3]]) {
                if (b62[n[1]]) {
                    x1 = base - 1;
                    y1 = b62[n[1]];
                }
                else {
                    x1 = base - 2;
                    y1 = 1;
                }
                z1 = base - 1;
                c1 = (x1 + y1 + z1 - b62[n[5]]) / base;
                x2 = base - 1;
                y2 = b62[n[2]];
                z2 = D(b62[n[4]] - x2 - y2 - c1, base);
                c2 = (x2 + y2 + z2 + c1 - b62[n[4]]) / base;
                x3 = ((base + b62[n[3]] - c2 - z1) >> 1);
                y3 = base + b62[n[3]] - c2 - z1 - x3;

                pal1[0] = rb62[x1];
                pal1[1] = rb62[x2];
                pal1[2] = rb62[x3];
                pal1[3] = rb62[x2];
                pal1[4] = rb62[x1];
                pal1[5] = '\0';
                pal2[0] = rb62[y1];
                pal2[1] = rb62[y2];
                pal2[2] = rb62[y3];
                pal2[3] = rb62[y2];
                pal2[4] = rb62[y1];
                pal2[5] = '\0';
                pal3[0] = rb62[z1];
                pal3[1] = rb62[z2];
                pal3[2] = rb62[z1];
                pal3[3] = '\0';
            }
            else if (D(b62[n[5]] - b62[n[1]] + 2, base) == 0 && b62[n[3]] == 0) {
                if (b62[n[1]] >= 3) {
                    c4 = (D(b62[n[2]] - 1, base) + 1 - b62[n[2]]) / base;
                    z2 = D(b62[n[4]] - b62[n[2]] - 1 + c4, base);
                    c2 = (2 - c4 + D(b62[n[2]] - 1, base) + z2 - b62[n[4]]) / base;

                    pal1[0] = '1';
                    pal1[1] = rb62[1 - c4];
                    pal1[2] = '0';
                    pal1[3] = '0';
                    pal1[4] = rb62[1 - c4];
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = rb62[b62[n[1]] - 1];
                    pal2[1] = rb62[D(b62[n[2]] - 1, base)];
                    pal2[2] = rb62[2 - c2];
                    pal2[3] = rb62[D(b62[n[2]] - 1, base)];
                    pal2[4] = rb62[b62[n[1]] - 1];
                    pal2[5] = '\0';
                    pal3[0] = rb62[base - 2];
                    pal3[1] = rb62[z2];
                    pal3[2] = rb62[base - 2];
                    pal3[3] = '\0';
                }
                else if (b62[n[1]] == 2) {
                    x2 = b62[n[2]];
                    y2 = 0;
                    z2 = D(b62[n[4]] - x2 - y2 - 2, base);
                    c2 = (x2 + y2 + z2 + 2 - b62[n[4]]) /  base;
                    if (c2 == 2) {
                        pal1[0] = '1';
                        pal1[1] = '2';
                        pal1[2] = rb62[base - 2];
                        pal1[3] = rb62[base - 2];
                        pal1[4] = '2';
                        pal1[5] = '1';
                        pal1[6] = '\0';
                        pal2[0] = '1';
                        pal2[1] = rb62[base - 3];
                        pal2[2] = '1';
                        pal2[3] = '\0';
                        pal3[0] = rb62[base - 2];
                        pal3[1] = '\0';
                    }
                    else {
                        x3 = (base - c2 - z2) >> 1;
                        y3 = base - c2 - z2 - x3;

                        pal1[0] = rb62[base - 1];
                        pal1[1] = rb62[x2];
                        pal1[2] = rb62[x3];
                        pal1[3] = rb62[x2];
                        pal1[4] = rb62[base - 1];
                        pal1[5] = '\0';
                        pal2[0] = '2';
                        pal2[1] = rb62[y2];
                        pal2[2] = rb62[y3];
                        pal2[3] = rb62[y2];
                        pal2[4] = '2';
                        pal2[5] = '\0';
                        pal3[0] = rb62[base - 1];
                        pal3[1] = rb62[z2];
                        pal3[2] = rb62[z2];
                        pal3[3] = rb62[base - 1];
                        pal3[4] = '\0';
                    }
                }
                else {
                    if (b62[n[1]]) {
                        pal1[0] = rb62[base - 1];
                        pal1[4] = rb62[base - 1];
                    }
                    else {
                        pal1[0] = rb62[base - 2];
                        pal1[4] = rb62[base - 2];
                    }
                    x2 = b62[n[2]];
                    y2 = 0;
                    z2 = D(b62[n[4]] - x2 - y2 - 1, base);
                    c2 = (x2 + y2 + z2 + 1 - b62[n[4]]) / base;
                    x3 = (base - c2 - z2) >> 1;
                    y3 = base - c2 - z2 - x3;

                    pal1[1] = rb62[x2];
                    pal1[2] = rb62[x3];
                    pal1[3] = rb62[x2];
                    pal1[5] = '\0';
                    pal2[0] = '1';
                    pal2[1] = rb62[y2];
                    pal2[2] = rb62[y3];
                    pal2[3] = rb62[y2];
                    pal2[4] = '1';
                    pal2[5] = '\0';
                    pal3[0] = rb62[base - 1];
                    pal3[1] = rb62[z2];
                    pal3[2] = rb62[z2];
                    pal3[3] = rb62[base - 1];
                    pal3[4] = '\0';
                }
            }
            else {
                if (b62[n[1]] == base - 1) {
                    pal1[0] = '1';
                    pal1[5] = '1';
                    pal1[6] = '\0';
                    pal2[0] = rb62[base - 4];
                    pal2[4] = rb62[base - 4];
                    pal2[5] = '\0';
                    pal3[0] = '1';
                    pal3[2] = '1';
                    pal3[3] = '\0';

                    x2 = 1;
                    y2 = 1;
                    z2 = D(b62[n[4]] - 3 - y2, base);
                    while (D(x2 + y2, base) != b62[n[2]] || (z2 == base - 1 || z2 == base - 2)) {
                        if (x2 < base - 1) x2++;
                        else {
                            y2++;
                            x2 = 1;
                        }
                        z2 = D(b62[n[4]] - 3 - y2, base);
                    }
                    c1 = (3 + y2 + z2 - b62[n[4]]) / base;
                    c4 = 0;
                    c2 = (x2 + D(b62[n[3]] - x2 - 1 - c1 + c4, base) + c1 + 1 - b62[n[3]]) / base;
                    if (c2 >= 2) {
                        c4 = 1;
                        c2 = (x2 + D(b62[n[3]] - x2 - 1 - c1 + c4, base) + c1 + 1 - b62[n[3]]) / base;
                    }
                    c3 = (x2 + D(y2 - c2, base) + c2 - b62[n[2]]) / base;

                    pal1[1] = rb62[3 - c3];
                    pal1[2] = rb62[x2 - c4];
                    pal1[3] = rb62[x2 - c4];
                    pal1[4] = rb62[3 - c3];
                    pal2[1] = rb62[y2 - c2 + c4];
                    pal2[2] = rb62[D(b62[n[3]] - x2 - 1 - c1 + c4, base)];
                    pal2[3] = rb62[y2 - c2 + c4];
                    pal3[1] = rb62[z2 + c2 - c4 + c3];
                }
                else {
                    x1 = base - 1;
                    y1 = b62[n[1]] + 1;
                    z1 = base - 1;
                    c1 = (x1 + y1 + z1) / base;
                    x2 = b62[n[2]] - 1;
                    y2 = 0;
                    z2 = D(b62[n[4]] - x2 - y2 - c1, base);
                    c2 = (x2 + y2 + z2 + c1 - b62[n[4]]) / base;
                    x3 = ((1 + b62[n[3]] - c2) >> 1);
                    y3 = (1 + b62[n[3]] - c2) - x3;

                    pal1[0] = rb62[x1];
                    pal1[1] = rb62[x2];
                    pal1[2] = rb62[x3];
                    pal1[3] = rb62[x2];
                    pal1[4] = rb62[x1];
                    pal1[5] = '\0';
                    pal2[0] = rb62[y1];
                    pal2[1] = rb62[y2];
                    pal2[2] = rb62[y3];
                    pal2[3] = rb62[y2];
                    pal2[4] = rb62[y1];
                    pal2[5] = '\0';
                    pal3[0] = rb62[z1];
                    pal3[1] = rb62[z2];
                    pal3[2] = rb62[z1];
                    pal3[3] = '\0';
                }
            }
        }
    }
    else {
        if (b62[n[1]] > 2) {
            x1 = b62[n[0]];
            if (D(b62[n[5]] - b62[n[0]] - b62[n[1]] + 1, base)) {
                y1 = b62[n[1]] - 1;
                z1 = D(b62[n[5]] - b62[n[0]] - b62[n[1]] + 1, base);
            }
            else {
                y1 = b62[n[1]] - 2;
                z1 =1;
            }
        }
        else {
            x1 = b62[n[0]] - 1;
            if (D(b62[n[5]] - b62[n[0]] + 2, base)) {
                y1 = base - 1;
                z1 = D(b62[n[5]] - b62[n[0]] + 2, base);
            }
            else {
                y1 = base - 2;
                z1 = 1;
            }
        }
        c1 = (x1 + y1 + z1) / base;
        if (z1 < b62[n[2]]) x2 = D(b62[n[1]] - y1, base);
        else x2 = D(b62[n[1]] - y1 - 1, base);
        y2 = D(b62[n[2]] - z1 - 1, base);
        z2 = D(b62[n[4]] - x2 - y2 - c1, base);
        c2 = (x2 + y2 + z2 + c1 - b62[n[4]]) / base;
        y3 = D(b62[n[3]] - z2 - c2, base);
        c3 = (y3 + z2 + c2 - b62[n[3]]) / base;

        pal1[0] = rb62[x1];
        pal1[1] = rb62[x2];
        pal1[2] = '0';
        pal1[3] = '0';
        pal1[4] = rb62[x2];
        pal1[5] = rb62[x1];
        pal1[6] = '\0';
        pal2[0] = rb62[y1];
        pal2[1] = rb62[y2];
        pal2[2] = rb62[y3];
        pal2[3] = rb62[y2];
        pal2[4] = rb62[y1];
        pal2[5] = '\0';
        pal3[0] = rb62[z1];
        pal3[1] = rb62[z2];
        pal3[2] = rb62[z2];
        pal3[3] = rb62[z1];
        pal3[4] = '\0';

        if (c3 == 0) {
            if (y3 == 0) {
                if (y2 == 0 && z2 == 0) {
                    if (z2 == 0) {
                        if (x2 == 0) {
                            if (x1 == 1) {
                                pal1[0] = '2';
                                for (int i = 1; i <= 4; i++) pal1[i] = '0';
                                pal1[5] = '2';
                                pal2[0] = '1';
                                pal2[1] = '1';
                                pal2[2] = '\0';
                                pal3[0] = rb62[base - 4];
                                pal3[1] = '\0';
                            }
                            else if (y1 == base - 1) {
                                pal1[0] = rb62[b62[pal1[0]] + 1];
                                for (int i = 1; i <= 4; i++) pal1[i] = '0';
                                pal1[5] = rb62[b62[pal1[5]] + 1];
                                pal2[0] = '1';
                                pal2[1] = '1';
                                pal2[2] = '\0';
                                pal3[0] = rb62[base - 4];
                                pal3[1] = '\0';
                            }
                            else {
                                pal1[0] = rb62[b62[pal1[0]] - 1];
                                pal1[1] = rb62[base - 1];
                                pal1[2] = '0';
                                pal1[3] = '0';
                                pal1[4] = rb62[base - 1];
                                pal1[5] = rb62[b62[pal1[5]] - 1];
                                pal2[0] = rb62[b62[pal2[0]] + 1];
                                pal2[1] = '0';
                                pal2[2] = rb62[base - 2];
                                pal2[3] = '0';
                                pal2[4] = rb62[b62[pal2[4]] + 1];
                                pal3[1] = '1';
                                pal3[2] = '1';
                            }
                        }
                        else {
                            pal1[1] = rb62[b62[pal1[1]] - 1];
                            pal1[2] = rb62[base - 1];
                            pal1[3] = rb62[base - 1];
                            pal1[4] = pal1[1];
                            pal2[1] = '1';
                            pal2[2] = '1';
                            pal2[3] = '1';
                            pal3[1] = '0';
                            pal3[2] = '0';
                        }
                    }
                    else {
                        pal1[1] = rb62[b62[pal1[1]] - 1];
                        pal1[2] = '1';
                        pal1[3] = '1';
                        pal1[4] = rb62[b62[pal1[4]] - 1];
                        pal2[1] = rb62[base - 1];
                        pal2[2] = rb62[base - 4];
                        pal2[3] = rb62[base - 1];
                        pal3[1] = '2';
                        pal3[2] = '2';
                    }
                }
                else if (y2 == 0) {
                    pal2[1] = '1';
                    pal2[2] = '1';
                    pal2[3] = '1';
                    pal3[1] = rb62[b62[pal3[1]] - 1];
                    pal3[2] = rb62[b62[pal3[2]] - 1];
                }
                else {
                    pal1[2] = '1';
                    pal1[3] = '1';
                    pal2[1] = rb62[b62[pal2[1]] - 1];
                    pal2[2] = rb62[base - 2];
                    pal2[3] = rb62[b62[pal2[3]] - 1];
                    pal3[1] = rb62[b62[pal3[1]] + 1];
                    pal3[2] = rb62[b62[pal3[2]] + 1];
                }
            }
            else {
                pal1[2] = '1';
                pal1[3] = '1';
                pal2[2] = rb62[b62[pal2[2]] - 1];
            }
        }
        else if (c3 == 2) {
            pal1[2] = '1';
            pal1[3] = '1';
            pal2[1] = rb62[b62[pal2[1]] - 1];
            pal2[2] = rb62[base - 2];
            pal2[3] = rb62[b62[pal2[3]] - 1];
            pal3[1] = '0';
            pal3[2] = '0';
        }

    }
}

void casesmall(int len, int base, char* n) {
    long long t = 0, t1, tmp, pal;
    for (int i = 0; i < len; i++) {
        t += b62[n[i]] * multiplied[base][len - i - 1];
    }
    switch (len) {
    case 6:
        casesmall_6(len, base, n);
        return;
    case 5:
    case 4:
        t1 = t / multiplied[base][2];
        pal = makepal(t1, base, len);
        if (t < pal || (t - pal) % base + 1 == (t - pal) / base) {
            t1--;
            pal = makepal(t1, base, len);
            if ((t - pal) % base + 1 == (t - pal) / base) {
                t1--;
                pal = makepal(t1, base, len);
            }
        }
        if (pal < multiplied[base][len - 1]) {
            for (int i = 0; i < len - 1; i++) {
                pal1[i] = rb62[base - 1];
            }
            pal1[len - 1] = '\0';
        }
        else {
            for (int i = 0; i < len; i++) {
                pal1[i] = rb62[pal / multiplied[base][i] % base];
            }
        }
        pal1[len] = '\0';
        t -= pal;
        break;
    case 3:
    case 2:
        t1 = t / base;
        pal = makepal(t1, base, len);
        if (t < pal) {
            t1--;
            pal = makepal(t1, base, len);
        }
        if (pal < multiplied[base][len - 1]) {
            for (int i = 0; i < len - 1; i++) {
                pal1[i] = rb62[base - 1];
            }
            pal1[len - 1] = '\0';
        }
        else {
            for (int i = 0; i < len; i++) {
                pal1[i] = rb62[pal / multiplied[base][i] % base];
            }
        }
        pal1[len] = '\0';
        t -= pal;
        break;
    case 1:
        pal1[0] = rb62[t];
        pal1[1] = '\0';
        t = 0;
        break;
    }

    if (t >= base) {
        t1 = t / base;
        len = 2 + (t1 >= base);
        pal = makepal(t1, base, len);
        if (t < pal) {
            t1--;
            pal = makepal(t1, base, len);
        }
        if (pal < multiplied[base][len - 1]) {
            for (int i = 0; i < len - 1; i++) {
                pal2[i] = rb62[base - 1];
            }
            pal2[len - 1] = '\0';
        }
        else {
            for (int i = 0; i < len; i++) {
                pal2[i] = rb62[pal / multiplied[base][i] % base];
            }
        }
        pal2[len] = '\0';
        t -= pal;
    }
    else {
        pal2[0] = rb62[t];
        pal2[1] = '\0';
        t = 0;
    }

    pal3[0] = rb62[t];
    pal3[1] = '\0';
}

void setdigits(int len, int opi, int mode, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    pal1[opi + mode] = rb62[xi];
    pal2[opi] = rb62[yi];
    pal3[opi] = rb62[zi];
    pal1[len - 1 - offsetx - opi] = rb62[xi];
    pal2[len - 1 - offsety - opi] = rb62[yi];
    pal3[len - 1 - offsetz - opi] = rb62[zi];
}

void algorithm1(int len, int base, char* n, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    int opi = 0, ci = (xi + yi + zi) / base;
    pal1[len - offsetx] = '\0';
    pal2[len - offsety] = '\0';
    pal3[len - offsetz] = '\0';
    setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
    opi++;

    if (zi < b62[n[2 + offsetx]]) xi = D(b62[n[1 + offsetx]] - yi, base);
    else xi = D(b62[n[1 + offsetx]] - yi - 1, base);
    yi = D(b62[n[2 + offsetx]] - zi - 1, base);
    zi = D(b62[n[len - 2]] - xi - yi - ci, base);
    ci = (xi + yi + zi + ci - b62[n[len - 2]]) / base;
    setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
    opi++;

    while (opi < ((len - 1) >> 1)) {
        if (zi < b62[n[opi + offsetx + 1]]) xi = 1;
        else xi = 0;
        yi = D(b62[n[opi + offsetx + 1]] - zi - 1, base);
        zi = D(b62[n[len - opi - 1]] - xi - yi - ci, base);
        ci = (xi + yi + zi + ci - b62[n[len - opi - 1]]) / base;
        setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
        opi++;
    }

    pal1[((len - 1) >> 1)] = '0';
    if (ci == 0) pal1[((len - 1) >> 1)] = '1';
    else if (ci == 2) {
        pal1[((len - 1) >> 1)] = '1';
        pal2[((len - 1) >> 1) - 1] = rb62[b62[pal2[((len - 1) >> 1) - 1]] - 1];
        pal2[((len - 1) >> 1)] = rb62[b62[pal2[((len - 1) >> 1)]] - 1];
        pal3[((len - 1) >> 1) - 1] = '0';
    }
}

void algorithm2(int len, int base, char* n, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    int opi = 0, ci = (xi + yi + zi) / base, cl;
    pal1[len - offsetx] = '\0';
    pal2[len - offsety] = '\0';
    pal3[len - offsetz] = '\0';
    setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
    opi++;

    if (zi < b62[n[2 + offsetx]]) xi = D(b62[n[1 + offsetx]] - yi, base);
    else xi = D(b62[n[1 + offsetx]] - yi - 1, base);
    yi = D(b62[n[2 + offsetx]] - zi - 1, base);
    zi = D(b62[n[len - 2]] - xi - yi - ci, base);
    ci = (xi + yi + zi + ci - b62[n[len - 2]]) / base;
    setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
    opi++;

    while (opi < ((len - 2) >> 1)) {
        if (zi < b62[n[opi + offsetx + 1]]) xi = 1;
        else xi = 0;
        yi = D(b62[n[opi + offsetx + 1]] - zi - 1, base);
        zi = D(b62[n[len - opi - 1]] - xi - yi - ci, base);
        ci = (xi + yi + zi + ci - b62[n[len - opi - 1]]) / base;
        setdigits(len, opi, 0, xi, yi, zi, offsetx, offsety, offsetz);
        opi++;
    }

    pal1[((len - 2) >> 1)] = '0';
    pal1[((len - 2) >> 1) + 1] = '0';
    pal2[((len - 2) >> 1)] = rb62[D(b62[n[opi + offsetx + 1]] - zi - ci, base)];
    cl = (b62[pal2[((len - 2) >> 1)]] + zi + ci - b62[n[len - opi - 1]]) / base;
    if (cl == 0) {
        if (pal2[((len - 2) >> 1)] == '0') {
            if (yi == 0) {
                if (zi == 0) {
                    pal1[((len - 2) >> 1) - 1] = rb62[b62[pal1[((len - 2) >> 1) - 1]] - 1];
                    pal1[((len - 2) >> 1)] = '1';
                    pal1[((len - 2) >> 1) + 1] = '1';
                    pal1[((len - 2) >> 1) + 2] = rb62[b62[pal1[((len - 2) >> 1) + 2]] - 1];
                    pal2[((len - 2) >> 1) - 1] = rb62[base - 1];
                    pal2[((len - 2) >> 1)] = rb62[base - 4];
                    pal2[((len - 2) >> 1) + 1] = rb62[base - 1];
                    pal3[((len - 2) >> 1)] = '2';
                    pal3[((len - 2) >> 1) - 1] = '2';
                }
                else {
                    pal2[((len - 2) >> 1) - 1] = '1';
                    pal2[((len - 2) >> 1)] = '1';
                    pal2[((len - 2) >> 1) + 1] = '1';
                    pal3[((len - 2) >> 1)] = rb62[b62[pal3[((len - 2) >> 1)]] - 1];
                    pal3[((len - 2) >> 1) - 1] = rb62[b62[pal3[((len - 2) >> 1) - 1]] - 1];
                }
            }
            else {
                pal1[((len - 2) >> 1)] = '1';
                pal1[((len - 2) >> 1) + 1] = '1';
                pal2[((len - 2) >> 1) - 1] = rb62[b62[pal2[((len - 2) >> 1) - 1]] - 1];
                pal2[((len - 2) >> 1)] = rb62[base - 2];
                pal2[((len - 2) >> 1) + 1] = rb62[b62[pal2[((len - 2) >> 1) + 1]] - 1];
                pal3[((len - 2) >> 1)] = rb62[b62[pal3[((len - 2) >> 1)]] + 1];
                pal3[((len - 2) >> 1) - 1] = rb62[b62[pal3[((len - 2) >> 1) - 1]] + 1];
            }
        }
        else {
            pal1[((len - 2) >> 1)] = '1';
            pal1[((len - 2) >> 1) + 1] = '1';
            pal2[((len - 2) >> 1)] = rb62[b62[pal2[((len - 2) >> 1)]] - 1];;
        }
    }
    else if (cl == 2) {
        pal1[((len - 2) >> 1)] = '1';
        pal1[((len - 2) >> 1) + 1] = '1';
        pal2[((len - 2) >> 1) - 1] = rb62[b62[pal2[((len - 2) >> 1) - 1]] - 1];
        pal2[((len - 2) >> 1)] = rb62[base - 2];
        pal2[((len - 2) >> 1) + 1] = rb62[b62[pal2[((len - 2) >> 1) + 1]] - 1];
        pal3[((len - 2) >> 1) - 1] = '0';
        pal3[((len - 2) >> 1)] = '0';
    }
}

void algorithm3(int len, int base, char* n, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    int opi = 0, ci = (1 + yi + zi) / base, y1 = yi, zl = zi, cl;
    setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
    pal1[0] = '1';
    pal1[len - 1] = '1';
    pal1[len] = '\0';
    pal2[len - 2] = '\0';
    pal3[len - 3] = '\0';
    opi++;

    yi = D(b62[n[3]] - zi - 1, base);
    zi = D(b62[n[len - 2]] - xi - yi - ci, base);
    ci = (xi + yi + zi + ci - b62[n[len - 2]]) / base;
    if (zl < b62[n[3]]) xi = D(b62[n[2]] - y1, base);
    else xi = D(b62[n[2]] - y1 - 1, base);
    setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
    zl = zi;
    opi++;

    while (opi < (len >> 1) - 1) {
        yi = D(b62[n[opi + 2]] - zi - 1, base);
        zi = D(b62[n[len - opi - 1]] - xi - yi - ci, base);
        ci = (xi + yi + zi + ci - b62[n[len - opi - 1]]) / base;
        if (zl < b62[n[opi + 2]]) xi = 1;
        else xi = 0;
        setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
        zl = zi;
        opi++;
    }

    pal1[len >> 1] = '0';
    pal2[(len >> 1) - 1] = rb62[D(b62[n[(len >> 1) + 1]] - zi - xi - ci, base)];
    cl = (xi + zi + b62[pal2[(len >> 1) - 1]] + ci - b62[n[len - opi - 1]]) / base;
    if (cl == 0) pal1[len >> 1] = '1';
    else if (cl == 2) {
        if (yi == 0) {
            if (zi == base - 1) {
                pal1[(len >> 1) - 1] = rb62[b62[pal1[(len >> 1) - 1]] - 1];
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 2] = '0';
                pal3[(len >> 1) - 1] = '0';
            }
            else {
                pal1[(len >> 1) - 1] = rb62[b62[pal1[(len >> 1) - 1]] - 1];
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] + 1];
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
        else {
            if (zi == base - 1) {
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 2] = '0';
                pal3[(len >> 1) - 1] = '0';
            }
            else {
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] + 1];
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
    }
}

void algorithm4(int len, int base, char* n, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    int opi = 0, ci = (1 + yi + zi) / base, y1 = yi, zl = zi, cl;
    setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
    pal1[0] = '1';
    pal1[len - 1] = '1';
    pal1[len] = '\0';
    pal2[len - 2] = '\0';
    pal3[len - 3] = '\0';
    opi++;

    yi = D(b62[n[3]] - zi - 1, base);
    zi = D(b62[n[len - 2]] - xi - yi - ci, base);
    ci = (xi + yi + zi + ci - b62[n[len - 2]]) / base;
    if (zl < b62[n[3]]) xi = D(b62[n[2]] - y1, base);
    else xi = D(b62[n[2]] - y1 - 1, base);
    setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
    zl = zi;
    opi++;

    while (opi < (len >> 1) - 1) {
        yi = D(b62[n[opi + 2]] - zi - 1, base);
        zi = D(b62[n[len - opi - 1]] - xi - yi - ci, base);
        ci = (xi + yi + zi + ci - b62[n[len - opi - 1]]) / base;
        if (zl < b62[n[opi + 2]]) xi = 1;
        else xi = 0;
        setdigits(len, opi, 1, xi, yi, zi, offsetx, offsety, offsetz);
        zl = zi;
        opi++;
    }

    pal1[(len >> 1) - 1] = rb62[xi];
    pal1[len >> 1] = rb62[xi];
    pal2[(len >> 1) - 2] = rb62[yi];
    pal2[(len >> 1) - 1] = rb62[yi];
    pal3[(len >> 1) - 2] = rb62[zi];
    if (xi + ci == 0 && yi != base - 1) {
        if (zi == 0 && b62[pal2[(len >> 1)]] == 0) {
            if (b62[pal3[(len >> 1) - 1]] == base - 1 && yi == 1) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = '0';
                pal3[(len >> 1) - 2] = '3';
                pal3[(len >> 1) - 1] = '0';
            }
            else if (b62[pal3[(len >> 1) - 1]] == base - 1) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '2';
                pal1[len >> 1] = '2';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = '0';
                pal3[(len >> 1) - 2] = '3';
                pal3[(len >> 1) - 1] = '0';
            }
            else {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
        else if (zi == 0) {
            if (yi == 1) {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = '0';
                pal3[(len >> 1) - 2] = '3';
                pal3[(len >> 1) - 1] = '0';
            }
            else if (b62[pal3[(len >> 1) - 1]] == base - 1) {
                pal1[(len >> 1) - 1] = '2';
                pal1[len >> 1] = '2';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = '0';
                pal3[(len >> 1) - 2] = '3';
                pal3[(len >> 1) - 1] = '0';
            }
            else {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
        else {
            pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] + 1];
            pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] + 1];
            pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] - 1];
        }
    }
    else if (xi + ci == 0) {
        pal1[(len >> 1) - 1] = '1';
        pal1[len >> 1] = '1';
        pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
        pal2[(len >> 1) - 2] = rb62[base - 2];
        pal2[(len >> 1) - 1] = rb62[base - 2];
        pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
        pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
        pal3[(len >> 1) - 2] = '1';
        pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
    }
    else if (xi + ci == 2 && xi == 0) {
        if (zi == base - 1 && b62[pal3[(len >> 1) - 1]] == base - 1) {
            if (yi == base - 1 || yi == base - 2) {
                if (b62[pal2[(len >> 1)]] == 0) {
                    pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                    pal1[(len >> 1) - 1] = '2';
                    pal1[len >> 1] = '2';
                    pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                    pal2[(len >> 1) - 3] = rb62[base - 1];
                    pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 3];
                    pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 3];
                    pal2[(len >> 1)] = rb62[base - 1];
                    pal3[(len >> 1) - 3] = '0';
                    pal3[(len >> 1) - 2] = '3';
                    pal3[(len >> 1) - 1] = '0';
                }
                else {
                    pal1[(len >> 1) - 1] = '2';
                    pal1[len >> 1] = '2';
                    pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                    pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 3];
                    pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 3];
                    pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                    pal3[(len >> 1) - 3] = '0';
                    pal3[(len >> 1) - 2] = '3';
                    pal3[(len >> 1) - 1] = '0';
                }
            }
            else {
                if (b62[pal2[(len >> 1)]] == base - 1) {
                    pal1[(len >> 1) - 1] = rb62[base - 2];
                    pal1[len >> 1] = rb62[base - 2];
                    pal2[(len >> 1) - 3] = '0';
                    pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] + 2];
                    pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] + 2];
                    pal2[(len >> 1)] = '0';
                    pal3[(len >> 1) - 3] = rb62[base - 2];
                    pal3[(len >> 1) - 2] = rb62[base - 2];
                    pal3[(len >> 1) - 1] = rb62[base - 2];
                }
                else {
                    pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                    pal1[(len >> 1) - 1] = rb62[base - 2];
                    pal1[len >> 1] = rb62[base - 2];
                    pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                    pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] + 1];
                    pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] + 2];
                    pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] + 2];
                    pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] + 1];
                    pal3[(len >> 1) - 3] = rb62[base - 2];
                    pal3[(len >> 1) - 2] = rb62[base - 2];
                    pal3[(len >> 1) - 1] = rb62[base - 2];
                }
            }
        }
        else if (zi == base - 1) {
            if (b62[pal2[(len >> 1)]] == 0) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
            else {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
        else {
            pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
            pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
            pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] + 1];
        }
    }
    else if (xi + ci == 2 && xi == 1) {
        if (yi == 0 && zi != base - 1) {
            pal1[(len >> 1) - 1] = '0';
            pal1[len >> 1] = '0';
            pal2[(len >> 1) - 2] = rb62[base - 1];
            pal2[(len >> 1) - 1] = rb62[base - 1];
            pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] + 1];
        }
        else if (yi != 0 && zi != base - 1) {
            pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
            pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
            pal3[(len >> 1) - 2] = rb62[b62[pal3[(len >> 1) - 2]] + 1];
        }
        else if (b62[pal3[(len >> 1) - 1]] != 0) {
            if (b62[pal2[(len >> 1)]] != base - 1) {
                pal1[(len >> 1) - 1] = '0';
                pal1[len >> 1] = '0';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] + 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] + 1];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] + 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] + 1];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 1]] - 1];
                pal3[(len >> 1) - 2] = rb62[base - 2];
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] - 1];
            }
            else if (yi >= 2) {
                pal1[(len >> 1) - 1] = '2';
                pal1[len >> 1] = '2';
                pal2[(len >> 1) - 3] = rb62[base - 2];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[base - 2];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
            else if (yi == 0) {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[base - 2];
                pal2[(len >> 1) - 2] = rb62[base - 2];
                pal2[(len >> 1) - 1] = rb62[base - 2];
                pal2[(len >> 1)] = rb62[base - 2];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
            else if (yi == 1) {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[base - 2];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[base - 2];
                pal3[(len >> 1) - 3] = rb62[b62[pal3[(len >> 1) - 3]] + 1];
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = rb62[b62[pal3[(len >> 1) - 1]] + 1];
            }
        }
        else if (b62[pal2[(len >> 1)]] == 0) {
            if (yi >= 2) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '2';
                pal1[len >> 1] = '2';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
            else if (yi == 0) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[base - 2];
                pal2[(len >> 1) - 1] = rb62[base - 2];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
            else if (yi == 1) {
                pal1[(len >> 1) - 2] = rb62[b62[pal1[(len >> 1) - 2]] - 1];
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal1[(len >> 1) + 1] = rb62[b62[pal1[(len >> 1) + 1]] - 1];
                pal2[(len >> 1) - 3] = rb62[base - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[base - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
        }
        else {
            if (yi >= 2) {
                pal1[(len >> 1) - 1] = '2';
                pal1[len >> 1] = '2';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 2];
                pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 2];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
            else if (yi == 0) {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[base - 2];
                pal2[(len >> 1) - 1] = rb62[base - 2];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
            else if (yi == 1) {
                pal1[(len >> 1) - 1] = '1';
                pal1[len >> 1] = '1';
                pal2[(len >> 1) - 3] = rb62[b62[pal2[(len >> 1) - 3]] - 1];
                pal2[(len >> 1) - 2] = rb62[base - 1];
                pal2[(len >> 1) - 1] = rb62[base - 1];
                pal2[(len >> 1)] = rb62[b62[pal2[(len >> 1)]] - 1];
                pal3[(len >> 1) - 3] = '1';
                pal3[(len >> 1) - 2] = '1';
                pal3[(len >> 1) - 1] = '1';
            }
            
        }
    }
    else if (xi + ci == 3) {
        pal2[(len >> 1) - 2] = rb62[b62[pal2[(len >> 1) - 2]] - 1];
        pal2[(len >> 1) - 1] = rb62[b62[pal2[(len >> 1) - 1]] - 1];
        pal3[(len >> 1) - 2] = '0';
    }

}

void nminus(int len, int base, char* np) {
    int m = 0, d;
    if (np[(len + 1) >> 1] == '0') {
        np[(len + 1) >> 1] = rb62[base - 1];
        m = 1;
    }
    else np[(len + 1) >> 1] = rb62[b62[np[(len + 1) >> 1]] - 1];
    if (b62[np[(len - 1) >> 1]] < m + 1) {
        np[(len - 1) >> 1] = rb62[D(b62[np[(len - 1) >> 1]] - (m + 1), base)];
        m = 1;
    }
    else {
        np[(len - 1) >> 1] = rb62[b62[np[(len - 1) >> 1]] - (m + 1)];
        m = 0;
    }

    d = ((len - 1) >> 1) - 1;
    while (m) {
        if (b62[np[d]] < m) {
            np[d] = rb62[D(b62[np[d]] - m, base)];
            m = 1;
        }
        else {
            np[d] = rb62[b62[np[d]] - m];
            m = 0;
        }
        d--;
    }

}

void shortennum(int len, int base, char* np) {
    for (int i = 1; i < len; i++) {
        np[i - 1] = np[i];
    }
    np[len - 1] = '\0';
}

void algorithm5(int len, int base, char* n, int xi, int yi, int zi, int offsetx, int offsety, int offsetz) {
    int shortened = 0, reduced = 1, casenum;
    char* np = malloc(sizeof(char) * (len + 100));
    strcpy(np, n);
    nminus(len, base, np);
    if (np[0] == '0') {
        shortennum(len, base, np);
        len--;
        shortened = 1;
    }
    if (np[(len - 1) >> 1] == '0' || np[(len + 1) >> 1] == '0') {
        reduced++;
        nminus(len, base, np);
        if (np[0] == '0') {
            shortennum(len, base, np);
            len--;
            shortened = 1;
        }
    }

    casenum = getcase(len, base, np);
    getalgorithm(casenum, len, base, np);
    if (strlen(pal1) & 1) {
        if (D(b62[np[len - 1]] - b62[np[2]], base)) casenum = 11;
        else casenum = 12;
        getalgorithm(casenum, len, base, np);
    }
    innercase = casenum;
    
    if (casenum == 5 || casenum == 6) {
        pal1[(len - 1) >> 1] = rb62[b62[pal1[(len - 1) >> 1]] + reduced];
        pal1[(len - 3) >> 1] = rb62[b62[pal1[(len - 3) >> 1]] + reduced];
    }
    else {
        pal1[(len - 1) >> 1] = rb62[b62[pal1[(len - 1) >> 1]] + reduced];
        pal1[(len + 1) >> 1] = rb62[b62[pal1[(len + 1) >> 1]] + reduced];
    }

    free(np);
}

void getalgorithm(int casenum, int len, int base, char* n) {
    int xi = 0, yi = 0, zi = 0, offsetx, offsety, offsetz;
    if (casenum == 0) {
        casesmall(len, base, n);
    }
    else if (casenum < 10) {
        if (casenum <= 4) {
            switch (casenum) {
            case 1:
                xi = b62[n[0]];
                yi = b62[n[1]] - 1;
                zi = D(b62[n[len - 1]] - b62[n[0]] - b62[n[1]] + 1, base);
                break;
            case 2:
                xi = b62[n[0]];
                yi = b62[n[1]] - 2;
                zi = 1;
                break;
            case 3:
                xi = b62[n[0]] - 1;
                yi = base - 1;
                zi = D(b62[n[len - 1]] - b62[n[0]] + 2, base);
                break;
            case 4:
                xi = b62[n[0]] - 1;
                yi = base - 2;
                zi = 1;
                break;
            }
            offsetx = 0;
            offsety = 1;
            offsetz = 2;

            if (len & 1) algorithm1(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
            else algorithm2(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
        }
        else {
            switch (casenum) {
            case 5:
                xi = base - 1;
                yi = b62[n[2]] + 1;
                zi = D(b62[n[len - 1]] - b62[n[2]], base);
                break;
            case 6:
                xi = base - 1;
                yi = b62[n[2]] + 2;
                zi = base - 1;
                break;
            }
            offsetx = 1;
            offsety = 2;
            offsetz = 3;

            if (len & 1) algorithm2(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
            else algorithm1(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
        }
    }
    else if (casenum < 20) {
        switch (casenum) {
        case 11:
            xi = b62[n[1]];
            yi = b62[n[2]] - 1;
            zi = D(b62[n[len - 1]] - b62[n[2]], base);
            break;
        case 12:
            xi = b62[n[1]];
            yi = b62[n[2]] - 2;
            zi = 1;
            break;
        case 13:
            xi = b62[n[1]] - 1;
            yi = base - 2;
            zi = 1;
            break;
        case 14:
            xi = b62[n[1]];
            yi = 1;
            zi = base - 2;
            break;
        case 15:
            xi = b62[n[1]] - 1;
            yi = base - 1;
            zi = b62[n[len - 1]];
            break;
        case 16:
            xi = b62[n[1]];
            yi = 2;
            zi = D(b62[n[len - 1]] - 3, base);
            break;
        case 17:
            xi = b62[n[1]];
            yi = 1;
            zi = 1;
            break;
        }

        offsetx = 1;
        offsety = 2;
        offsetz = 3;
        if (len & 1) algorithm3(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
        else algorithm4(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
    }
    else if (casenum == 21) {
        offsetx = 1;
        offsety = 2;
        offsetz = 3;
        algorithm5(len, base, n, xi, yi, zi, offsetx, offsety, offsetz);
    }
    else {
        //while (1) 
    }
}

int main(void) {
    int t, base, len, casenum = 0;
    for (int i = 2; i <= 62; i++) {
        multiplied[i][0] = 1;
        for (int j = 1; j <= 31; j++) {
            multiplied[i][j] = multiplied[i][j - 1] * i;
        }
    }
    
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%s", &base, n);
        //scanf("%s%s%s", pal1, pal2, pal3);
        //if (n[0] == '0') return 1;
        len = strlen(n);
        if (len > 1000000) return 1;

        casenum = getcase(len, base, n);
        getalgorithm(casenum, len, base, n);
        /*
        if (casenum < 0) return -1;
        
        if (!finalcheck(len, base)) {
            //while (base > 10) tt = tt;
            return 1;
        }
        if ((pal1[0] == '0' && strlen(pal1) > 1) || (pal2[0] == '0' && strlen(pal2) > 1) ||
            (pal3[0] == '0' && strlen(pal3) > 1)) {
            return 1;
        }
        if (!ispal(pal1) || !ispal(pal2) || !ispal(pal3)) {
            return 1;
        }
        */

        printf("%s ", pal1);
        printf("%s ", pal2);
        printf("%s\n", pal3);
    }
    
    /*
    //작은 수에 대한 브루트 포스
    base = 5;
    for //(long long i = 1; i < multiplied[base][5]; i++) {
        (long long i = 762939453125; i; i++) {
        len = 1;
        for (int j = 1; j <= 31; j++) {
            if (i < multiplied[base][j]) {
                len = j;
                break;
            }
        }
        if (len & 1) continue;
        for (int j = 0; j <= len; j++) {
            pal1[j] = '4';
            pal2[j] = '4';
            pal3[j] = '4';
        }
        for (long long j = 0, k = i; j < len; j++) {
            n[len - j - 1] = rb62[k % base];
            k /= base;
            //if (j > len - 1) break;
            //n[j] = rb62[i / multiplied[base][len - j - 1] % base];
        }
        casenum = getcase(len, base, n);
        if (casenum < 20) continue;
        getalgorithm(casenum, len, base, n);

        if (!finalcheck(len, base)) {
            printf("Sum error at %lld: %s %s %s\n", i, pal1, pal2, pal3);
        }
        else if ((pal1[0] == '0' && strlen(pal1) > 1) || (pal2[0] == '0' && strlen(pal2) > 1) ||
            (pal3[0] == '0' && strlen(pal3) > 1)) {
            printf("Zero error at %lld: %s %s %s\n", i, pal1, pal2, pal3);
        }
        if (pal1[0] == '\0' || pal2[0] == '\0' || pal3[0] == '\0') {
            printf("NULL error at %lld: %s %s %s\n", i, pal1, pal2, pal3);
        }
        if (!ispal(pal1) || !ispal(pal2) || !ispal(pal3)) {
            printf("Palindrome error at %lld: %s %s %s\n", i, pal1, pal2, pal3);
        }
        //printf("%s %s %s\n", pal1, pal2, pal3);
    }
    */
    return 0;
}

/*
Our resonating wishes are starting to wake up,
for our most treasured future.
After surpassing our destiny of reuniting,
my thoughts will shine brilliantly.

Having entrusted my hope to my not-yet-found future,
I continued searching for the true meaning of "strength".

What's the point of "accepting the pain in plain view"?
You must know, as you keep running towards tomorrow.

The coming-and-going scenery now flows away
towards the front of the world that I'm grasping.
Feeling with my entire body the signals pouring in,
I now let go of everything.

Just truth in my heart,
I won't lose my way no matter when,
because I'll always have my will.
Without averting my eyes from the exposed truths,
I'll reach the next stage to realize all.

I was able to sense you as you chased from behind,
but since when do you feel so close to me?

Unable to hide my uneasiness, I looked up at the intimidating sky.
Some day, I will get over my memories of getting hurt.

My yearning has awakened my strength,
because there are people I want to protect.
The coming-and-going scenery now simply runs up my chest,
as my pain disappears in the wind.

Believe in Judgelight,
piercing through even fate itself,
I will create a new dawn by my own hands,
with my strengthening courage and determined heart.
I believe myself and precious emotion,
I will smash all obstacles with my will!

We made a vow in the light of a new beginning,
that we'd pass judgment onto this boundless darkness.
We feared that we'd drown in the swirl of loneliness,
but still, we will not look back.

The coming-and-going scenery now flows away
towards the front of the world that I'm grasping.
Feeling with my entire body the signals pouring in,
I now let go of everything.

Just truth in my heart,
I won't lose my way no matter when,
because I'll always have my will.
Without averting my eyes from the exposed truths,
I'll reach the next stage to realize all,
believing in our firm bond.
*/