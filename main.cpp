#include "matrix.h"

void koniec(){

cout << "___";}

int main(void){
//atexit(koniec);
//Matrix m1, m2(3,6);
/*
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
cout << m1;*//*
string s = "macierz1.txt";
m2.wczytaj_z_pliku(s);
m2(0,0) = 21;
cout << m2;
cout << m2(0,0);
*/
cout << "Spr wyjatkow\n";
Matrix m3(6,7), m4(3,2);
cout << "\n";
cout << m3 << m4;
cout << "spr - : " << m3 - m4;
cout << "\nspr wczytania z pliku: ";
cout << m3 << m4;
string ss = "łubałuba";
m3.wczytaj_z_pliku(ss);
cout << "\n";
cout << m3 << m4;
cout << "spr * :" << m3 * m4 <<"\n";
cout << m3 << m4;
cout << "spr + :" << m3 + m4 <<"\n";
cout << m3 << m4;
cout << "mnozenie minora: \n";

ss = "macierz1.txt";
m3.wczytaj_z_pliku(ss);
cout << m3;
m3 = m3 * 3;
cout << m3;
m3 = 3 * m3;
cout<< m3;
cout << "koniec";
return 0;
};
