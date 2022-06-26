#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include <string>
using namespace std;

/*
���� : N(N <= 30000)���� ���� �ٸ� �̸����� ����Ѵ�. �� �̸��� 3�� �̻� 20�� ���Ͽ��� �ϸ�,
3�� �̻� �����̳� ������ �����ؼ��� �� �ȴ�.

�ذ� ��� : �� ������ �����ϴ� �̸����� �������� ������ ����� ����� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, ������ȭ

��ó : KTH 2022 A��
*/

char s[103000][32], tmp[32];
const int freq[26] = { 12702, 21758, 29925, 37432, 44398, 51147, 57474, 63568, 69555, 73808, 77833, 80615, 83373,
85779, 88139, 90367, 92382, 94356, 96285, 97777, 98755, 99527, 99680, 99830, 99925, 99999 };
const int lnfreq[16] = { 0, 3160, 20135, 41327, 57005, 67857, 76381, 84105,
89728, 93760, 96526, 98108, 99025, 99508, 99770, 100000 };
const char* alpha = "etaoinshrdlcumwfgypbvkjxqz";
unordered_set<string> name;

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

long long getrand(long long s, long long e) {
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
    int l, r, t;
    while (1) {
        l = getrand(0, 99999);
        for (int i = 1; i < 16; i++) {
            if (l <= lnfreq[i]) {
                l = i;
                break;
            }
        }
        if (l < 3) l = 3;
        if (l > 20) l = 20;

        r = 0;
        for (int i = 0; i < l; i++) {
            t = getrand(0, 99999);
            for (int j = 0; j < 25; j++) {
                if (t <= freq[j]) {
                    tmp[i] = alpha[j];
                    break;
                }
            }
            if (i > 1 && (isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 3 ||
                isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 0)) {
                i--;
                continue;
            }
        }
        tmp[l] = '\0';
        if (name.find(tmp) != name.end()) continue;
        //strcpy(s[p], tmp);
        printf("%s\n", tmp);
        name.insert(tmp);
        break;
    }
}

int main(void) {
    int n, cnt = 0;
    srand(time(NULL));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printrandword(i);
    }
    return 0;
}