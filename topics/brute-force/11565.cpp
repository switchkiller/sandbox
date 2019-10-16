#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int N, x, y, z, A, B, C;
    cin >> N;
    while (N--){
        bool sol=false;
        cin >> A >> B >> C;
        for(x=-22;x <= 22 && !sol; x++)
            if (x * x <= C)
                for (y = -100; y <= 100 && !sol; y++)
                    if (y != x && x*x + y*y <= C)
                        for (z = -100; z <= 100 && !sol; z++)
                            if (z != x && z != y && x + y + z == A && x * y * z == B && x*x + y*y + z*z == C){
                                cout << x << " "<< y << " " << z << endl;
                                sol = true;
                            }
        if (sol == false)
            cout << "No solution." << endl;
    }
    return 0;
}
