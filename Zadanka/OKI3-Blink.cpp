#include<iostream>

#define NMAX 16

int firstOcc[1 << NMAX];
int stateAtT[1 << NMAX];

int main() {
    int n;
    long long b;
    scanf("%d", &n);
    scanf("%lld", &b);
    int state = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            state = state | (1 << i);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        firstOcc[i] = -1;
    }

    int t = 0;
    firstOcc[state] = 0;
    stateAtT[0] = t;
    while ((long long) t < b) {
        t++;
        int rot = (state << 1);
        rot = (rot | (rot >> n)) & ((1 << n) - 1);
        state = state ^ rot;

        if (firstOcc[state] == -1) {
            firstOcc[state] = t;
            stateAtT[t] = state;
        } else {
            int cyclelen = t - firstOcc[state];
            int t1 = firstOcc[state] + (int) ((b - (long long) firstOcc[state]) % (long long) cyclelen);
            state = stateAtT[t1];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", (state >> i) & 1);
    }
}