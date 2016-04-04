// Qualification Round Africa 2010

#include<bits/stdc++.h>
#define REP(i,a,b) for (int (i) = (a); (i) < (b); i++)
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii; 
vii lst;
ii ans;
/*struct CompareFirst
{
  CompareFirst(int val) : val_(val) {}
  bool operator()(const std::pair<int,char>& elem) const {
    return val_ == elem.first;
  }
  private:
    int val_;
};*/

void finditems(int C, int n, int cs){
	int item;
	/*for (vector<ii>::iterator itr1 = lst.begin(); itr1 != lst.end(); itr1++){
		if (C < (*itr1).first)
			item = C - (*itr1).first;
		else
			continue;
		vii::iterator pos = lower_bound(itr1+1, lst.end(), CompairFirst(item));
		if ((*pos).first == item ){
			arr[0] = (*itr1).first;
			arr[1] = (*pos).second;
			break;
		}
	}*/
	REP(i,0,n){
		int key;
		if (C > lst[i].first) 
			key = C - lst[i].first;
		else
			continue;
		int low = i + 1, high = n-1, mid;
		while (low <= high){
			mid = (low+high)/2;
			if (lst[mid].first == key){
				ans = make_pair(lst[i].second+1, lst[mid].second+1);
				break;
			}
			else if (lst[mid].first > key)
				high = mid - 1;
			else 
				low = mid + 1;
		}

	}
}


int main(){
	
	ifstream infile;
	ofstream outfile;
	infile.open("A-small-practice.in");
	outfile.open("A-small-practice.out");

	int N, C, I, val, cs = 0;
	infile >> N;
	while (N--){
		infile >> C >> I;
		REP(i,0,I){
			infile >> val;
			lst.push_back(make_pair(val, i));
		}
		sort(lst.begin(), lst.end());
		cs++;
		finditems(C, I, cs);
		lst.clear();
		if (ans.first > ans. second)
			outfile << "Case #" << cs << ": " << ans.second <<" " << ans.first << endl;
		else
			outfile << "Case #" << cs << ": " << ans.first <<" " << ans.second << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}