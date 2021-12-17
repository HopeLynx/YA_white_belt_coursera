#include <iostream>
#include <exception>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>

using namespace std;

const vector<string> my_split(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;
    for(auto n:s){
        if(n != c) buff+=n;
        else if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    return v;
}

/*
    cin >> tmp;
    if (tmp == "") return;
    vector<string> v{my_split(tmp, '/')};
*/


class Date {
    int year; int month; int day;
public:
    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}
    Date(int y,int m,int d)
    {
        if (m < 1 || m > 12)
        {
            throw out_of_range("Month value is invalid: " + to_string(m));
        } else if (d < 1 || d > 31)
        {
            throw out_of_range("Day value is invalid: " + to_string(d));
        }
        year = y; month = m; day = d;
    }
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();}
    else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();}
    else {return lhs.GetDay() < rhs.GetDay();}
}

ostream& operator << (ostream& stream, const Date& date)
{
    stream << setfill('0') << setw(4) << to_string(date.GetYear());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetMonth());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetDay());
    return stream;
}

class Database {
    map<Date,set<string>> storage;
public:
    void AddEvent(const Date& date, const string& event){if (!event.empty()) storage[date].insert(event);}
    bool DeleteEvent(const Date& date, const string& event)
    {
        if (storage.count(date) > 0 && storage[date].count(event) > 0)
        {storage[date].erase(event);return true;}
        return false;
    }
    int  DeleteDate(const Date& date)
    {
        int ans = 0;
        if (storage.count(date) > 0) {ans = storage.at(date).size();storage.erase(date);}
        return ans;
    }

    /* ??? */

    void Find(const Date& date) const
    {
        set<string> res;
        if (storage.count(date)) res = storage.at(date);
        for (auto r : res) cout << r << endl;
        return;
    }

    void Print() const{
        for (const auto& s : storage){
            for (auto r: s.second){
                cout << s.first << " " << r << endl;
            }
        }
    }
};

Date ParseDate(const string& date)
{
    istringstream date_s(date);
    bool fl = true;

    int year = 0;
    fl = fl && (date_s >> year);
    fl = fl && (date_s.peek() == '-');
    date_s.ignore(1);

    int month = 0;
    fl = fl && (date_s >> month);
    fl = fl && (date_s.peek() == '-');
    date_s.ignore(1);

    int day = 0;
    fl = fl && (date_s >> day);
    fl = fl && date_s.eof();

    if (!fl){throw  logic_error("Wrong date format: " + date);}
    return Date(year, month, day);
}

int main() {

    try {
        Database db;
        string command;
        while (getline(cin, command)) {
            // Считайте команды с потока ввода и обработайте каждую
            if (command.length() > 0){
                vector<string> v{my_split(command, ' ')};
                bool used = false;
                if (v.size() > 1) {
                    Date date = ParseDate(v[1]);
                    if (v[0] == "Add" && v.size() == 3) {
                        if (v[2] != "" || v[2] != " ")
                            db.AddEvent(date,v[2]);
                        used = true;
                    }
                    else if (v[0] == "Del"){
                        if (v.size() == 3) { db.DeleteEvent(date,v[2]) ? cout << "Deleted successfully" << endl : cout << "Event not found" << endl;used = true;}
                        else if (v.size() == 2) {int kek = db.DeleteDate(date);used = true; cout << "Deleted " << kek << " events" << endl;}
                    }
                    else if (v[0] == "Find" && v.size() == 2){db.Find(date);used = true;}
                }
                else if (v[0] == "Print"){db.Print(); used = true;}
                if (!used) cout << "Unknown command: " << command << endl;
            }
        }
    }  catch (exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
