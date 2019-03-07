
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
struct compareSecond {
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs.second > rhs.second;
    }
};

int minTutors(vector<int> A) {
    if (A.empty())
        return 0;

    sort(A.begin(), A.end());

    using Tutor = pair<int, int>;   // start, end
    priority_queue<Tutor, vector<Tutor>, compareSecond<Tutor>> Q;

    int count = 0;
    for (auto& t: A) {
        //cout << "Time: " << t << endl;

        while (!Q.empty()) {
            //cout << "Earliest: " << Q.top().second << endl;
            if (Q.top().second <= t) {
                auto current = Q.top();
                Q.pop();
                if (current.first + 90 > t) {
                    current.second = t + 30;
                    Q.push(current);
                    goto end_loop;
                }
            }
            else
                break;
        }
        //cout << "Add new: " << t << endl;
        Q.push({t, t+30});
        ++count;
    end_loop:
        ;
    }
    return count;
}

int main() {
    vector<int> ttt = { 0, 30, 40, 65, 95 };
    cout << minTutors(ttt) << endl;
}