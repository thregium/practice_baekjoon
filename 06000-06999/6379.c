#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 문자들과 숫자들이 섞인 목록들(N <= 100)이 주어질 때, 각 목록마다 문자는 문자끼리, 숫자는 숫자끼리 정렬한 후 출력한다.
단, 문자를 정렬할 때 대소문자는 무시해야 한다.

해결 방법 : 우선, 목록의 각 원소들을 문자와 숫자로 분류한다. 목록의 마지막 글자의 종류에 따라 분류할 수 있다.
그 다음 분류한 각 목록을 각각 정렬해 준다. 숫자인 경우 atoi를 이용하면 되고, 문자라면 새로운 배열에 둘 다 소문자로 만들고
strcmp를 이용하면 된다. 정렬이 끝나면 다시 원래 목록으로 돌아와서 문자와 숫자를 따로 세어가며 원소들을 출력하면 된다.

주요 알고리즘 : 구현, 정렬, 파싱

출처 : GNY 2000 4번
*/

char orig[256][64], words[256][64], nums[256][64];
int types[256];

int cmp1(const void* a, const void* b) {
    //수 비교
    int ai = atoi((char*)a);
    int bi = atoi((char*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    //문자열 비교
    char al[64] = { 0, };
    char bl[64] = { 0, };
    for (int i = 0; ((char*)a)[i]; i++) {
        al[i] = tolower(((char*)a)[i]);
    }
    for (int i = 0; ((char*)b)[i]; i++) {
        bl[i] = tolower(((char*)b)[i]);
    }
    return strcmp(al, bl);
}

int main(void) {
    int sz, wd, nm;
    while (1) {
        for (sz = 0;; sz++) {
            //목록에서 각 원소 추출
            scanf("%s", orig[sz]);
            if (orig[sz][strlen(orig[sz]) - 1] == '.') {
                orig[sz][strlen(orig[sz]) - 1] = '\0';
                sz++;
                break;
            }
            orig[sz][strlen(orig[sz]) - 1] = '\0';
        }
        if (sz == 1 && strlen(orig[0]) == 0) break;

        wd = 0;
        nm = 0;
        for (int i = 0; i < sz; i++) {
            //원소 분류
            if (isdigit(orig[i][strlen(orig[i]) - 1])) {
                strcpy(nums[nm], orig[i]);
                nm++;
                types[i] = 1;
            }
            else {
                strcpy(words[wd], orig[i]);
                wd++;
                types[i] = 2;
            }
        }

        qsort(nums, nm, sizeof(char) * 64, cmp1);
        qsort(words, wd, sizeof(char) * 64, cmp2);

        nm = 0;
        wd = 0;
        for (int i = 0; i < sz; i++) {
            if (types[i] == 1) printf("%s", nums[nm++]);
            else printf("%s", words[wd++]);
            if (i == sz - 1) printf(".\n");
            else printf(", ");
        }
    }
    return 0;
}