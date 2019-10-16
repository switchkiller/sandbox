#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (i = (a); i < (b); i++)
#define all(X) X.begin(), X.end()

// XXX whenever we have to associate an id with numbers use structures

// Because I am sorting, the id will get lost, so its better to use structures

typedef struct{
	int C, id;
} T;

int cmp(const void *i, const void *j){
	T *x, *y;
	x = (T *) i, y = (T *) j;	// args to cmp are of the type of the object type to be sorted.
	if (x->C != y->C)
		return y->C - x->C;
	return x->C - y->C;
}


int main(){
	int N, M;
	while (scanf("%d %d", &N, &M) && N && M){
		T team[70];
		T table[70];
		int ans[70][70];
		int i, j;
		REP(i,0,N){
			cin >> team[i].C; team[i].id = i;
		}
		REP(i,0,M){
			cin >> table[i].C; table[i].id = i;
		}
		qsort(team, N, sizeof(T), cmp);
		REP(i,0,N){
			qsort(table, M, sizeof(T), cmp);
			int temp = team[i].C, idx = 0, err = 0;
			REP(j,0,M) {
				if (temp == 0) break;
				if (table[j].C){
					ans[team[i].id][idx++] = table[j].id;
					table[j].C--;
					temp--;
				}
				else{
					err = 1;				
					break;
				}
			}
			if (temp || err) break;
		}
		// cout << i;
		if (i == N){
			cout << "1" << endl;
			int len[70];
			REP(i,0,N){
				int n = team[i].C;
				len[team[i].id] = team[i].C;
				sort(ans[team[i].id], ans[team[i].id]+n);
			}
			REP(i,0,N){
				cout << ans[i][0]+1;
				REP(j,1,len[i])
					cout << " " << ans[i][j]+1;
				cout << endl;
			}
		}
		else 
			cout << "0" << endl;
		}
	return 0;
}