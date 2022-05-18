#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <random>
using namespace std;

/*
문제 : N(N <= 5000)개의 소포가 있다. 각 소포의 무게는 200000 이하의 자연수이며, 모든 소포의 무게는 다르다.
이때, 4개의 서로 다른 소포의 무게 합이 W(10 <= W <= 799994)가 되는 경우가 있는 지 구한다.

해결 방법 : 수열을 무작위하게 섞은 후 앞쪽 절반 중 2개를 뽑은 것과,
뒤쪽 절반 중 2개를 뽑은 것의 합을 각각의 배열에 저장한다. 그 후 두 배열을 순회하면서
합이 W가 되는 경우가 있는 지 확인한다. 이러면 앞에서 2개를 뽑고 뒤에서 2개를 뽑는 경우가 최적인 경우는
37.5%가 된다. 충분히(30회 이상) 반복하면 매우 높은 확률(99.9999% 이상)로 정답을 찾을 수 있다.
반복 횟수가 중요하므로 어느 정도 최적화가 이루어져야 하며 랜덤 함수도 잘 확인해야 한다.

주요 알고리즘 : 밋 인 더 미들, 무작위화

출처 : Seoul 2018I F번
*/

int a[5120];
char memlo[103000 * 4], memhi[103000 * 4];

int main(void) {
    int w, n, r = 0;
    scanf("%d %d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //a[i] = i + 1;
    }
    for (int randi = 0; randi < 39; randi++) {
        shuffle(a, a + n, std::default_random_engine(clock() * 401 + randi * 31));
        for (int i = 0; i < (n >> 1); i++) {
            for (int j = i + 1; j < (n >> 1); j++) {
                memlo[a[i] + a[j]] = 1;
            }
        }
        for (int i = n >> 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                memhi[a[i] + a[j]] = 1;
            }
        }
        for (int i = 2; i <= w && i <= 400000; i++) {
            if (w - i > 400000) continue;
            if (memlo[i] && memhi[w - i]) r = 1;
        }
        memset(memlo, 0, sizeof(memlo));
        memset(memhi, 0, sizeof(memhi));
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}