#include <stdio.h>

int in[103000], po[103000];

void find(int si, int ei, int sp, int ep) {
    int t = -1, r = po[ep];
    printf("%d ", r);
    for (int i = si; i <= ei; i++) {
        if (in[i] == r) {
            t = i;
            break;
        }
    }
    if(t > si) find(si, t - 1, sp, sp + (t - si - 1));
    if(t < ei) find(t + 1, ei, sp + (t - si), ep - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &po[i]);
    }
    find(0, n - 1, 0, n - 1);
    return 0;
}