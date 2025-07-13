#include <iostream> // input y output
#include <cctype> // trabajr con caracteres

int	main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i++;
		while(i < ac)
		{
			j = 0;
			while(av[i][j])
			{
				std::cout << static_cast<char>(std::toupper(av[i][j]));
                ++j;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return(0);
}
