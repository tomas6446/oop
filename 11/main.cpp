#include <iostream>
#include "Inheritence.h"
#include "vector"

int main()
{
    auto *sk = new Skritulys(Taskas(1, 2), 4);
    auto *el = new Elipse(Taskas(3, 4), 5, 4);
    auto *kv = new Kvadratas(Taskas(4, 2), 3);
    auto *st = new Staciakampis(Taskas(2, 2), 4, 5);
    std::cout << std::endl;

    std::vector<Figura *> figura{sk, el, kv, st};

    for (auto it: figura) {
        std::cout << (dynamic_cast< Elipse *>(it) ? "Elipse" :
                      dynamic_cast< Skritulys *>(it) ? "Skritulys" :
                      dynamic_cast< Staciakampis *>(it) ? "Staciakamplis" :
                      dynamic_cast< Kvadratas *>(it) ? "Kvadratas" :
                      "nezinomas objektas")
                  << std::endl;

        it->spausdinti();
        delete it;
    }

    return 0;
}
