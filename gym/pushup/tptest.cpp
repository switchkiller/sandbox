/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
int n, m;
visited[2005][2005];
int count;
// 0,2,5,7
int dx [] = {-1,0,1,-1,1,-1,0,1}, dy[] = {-1,-1,-1,0,0,1,1,1};
char match1[] = "_#_##_#_";
char match2[] = "#_#__#_#";
bool dfs(int i, int j, int type){
    if (i < 0 || i >= n || j < 0 || j >= m) return true;
    if (mat[i][j] == match1[type]) return true;
    for (int x = 0; x < 8; x++){
        if (mat[i][j] == "_")
        dfs(i+dx[x], j + dy[x], i);
    }

}
int main(){
    cin >> n >> m;
    char mat[n+1][m+1];
    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j]){
                if (dfs(i,j))   count++;
            }

    cout << count << endl;
    return 0;
}
