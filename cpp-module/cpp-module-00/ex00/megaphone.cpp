#include <iostream>

int main(int ac, char **av)
{
    if(ac >= 2){
        for(int i = 1; av[i]; i++){
            for(int n = 0; av[i][n]; n++)
                std::cout << static_cast<char>(toupper(av[i][n]));
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}