/*
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".

Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".

Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

Пример

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");

Вывод
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct fname {
    string name;
    string surname;
};

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if (yeared_name.count(year) == 0) yeared_name[year].surname = "";
        yeared_name[year].name = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (yeared_name.count(year) == 0) yeared_name[year].name = "";
        yeared_name[year].surname = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string name_s = "";
        string surname_s = "";
        for (const auto& i : yeared_name) {
            if (i.first <= year && i.second.surname != "") surname_s = i.second.surname;
            if (i.first <= year && i.second.name != "") name_s = i.second.name;
        }
        if (name_s == "" && surname_s == "") return  "Incognito";
        else if(name_s == "") return surname_s + " with unknown first name";
        else if(surname_s == "") return name_s + " with unknown last name";
        else return name_s + " " + surname_s;
    }
private:
    // приватные поля
    map<int ,fname> yeared_name;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
