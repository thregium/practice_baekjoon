#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

/*
문제 : 6자리 이하의 자연수 N과 10 이하의 자연수 K가 주어질 때, N의 자리를 K회 바꾸어 만들 수 있는 자연수 가운데
가장 큰 것을 고른다. 단, 중간 과정에서 0이 맨 앞에 오는 경우가 나오면 안 된다.
바꿀 수 없다면 -1을 출력하면 된다.

해결 방법 : BFS를 하되, 같은 수에 여러번 도달 가능하다록 각 자연수와 바꾼 횟수에 따라 방문 여부를 다르게 저장한다.
처음 N과의 거리가 K가 될 때 까지 이를 반복하고, 거리가 K인 것 가운데 가장 큰 값을 구하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 해시셋

출처 : SRM 437 D1A/D2B
*/

int tmp[16];
queue<int> q; //큐와 셋에는 N * 100 + K의 값을 저장한다.
unordered_set<int> us;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int bfs(int n, int k) {
    int d = 0, dist, res = -1;
    q.push(n * 100);
    us.insert(n * 100);
    while (n) {
        d++; //미리 자릿수를 구한다.
        n /= 10;
    }
    while (q.size()) {
        n = q.front();
        q.pop();
        dist = n % 100;
        n /= 100;
        if (dist > k) continue;
        else if (dist == k) {
            if (n > res) res = n; //K회 바꾼 것 가운데 가장 큰 것을 구한다.
        }
        for (int i = 0; i < d; i++) {
            tmp[d - i - 1] = n % 10; //각 자릿수로 나눈다.
            n /= 10;
        }
        for (int i = 0; i < d; i++) {
            for (int j = i + 1; j < d; j++) {
                //해당 자릿수의 모든 교환을 추가한다.
                swap(&tmp[i], &tmp[j]);
                if (tmp[0] == 0) {
                    swap(&tmp[i], &tmp[j]);
                    continue;
                }
                n = 0;
                for (int i = 0; i < d; i++) {
                    n *= 10;
                    n += tmp[i];
                }
                if (us.find(n * 100 + dist + 1) == us.end()) {
                    //이미 방문하지 않은 경우 다시 방문한다.
                    us.insert(n * 100 + dist + 1);
                    q.push(n * 100 + dist + 1);
                }
                swap(&tmp[i], &tmp[j]);
            }
        }
    }
    return res;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", bfs(n, k));
    return 0;
}