#include <stdio.h>
#include <malloc.h>

/*
문제 : N명의 학생들의 키를 M번 비교했을 때, 학생들을 키 순서대로 정렬한 것이 될 수 있는 방법 가운데 아무거나 하나를 출력한다. (N <= 32000, M <= 100000)

해결 방법 : 위상 정렬을 이용해 학생들의 키를 비교한 것을 순서대로 확인한다. N이 크기 때문에 우선순위 큐와 연결 리스트를 활용한다.
우선순위 큐에 새로운 원소를 넣을 때에는 각 원소의 진입 차수가 같다면 나중에 넣은 원소가 위로 가도록 해야 한다.

주요 알고리즘 : 그래프 이론, 위상 정렬, 우선순위 큐, 연결 리스트
*/

typedef struct ilist {
     int n;
     struct ilist* l;
} ilist;

ilist* hcmp[32768]; //링크(연결 리스트 형)
int hent[32768]; //진입 차수

int hh[131072]; //힙
int hs = 0; //힙 사이즈
int chk[32768]; //방문 체크

void hpush(int x) {
     int t = ++hs;

     for (; t > 1; t /= 2) {
          if (hent[x] <= hent[hh[t / 2]]) hh[t] = hh[t / 2]; //새로운 원소의 진입 차수와 비교하는 원소의 진입 차수가 같은 경우 새로운 원소를 위로 올려보냄
          else break;
     }
     hh[t] = x;
}

int hpop(void) {
     int r = hh[1], t = hh[hs--];
     int p = 1, c = 2;

     while (c <= hs) {
          if (c < hs && hent[hh[c]] > hent[hh[c + 1]]) c++; //오른쪽이 더 작은 경우
          if (hent[t] <= hent[hh[c]]) break; //맨 아래 있던 노드가 더 작으면 중지
          hh[p] = hh[c];
          p = c;
          c *= 2;
     }
     hh[p] = t;

     return r;
}

int main(void) {
     int n, m, a, b, x;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d", &a, &b);
          ilist* ab;
          ab = calloc(1, sizeof(ilist));
          ab->n = b;
          ab->l = hcmp[a];
          hcmp[a] = ab;
          hent[b]++;
     }
     for (int i = 1; i <= n; i++) {
          hpush(i);
     }
     for (int i = 0; i < n; i++) {
          while (1) {
               x = hpop();
               if (!chk[x]) {
                    chk[x] = 1; //방문 체크는 힙에서 뺄 때
                    break;
               }
          }
          if (hent[x]) break;
          else {
               printf("%d ", x);
               for (ilist* hl = hcmp[x]; hl; hl = hl->l) {
                    hent[hl->n]--;
                    hpush(hl->n);
                    //if (hs > 120000) return 1;
               }
          }
     }
     return 0;
}