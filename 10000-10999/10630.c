#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : RLE 형태로 이루어진 세 문자열이 주어진다. 첫 문자열에서 두 번째 문자열이 있는 첫 위치를 찾아
그 문자열을 세 번째 문자열로 바꾼 후 RLE 형태로 출력한다.
그러한 문자열이 없는 경우는 그대로 출력한다.
각 문자열의 연속한 문자 수는 최대 10^8개이고, 문자 덩어리의 수는 최대 1000개이다.

해결 방법 : 우선 파싱을 통해 RLE의 값들을 각각 구해준다. 그런 다음, 문자열을 찾아 나간다.

첫 문자열에서 두 번째 문자열을 찾는 방법은 다음과 같다.
두 번째 문자열의 덩어리 수가 1인 경우에는 해당 덩어리와 같은 문자며 길이가 그 이상인 덩어리를
찾아서 그 덩어리의 첫 부분을 바꾼다.
2 이상이라면 시작과 끝점의 경우 같은 문자며 길이가 그 이상, 그 외 지점은 같은 문자에 길이도
같은 덩어리의 묶음을 찾아야 한다. 하지만 덩어리의 수가 작으므로 단순 브루트 포스를 사용할 수 있다.

문자열을 찾은 다음에는 문자열의 내용을 바꿔나가야 한다. 우선 두 번째 문자열과 겹치지 않는 부분은
그대로 내보낸다. 그리고 시작과 끝점은 길이를 확인해 그 길이만큼만 새 문자열에 넣는다.
중간 점들은 세 번째 문자열의 내용을 그대로 새 문자열에 넣는다.

그리고 이 과정에서 나온 길이 0 또는 연속한 같은 덩어리들을 정리하는 작업을 한다.
이는 배열 2개를 사용하면 간단하다. 이 과정이 끝나면 RLE 형식으로 문자열을 출력해 나가면 된다.

주요 알고리즘 : 문자열, 구현, 케이스 워크, 브루트 포스 등

출처 : JAG 2014SC H번
*/

char a[16384], b[16384], c[16384], ac[1024], bc[1024], cc[1024], tc[2048], rc[2048];
long long ai[1024], bi[1024], ci[1024], ti[2048], ri[2048];
int acnt, bcnt, ccnt, rcnt;

void parse(char* text, char* carr, long long* iarr, int* cnt) {
    *cnt = 0;
    for (int i = 0; text[i] != '$'; i++) {
        if (isupper(text[i])) {
            carr[*cnt] = text[i];
            iarr[(*cnt)++] = strtoll(&text[i + 2], NULL, 10);
        }
    }
}

void replace(int pos, int posi) {
    int rp = 0;
    rcnt = 0;
    for (int i = 0; i < pos; i++) {
        tc[rp] = ac[i];
        ti[rp++] = ai[i];
    }
    tc[rp] = ac[pos];
    ti[rp++] = posi;
    for (int i = 0; i < ccnt; i++) {
        tc[rp] = cc[i];
        ti[rp++] = ci[i];
    }
    tc[rp] = ac[pos + bcnt - 1];
    ti[rp++] = ai[pos + bcnt - 1] - bi[bcnt - 1];
    for (int i = pos + bcnt; i < acnt; i++) {
        tc[rp] = ac[i];
        ti[rp++] = ai[i];
    }

    for (int i = 0; i < rp; i++) {
        if (ti[i] == 0) continue;
        if (i > 0 && tc[i] == rc[rcnt - 1]) ri[rcnt - 1] += ti[i];
        else {
            rc[rcnt] = tc[i];
            ri[rcnt++] = ti[i];
        }
    }
}

int main(void) {
    int t;
    fgets(a, 16000, stdin);
    fgets(b, 16000, stdin);
    fgets(c, 16000, stdin);
    parse(a, ac, ai, &acnt);
    parse(b, bc, bi, &bcnt);
    parse(c, cc, ci, &ccnt);

    rcnt = acnt;
    for (int i = 0; i < acnt; i++) {
        rc[i] = ac[i];
        ri[i] = ai[i];
    }

    if (bcnt == 1) {
        for (int i = 0; i < acnt; i++) {
            if (ac[i] == bc[0] && ai[i] >= bi[0]) {
                replace(i, 0);
                break;
            }
        }
    }
    else {
        for (int i = 0; i <= acnt - bcnt; i++) {
            t = 1;
            if (ac[i] != bc[0] || ai[i] < bi[0]) t = 0;
            for (int j = 1; j < bcnt - 1; j++) {
                if (ac[i + j] != bc[j] || ai[i + j] != bi[j]) t = 0;
            }
            if (ac[i + bcnt - 1] != bc[bcnt - 1] || ai[i + bcnt - 1] < bi[bcnt - 1]) t = 0;
            if (t) {
                replace(i, ai[i] - bi[0]);
                break;
            }
        }
    }

    for (int i = 0; i < rcnt; i++) {
        printf("%c %lld ", rc[i], ri[i]);
    }
    printf("$\n");
    return 0;
}