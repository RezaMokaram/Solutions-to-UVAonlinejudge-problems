#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//

//
int main()
{	
	string a;
	bool f = false;
	while (getline(cin,a))
	{
		if (f)
		{
			cout << endl;
		}
		f = true;
		int arr[97] = { 0 };
		int list[97] = { 32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128 };

		for (size_t i = 0; i < a.length(); i++)
		{
			if (a[i]>=32 &&  a[i]<=128)
			{
				arr[a[i] - 32]++;
			}
		}
		for (size_t i = 0; i < 97; i++)
		{
			for (size_t j = 0; j < 96-i; j++)
			{
				if (arr[j]>arr[j+1])
				{
					swap(arr[j], arr[j + 1]);
					swap(list[j], list[j + 1]);
				}
				if (list[j]<list[j+1] && arr[j]==arr[j+1])
				{
					swap(arr[j], arr[j + 1]);
					swap(list[j], list[j + 1]);
				}
			}
		}
		for (size_t i = 0; i < 97; i++)
		{
			if (arr[i]>0)
			{
				cout << list[i] << " " << arr[i] << endl;
			}
		}
	}
}
