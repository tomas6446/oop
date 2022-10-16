#include <iostream>
#include <utility>
#include <regex>
#include <fstream>

using namespace std;

class MyPrintable {
public:
    virtual void print() = 0;
};


class MySentence : public MyPrintable {
private:
    string field;

    bool validate(string f) {
        string validate = std::move(f);
        string lastSymbols;

        if(validate.back() == '\0' || validate.back() == '\n' || validate.back() == ' ') {
            validate.pop_back();
        }

        if(!validate.empty())
        {
            do  {
                validate.pop_back();
                lastSymbols.push_back(validate.back());
            } while((validate.back() == '!' || validate.back() == '?' || validate.back() == '.'));
        }

        for (auto v: validate) {
            if (v == '!' || v == '?' || v == '.') {
                return false;
            }
        }

        return true;
    }

public:
    MySentence() = default;

    explicit MySentence(const string& f) {
        setField(f);
    };

    void setField(string f) {
        if(validate(f))
        {
            field = std::move(f);
        }
    }

    string getField() {
        return field;
    }

    void print() override {
        cout << field;
    }
};

class MyParagraph : public MySentence {
private:
    vector<MySentence> paragraph;
public:
    MyParagraph() = default;

    explicit MyParagraph(const string &f) {
        paragraph.emplace_back(MySentence(f));
    }

    void print() override {
        for (auto p: paragraph) {
            p.print();
        }
    }
};

class MyText : public MyParagraph {
private:
    vector<MyParagraph> text;
public:
    MyText() = default;

    explicit MyText(const string &f) {
        text.emplace_back(MyParagraph(f + '\n'));
    }

    void print() override {
        for (auto t: text) {
            t.print();
        }
    }
};

int main() {
    std::ifstream file("input.txt");

    string input;
    if (file.is_open()) {
        while (getline(file, input)) {
            auto *text = new MyText(input);
            text->print();
        }
        file.close();
    }

    return 0;
}
