//Minimum Scalar Product
#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
//using namespace std;

long minimumProduct(std::vector<long> &a, std::vector<long> &b){
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    //std::sort(b.r.begin(), b.rend()); // xxx
    long long product = 0;
    for (int i =0; i < a.size(); i++){
      product += (a[i] * b[b.size()-1-i]);
      //product += (a[i] * b[i]); // xxx
    }
    return product;
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests, n, temp;
  scanf("%d", tests);
  for (int t = 1; t <= tests; t++){
    scanf("%d",&n);
    std::vector<long> a, b;
    for (int i = 0; i < n; i++){
      scanf("%d",&temp);
      a.emplace_back(temp);
    }
    for (int i = 0; i < n; i++){
      scanf("%d",&temp);
      b.emplace_back(temp);
    }
    long long product = minimumProduct(a, b);
    printf("Case #%d: %lld\n",t,product);
  }
  return 0;
}
