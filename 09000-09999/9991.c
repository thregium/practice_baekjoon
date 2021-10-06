#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : W개의 문자열이 주어진다. 해당하는 문자열은 알파벳 소문자로 이루어져 있고, 주어지는 문자열의 길이 합은 10^6 이하다.
그 후 N(N <= 1000)개의 문자열들과 K가 주어진다. 해당하는 문자열들은 1000자 이하의 소문자로 이루어져 있다.
각 문자열마다 해당 문자열로 시작하는 K번째 단어(처음 나온 문자열들)를 구한다. 해당하는 단어가 없다면 -1을 출력한다.

해결 방법 : 트라이 자료구조를 이용한다. 이때, 메모리를 절약하기 위해 다음 노드의 목록은 동적으로 할당해야 한다.
각 문자열들을 트라이에 저장한 다음, 각 문자열들을 입력받으며 해당 문자열에서 시작하는 문자열의 개수를 확인하며
해당하는 문자열을 찾아나간다.

주요 알고리즘 : 자료 구조, 트라이, 문자열

출처 : USACO 2014F B2/S1번
*/

typedef struct trie {
    int cnt; //해당 문자열로 시작하는 문자열의 개수
    int fin; //해당 문자열이 끝나는 문자열이라면 그 문자열의 번호를 저장, 없으면 0
    char msz; //다음 트라이 메모리의 크기
    char sz; //다음 트라이의 개수
    char last; //최근 문자
    struct trie** nxt; //다음 트라이들의 목록
} trie;

char buff[1048576];
int ccc = 0, error = 0;

int cmp1(const void* a, const void* b) {
    //트라이의 목록을 정렬한다.
    trie* ai = *(trie**)a;
    trie* bi = *(trie**)b;
    return ai->last > bi->last ? 1 : ai->last == bi->last ? 0 : -1;
}

void assign(trie* tr, int p, int ki) {
    //해당하는 문자를 트라이에 저장한다.
    int li;
    trie** tmp;
    (tr->cnt)++;
    while (buff[p]) {
        li = -1;
        for (int i = 0; i < tr->sz; i++) {
            if (tr->nxt[i]->last == buff[p]) {
                li = i; //다음 문자를 찾음
                break;
            }
        }
        if (li < 0) {
            //다음 문자를 찾을 수 없다면
            if (tr->sz == 0) {
                tr->nxt = calloc(1, sizeof(trie*)); //아직 배열이 없던 경우
                tr->msz = 1;
            }
            else if (tr->sz == tr->msz) {
                tmp = realloc(tr->nxt, sizeof(trie*) * ((long long)tr->msz << 1)); //메모리가 가득 차면 2배로 재할당
                if (tmp == NULL) {
                    error = 1; //할당에 실패할 경우?
                    return;
                }
                tr->nxt = tmp;
                tr->msz <<= 1;
            }
            ((tr->nxt)[tr->sz]) = calloc(1, sizeof(trie)); //새로운 노드 할당
            ((tr->nxt)[tr->sz])->last = buff[p];
            li = (tr->sz)++;
        }
        tr = tr->nxt[li];
        (tr->cnt)++;
        p++;
    }
    tr->fin = ki; //문자열의 끝
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("auto.in", "r");
        fo = fopen("auto.out", "w");
    }
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2014_02\\auto\\6.in", "r", stdin);
    int w, n, k, li, eend;
    trie* tr = calloc(1, sizeof(trie));
    trie* tx;
    scanf("%d %d", &w, &n);
    for (int i = 0; i < w; i++) {
        scanf("%s", buff);
        assign(tr, 0, i + 1); //각 문자열들을 트라이에 저장한다.
        if (error) return -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &k, buff);
        tx = tr;
        eend = 0;
        for (int j = 0; buff[j]; j++) {
            li = -1;
            for (int jj = 0; jj < tx->sz; jj++) {
                if (tx->nxt[jj]->last == buff[j]) {
                    li = jj; //주어진 문자열의 노드까지 이동한다.
                    break;
                }
            }
            if (li < 0) {
                printf("%d\n", -1); //이동이 불가능하다면 시작하는 문자열이 0개라는 의미이므로 -1을 출력한다.
                eend = 1;
                break;
            }
            tx = tx->nxt[li];
        }
        if (eend) continue;
        if (tx->cnt < k) printf("%d\n", -1); //또는 시작하는 문자열이 K개 미만인 경우에도 -1을 출력한다.
        else {
            while (k > 0) {
                if (tx->fin) k--;
                if (k == 0) printf("%d\n", tx->fin); //해당하는 문자열을 찾은 경우 출력하고 종료한다.
                else {
                    qsort(tx->nxt, tx->sz, sizeof(trie*), cmp1);
                    for (int j = 0; j < tx->sz; j++) {
                        if (tx->nxt[j] == NULL) return 2;
                        if (tx->nxt[j]->cnt < k) k -= tx->nxt[j]->cnt; //그 외에는 사전순으로 살펴본다.
                        else {
                            tx = tx->nxt[j];
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}