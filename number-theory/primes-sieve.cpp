//Generate prime numbers using sieve of eratosthenes.
#include<iostream>
#include<bitset>
#include<vector>
typedef long long ll;
using namespace std;
ll sieve_size;
bitset<10000010> bs;
typedef vector<int> vi;
vi primes;
#define REP(i,m,n) for(int i = m; i <= n; i++)

void sieve(ll upperbound){
  sieve_size = upperbound + 1;
  bs.reset();
  bs.flip();
  bs.set(0, false);
  bs.set(1, false);
  for (ll i = 2; i <= sieve_size; i++) if (bs.test((size_t)i)){
    for (ll j = i * i; j <= sieve_size; j += i) bs.set((size_t)j, false);
    primes.push_back((int)i);
  }
}

bool isPrime(ll N){
  if (N < sieve_size) return bs.test(N);
  REP(i, 0, primes.size()-1) if (N % primes[i] == 0) return false;
  return true;
}

int main(){
  sieve(1000000);
  cout<<isPrime(5915587277);
}
