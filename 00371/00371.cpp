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
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
int main()
{
	ll a, b,start;
	while (cin >> a >> b && a && b)
	{
		if (a > b)swap(a, b);
		start = a;
		ll ans = 0, val = 0;
		for (; a < b+1; a++)
		{
			ll temp = a, gam = 0;
			do
			{
				gam++;
				if (temp % 2)
					temp = temp * 3 + 1;
				else
					temp /= 2;
			} while (temp > 1);
			if (ans < gam)
				ans = gam, val = a;
		}
		cout << "Between " << start << " and " << b << ", " << val << " generates the longest sequence of " << ans << " values." << endl;
	}
}
