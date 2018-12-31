#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int l, r;
int n, m;
int ans;

bool check(int x) {
	int d = 1;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(sum + a[i] > m) {
			sum = a[i];
			d++;
		}
		else sum += a[i];
	}
	return d <= x;
}

int main()
{
	r = 1e5;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else l = mid + 1;
	}
	
	printf("%d",l);
	return 0;
}
