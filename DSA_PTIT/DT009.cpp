#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;
int n, k;

struct matran {
    long long F[11][11];
    friend istream& operator>>(istream& in, matran& x)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x.F[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, matran x)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out << x.F[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

matran operator*(matran a, matran b)
{
    matran ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans.F[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ans.F[i][j] += a.F[i][k] * b.F[k][j];
                ans.F[i][j] %= MOD;
            }
        }
    }
    return ans;
}

matran powMod(matran a, long long k)
{
    if (k == 1) {
        return a;
    }
    matran x = powMod(a, k / 2);
    if (k % 2 == 1) {
        return x * x * a;
    } else {
        return x * x;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        matran a;
        cin >> a;
        matran res = powMod(a, k);
        long long tong = 0;
        for (int i = 0; i < n; i++) {
            tong += res.F[i][i];
            tong %= MOD;
        }
        cout << tong << endl;
    }
    return 0;
}