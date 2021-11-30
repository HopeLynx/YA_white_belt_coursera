/*
Дана структура LectureTitle:

struct LectureTitle {
  string specialization;
  string course;
  string week;
};

Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект LectureTitle можно было создать с помощью кода 

LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);

но нельзя было с помощью следующих фрагментов кода:

LectureTitle title("C++", "White belt", "4th");

LectureTitle title(string("C++"), string("White belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Specialization{
    string s;
    explicit Specialization(string ns){
        s = ns;
    }
};

struct Course{
    string s;
    explicit Course(string ns){
        s = ns;
    }
};

struct Week{
    string s;
    explicit Week(string ns){
            s = ns;
        }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization s, Course c, Week w){
          specialization = s.s;
          course = c.s;
          week = w.s;
      }
};

int main() {

    LectureTitle title1(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
/*
    LectureTitle title2("C++", "White belt", "4th");

    LectureTitle title3(string("C++"), string("White belt"), string("4th"));

    LectureTitle title4 = {"C++", "White belt", "4th"};

    LectureTitle title5 = {{"C++"}, {"White belt"}, {"4th"}};

    LectureTitle title6(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title7(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );
*/
  return 0;
}

