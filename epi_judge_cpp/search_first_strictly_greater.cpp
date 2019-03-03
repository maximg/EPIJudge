
#include <iostream>
#include <vector>

using namespace std;
using std::vector;


int SearchFirstGreater(const vector<int>& A, int k) {
    int l = 0, h = A.size() - 1;
    int res = -1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (A[m] <= k) {
            l = m + 1;
        }
        else {
            res = m;
            h = m - 1;
        }
    }
    return res;
}

int main() {
    vector<int> arrs = {0,1,2,3,5,6,7};

    auto v = SearchFirstGreater(arrs, 10);
    cout << v << endl;
}