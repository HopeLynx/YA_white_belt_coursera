#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in("input.txt");
//    ofstream out("output.txt");
    int n,m;
    if (in) {
        in >> n >> m;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int tmp;
                in >> tmp;
                in.ignore(1);
                cout << setw(10) << tmp;
                if (j != m-1) cout << " ";
            }
            if (i != n-1) cout << endl;
        }
    }


    return 0;
}

