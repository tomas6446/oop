#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Person{
private:
    string name;
    int currentYear, currentMonth, currentDay, birthYear, birthMonth, birthDay,
            calculatedYears, calculatedMonths, calculatedDays;

public:
    Person(string name, int currentYear, int currentMonth, int currentDay, int birthYear, int birthMonth, int birthDay){
        this->name = name;
        this->currentYear = currentYear;
        this->currentMonth = currentMonth;
        this->currentDay = currentDay;
        this->birthYear = birthYear;
        this->birthMonth = birthMonth;
        this->birthDay = birthDay;
        this->calculatedYears = 0;
        this->calculatedMonths = 0;
        this->calculatedDays = 0;
    }

    void calculateAge(){
        int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (birthDay > currentDay){
            currentDay = currentDay + month[birthMonth - 1];
            currentMonth = currentMonth - 1;
        }

        if (birthMonth > currentMonth){
            currentYear = currentYear - 1;
            currentMonth = currentMonth + 12;
        }

        calculatedDays = currentDay - birthDay;
        calculatedMonths = currentMonth - birthMonth;
        calculatedYears = currentYear- birthYear;
    }

    string getName(){
        return name;
    }

    int getYears(){
        return calculatedYears;
    }

    int getMonths(){
        return calculatedMonths;
    }

    int getDays(){
        return calculatedDays;
    }

    string toString(){
        stringstream ss;
        ss << getName() << " is " << getYears() << " years, " << getMonths() << " months and " << getDays() << " days old";
        return ss.str();
    }
};

int main(){
    Person person("John", 2022, 3, 3, 1985, 1, 1);

    person.calculateAge();

    cout << person.toString() << endl;
}