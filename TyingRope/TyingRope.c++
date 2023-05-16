#include <bits/stdc++.h>

using namespace std;
template<typename T> 
struct SIMPLE_UFDS{
  std::vector<T> ps;
  SIMPLE_UFDS(T n):ps(n){
    iota(ps.begin(), ps.end(), 0);
  }


  T find_set(T x){
    return x == ps[x] ? x : ps[x] = find_set(ps[x]);
  }

  bool same_set(T a, T b){
    return find_set(a) == find_set(b);
  }



  void union_set(T a, T b){
    T p = find_set(a);
    T q = find_set(b);

    if (p == q)
      return;

    ps[q] = p;
  }


};



int main(){
  int n, m;
  cin >> n >> m;

  SIMPLE_UFDS<int> ufds(n);
  int res = 0;

  while(m--){
    char trash;
    int a, b;
    cin >> a >> trash >> b >> trash;


    if ( ufds.same_set(a-1, b-1)){
      res++;
    }else {
      ufds.union_set(a-1,b-1);
    }

  }

  set<int> c;
  for (auto e : ufds.ps)
    c.insert(ufds.find_set(e));

  cout << res <<" " << c.size() - res << endl;





}
