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
public:
    vector<Preke> prekes;

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
protected:
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
        return nextNuolaida;
    }
};

class FiksuotaNuolaida : public Nuolaida {
private:
    double slenkantiSuma{}, fiksuotaSuma{};
public:
    FiksuotaNuolaida() = default;

    FiksuotaNuolaida(double slenkantiSuma, double fiksuotaSuma) : slenkantiSuma(slenkantiSuma),
                                                                  fiksuotaSuma(fiksuotaSuma),
                                                                  Nuolaida() {};

    double calculate(Krepselis *kr) override {
        double krepselioSuma = kr->calculate();
        if (krepselioSuma > slenkantiSuma) {
            cout << "[Fiksuota] -> ";
            return fiksuotaSuma;
        }
        return Nuolaida::calculate(kr);
    }
};

class SantykineNuolaida : public Nuolaida {
private:
    double slenkantiSuma{}, procentai{};
public:
    SantykineNuolaida(double slenkantiSuma, double procentai) : slenkantiSuma(slenkantiSuma),
                                                                procentai(procentai),
                                                                Nuolaida() {};

    double calculate(Krepselis *kr) {
        double krepselioSuma = kr->calculate();
        if (krepselioSuma > slenkantiSuma) {
            cout << "[SantykineNuolaida] -> ";
            return krepselioSuma * (procentai / 100);
        }
        return Nuolaida::calculate(kr);
    }
};

class NuolaidaKategorijai : public Nuolaida {
private:
    string kategorija;
public:
    NuolaidaKategorijai(string kategorija) : kategorija(kategorija), Nuolaida() {}

    double calculate(Krepselis *kr) {
        double nuolaida = 0;
        cout << "[Nuolaida Kategorijai] -> ";
        for (auto preke: kr->prekes) {
            if (preke.getKategorija() == kategorija) {
                Krepselis *newKrepselis = new Krepselis({Preke(preke.getPav(), preke.getKategorija(), preke.getKaina())});
                nuolaida += nextNuolaida->calculate(newKrepselis);
            }
        }
        return nuolaida;
    }
};

class NuolaidaKainai : public Nuolaida {
private:
    double kaina;
public:
    NuolaidaKainai(double kaina) : kaina(kaina), Nuolaida() {}

    double calculate(Krepselis *kr) {
        double nuolaida = 0;
        cout << "[Nuolaida Kainai] -> ";
        for (auto preke: kr->prekes) {
            if (preke.getKaina() > kaina) {
                Krepselis *newKrepselis = new Krepselis({Preke(preke.getPav(), preke.getKategorija(), preke.getKaina())});
                nuolaida += nextNuolaida->calculate(newKrepselis);
            }
        }
        return nuolaida;
    }
};

class NuolaidaPavadinimui : public Nuolaida {
private:
    string pavadinimas;
public:
    NuolaidaPavadinimui(string pavadinimas) : pavadinimas(pavadinimas), Nuolaida() {}

    double calculate(Krepselis *kr) {
        double nuolaida = 0;
        cout << "[Nuolaida pavadinimui] -> ";
        for (auto preke: kr->prekes) {
            if (preke.getPav() == pavadinimas) {
                Krepselis *newKrepselis = new Krepselis({Preke(preke.getPav(), preke.getKategorija(), preke.getKaina())});
                nuolaida += nextNuolaida->calculate(newKrepselis);
            }
        }
        return nuolaida;
    }
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

    Preke siurblys = Preke("siurblys", "Dulkiu siurbliai", 107);
    Preke robotas = Preke("robotas siurblys", "Dulkiu siurbliai", 250);

    Preke televizorius = Preke("televizorius", "televizoriai ir garso technika", 1500);
    Preke mikrofonas = Preke("mikrofonas", "televizoriai ir garso technika", 25);

    auto *parduotuve = new Parduotuve({dviratis,
                                       ratas,
                                       siurblys,
                                       robotas,
                                       televizorius,
                                       mikrofonas});
    cout << "\nParduotuve:\n"
         << dviratis.getPav() << " ; " << dviratis.getKategorija() << " ; " << dviratis.getKaina() << "\n"
         << ratas.getPav() << " ; " << ratas.getKategorija() << " ; " << ratas.getKaina() << "\n"
         << siurblys.getPav() << " ; " << siurblys.getKategorija() << " ; " << siurblys.getKaina() << "\n"
         << robotas.getPav() << " ; " << robotas.getKategorija() << " ; " << robotas.getKaina() << "\n"
         << televizorius.getPav() << " ; " << televizorius.getKategorija() << " ; " << televizorius.getKaina() << "\n"
         << mikrofonas.getPav() << " ; " << mikrofonas.getKategorija() << " ; " << mikrofonas.getKaina() << "\n";

    auto *krepselis = new Krepselis({siurblys, robotas, dviratis, ratas, televizorius, mikrofonas});

    cout << "\nKrepselis:\n";
    for (auto kr: krepselis->prekes) {
        cout << kr.getPav() << " ; " << kr.getKategorija() << " ; " << kr.getKaina() << "\n";
    }
    cout << endl;

    FiksuotaNuolaida *fiksNuolaida1 = new FiksuotaNuolaida(300, 50);
    FiksuotaNuolaida *fiksNuolaida2 = new FiksuotaNuolaida(200, 20);
    FiksuotaNuolaida *fiksNuolaida3 = new FiksuotaNuolaida(100, 10);

    SantykineNuolaida *santNuolaida1 = new SantykineNuolaida(300, 50);
    SantykineNuolaida *santNuolaida2 = new SantykineNuolaida(200, 20);
    SantykineNuolaida *santNuolaida3 = new SantykineNuolaida(100, 10);

    /*----------------------------------------------------------------------------------------------------*/

    NuolaidaKategorijai *nuolaidaKategorijai = new NuolaidaKategorijai("Dulkiu siurbliai");

    nuolaidaKategorijai->
            setNextNuolaida(fiksNuolaida1)->
            setNextNuolaida(santNuolaida2)->
            setNextNuolaida(fiksNuolaida3);

    parduotuve->setNuolaida(nuolaidaKategorijai);
    cout << "Nuolaida ketegorijai: " << parduotuve->getResult(krepselis) << "\n";

    /*----------------------------------------------------------------------------------------------------*/

    NuolaidaKainai *nuolaidaKain = new NuolaidaKainai(200);

    nuolaidaKain->setNextNuolaida(fiksNuolaida1)->
            setNextNuolaida(santNuolaida2)->
            setNextNuolaida(fiksNuolaida3);

    parduotuve->setNuolaida(nuolaidaKain);
    cout << "Nuolaida kainai: " << parduotuve->getResult(krepselis) << "\n";

    /*----------------------------------------------------------------------------------------------------*/
    NuolaidaPavadinimui *nuolaidaPav = new NuolaidaPavadinimui("dviratis");

    nuolaidaPav->
            setNextNuolaida(fiksNuolaida1)->
            setNextNuolaida(santNuolaida2)->
            setNextNuolaida(fiksNuolaida3);

    parduotuve->setNuolaida(nuolaidaPav);
    cout << "Nuolaida pavadinimui: " << parduotuve->getResult(krepselis) << "\n";

    /*----------------------------------------------------------------------------------------------------*/

    NuolaidaPavadinimui *nuolaidaPav2 = new NuolaidaPavadinimui("televizorius");
    NuolaidaKainai *nuolaidaKain2 = new NuolaidaKainai(1000);
    NuolaidaKategorijai *nuolaidaKategorijai2 = new NuolaidaKategorijai("televizoriai ir garso technika");

    nuolaidaKain2->
            setNextNuolaida(nuolaidaPav2)->
            setNextNuolaida(nuolaidaKategorijai2)->
            setNextNuolaida(santNuolaida1);

    parduotuve->setNuolaida(nuolaidaKategorijai2);
    cout << "Nuolaida pavadinimui: " << parduotuve->getResult(krepselis) << "\n";

    /*----------------------------------------------------------------------------------------------------*/

    delete fiksNuolaida1;
    delete fiksNuolaida2;
    delete fiksNuolaida3;

    delete santNuolaida1;
    delete santNuolaida2;
    delete santNuolaida3;

    return 0;
}

