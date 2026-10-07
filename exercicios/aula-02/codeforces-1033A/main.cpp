#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ax, ay;
    cin >> ax >> ay;

    int bx, by;
    cin >> bx >> by;

    int cx, cy;
    cin >> cx >> cy;

    bool b = (bx < ax) == (cx < ax) && (by < ay) == (cy < ay);

    if (b) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    
}