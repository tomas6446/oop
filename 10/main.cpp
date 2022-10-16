#include <iostream>
#include "Inheritence.h"

int main()
{
    std::cout << "Skritulys:" << std::endl;
    Skritulys skr(4, 3);
    skr.setTaskas(Inheritence(1, 2));
    skr.spausdinti();
    std::cout << "Plotas: " << skr.plotas() << std::endl;
    std::cout << "Perimetras: " << skr.perimetras() << std::endl;
    std::cout << endl;

    std::cout << "Elipse:" << std::endl;
    Elipse el(4, 1, 4);
    skr.setTaskas(Inheritence(3, 2));
    el.spausdinti();
    std::cout << "Plotas: " << el.plotas() << std::endl;
    std::cout << "Perimetras: " << el.perimetras() << std::endl;
    std::cout << endl;

    std::cout << "Kvadratas:" << std::endl;
    Kvadratas kv(4, 4);
    kv.setTaskas(Inheritence(5, 2));
    kv.spausdinti();
    std::cout << "Plotas: " << kv.plotas() << std::endl;
    std::cout << "Perimetras: " << kv.perimetras() << std::endl;
    std::cout << endl;

    std::cout << "Staciakamplis:" << std::endl;
    Staciakamplis st(4, 3, 3);
    st.setTaskas(Inheritence(5, 3));
    st.spausdinti();
    std::cout << "Plotas: " << st.plotas() << std::endl;
    std::cout << "Perimetras: " << st.perimetras() << std::endl;
    std::cout << endl;

    return 0;
}
