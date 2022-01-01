#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 주어진 문서에서 색인을 만들어 출력한다. {} 안에 있는 내용이 대상이며, 1차와 2차 내용으로 나뉜다.
$의 뒤에 있는 내용은 2차 내용이고, %가 있다면 그 뒤의 내용으로 적용해야 한다. &는 페이지 바꿈이다.
출력할 때에는 사전순으로 정렬하되, 대소문자를 구분하지 않는다. {}는 최대 100개이며, 각 {}의 길이는 최대 80이다.

해결 방법 : 먼저 문서의 내용을 줄 단위로 받은 다음, 줄 바꿈을 공백으로 바꾸고 전부 이어준다.
그리고 {} 안에 있는 내용들을 전부 꺼내서 저장해둔다.
그 다음으로는 1차와 2차 내용을 꺼내고 앞뒤의 공백을 제거하여 저장한다.
이제 1차 내용과 같은 것이 색인에 있는 지 찾고 그러하다면 그 색인에 현재 페이지를 추가한다.(이미 있다면 추가하지 않는다.).
그리고 그 색인에 2차 내용을 확인해 같은 것이 있다면 거기에도 현재 페이지를 추가한다. 없다면 2차 내용의 링크를 이은 다음,
새로 2차 내용의 색인을 작성한다. 1차 내용도 없다면 마찬가지로 한다.

이를 반복한 다음, 모든 내용을 만들었다면 각 색인들을 정렬한다. 정렬 함수를 새로 만들도록 한다.
그리고 마지막으로 형식에 맞게 출력하면 된다.

주요 알고리즘 : 구현, 문자열, 파싱, 정렬

출처 : MidC 2001 D번
*/

typedef struct entry {
    char term[128]; //내용의 문자열
    int page[16]; //존재하는 페이지
    int subn[8]; //해당 내용의 2차 내용 번호들
} entry;

char buff[128], str[103000], mark[128][128], ps[128], ss[128];
int mp[128];
entry primary[32], secondary[128];

int cmp1(const void* a, const void* b) {
    //1차 정렬
    entry ai = *(entry*)a;
    entry bi = *(entry*)b;
    for (int i = 0; i < 128; i++) {
        if (tolower(ai.term[i]) > tolower(bi.term[i])) return 1;
        else if (tolower(ai.term[i]) < tolower(bi.term[i])) return -1;
    }
    return 0;
}

int cmp2(const void* a, const void* b) {
    //2차 정렬
    entry ai = secondary[*(int*)a];
    entry bi = secondary[*(int*)b];
    for (int i = 0; i < 128; i++) {
        if (tolower(ai.term[i]) > tolower(bi.term[i])) return 1;
        else if (tolower(ai.term[i]) < tolower(bi.term[i])) return -1;
    }
    return 0;
}

void trim(char* s) {
    //문자열 앞뒤의 공백을 제거함
    int st = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ' && st < 0) st = i;
        if (st >= 0) s[i - st] = s[i];
        if (!s[i + 1]) s[i + 1 - st] = '\0';
    }
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            s[i + 1] = '\0';
            break;
        }
    }
}

int main(void) {
    int end = 0, pn, sn, mn, page, ex;
    char* ptr;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\indexgen\\indexgen.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\indexgen\\indexgen_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        strcpy(str, " ");
        while (1) {
            //문서 내용 이어주기
            fgets(buff, 100, stdin);
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = ' ';
            strcat(str, buff);
            if (strstr(buff, "**") == buff) {
                end = 1;
                break;
            }
            else if (strstr(buff, "*") == buff) break;
        }
        if (end) break;
        pn = 0, sn = 0, mn = 0, page = 1;
        ptr = strtok(str, "{");
        while (ptr) {
            //괄호, 페이지 확인
            for (int i = 0; ptr[i]; i++) page += (ptr[i] == '&');
            ptr = strtok(NULL, "}");
            if (!ptr) break;
            mp[mn] = page;
            strcpy(mark[mn++], ptr);
            ptr = strtok(NULL, "{");
        }

        for (int i = 0; i < mn; i++) {
            //%, $ 확인
            if (strchr(mark[i], '%')) {
                ptr = strtok(mark[i], "%");
                ptr = strtok(NULL, "%");
                if (ptr == NULL) return 1;
                strcpy(mark[i], ptr);
            }
            ptr = strtok(mark[i], "$");
            strcpy(ps, ptr);
            ptr = strtok(NULL, "$");
            if (ptr) strcpy(ss, ptr);
            else ss[0] = '\0';
            trim(ps);
            if (ss[0]) trim(ss);

            //printf("%s:%s-%d\n", ps, ss, mp[i]);
            ex = 0;
            for (int j = 0; j < pn; j++) {
                if (!strcmp(ps, primary[j].term)) {
                    //1차 내용 확인
                    if (ss[0] == '\0' && primary[j].page[primary[j].page[0]] != mp[i]) {
                        primary[j].page[++primary[j].page[0]] = mp[i];
                    }
                    ex = 1;
                    if (ss[0] != '\0') {
                        //2차 내용 확인
                        for (int k = 1; k <= primary[j].subn[0]; k++) {
                            if (!strcmp(ss, secondary[primary[j].subn[k]].term)) {
                                if (secondary[primary[j].subn[k]].page[secondary[primary[j].subn[k]].page[0]] != mp[i]) {
                                    secondary[primary[j].subn[k]].page[++secondary[primary[j].subn[k]].page[0]] = mp[i];
                                }
                                ex = 2;
                                break;
                            }
                        }
                        if (ex == 1) {
                            primary[j].subn[++primary[j].subn[0]] = sn;
                            strcpy(secondary[sn].term, ss);
                            secondary[sn].page[0]++;
                            secondary[sn].page[1] = mp[i];
                            sn++;
                        }
                    }
                    break;
                }
            }
            if (!ex) {
                //1차 내용이 일치하는 경우가 없을 때
                strcpy(primary[pn].term, ps);
                if (ss[0] != '\0') {
                    primary[pn].subn[++primary[pn].subn[0]] = sn;
                    strcpy(secondary[sn].term, ss);
                    secondary[sn].page[0]++;
                    secondary[sn].page[1] = mp[i];
                    sn++;
                }
                else {
                    primary[pn].page[0]++;
                    primary[pn].page[1] = mp[i];
                }
                pn++;
            }
        }
        //정렬
        qsort(primary, pn, sizeof(entry), cmp1);
        for (int i = 0; i < pn; i++) {
            qsort(&primary[i].subn[1], primary[i].subn[0], sizeof(int), cmp2);
        }


        //출력
        printf("DOCUMENT %d\n", tt);
        for (int i = 0; i < pn; i++) {
            printf("%s", primary[i].term);
            for (int j = 1; j <= primary[i].page[0]; j++) {
                printf(", %d", primary[i].page[j]);
            }
            printf("\n");
            for (int j = 1; j <= primary[i].subn[0]; j++) {
                printf("+ %s, ", secondary[primary[i].subn[j]].term);
                for (int k = 1; k <= secondary[primary[i].subn[j]].page[0]; k++) {
                    printf("%d", secondary[primary[i].subn[j]].page[k]);
                    if (k < secondary[primary[i].subn[j]].page[0]) printf(", ");
                }
                printf("\n");
            }
        }

        //초기화
        for (int i = 0; i < pn; i++) {
            primary[i].page[0] = 0;
            primary[i].subn[0] = 0;
        }
        for (int i = 0; i < sn; i++) secondary[i].page[0] = 0;
    }
    return 0;
}