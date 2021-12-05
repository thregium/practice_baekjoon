#include <stdio.h>
#include <time.h>
#include <map>
#include <set>
using namespace std;

/*
문제 : N(N <= 200000)개의 1부터 K(K <= N)까지의 자연수로 이루어진 수열이 주어진다. 이때, 이 수열의 부분수열 가운데
1부터 K까지 모든 자연수가 들어있고 사전순으로 가장 빠른 부분 수열을 구한다.
주어지는 수열에는 1부터 K까지의 모든 자연수가 들어 있다.

해결 방법 : 뒤에서부터 수들을 확인하며 각 수가 처음 나오는 곳마다 구간을 나누어 둔다.
각 구간 내에서는 구간의 마지막 수(또는 그와 같은 수)를 뽑으며 오름차순으로 가장 작은 수부터 뽑는 것이 이득임을 알 수 있다.
가장 작은 맨 앞의 수를 뽑고, 그 뒤의 수 가운데 가장 작은 수, ... 를 반복해 나간다.
마지막 수가 뽑히면 다음 구간으로 나아간다. 이때, 해당 구간의 마지막 수가 이미 뽑혔다면 다음 구간까지 살펴보아야 한다.
이를 반복하면 답을 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 자료 구조, 셋, 맵

출처 : PacNW 2019 B번
*/

char chk[204800];
int a[204800];
map<int, int> lower; //해당 구간 이후의 수들과 각 수의 개수
map<int, set<int>> upper; //해당 구간까지의 수들 가운데 아직 뽑지 않은 수와 그 수가 있는 위치들

int main(void) {
    int n, k, p = -1, last = -1;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2019\\perfectflush\\data\\secret\\PerfectFlush-1005.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2019\\perfectflush\\data\\secret\\PerfectFlush-1005_t.out", "w", stdout);
    scanf("%d %d", &n, &k);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //a[i] = rand() % k + 1;
        //printf("%d ", a[i]);
    }
    //printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        //뒤에서부터 수들을 살펴본다. 모든 수가 한 번씩 나올 때 까지 뒤쪽 수들을 담은 셋에 추가한다.
        if (lower.find(a[i]) == lower.end()) lower.insert(pair<int, int>(a[i], 1));
        else lower[a[i]]++;
        if (lower.size() == k) {
            lower.erase(a[i]);
            last = i;
            break;
        }
    }
    for (int i = 0; i <= last; i++) {
        //뒤에서부터 봤을 때 모든 수가 나오는 지점까지 앞에서부터 수들을 추가한다.
        if (upper.find(a[i]) == upper.end()) upper.insert(pair<int, set<int>>(a[i], set<int>{i}));
        else upper[a[i]].insert(i);
    }
    p = *(upper.begin()->second.begin());
    for (int i = k - 1; i >= 0; i--) {
        //모든 수를 찾을 때 까지 현재 구간에서 이전 수 이후의 수 가운데 가장 작은 수를 찾는 것을 반복한다.
        printf("%d", a[p]);
        chk[a[p]] = 1;
        if (i == 0) break;
        else printf(" ");

        while (chk[a[last]] || a[p] == a[last]) {
            //마지막 수를 찾은 경우 다음 구간을 살펴본다.
            for (int j = last + 1; j < n; j++) {
                if (!chk[a[j]]) {
                    if (upper.find(a[j]) == upper.end()) upper.insert(pair<int, set<int>>(a[j], set<int>{j}));
                    else upper[a[j]].insert(j);
                }
                if (lower[a[j]] == 1) {
                    lower.erase(a[j]);
                    last = j;
                    break;
                }
                else lower[a[j]]--;
            }
        }
        while (*(upper.begin()->second.begin()) <= p || chk[upper.begin()->first]) {
            //이전 수 이후의 수 가운데 가장 작은 것을 찾는다.
            upper.begin()->second.erase(upper.begin()->second.begin());
            if (upper.begin()->second.empty()) upper.erase(upper.begin());
            if (upper.empty()) break;
        }
        p = *(upper.begin()->second.begin());
    }
    printf("\n");
    return 0;
}