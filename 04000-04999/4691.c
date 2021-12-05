#include <stdio.h>
#include <string.h>

/*
���� : 255�� ������ DNA ���ڿ��� �־��� ��, �� DNA�� RNA �Ǵ� ������ RNA�� ������ �Ǵ� ���������� ���� RNA��
���� �� �ִ� �ܹ����� ����Ѵ�. (�ڵ�ǥ ����). ���� �� ���� ��� "*** No translatable DNA found ***"�� ����Ѵ�.
���� ���� ��찡 ���´ٸ� (������, ��), (������, ��), (������, �ش�), (������, �ش�) ������ ����Ѵ�.
�� ��쿡�� ���� �� �ִ� �ܹ����� 1���� ���Ϸ� �־�����.

�ذ� ��� : �ڵ�ǥ�� �̸� �ϵ��ڵ��ص� �� �־��� ������� �ܹ����� ������.
AUG�� ���� �� ���� �ܹ����� Ȯ���ϰ�, AUG�� ������ UAA, UGA, UAG �� �ϳ��� ���� �� ���� �ƹ̳���� �����Ѵ�.
��, �׵� �� �ϳ��� ������ �ʴ´ٸ� �ܹ����� �ϼ����� ���� ���̴�.
�� �� �ϳ��� ���´ٸ� �� ���¿��� �ܹ����� �ϼ��� ���̹Ƿ� �ڵ�ǥ���� �ƹ̳���� ã�� ����ϸ� �ȴ�.
��� ��쿡�� ������ �ʾҴٸ� "*** No translatable DNA found ***"�� ����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : MidC 1995 1��
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