#include <stdio.h>
#include <string.h>

/*
문제 : 255자 이하의 DNA 문자열이 주어질 때, 이 DNA의 RNA 또는 상보적인 RNA를 정방향 또는 역방향으로 만든 RNA로
만들 수 있는 단백질을 출력한다. (코돈표 생략). 만들 수 없는 경우 "*** No translatable DNA found ***"를 출력한다.
여러 가지 경우가 나온다면 (정방향, 상보), (역방향, 상보), (정방향, 해당), (역방향, 해당) 순으로 출력한다.
각 경우에서 만들 수 있는 단백질은 1가지 이하로 주어진다.

해결 방법 : 코돈표를 미리 하드코딩해둔 후 주어진 순서대로 단백질을 만들어본다.
AUG가 나올 때 까지 단백질을 확인하고, AUG가 나오면 UAA, UGA, UAG 중 하나가 나올 때 까지 아미노산을 연결한다.
단, 그들 중 하나가 나오지 않는다면 단백질이 완선되지 않은 것이다.
셋 중 하나가 나온다면 그 상태에서 단백질이 완성된 것이므로 코돈표에서 아미노산을 찾아 출력하면 된다.
모든 경우에서 나오지 않았다면 "*** No translatable DNA found ***"를 출력한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : MidC 1995 1번
*/

char dna[320];
int res[128];
const int codon[64] = { 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 0, 0, 5, 5, 0, 6,
2, 2, 2, 2, 7, 7, 7, 7, 8, 8, 9, 9, 10, 10, 10, 10,
11, 11, 11, 12, 13, 13, 13, 13, 14, 14, 15, 15, 3, 3, 10, 10,
16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 19, 19, 20, 20, 20, 20 };
const char* codons[21] = { "End", "Phe", "Leu", "Ser", "Tyr", "Cys", "Trp", "Pro",
"His", "Gln", "Arg", "Ile", "Met", "Thr", "Asn", "Lys",
"Val", "Ala", "Asp", "Glu", "Gly" };

int tobase(char c) {
    if (c == 'T') return 0;
    else if (c == 'C') return 1;
    else if (c == 'A') return 2;
    else if (c == 'G') return 3;
    else return -1;
}

int getcodon(int p, int c, int d) {
    if (c) {
        if (d) return codon[(tobase(dna[p]) ^ 2) * 16 + (tobase(dna[p - 1]) ^ 2) * 4 + (tobase(dna[p - 2]) ^ 2)];
        else return codon[(tobase(dna[p]) ^ 2) * 16 + (tobase(dna[p + 1]) ^ 2) * 4 + (tobase(dna[p + 2]) ^ 2)];
    }
    else {
        if (d) return codon[tobase(dna[p]) * 16 + tobase(dna[p - 1]) * 4 + tobase(dna[p - 2])];
        else return codon[tobase(dna[p]) * 16 + tobase(dna[p + 1]) * 4 + tobase(dna[p + 2])];
    }
}

int printcodon(int l) {
    for (int i = 0; i < l; i++) {
        printf("%s", codons[res[i]]);
        if (i < l - 1) printf("-");
    }
    printf("\n");
}

int main(void) {
    int len = 0, r = 0, l = 0, st = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\dna.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\dna_t.out", "w", stdout);
    while (1) {
        scanf("%s", dna);
        len = strlen(dna);
        if (dna[0] == '*') break;
        r = 0, l = 0, st = -1;
        for (int i = 0; i < len - 2; i++) {
            if (getcodon(i, 0, 0) == 12) {
                st = i;
                break;
            }
        }
        if (st >= 0) {
            for (int i = st + 3; i < len - 2; i += 3) {
                if (getcodon(i, 0, 0) == 0) {
                    if (l > 0) r = 1;
                    break;
                }
                res[l++] = getcodon(i, 0, 0);
            }
        }
        if (r) {
            printcodon(l);
            continue;
        }

        l = 0, st = -1;
        for (int i = len - 1; i >= 2; i--) {
            if (getcodon(i, 0, 1) == 12) {
                st = i;
                break;
            }
        }
        if (st >= 0) {
            for (int i = st - 3; i >= 2; i -= 3) {
                if (getcodon(i, 0, 1) == 0) {
                    if (l > 0) r = 1;
                    break;
                }
                res[l++] = getcodon(i, 0, 1);
            }
        }
        if (r) {
            printcodon(l);
            continue;
        }

        l = 0, st = -1;
        for (int i = len - 1; i >= 2; i--) {
            if (getcodon(i, 1, 1) == 12) {
                st = i;
                break;
            }
        }
        if (st >= 0) {
            for (int i = st - 3; i >= 2; i -= 3) {
                if (getcodon(i, 1, 1) == 0) {
                    if (l > 0) r = 1;
                    break;
                }
                res[l++] = getcodon(i, 1, 1);
            }
        }
        if (r) {
            printcodon(l);
            continue;
        }

        l = 0, st = -1;
        for (int i = 0; i < len - 2; i++) {
            if (getcodon(i, 1, 0) == 12) {
                st = i;
                break;
            }
        }
        if (st >= 0) {
            for (int i = st + 3; i < len - 2; i += 3) {
                if (getcodon(i, 1, 0) == 0) {
                    if (l > 0) r = 1;
                    break;
                }
                res[l++] = getcodon(i, 1, 0);
            }
        }
        if (r) {
            printcodon(l);
            continue;
        }
        printf("*** No translatable DNA found ***\n");
    }
    return 0;
}