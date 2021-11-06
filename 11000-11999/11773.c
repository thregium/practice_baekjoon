#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : A개 이상 B(A, B <= 100000)개의 단어를 출력한다. 각 단어는 영어 소문자로 이루어지고 1 ~ 15자여야 한다.
또한, 사용한 단어들의 종류는 B / 2개 이상이어야 한다.

해결 방법 : 15자 이하의 무작위한 단어를 출력한다. 단어가 길어질 수록 겹칠 확률은 낮아지므로
되도록 긴 단어를 만드는 것이 좋다. (코드는 그렇게 하고 있지 않아 틀릴 확률이 어느정도 있다.)

주요 알고리즘 : 문자열, 구성적, 무작위화

출처 : COCI 15/16#3 2번
*/

char s[103000][16], tmp[16];
const int freq[26] = { 12702, 21758, 29925, 37432, 44398, 51147, 57474, 63568, 69555, 73808, 77833, 80615, 83373,
85779, 88139, 90367, 92382, 94356, 96285, 97777, 98755, 99527, 99680, 99830, 99925, 99999 }; //각 글자의 사용 비율(누적)
const int lnfreq[16] = { 0, 3160, 20135, 41327, 57005, 67857, 76381, 84105,
89728, 93760, 96526, 98108, 99025, 99508, 99770, 100000 }; //각 단어 길이 별 사용 비율(누적)
const char* alpha = "etaoinshrdlcumwfgypbvkjxqz"; //글자별 사용 비율 순서

int isvowel(char c) {
    //모음 여부 구하기
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

long long getrand(long long s, long long e) {
    //s와 e 사이 무작위 값 구하기
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
    int l = getrand(0, 99999); //해당 단어의 길이를 정한다.
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
            t = getrand(0, 99999); //각 글자를 정한다
            for (int j = 0; j < 25; j++) {
                if (t <= freq[j]) {
                    tmp[i] = alpha[j];
                    break;
                }
            }
            if (i > 1 && (isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 3 ||
                isvowel(tmp[i]) + isvowel(tmp[i - 1]) + isvowel(tmp[i - 2]) == 0)) {
                //자음이나 모음이 3연속으로 오지 않도록 한다.
                i--;
                continue;
            }
        }
        tmp[l] = '\0';
        strcpy(s[p], tmp);
        printf("%s ", tmp); //해당 단어를 출력한다.
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
    qsort(s, r, sizeof(char) * 16, strcmp); //이 아래로는 전체 단어의 종류를 검증하기 위한 코드이다.
    for (int i = 0; i < r; i++) {
        if (i > 0 && strcmp(s[i], s[i - 1]) == 0) continue;
        cnt++;
    }
    printf("\n%d : %d", cnt, r);
    */
    return 0;
}