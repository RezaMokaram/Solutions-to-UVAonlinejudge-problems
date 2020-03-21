//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<ll, ll>> vii;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAX = 100000;
typedef pair<double, pair<int, int>> nod;
nod ndc(int a, int b, double val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
typedef pair<llu, llu> no;
no nc(ll a, ll b) { return pair<ll, ll>(a, b); }
//
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
vector<vector<pii>>li;
void prset(ll a)
{
	pr.clear();
	li.clear();
	for (int i = 0; i < a; i++)
	{
		pr.push_back(i);
		vector<pii>z;
		li.push_back(z);
	}
}
int getp(int n) { return pr[n] == n ? n : pr[n] = getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
double cmpt(pii a, pii b)
{
	ll x = abs(a.first - b.first), y = abs(a.second - b.second);
	x *= x;
	y *= y;
	x += y;
	double xx = x;
	xx = sqrt(x);
	return xx;
}
int main()
{
	int m;
	while (cin >> m)
	{
		int ans = m;
		vector<pii>mm(m);
		priority_queue<nod, vector<nod>, greater<nod>>p;
		for (size_t i = 0; i < m; i++)
		{
			cin >> mm[i].first >> mm[i].second;
			for (size_t j = 0; j < i; j++)
			{
				p.push(ndc(i, j, cmpt(mm[i], mm[j])));
			}
		}
		double mx = 0;
		prset(m + 2);
		int n;
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			pr[getp(a)] = getp(b);
			ans--;
			//mx += cmpt(mm[a], mm[b]);
		}
		while (p.size())
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.first), y = getp(temp.second.second);
			if (x != y)
			{
				mx += temp.first;
				pr[x] = y;
				ans--;
			}
			//if (ans == n)break;
		}
		cout << fixed << setprecision(2) << mx << endl;
	}
}
