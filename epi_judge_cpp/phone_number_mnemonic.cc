#include <string>
#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;
vector<string> PhoneMnemonic(const string& phone_number) {
    vector<string> M =
        { "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

    if (phone_number.empty())
        return {};

    vector<string> perms;
    int pos = 0;
    std::queue<string> bfs;
    bfs.push({});
    while (!bfs.empty()) {
        string next = bfs.front();
        bfs.pop();
        if (next.length() == phone_number.length()) {
            perms.push_back(next);
            continue;
        }

        int pos = next.length();
        char c = phone_number[pos];
        if (c == '*' || c == '#')
            bfs.push(next + c);
        else for (char alpha: M[c - '0'])
            bfs.push(next + alpha);
    }

    return perms;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  return GenericTestMain(args, "phone_number_mnemonic.cc",
                         "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         &UnorderedComparator<std::vector<std::string>>,
                         param_names);
}
