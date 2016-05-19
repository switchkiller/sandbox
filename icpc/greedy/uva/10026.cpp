#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i < (b); i++)

struct Job{
	int time;
	int fine;
	int id;
};

bool comp(const Job &j1, const Job &j2)
{
    return j1.time * j2.fine < j2.time * j1.fine;
}

int main(){
	int T, N;
	//	vector< pair<ii, int> > v; went complicated. 
	cin >> T;
	while(T--){
		cin >> N;
		vector<Job> v(N);
		REP(i,0,N){
		cin >> v[i].time >> v[i].fine;
		v[i].id = i+1;	}
		stable_sort(v.begin(), v.end(), comp); // Important! XXX Quick sort fails! Because we want lexographical ordering.
		vector<Job>::iterator itr = v.begin();
		cout << (*itr).id; itr++;
		for (; itr != v.end(); itr++)
			cout << " " << (*itr).id ;
		if (T) cout << endl;
	}
	return 0;
} 