
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> p;
	p.push_back(1);

	int n = 1;
	while(true)
	{
		int i = 0;
		int penta = 1;
		p.push_back(0);

		while(penta <= n)
		{
			int sign = (i % 4 > 1) ? -1 : 1;
			p[n] += sign * p[n - penta];
			p[n] %= 1000000;
			i++;

			int j = (i % 2 == 0) ? i / 2 + 1 : -(i / 2 + 1);
			penta = j * (3 * j - 1) / 2;
		}
		if(p[n] == 0)
		{
			std::cout << n << '\n';
			break;
		}
		n++;
	}
}

