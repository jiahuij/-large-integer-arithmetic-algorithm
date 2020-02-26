#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int THREADHOLD = 2;

int prod(int u, int v)
{
	int uDigit = 0,
	    vDigit = 0,
		num1 = u,
		num2 = v;


	while (num1 != 0) { num1 /= 10; uDigit++; }
	while (num2 != 0) { num2 /= 10; vDigit++; }

	int n = max(uDigit, vDigit);

	if (u == 0 || v == 0)
		return 0;
	else if (n < THREADHOLD)
		return v*u;
	else
	{
		int m = n / 2,
			i = pow(10, m),
			x = u / i,
			y = u % i,
			w = v / i,
			z = v % i,
			r = prod(x + y, w + z),
			p = prod(x, w),
			q = prod(y, z);
		return p * pow(10, 2 * m) + (r - q - p)*i + q;
	}
}

int main()
{

	int num1 = -1, num2 = -1,product;

	while (num1 < 0 || num2 < 0)
	{
		cout << "Enter two non negative numbers: " << endl;
		cin >> num1>> num2;
	}

	product = prod(num1, num2);

	cout << "The result determined using the large integer arithmetic algorithm is  " << product << endl;;
	 cout << "The result determined using the standard algorithm is " << num1*num2;

	char c;
	cin >> c;
	return 0;
}