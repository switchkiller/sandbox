#include <iostream>
#include <vector>
#include <bitset>
#include <set>
using namespace std;
int main()
{
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    int *arr = new int[N];
    arr[0] = S % (10000000);
    for (int i = 1; i < N; i++)
        arr[i] = arr[i-1]*P + (Q % (10000000));
    set<int> s(&arr[0], &arr[N]);
    cout << s.size() << endl;
    return 0;
}
