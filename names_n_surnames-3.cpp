/*
Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:

методы GetFullName и GetFullNameWithHistory должны отдавать "No person";

методы ChangeFirstName и ChangeLastName должны игнорировать запрос.

Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

Пример
Код

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;

Вывод

No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)

Как отправить
Когда работа будет готова, вы можете загрузить файлы для каждой части задания на вкладке 'Мои работы'.
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
    Person(string name,string surname,int yb){
        ChangeFirstName(yb,name);
        ChangeLastName(yb,surname);
        year_birth = yb;
    }
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
       if (year < year_birth) return;
       if (yeared_name.count(year) == 0) yeared_name[year].surname = "";
       yeared_name[year].name = first_name;
        for (auto& i : yeared_name) {
                    if (year > i.first) {
                        if (yeared_name.count(year) == 0) yeared_name[year].surname = "";
                        yeared_name[year].name = first_name;
                    }
                    break;
                }
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if (year < year_birth) return;
       if (yeared_name.count(year) == 0) yeared_name[year].name = "";
       yeared_name[year].surname = last_name;

    }
    string GetFullName(int year) const {
        // получить имя и фамилию по состоянию на конец года year
        if (year_birth != 0 && year < year_birth) {
                    return "No person";
                }
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
    string GetFullNameWithHistory(int year) const {
        // получить все имена и фамилии по состоянию на конец года year
        string name_s = "";
        string surname_s = "";
        for (const auto& i : yeared_name) {
            if (i.first <= year && i.second.surname != "") surname_s = i.second.surname;
            if (i.first <= year && i.second.name != "") name_s = i.second.name;
        }


        if (year_birth != 0 && year < year_birth) return "No person";
        int i = 0;
        vector<int> v;
        vector<string> nhv;
        vector<string> shv;
        for (const auto& y : yeared_name) {
            v.push_back(y.first);
            if (y.first > year && i < 1) {
                return "Incognito";
            }
            i++;
        }
        reverse(begin(v), end(v));
        int fp = 0;
        int lp = 0;

        for (const auto& y : v) {
            for (const auto& tmp_map : yeared_name) {
                if (y <= year && y == tmp_map.first && tmp_map.second.name != "") {
                    if (name_s == "") {
                        name_s = tmp_map.second.name;
                    }
                    else if (name_s != tmp_map.second.name || fp > 0) {
                        nhv.push_back(tmp_map.second.name);
                        fp++;
                    }
                }
                if (y <= year && y == tmp_map.first && tmp_map.second.surname != "") {
                    if (surname_s == "") {
                        surname_s = tmp_map.second.surname;
                    }
                    else if (surname_s != tmp_map.second.surname || lp > 0) {
                        shv.push_back(tmp_map.second.surname);
                        lp++;
                    }
                }
            }


        }

        if (name_s == "") {
            if (!shv.empty()) {
                int ii = 0;
                for (const auto& r : shv) {
                    if (ii > 0) {
                        surname_s += ", ";
                        surname_s += r;
                    }
                    else {
                        surname_s += " (";
                        surname_s += r;
                    }
                    ii++;
                }
                return surname_s + ") " + "with unknown first name";
            }
            return surname_s + " " + "with unknown first name";
        }
        else if (surname_s == "") {
            if (!nhv.empty()) {
                int ii = 0;
                for (const auto& r : nhv) {
                    if (ii > 0) {
                        name_s += ", ";
                        name_s += r;
                    }
                    else {
                        name_s += " (";
                        name_s += r;
                    }
                    ii++;
                }
                return name_s + ") " + "with unknown last name";
            }
            return name_s + " " + "with unknown last name";
        }
        else {
            if (!nhv.empty()) {
                int ii = 0;
                for (const auto& r : nhv) {
                    if (ii > 0) {
                        name_s += ", ";
                        name_s += r;
                    }
                    else {
                        name_s += " (";
                        name_s += r;
                    }
                    ii++;
                }
                name_s += ")";
            }
            if (!shv.empty()) {
                int ii = 0;
                for (const auto& r : shv) {
                    if (ii > 0) {
                        surname_s += ", ";
                        surname_s += r;
                    }
                    else {
                        surname_s += " (";
                        surname_s += r;
                    }
                    ii++;
                }
                surname_s += ")";
            }
            return name_s + " " + surname_s;
        }
    }
private:
    // приватные поля
    map<int ,fname> yeared_name;
    int year_birth = 0;
};
/*
int main() {

    Person person("-1_first", "-1_last", -1);

    int year = -1;
    person.ChangeFirstName(year, std::to_string(2) + "_first");
    person.ChangeLastName(year, std::to_string(2) + "_last");

    year = 5;
    person.ChangeFirstName(year, std::to_string(year) + "_first");
    person.ChangeLastName(year, std::to_string(year) + "_last");


    year = 7;
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullName(year) << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    return 0;
}
*/
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

