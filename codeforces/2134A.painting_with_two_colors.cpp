#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a > b) {
            cout << ((a % 2 == b % 2 && n % 2 == a % 2) ? "YES" : "NO") << endl;
        } else {
            cout << (n % 2 == b % 2 ? "YES" : "NO") << endl;
        }
    }
}