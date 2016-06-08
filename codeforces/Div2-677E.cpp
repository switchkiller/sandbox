
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define MOD 1000000007

const int MAX = 1000;

int dist[8][2] = {{-1,-1},{-1,1},{1,-1},{1,1},{1,0},{0,1},{-1,0},{0,-1}};

int n;
double arr[8][MAX][MAX];   // Find for all directions i.e L, R, T, B, LR, RT, LB, RB
int parr[8][MAX][MAX], ansx, ansy, ansn, ansdir;
double ans=-1; long long total=0;
bool inrange(int x){
    return (x >= 0 && x < n);
}

int main(){
    cin >> n;
    string s[n];
    REP(i,0,n)
        cin >> s[i];

    // Converting data to logs is one optimisation
    double logs[n][n];
    REP(i,0,n){
        REP(j,0,n){
            if (s[i][j] == '2')
                logs[i][j] = log(2);
            else if (s[i][j] == '3')
                logs[i][j] = log(3);
        }
    }

    REP(x,0,8){
        REP(i,0,n){
            REP(j,0,n){
                if (!inrange(i-dist[x][0]) || !inrange(j-dist[x][1])){
                    long long distx = dist[x][0], disty = dist[x][1], k=0;
                    for(long long p=i, q=j; inrange(p) && inrange(q); p+=distx, q+=disty){
                        if (s[p][q] != '0'){
                            k++;
                            if (p==i && q==j)
                                arr[x][p][q] = logs[p][q];
                            else
                                arr[x][p][q] =  arr[x][p-distx][q-disty] + logs[p][q];
                        }
                        else{
                            arr[x][p][q] = 0;
                            k=0;
                        }
                        parr[x][p][q] = k; // I liked this usage and the usage of the 3D array to get the sum as a whole in 8 directions.
                    }
                }
            }
        }
    }

    // We have built an array which will contain after what distance there is a non zero number in a given direction. Now we use the property of logs to compare and get the maximum product. We have used arr which will contain sum of logs in a given direction...now we need to search for the maximum.

    // This question is good. We are dealing with 3D array and apply DP collectively. Though its a Div2E.

    // We have to deal with normal cross and rotated cross. So we will iterate througout the string, but we know wherever a[i][j] such that i and j are bounded by n, they should not be 0, otherwise the product becomes 0.

    // int ans=-1, ansx, ansy, ansn, ansdir, total=0; // This will hold the maximum throught the array arr[][][].
    REP(i,0,n)
        REP(j,0,n)
            if (s[i][j] != '0'){

                // Now we have to use arr & parr for given direction..we are already having i and j to iterate, now we need to iterate 8 directions, and hold the maximum?
                //1. Round up procedure.
                int tmp = n + 10; // tmp is sufficiently choosen large
                REP(k,0,4)
                    tmp = min(tmp, parr[k][i][j]); // We know that parr[][][] will count the number of the non zeros in given direction upto given (i,j). So choosing the minimum will help to get proper nXn product.
                    // After we get this, i.e the proper nXn size which is possible, we will take the product as answer.
                double val = logs[i][j]; // We need to add it to our answer later.
                // I really appreciate this technique.

                REP(k,0,4)
                // Now make the use of the directions arr[][][] which might be tricky
                    val += arr[k][i+dist[k][0]*(tmp-1)][j+dist[k][1]*(tmp-1)] - arr[k][i][j]; // I am really obsessed by the solution, how amazing it is. Thanks !

                if (val > ans){
                    ans = val;
                    ansx = i;
                    ansy = j;
                    ansn = tmp;
                    ansdir = 0;
                }
                // Normal procedure.
                tmp = n + 5;
                REP(k,4,8)
                    tmp = min(tmp, parr[k][i][j]);
                val = logs[i][j];
                REP(k,4,8)
                    val += arr[k][i+dist[k][0]*(tmp-1)][j+dist[k][1]*(tmp-1)] - arr[k][i][j];

                if (val > ans){
                    ans = val;
                    ansx = i;
                    ansy = j;
                    ansn = tmp;
                    ansdir = 4;
                }
            }
    total = s[ansx][ansy]-'0';
    REP(k,ansdir,ansdir+4)
        REP(i,1,ansn)
            total = (total*(s[ansx+dist[k][0]*i][ansy+dist[k][1]*i] - '0'))%MOD;
    cout << total << endl;
    return 0;
}
