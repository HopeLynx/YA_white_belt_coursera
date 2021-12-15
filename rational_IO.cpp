#include <iostream>
#include <numeric>
#include <iomanip>
#include <sstream>
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

istream& operator >> (istream& stream, Rational& r){
    int n=-100000, d=-10000;char c;
       if (stream >> n  >> c >> d) {
           if (c == '/' && n != -100000 && d != -10000)r = { n, d };
           else r = Rational();
       }
       return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

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

Rational operator*(const Rational& r1,const Rational& r2){

    int n = r1.Numerator()*r2.Numerator();
    int d = r1.Denominator()*r2.Denominator();

    return Rational(n,d);
}

Rational operator/(const Rational& r1,const Rational& r2){

    int n = r1.Numerator()*r2.Denominator();
    int d = r1.Denominator()*r2.Numerator();

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

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
