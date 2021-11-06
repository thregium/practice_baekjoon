#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
���� : A�� �̻� B(A, B <= 100000)���� �ܾ ����Ѵ�. �� �ܾ�� ���� �ҹ��ڷ� �̷������ 1 ~ 15�ڿ��� �Ѵ�.
����, ����� �ܾ���� ������ B / 2�� �̻��̾�� �Ѵ�.

�ذ� ��� : 15�� ������ �������� �ܾ ����Ѵ�. �ܾ ����� ���� ��ĥ Ȯ���� �������Ƿ�
�ǵ��� �� �ܾ ����� ���� ����. (�ڵ�� �׷��� �ϰ� ���� �ʾ� Ʋ�� Ȯ���� ������� �ִ�.)

�ֿ� �˰��� : ���ڿ�, ������, ������ȭ

��ó : COCI 15/16#3 2��
*/

char s[103000][16], tmp[16];
const int freq[26] = { 12702, 21758, 29925, 37432, 44398, 51147, 57474, 63568, 69555, 73808, 77833, 80615, 83373,
85779, 88139, 90367, 92382, 94356, 96285, 97777, 98755, 99527, 99680, 99830, 99925, 99999 }; //�� ������ ��� ����(����)
const int lnfreq[16] = { 0, 3160, 20135, 41327, 57005, 67857, 76381, 84105,
89728, 93760, 96526, 98108, 99025, 99508, 99770, 100000 }; //�� �ܾ� ���� �� ��� ����(����)
const char* alpha = "etaoinshrdlcumwfgypbvkjxqz"; //���ں� ��� ���� ����

int isvowel(char c) {
    //���� ���� ���ϱ�
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

long long getrand(long long s, long long e) {
    //s�� e ���� ������ �� ���ϱ�
    unsigned long long r = 0;
    for (int i = 0; i < 8; i++) {
        r <<= 8;
        r += (rand() & 255);
    }
    if (e < s) return r;
    r %= e - s + 1;
    r += s;
    return r;
}

void printrandword(int p) {
    /*
    int l = getrand(1, 225);
    for (int i = 1; i <= 15; i++) {
        if (i * i >= l) {
            l = i;
            break;
        }
    }
    */
    int l = getrand(0, 99999); //�ش� �ܾ��� ���̸� ���Ѵ�.
    for (int i = 1; i < 16; i++) {
        if (l <= lnfreq[i]) {
            l = i;
            break;
        }
    }
    int r = 0, t;
    while (1) {
        r = 0;
        for (int i = 0; i < l; i++) {
            t = getrand(0, 99999); //�� ���ڸ� ���Ѵ�
            for (int j = 0; j < 25; j++) {
                if (t <= freq[j]) {
                    tmp[i] = alpha[j];
                    break;
                }
            }
            if (i > 1 && (isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 3 ||
                isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 0)) {
                //�����̳� ������ 3�������� ���� �ʵ��� �Ѵ�.
                i--;
                continue;
            }
        }
        tmp[l] = '\0';
        strcpy(s[p], tmp);
        printf("%s ", tmp); //�ش� �ܾ ����Ѵ�.
        break;
    }
}

int main(void) {
    int a, b, r, cnt = 0;
    srand(time(NULL));
    scanf("%d %d", &a, &b);
    if (((b + 1) >> 1) > a) a = (b >> 1);
    r = getrand(a, b);
    r = b;
    for (int i = 0; i < r; i++) {
        printrandword(i);
    }
    /*
    qsort(s, r, sizeof(char) * 16, strcmp); //�� �Ʒ��δ� ��ü �ܾ��� ������ �����ϱ� ���� �ڵ��̴�.
    for (int i = 0; i < r; i++) {
        if (i > 0 && strcmp(s[i], s[i - 1]) == 0) continue;
        cnt++;
    }
    printf("\n%d : %d", cnt, r);
    */
    return 0;
}