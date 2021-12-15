#include <iostream>
#include <numeric>
using namespace std;

int NOD(int n, int m){
    while (n != 0 && m != 0){
        if (n>m) n = n % m; else m = m % n;
    }
    return m+n;
}

class Rational {
public:

    Rational() {
        n=0;
        d=1;
        // Р РµР°Р»РёР·СѓР№С‚Рµ РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0){
            if (numerator < 0){
                denominator = abs(denominator);
                numerator = abs(numerator);
            } else {
                denominator = abs(denominator);
                numerator *= -1;
            }
        }
        if (numerator == 0){
            denominator = 1;
        }
        int gc = NOD(abs(numerator),abs(denominator));
        n = numerator/gc;
        d = denominator/gc;
        // Р РµР°Р»РёР·СѓР№С‚Рµ РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ
    }

    int Numerator() const {
        // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
        return n;
    }

    int Denominator() const {
        // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
        return d;
    }

private:
    // Р”РѕР±Р°РІСЊС‚Рµ РїРѕР»СЏ
    int n;
    int d;
};

Rational operator+(const Rational& r1,const Rational& r2){

    int gc = NOD(abs(r1.Denominator()),abs(r2.Denominator()));
    int n = r1.Numerator()*r2.Denominator()/gc
            +r2.Numerator()*r1.Denominator()/gc;
    int d = r1.Denominator()*r2.Denominator()/gc;

    return Rational(n,d);
}
Rational operator-(const Rational& r1,const Rational& r2){

    int gc = NOD(abs(r1.Denominator()),abs(r2.Denominator()));
    int n = r1.Numerator()*r2.Denominator()/gc
            -r2.Numerator()*r1.Denominator()/gc;
    int d = r1.Denominator()*r2.Denominator()/gc;

    return Rational(n,d);
}
bool operator==(const Rational& r1,const Rational& r2){
    return r1.Numerator() == r2.Numerator() &&
           r1.Denominator() == r2.Denominator();
}

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
