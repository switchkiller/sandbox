#include<bits/stdc++.h>
using namespace std;

bitset<1000010> bs;	//better than using vector<bool> 10^7 must be enough.
vector<int> primes;


void sieve(long long upper_bound){
	bs.set();	// Add 1 to include at the upper bound
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= upper_bound+1; i++)	//optimized
		if (bs[i]){
			for (long long j = i*i; j <= upper_bound + 1; j += i) //optimized
				bs[j] = 0;
			primes.push_back((int)i);
		}																																																																																																																																		
}

int main(){
	int N, T = 0;
	sieve(1000000);
	while (cin >> N){
		if (N == 0)
			break;
		T++;
		int i = 0, t = 0;
		while (primes[i] < N){
			//set the iterator to initial lower_bound position and specifying a range of data until primes[i] + primes[j] <= n
			vector<int>::iterator itr = lower_bound(primes.begin(), primes.end(), N-primes[i]);

			while (itr - primes.begin() < primes.size()){
				int j = itr - primes.begin();	// position of the itr
				if (j <= i) break;	// because we have to search element (prime number) before i th position. 
				itr--; // because maximum for primes[i] the iterator can have lower_bound itr so decrement it..so that we can get all the possible prime values
				if (primes[i] + primes[j] > N) continue;
				t += j-i; //trivial
				break;
			} 		
			i++;
		}
		cout << "Case " << T << ": " << t << endl;  																																																																	
		}
	return 0;
}																																													