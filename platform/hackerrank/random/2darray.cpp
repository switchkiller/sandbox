#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int N = arr.size(), M = arr[0].size();
    int mx = -0x3f3f3f3f;
    int dy[] = {-1, 0, 1};

    for (int i = 1; i < N-1; i++)
        for (int j = 1; j < M-1; j++){
            int s = arr[i][j];
            for (int k = 0; k < 3; k++)
                s+= arr[i-1][j+dy[k]] + arr[i+1][j+dy[k]];
            mx = max(mx, s);
        }
    return mx;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
