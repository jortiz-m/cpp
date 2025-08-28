#include <iostream> 			// input y output
#include <cctype> 				// trabajar con caracteres

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
				std::cout << static_cast<char>(std::toupper(av[i][j]));  //devuelve un int
                ++j;
			}
			if(i != ac - 1)
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return(0);
}


//toupper es un método que devuelve un int y se tiene que castear para que devuelva un char
// static_cast<char> es la forma de utilizarlo en cpp