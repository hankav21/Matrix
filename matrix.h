#ifndef matrix_H
#define matgix_G
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <new>

using namespace std;

class Matrix{
public:
	class Tab;
	Tab* data;

	class Mref;
	class Range{};	//do wyjatkow
	Matrix();//
	Matrix(unsigned int, unsigned int); //
	Matrix(Matrix&);
	~Matrix();//

	Matrix operator+ (const Matrix &) const;//
	Matrix operator- () const;//
	Matrix operator- (const Matrix &) const;//
	Matrix operator* (const double &) const;
	friend Matrix operator* (const double&, const Matrix& );
	Matrix operator* (const Matrix &) const;//
	Matrix& operator+= (const Matrix &);//
	Matrix& operator-= (const Matrix &);//
	Matrix& operator*= (const Matrix &);//
	
	bool operator== (const Matrix &) const;//
	Matrix& operator= (const Matrix &);//

	friend std::ostream & operator<< (std::ostream &, const Matrix &);//
	//friend std::fstream & operator<< (std::ostream &, const Matrix &);

	Matrix& wczytaj_z_pliku(std::string&);//

	double operator() (const unsigned int, const unsigned int) const;//?
	Mref operator() (const unsigned int, const unsigned int);

	void check(unsigned int, unsigned int) const;//
	double read(const unsigned int, const unsigned int) const;
	void write(const unsigned int, const unsigned int, double);

	int spr_liczby_odwolan();
	
	void test(){cout << "test";};
	void static koniec_programu(){
		cout << "KONIEC";
		//Matrix m; m.test();
		//~Matrix();
	};


};

class Matrix::Tab{
	
public:
	Tab(unsigned int, unsigned int);//
	~Tab();//

	double *t;
	unsigned int w,k;
	unsigned int n;	//liczba odwolan

	Tab* detach();//	//tym sie robi jak sie zmienia pojedyncze komorki i juz sa inne
	void assign(unsigned int, const char*);	//dostosowac
};

class Matrix::Mref{
	friend class Matrix;
	Matrix& m;
	unsigned int w,k;
	Mref(Matrix& mm, unsigned int ww, unsigned int kk): m(mm), w(ww), k(kk){};
public:
	operator double() const; 
	Mref& operator= (double);
	Mref& operator= (const Mref&);
}; 

#endif
