/*
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. 
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.
Реализуйте обработку следующих операций над очередью:
WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.
Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void make_worry(vector<bool>& v,int i){v[i]=true;}
void make_quiet(vector<bool>& v,int i){v[i]=false;}
void come_cmd(vector<bool>& v,int k){
    if (k > 0) {
        v.insert(v.end(),k,false);
    } else if (k < 0) {
        v.resize(v.size()+k);
    }
}
int worry_cnt(const vector<bool>& v){
    return count(v.begin(),v.end(),true);
}

int main(){
    int n; cin >> n; vector<bool> v;
    for(int i = 0; i < n; i++){
        string cmd; cin >> cmd; int tmp;
        if (cmd == "WORRY"){cin >> tmp; make_worry(v,tmp);}
        else if (cmd == "QUIET") {cin >> tmp; make_quiet(v,tmp);}
        else if (cmd == "COME") {cin >> tmp; come_cmd(v,tmp);}
        else if (cmd == "WORRY_COUNT"){cout << worry_cnt(v) << endl;}
    }
    return 0;
}
