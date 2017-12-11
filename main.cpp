#include "matrix.h"


int main(void){
Matrix m1, m2(3,6);
if(m1==m1) cout << "m==m\n";
m1 = m2;
if(m2==m1) cout << "m==m\n";
m1 = m2 + m2;
m2+=m2;
m2 = -m2;
m2 = m2 - m2;
m2 = Matrix(2,2) * Matrix(2,2);
m2 -= m2;
m1 = Matrix(3,3);
m1 *= m1;
cout << m1;
string s = "macierz1.txt";
m2.wczytaj_z_pliku(s);
m2(0,0) = 21;
cout << m2;
cout << m2(0,0);
return 0;
};
