#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    int64_t ans = 0;

    vector<int> dist(N + 1, -1), from(N + 1), nOddChangedToGetHere(N + 1);

    dist[N] = 0;
    from[N] = -1;

    vector<int> q;
    q.push_back(N);

    for(int i = 0; i < q.size(); i++) {
        int nEven = q[i];
        int nOdd = N - nEven;

        for(int nOddToChange = 0; nOddToChange <= min(nOdd, K); nOddToChange++) {
            int nEvenToChange = K - nOddToChange;
            int otherNode = nEven - nEvenToChange + nOddToChange;

            if(otherNode < 0 || nEvenToChange > nEven || otherNode > N) {
                continue;
            }

            if(dist[otherNode] != -1) 
                continue;

            dist[otherNode] = dist[nEven] + 1;
            from[otherNode] = nEven;
            nOddChangedToGetHere[otherNode] = nOddToChange;
            q.push_back(otherNode);
        }
    }

    vector<int> nOddsChanged;

    int at = 0;
    if(dist[at] == -1) {
        cout << -1 << endl;
        return;
    }
    while(at != N) {
        nOddsChanged.push_back(nOddChangedToGetHere[at]);
        at = from[at];
    }

    deque<int> even, odd;

    for(int i = 0; i < N; i++) {
        even.push_back(i);
    }

    for(int i = nOddsChanged.size() - 1; i >= 0; i--) {
        int nOddsToChange = nOddsChanged[i];
        int nEvensToChange = K - nOddsToChange;

        vector<int> queryIndexes;
        for(int i = 0; i < nEvensToChange; i++) {
            int makeOdd = even.front();
            even.pop_front();
            odd.push_back(makeOdd);
            queryIndexes.push_back(makeOdd);
        }
        for(int i = 0; i < nOddsToChange; i++) {
            int makeEven = odd.front();
            odd.pop_front();
            even.push_back(makeEven);
            queryIndexes.push_back(makeEven);
        }

        cout << "? ";
        for(auto index: queryIndexes) {
            cout << index + 1 << " ";
        }
        cout << endl;
        int64_t xorSum;
        cin >> xorSum;
        ans ^= xorSum;
    }

    cout << "! " << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}