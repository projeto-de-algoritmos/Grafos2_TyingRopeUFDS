#include<bits/stdc++.h>

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
	int n, k;
	cin >> n >> k;

	UFDS<int> ufds(n);

	int res = 0;

	while (k--){
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		if (  ufds.same_set(a, b))
			res++;

		ufds.union_set(a, b);


	}


	cout << res << '\n';






}
