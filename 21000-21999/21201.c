#include <stdio.h>
#include <malloc.h>

/*
문제 : N(N <= 100000)개의 자연수가 있을 때, 양 옆에 자신보다 큰 수가 있는 수를 제거해나가는 과정을 출력한다.

해결 방법 : 단순히 시뮬레이션으로 해결 가능할 것 같지만 O(N^2) 시간이 걸리기 때문에 다른 방법을 사용해야 한다.
한 방법으로는 연결 리스트를 응용하는 것이 있다. 연결 리스트를 통해 연속된 같은 수들을 건너뛰는 것이다.
같은 수들의 마지막, 또는 다음 수로 넘어가는 포인터를 추가한 다음 연결 리스트를 순회하며 다음 수들을 찾는다.
찾아가며 삭제할 수들을 기록한 다음, 삭제할 수들을 삭제하며 주위 칸들의 건너뛰는 수들도 조절해 나간다.

주요 알고리즘 : 자료구조, 연결 리스트

출처 : Rocky 2020 E번
*/

typedef struct llst{
    int n;
    struct llst* next;
    struct llst* prev;
    struct llst* jump;
} llst;

llst* q, *erasetmp[103000], *erase[103000], *elast[103000];
int ep = 0, tp = 0;

llst* makejump(llst* now, int c) {
    if (now->n != now->next->n) {
        now->jump = now->next;
        return now;
    }
    else {
        llst* dest = makejump(now->next, c + 1);
        now->jump = dest;
        return dest;
    }
}

int main(void) {
    int n;
    llst* last, *node;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2020\\problems\\interviewqueue\\data\\secret\\sparse-234-1.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2020\\problems\\interviewqueue\\data\\secret\\random-4-check.out", "w", stdout);
    scanf("%d", &n);
    q = malloc(sizeof(llst));
    q->n = -1;
    q->jump = NULL;
    q->prev = NULL;
    last = q;
    for (int i = 1; i <= n + 1; i++) {
        node = malloc(sizeof(llst));
        if (i > n) node->n = -1;
        else scanf("%d", &(node->n));
        last->next = node;
        node->prev = last;
        node->next = NULL;
        node->jump = NULL;
        last = node;
    }
    for (llst* i = q->next; i->next; i = i->next) {
        /*
        if (i->jump == NULL) {
            makejump(i, 1);
        }
        */
        if (i->n != i->next->n) {
            for (llst* j = i->prev; j->prev && !(j->jump); j = j->prev) {
                j->jump = i;
            }
            i->jump = i->next;
        }
    }
    while (1) {
        tp = 0;
        for (llst* i = q->next; i->next; i = (i->jump->n == -2 ? i->next : i->jump)) {
            if (i->n == -2) {
                return 1;
            }
            if (i->n < i->prev->n || i->n < i->next->n) {
                erasetmp[tp++] = i;
                if (tp > 100000) {
                    return 1;
                }
                node = malloc(sizeof(llst));
                node->n = i->n;
                node->next = NULL;
                if (erase[ep] == NULL) {
                    erase[ep] = node;
                    elast[ep] = node;
                }
                else {
                    elast[ep]->next = node;
                    elast[ep] = node;
                }
            }
        }

        if (tp == 0) break;

        for (int i = 0; i < tp; i++) {
            if (erasetmp[i]->prev == NULL) return 1;
            if (erasetmp[i]->next == NULL) return 1;
            //if (erasetmp[i]->next->jump == NULL) return 1;
            erasetmp[i]->prev->next = erasetmp[i]->next;
            erasetmp[i]->prev->jump = erasetmp[i]->next;
            erasetmp[i]->next->prev = erasetmp[i]->prev;
            erasetmp[i]->n = -2;
            if (q->next->jump == erasetmp[i] && erasetmp[i] != q->next) {
                q->next->jump = erasetmp[i]->prev;
            }

            if (erasetmp[i]->next->jump == erasetmp[i]->next->next || erasetmp[i]->next->jump == NULL || erasetmp[i]->jump->next == NULL) continue;
            while (erasetmp[i]->next->jump->n == -2 || erasetmp[i]->next->jump->n < erasetmp[i]->next->jump->next->n) {
                erasetmp[i]->next->jump = erasetmp[i]->next->jump->prev;
                /*
                if (erasetmp[i]->jump->n < erasetmp[i]->jump->next->n) {
                    erasetmp[i]->next->jump = erasetmp[i]->jump->prev;
                }
                else {
                    erasetmp[i]->next->jump = erasetmp[i]->jump;
                    if (erasetmp[i]->next->jump == erasetmp[i]->next) {
                        erasetmp[i]->next->jump = erasetmp[i]->next->next;
                        while (erasetmp[i]->next->jump->n == -2) erasetmp[i]->next->jump = erasetmp[i]->next->jump->next;
                    }
                }
                */
            }
            if (erasetmp[i]->next->jump == erasetmp[i]->next) {
                erasetmp[i]->next->jump = erasetmp[i]->next->next;
                while (erasetmp[i]->next->jump->n == -2 || erasetmp[i]->next->jump->n < erasetmp[i]->next->jump->next->n) {
                    erasetmp[i]->next->jump = erasetmp[i]->next->jump->next;
                }
            }
            
        }
        ep++;
        if (ep > 100000) return 1;
    }
    printf("%d\n", ep);
    for (int i = 0; i < ep; i++) {
        for (llst* j = erase[i]; j; j = j->next) {
            printf("%d ", j->n);
        }
        printf("\n");
    }
    for (llst* i = q->next; i->next; i = i->next) {
        printf("%d ", i->n);
    }
    return 0;
}