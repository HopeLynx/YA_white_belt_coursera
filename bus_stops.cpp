/*
Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:
NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
ALL_BUSES — вывести список всех маршрутов с остановками.

Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.
Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.
Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0,
а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.

Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:
На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке,
в котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.

На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS.
Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке,
в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus,
вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.

На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке,
в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.

Предупреждение
Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте условие ещё раз.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

void PrintVec(const vector<string>& v){
    for (vector<string>::const_iterator it = v.begin();it != v.end()-1;it++){
        cout << *it << " ";
    }
    cout << (v.back());
}

void Buses_for_stop(const map<string,vector<string>>& busses,const string stop){
    vector<string> v;
    for (auto it = busses.begin(); it != busses.end(); it++) {
        if ((*it).second.end() != find((*it).second.begin(),(*it).second.end(),stop)) v.push_back((*it).first);
    }
    if (!v.size()) cout << "No stop" << endl; else {PrintVec(v); cout << endl;}
}

void Stops_for_bus(const map<string,vector<string>>& busses,const string bus){

    auto iter = busses.find(bus);
    if (iter != busses.end()){
        for (auto vit = (*iter).second.begin();vit != (*iter).second.end();vit++){
            vector<string> v; string stop = *vit;
            for (auto it = busses.begin(); it != busses.end(); it++) {
                if ((*it).second.end() != find((*it).second.begin(),(*it).second.end(),stop))
                    if (bus != (*it).first) v.push_back((*it).first);
            }
            if (!v.size()) cout << "Stop " << stop << ": no interchange" << endl;
            else {cout << "Stop " << stop << ": "; PrintVec(v); cout << endl;}
        }
    } else {
        cout << "No bus" << endl;
    }

}

// NEW_BUS bus stop_count stop1 stop2 ...
//BUSES_FOR_STOP stop STOPS_FOR_BUS bus ALL_BUSES

int main(){
    // name -- stops
    map<string,vector<string>> busses;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string cmd; cin >> cmd;
        if (cmd == "NEW_BUS"){

            string name; cin >> name; int tmp; cin >> tmp;
            vector<string> v;
            for (int i = 0; i < tmp; i++) {
                string meme;cin >> meme;
                v.push_back(meme);
            }
            busses[name] = v;

        } else if (cmd == "BUSES_FOR_STOP") {

            string stop; cin >> stop;
            Buses_for_stop(busses,stop);

        } else if (cmd == "STOPS_FOR_BUS") {

            string bus; cin >> bus;
            Stops_for_bus(busses,bus);

        } else if (cmd == "ALL_BUSES") {

            if (!busses.size()) cout << "No buses" << endl;
            else {
                auto iter = busses.end(); advance(iter,-1);
                for (auto it = busses.begin(); it != iter; it++) {
                    cout << "Bus " << (*it).first << ": "; PrintVec((*it).second); cout << endl;
                } /*iter++;*/ cout << "Bus " << (*iter).first << ": "; PrintVec((*iter).second);
            }

        }
    }
    return 0;
}

