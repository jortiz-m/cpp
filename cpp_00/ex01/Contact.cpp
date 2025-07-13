#include "Contact.hpp"
#include <iostream>

static std::string get_non_empty_input(const std::string &prompt) 
{
    std::string input;

    std::cout << prompt; //muestra en la salida el mensaje de solicitud
    std::getline(std::cin, input); //lee lo que el usuario introduce y lo guarda en la variable input

    while (input.empty()) // Verifica si la entrada está vacía
    {
        std::cout << prompt; // Si está vacía, vuelve a solicitar la entrada
        std::getline(std::cin, input); // Lee nuevamente la entrada del usuario
    }
    return (input);
}

void Contact::fill() 
{
    first_name = get_non_empty_input("First Name: ");
    last_name = get_non_empty_input("Last Name: ");
    nickname = get_non_empty_input("Nickname: ");
    phone_number = get_non_empty_input("Phone Number: ");
    darkest_secret = get_non_empty_input("Darkest Secret: ");
}

void Contact::display_full() const 
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void Contact::display_summary(int index) const
{
    std::cout << "|"; // Muestra una barra vertical
    std::cout.width(10); // Establece el ancho de la siguiente salida en 10 caracteres
    std::cout << index << "|"; // Muestra el índice del contacto y otra barra vertical

    std::string items[3] = {first_name, last_name, nickname}; // Crea un array con los tres datos a mostrar
    int i = 0; // Inicializa el contador para recorrer el array
    while (i < 3) // Recorre los tres elementos del array
    {
        std::cout.width(10); // Establece el ancho de la siguiente salida en 10 caracteres
        if (items[i].length() > 10) // Si el dato tiene más de 10 caracteres...
            std::cout << items[i].substr(0, 9) + "."; // ...muestra los primeros 9 caracteres y un punto
        else
            std::cout << items[i]; // Si tiene 10 o menos, lo muestra completo
        std::cout << "|"; // Muestra una barra vertical después de cada dato
        i++; // Pasa al siguiente dato
    }
    std::cout << std::endl; // Salta a la siguiente línea al terminar la fila
}

std::string Contact::get_first_name() const { return first_name; }
std::string Contact::get_last_name() const { return last_name; }
std::string Contact::get_nickname() const { return nickname; }
