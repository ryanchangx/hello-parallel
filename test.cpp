#include <bits/stdc++.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
using namespace std;

int ptest(vector<int> v, int i, int j){
	if(j-i == 0) return v[i];
	int m = (j + i) / 2;
	int a = cilk_spawn ptest(v, i, m);
	int b = ptest(v, m + 1, j);
	cilk_sync;
	return max(a,b);
}

int main(){
	vector<int> v = {8,3,5,4,29,3,5,5,4,3,8};
	cout << ptest(v, 0, v.size() - 1) << endl;
	return 0;
}
