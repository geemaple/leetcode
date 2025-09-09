#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cout << arr[i] + 1LL * k * (arr[i] % (k + 1)) << ' ';
        }
        cout << '\n';
    }
}

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main2() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    for (int g = 2; g <= k + 1; g++) {
      if (gcd(g, k) == 1) {
        for (auto &i : a) {
            while (i % g != 0) {
                i += k;
            }   
        }
        for (auto &i : a) {
            cout << i << ' ';
        }
            
        cout << '\n';
        break;
      }
    }
  }
}