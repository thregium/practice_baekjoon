#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ed[512], de[512];
int in[512], tm[512], mem[512];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tm[i]);
        while (1) {
            scanf("%d", &x);
            if (x < 0) break;
            ed[i].push_back(x);
            de[x].push_back(i);
            in[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (in[j] == 0) {
                x = 0;
                for (int k = 0; k < ed[j].size(); k++) {
                    x = big(x, mem[ed[j][k]]);
                }
                mem[j] = x + tm[j];
                in[j]--;
                for (int k = 0; k < de[j].size(); k++) {
                    in[de[j][k]]--;
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", mem[i]);
    }
    return 0;
}