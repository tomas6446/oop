#include <iostream>
#include <vector>

using namespace std;

class GuessWord;

class Action {
public:
    static int commandCount;

    virtual void run(GuessWord *guess_word) = 0;
};

int Action::commandCount = 0;

class GuessWord {
    std::string word;
    std::string hidden_word;
public:
    GuessWord(const std::string &word);

    void guess_char(char chr);

    bool have_won();

    void reveal_letter(int index);

    void set_word(const std::string &word);

    void show_hidden_word();

    int getSize();

    char getCh(int index);
};

GuessWord::GuessWord(const std::string &word)
{
    set_word(word);
}

void GuessWord::guess_char(char chr)
{
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == chr && hidden_word[i] == '*') {
            reveal_letter(i);
        }
    }
}

bool GuessWord::have_won()
{
    return word == hidden_word;
}

void GuessWord::reveal_letter(int index)
{
    if (index >= 0 && index < word.size()) {
        hidden_word[index] = word[index];
    }
}

int GuessWord::getSize()
{
    return (int) word.size();
}

char GuessWord::getCh(int index)
{
    return hidden_word[index];
}

void GuessWord::set_word(const string &word)
{
    this->word = word;
    this->hidden_word.clear();
    for (int i = 0; i < word.size(); i++)
        hidden_word.push_back('*');
}

void GuessWord::show_hidden_word()
{
    cout << "WORD: " << hidden_word << endl;
}

class GuessLetter : public Action {
private:
    char letter{};
public:
    GuessLetter() = default;

    void setLetter(char ch);

    void run(GuessWord *guess_word) override;

    ~GuessLetter() = default;
};

void GuessLetter::setLetter(char ch)
{
    letter = ch;
}

void GuessLetter::run(GuessWord *guess_word)
{
    Action::commandCount++;
    guess_word->guess_char(letter);
}

class RevealLetter : public Action {
private:
    int index{};
    static int count;
public:
    RevealLetter() = default;

    void setIndex(int i);

    void run(GuessWord *guess_word) override;

    ~RevealLetter() = default;
};

int RevealLetter::count = 0;

void RevealLetter::setIndex(int i)
{
    index = i;
}

void RevealLetter::run(GuessWord *guess_word)
{
    if (count < 2) {
        count++;
        Action::commandCount++;
        guess_word->reveal_letter(index);
    }
    else {
        cout << "Not enough tries" << endl;
    }
}

class RevealRandom : public Action {
private:
    static int count;
public:
    RevealRandom() = default;

    void run(GuessWord *guess_word) override;

    ~RevealRandom() = default;
};

int RevealRandom::count = 0;

void RevealRandom::run(GuessWord *guess_word)
{
    if (count < 2) {
        count++;
        Action::commandCount++;
        srand(time(nullptr));
        int randIndx = (rand() + 1) % guess_word->getSize();
        while (guess_word->getCh(randIndx) != '*') {
            randIndx = (rand() + 1) % guess_word->getSize();
        }
        guess_word->reveal_letter(randIndx);
    }
    else {
        cout << "Not enough tries" << endl;
    }
}


int main(int argc, char **argv)
{
    auto *word = new GuessWord("hello");
    auto *letter = new GuessLetter;
    auto *index = new RevealLetter;
    auto *random = new RevealRandom;

    vector<Action *> commands;
    string input;
    int num;
    char ch;

    cout << "ACTIONS: GuessLetter letter; RevealLetter index; RevealRandom" << std::endl;
    word->show_hidden_word();

    while (!word->have_won() && Action::commandCount < 10) {
        cout << "[" << Action::commandCount + 1 << "] > ";
        cin >> input;

        if (input == "GuessLetter") {
            cin >> ch;
            letter->setLetter(ch);
            letter->run(word);
            commands.push_back(letter);
        }
        else if (input == "RevealLetter") {
            cin >> num;
            index->setIndex(num);
            index->run(word);
            commands.push_back(index);
        }
        else if (input == "RevealRandom") {
            random->run(word);
            commands.push_back(random);
        }

        word->show_hidden_word();
    }

    cout << endl;
    for (auto c: commands) {
        if (dynamic_cast<GuessLetter *>(c)) {
            cout << "GuessLetter" << std::endl;
        }
        else if (dynamic_cast<RevealLetter *>(c)) {
            cout << "*RevealLetter" << endl;
        }
        else if (dynamic_cast<RevealRandom *>(c)) {
            cout << "*RevealRandom" << endl;
        }
    }
}