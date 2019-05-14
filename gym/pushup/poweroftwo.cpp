// Atcoder - 029
/* Problem Description:

*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>


using namespace std;

int main(){
	int n;
	cin >> n;
	long arr[n];
	map<long, int> mp;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	sort(arr, arr+n);
	int ans = 0;
	for(int i = n-1; i >= 0; --i){
		long pwr = 1;
		while (pwr <= arr[i]) pwr *= 2;
		mp[arr[i]]--;
		long need = pwr - arr[i];
		if (mp[need] > 0){
			ans++;
			mp[need]--;
		}
    else if (need == arr[i]){
      if (mp[0] > 0){
        ans++;
        mp[0]--;
      }
    }
	}
	cout << ans;
	return 0;
}
