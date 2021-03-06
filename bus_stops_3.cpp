/*
В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить друг из друга перестановкой элементов или
добавлением/удалением повторяющихся, следует считать одинаковыми.  

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.
Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных). Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.
Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    // name -- stops
    map<int,set<string>> buses;
    int n; cin >> n;
    for(int i = 0; i < n; i++){

            int tmp; cin >> tmp;
            set<string> v;
            for (int i = 0; i < tmp; i++) {
                string meme;cin >> meme;
                v.insert(meme);
            }
            auto it = buses.begin();;
            for (;it != buses.end();it++){
                if ((*it).second == v) break;
            }
            if (it == buses.end()) {
                int kek = buses.size()+1;
                buses[kek] = v;
                cout << "New bus " << kek << endl;
            } else {
                cout << "Already exists for " << distance(buses.begin(),it) + 1 << endl;
            }

    }
    return 0;
}
