#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
#include <random>

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int partition(vector<int>& A, int pivot_idx, int ll, int hh) {
    int l = ll, h = hh;    // l: first unsorted entry, h - last
    int pivot = A[pivot_idx];
    std::swap(A[hh], A[pivot_idx]);
    int largest_value = ll;
    for (int i = ll; i < hh; ++i) {
      if (A[i] > pivot)
        std::swap(A[i], A[largest_value++]);
    }
    std::swap(A[hh], A[largest_value]);    
    return largest_value;
}

int FindKthLargest(int k, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;

    int ll = 0, hh = A.size() - 1;
    while (ll <= hh) {
        std::default_random_engine gen((std::random_device())());
        std::uniform_int_distribution<int> dis(ll, hh);
        int l = partition(A, dis(gen), ll, hh);
        if (l == k - 1)
            return A[l];
        if (l > k - 1)
            hh = l - 1;
        else
            ll = l + 1;
    }
    return 0;
}

int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
