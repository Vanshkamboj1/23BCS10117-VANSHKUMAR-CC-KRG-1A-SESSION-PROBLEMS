#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool insideConvex(vector<Point>& A, Point p) {
    int n = A.size();
    
    if (cross(A[0], A[1], p) >= 0) return false;
    if (cross(A[0], A[n-1], p) <= 0) return false;
    
    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross(A[0], A[mid], p) < 0)
            l = mid;
        else
            r = mid;
    }
    
    return cross(A[l], A[l+1], p) < 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y;

    int m;
    cin >> m;
    vector<Point> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i].x >> B[i].y;

    for (int i = 0; i < m; i++) {
        if (!insideConvex(A, B[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}