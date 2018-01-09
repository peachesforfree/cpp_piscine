#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	int x;
	int y = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (y < argc)
	{
		x = 0;
		while (argv[y][x] != 0)
		{
			if (std::islower(argv[y][x]))
				argv[y][x] = std::toupper(argv[y][x]);
			std::cout << argv[y][x];
			x++;
		}
		y++;
	}
	
	std::cout << std::endl;
	return 0;
}
