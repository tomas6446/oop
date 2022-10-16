#include <iostream>
#include <algorithm>

using namespace std;

class EmptyWordException {
public:
    EmptyWordException() = default;

    string what() const {
        return "Empty word exception";
    }
};

class HasSpacesEception {
public:
    HasSpacesEception() = default;

    string what() const {
        return "Has spaces exception";
    }
};


class MyWord {
private:
    string word;

    string normalise(string word) {
        for (auto &w: word) {
            if (!isalpha(w)) {
                w = '?';
            }
            w = (char) tolower(w);
        }
        return word;
    }

public:
    MyWord() = default;

    MyWord(const string &word) {
        setWord(word);
    }

    void setWord(const string &word) {
        if (word.find(' ') != string::npos) {
            throw HasSpacesEception();
        } else {
            this->word = normalise(word);
        }
    }

    string getWord() {
        if (word.empty()) {
            throw EmptyWordException();
        } else if (word.find(' ') != string::npos) {
            throw HasSpacesEception();
        } else {
            return this->word;
        }
    }
};

class Printer {
public:
    virtual void print(MyWord *word) = 0;
};

class SimplePrinter : public Printer {
public:
    SimplePrinter() = default;

    void print(MyWord *word) override {
        cout << word->getWord() << endl;
    }
};

class StrangePrinter : public Printer {
public:
    StrangePrinter() = default;

    void print(MyWord *word) override {
        string reversedWord = word->getWord();
        reverse(reversedWord.begin(), reversedWord.end());
        cout << reversedWord << endl;
    }
};

class MyPrintableWord : public MyWord {
private:
    Printer *printer;
public:
    MyPrintableWord() { printer = new SimplePrinter; }

    MyPrintableWord(Printer *printer) : printer(printer) {};

    void setPrinter(Printer *printer) {
        this->printer = printer;
    }

    void print(MyWord *word) {
        printer->print(word);
    }
};

int main() {
    const string w1 = " ";
    try {
        auto print = new MyPrintableWord(new SimplePrinter);
        print->print(new MyWord(w1));
    } catch (HasSpacesEception &e) {
        cout << e.what() << endl;
    }
    try {
        auto print = new MyPrintableWord(new SimplePrinter);
        print->print(new MyWord());
    } catch (EmptyWordException &e) {
        cout << e.what() << endl;
    }

    cout << endl;

    const string w2 = "T;o.m!as";
    auto firstWord = new MyPrintableWord();
    auto secondWord = new MyPrintableWord();
    firstWord->print(new MyWord(w2));
    secondWord->print(new MyWord(w2));

    cout << endl;

    firstWord->setPrinter(new StrangePrinter);
    firstWord->print(new MyWord(w2));
    secondWord->print(new MyWord(w2));

    return 0;
}
