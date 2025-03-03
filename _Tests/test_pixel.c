#include <math.h>
#include <stdio.h>

int	ft_round(double x)
{
	int n;

	n = (int)x;
	if (x - (double)n <= 0.5)
	{
		return (n);
	}
	return (n + 1);
}

int main()
{
	printf("%d", ft_round(8.5000));
}