#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct UFDS{

	std::vector<T> ps, size;
	
	UFDS(){}

	UFDS(T n) :ps(n),  size(n, 1) {
		iota(ps.begin(), ps.end(), 0);
	}

	T find_set(T x){
		return ps[x] == x ? x :  ps[x] = find_set(ps[x]);
	}

	bool same_set(T x, T y){
		return find_set(x) == find_set(y);
	}

	void union_set(T x, T y){

		if (same_set(x, y))
			return;
		

		T q = find_set(x);
		T p = find_set(y);

		ps[q] = p;

		size[p] += size[q];

	}

	T max(){
		return *max_element(size.begin(), size.end());
	}

};

int main(){
  int n, m;

  cin >> n >> m;

  UFDS<int> ufds(n+1);

  vector<pair<int, int>> p;

  vector<int> edges(n+1,0);

  while (m--){
    int a, b;
    cin >> a >> b;
    p.emplace_back(a, b);

    ufds.union_set(a, b);
  }

  for ( auto [a, b] : p){
    edges[ufds.find_set(a)]++;
  }

  for ( int i = 1; i <= n; i++){
    if ( edges[ufds.find_set(i)] != ufds.size[ufds.find_set(i)]){
      cout << "No\n";
      return 0;
    }


  }

  cout << "Yes\n";


}
