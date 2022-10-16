#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Preke {
private:
    string pavadinimas{}, kategorija{};
    double kaina{};

public:
    Preke(string pavadinimas, string kategorija, double kaina) : pavadinimas(std::move(pavadinimas)),
                                                                 kategorija(kategorija), kaina(kaina) {};

    double getKaina() const { return kaina; }

    string getKategorija() const { return kategorija; }

    string getPav() const { return pavadinimas; }
};

class Krepselis {
private:
    vector<Preke> prekes;

public:
    Krepselis() = default;

    explicit Krepselis(vector<Preke> pr) : prekes(std::move(pr)) {};

    double calculate() {
        double sum = 0;
        for (auto &pr: prekes) {
            sum += pr.getKaina();
        }
        return sum;
    }
};

class Nuolaida {
private:
    Nuolaida *nextNuolaida = nullptr;
public:
    Nuolaida() = default;

    virtual double calculate(Krepselis *kr) {
        if (nextNuolaida) {
            return nextNuolaida->calculate(kr);
        }
        return kr->calculate();
    }

    Nuolaida *setNextNuolaida(Nuolaida *nuolaida) {
        nextNuolaida = nuolaida;
        return this;
    }
};

class FiksuotaNuolaida : public Nuolaida {
private:
    double slenkantiSuma{}, fiksuotaSuma{};
public:
    FiksuotaNuolaida() = default;

    FiksuotaNuolaida(double slenkantiSuma, int fiksuotaSuma) : slenkantiSuma(slenkantiSuma),
                                                               fiksuotaSuma(fiksuotaSuma) {};

    double calculate(Krepselis *kr) override {
        double krepselioSuma = kr->calculate();
        if (krepselioSuma > slenkantiSuma) {
            return krepselioSuma - fiksuotaSuma;
        }
        return Nuolaida::calculate(kr);
    }
};

class SantykineNuolaida : public Nuolaida {
private:
    double slenkantiSuma{}, procentai{};
public:
    SantykineNuolaida(double slenkantiSuma, double procentai) : slenkantiSuma(slenkantiSuma),
                                                                procentai(procentai) {};

    double calculate(Krepselis *kr) override {
        double krepselioSuma = kr->calculate();
        if (krepselioSuma > slenkantiSuma) {
            return (krepselioSuma - (krepselioSuma * (procentai / 100)));
        }
        return Nuolaida::calculate(kr);
    };
};

class Parduotuve {
private:
    vector<Preke> katalogas;
    Nuolaida *nuolaida{};

public:
    Parduotuve() = default;

    explicit Parduotuve(vector<Preke> katalog) : katalogas(std::move(katalog)) {};

    void setKatalogas(vector<Preke> katalog) {
        katalogas = std::move(katalog);
    }

    void setNuolaida(Nuolaida *nuol) {
        nuolaida = nuol;
    }

    double getResult(Krepselis *kr) {
        return nuolaida->calculate(kr);
    }
};

int main() {
    Preke dviratis = Preke("dviratis", "Dviračiai ir detales", 250);
    Preke ratas = Preke("ratas", "Dviračiai ir detales", 51);

    Preke siurblys = Preke("siurblys", "Dulkiu siurbliai", 101);
    Preke robotas = Preke("robotas siurblys", "Dulkiu siurbliai", 250);

    Preke televizorius = Preke("televizorius", "televizoriai ir garso technika", 1500);
    Preke mikrofonas = Preke("mikrofonas", "televizoriai ir garso technika", 25);

    auto *parduotuve = new Parduotuve({dviratis,
                                       ratas,
                                       siurblys,
                                       robotas,
                                       televizorius,
                                       mikrofonas});
    auto *krepselis = new Krepselis({siurblys});

    //7)
    std::cout << "Be Chain of Responsibility" << std::endl;
    parduotuve->setNuolaida(new FiksuotaNuolaida(100, 50));
    cout << parduotuve->getResult(krepselis) << endl;

    parduotuve->setNuolaida(new SantykineNuolaida(100, 10));
    cout << parduotuve->getResult(krepselis) << endl << endl;

    //8)
    cout << "Chain of Responsibility" << endl;

    cout << "Fiksuota nuolaida:" << endl;
    FiksuotaNuolaida *fiksNuolaida1 = new FiksuotaNuolaida(300, 30);
    FiksuotaNuolaida *fiksNuolaida2 = new FiksuotaNuolaida(200, 20);
    FiksuotaNuolaida *fiksNuolaida3 = new FiksuotaNuolaida(100, 10);

    fiksNuolaida1->setNextNuolaida(fiksNuolaida2)->
            setNextNuolaida(fiksNuolaida3); // paskutine NULL nuolaida nurodziau parent klaseje

    parduotuve->setNuolaida(fiksNuolaida1);
    cout << parduotuve->getResult(krepselis) << endl;

    delete fiksNuolaida1;
    delete fiksNuolaida2;
    delete fiksNuolaida3;

    std::cout << "Santykine nuolaida:" << std::endl;
    SantykineNuolaida *santNuolaida1 = new SantykineNuolaida(300, 30);
    SantykineNuolaida *santNuolaida2 = new SantykineNuolaida(200, 20);
    SantykineNuolaida *santNuolaida3 = new SantykineNuolaida(100, 10);

    santNuolaida1->setNextNuolaida(santNuolaida2)->
            setNextNuolaida(santNuolaida3); // paskutine NULL nuolaida nurodziau parent klaseje

    parduotuve->setNuolaida(santNuolaida1);
    cout << parduotuve->getResult(krepselis) << endl;

    delete santNuolaida1;
    delete santNuolaida2;
    delete santNuolaida3;

    return 0;
}

