#include "matrix.h"

//...........................Matrix.......................
Matrix::Matrix(){
	data = new Tab(0,0);
}

Matrix::Matrix(unsigned int ww, unsigned int kk){
	data = new Tab(ww,kk);
}

Matrix::Matrix(Matrix& mat){
	mat.data->n++;
	data = mat.data;
}

Matrix::~Matrix(){
	if(--data->n == 0)
		delete data;
}

Matrix Matrix::operator+ (const Matrix & mat) const{
	if(mat.data->k != data->k || mat.data->w != data->w)
		throw Range();

	Matrix c(data->k, data->w);
	for(int i=0; i< data->k * data->w; i++)
		c.data->t[i] = data->t[i] + mat.data->t[i];
	return c;
}

Matrix Matrix::operator- () const{
	Matrix c(data->k,data->w);
	for(int i=0; i < data->k * data->w; i++)
		c.data->t[i] = -data->t[i];
	return c;
}

Matrix Matrix::operator- (const Matrix& mat) const{
	if(mat.data->k != data->k || mat.data->w != data->w)
		throw Range();	

	Matrix c(data->k, data->w);
	for(int i=0; i< data->k * data->w; i++)
		c.data->t[i] = data->t[i] - mat.data->t[i];
	return c;
}

Matrix Matrix::operator* (const Matrix& mat) const{
	if(mat.data->w != data->k)
		throw Range();

	Matrix c(data->w,mat.data->k);	//Macierz wynikowa C ma tyle wierszy, ile macierz A oraz tyle kolumn, ile macierz B.

	for(int i = 0; i < c.data->w; i++)
		for(int j = 0; j < c.data->k; j++)
			for(int a = 0; a < data->k; a++)
				for(int b = 0; b < mat.data->w; b++)
					c.data->t[i * c.data->k + j] += data->t[a + a*i]*mat.data->t[b+j]; 
	return c;
}

bool Matrix::operator== (const Matrix& mat) const{
	if(data->k != mat.data->k || data->w != mat.data->w) return 0;
	for(int i = 0; i < data->w * data->k; i++)
		if(data->t[i] != mat.data->t[i]) return 0;
	return 1;  
}

Matrix& Matrix::operator+= (const Matrix& mat){
	*this = *this + mat;
	return *this;
}

Matrix& Matrix::operator-= (const Matrix& mat){
	*this = *this - mat;
	return *this;
}

Matrix& Matrix::operator*= (const Matrix& mat){
	*this = *this * mat;
	return *this;
}

Matrix& Matrix::operator= (const Matrix& mat){
	/*
	if(mat.data->k != data->k || mat.data->w != data->w)
	{
		data->k = mat.data->k;
		data->w = mat.data->w;
		delete [] data;
		dane = new (std::nothrow) double[data->k * data->w];
		//assert(dane!=nullptr && "@balad alokacji@");
	} 
	for(int i=0; i < data->k * data->w; i++)
		dane->t[i] = mat.data->t[i];*/
	mat.data->n++;
	if(--data->n == 0)
		delete data;
	data = mat.data;
	return *this;
}

std::ostream & operator<< (std::ostream& s, const Matrix& mat){
	s << "\n";
	for(int i=0; i < mat.data->w; i++)
	{
		for(int j=0; j < mat.data->k; j++)
			s << mat.data->t[i * mat.data->k + j] << " ";
		s << "\n";
	}
	return s;
}

Matrix& Matrix::wczytaj_z_pliku(std::string& s){
	std::ifstream plik;	//tylko odczyt
	//plik.open(s,std::ios::in);
	plik.open(s.c_str());
	if(!plik.good()){
		std::cout << "blad odczytu pliku";
		throw Range();
	}
	int w, k;
	plik >> w >> k;
	Matrix c(w,k);
	for(int i = 0; i < w * k; i++)
		plik >> c.data->t[i];
	plik.close();
	*this = c;
	return *this;
}

double Matrix::operator() (const unsigned int ww, const unsigned int kk) const{
	cout << "(DOUBLE)"; //do tego nigdy nie wchodzi?
	check(ww,kk);	//sprawdzanie czy i jest w tekscie
	return data->t[ww*data->k + kk];
}

Matrix::Mref Matrix::operator() (const unsigned int ww, const unsigned int kk){
	cout << "(MREF)";
	check(ww,kk);	//sprawdzanie czy i jest w tekscie
	return Mref(*this,ww,kk);
}

void Matrix::check(unsigned int ww, unsigned int kk) const{
	cout << "CHECK";
	if(data->w <= ww || data->k < kk)
		throw Range(); //throw = wyrzucenie wyjatku
}

double Matrix::read(const unsigned int ww, const unsigned int kk) const{
	cout << "READ";
	return data->t[ww*data->w + kk];
	
}

void Matrix::write(const unsigned int ww, const unsigned int kk, double dd){
	cout << "WRITE";
	data = data->detach();
	data->t[ww*data->w + kk] = dd;
}
//..........................Tab....................
Matrix::Tab::Tab(unsigned int ww, unsigned int kk){
	t = new (std::nothrow) double[ww*kk];
	w = ww;
	k = kk;
	for(int i = 0; i <w*k; i++)
		t[i] = 0;
	n = 1;
}

Matrix::Tab::~Tab(){
	delete [] t;
}

Matrix::Tab* Matrix::Tab::detach(){
	if(n == 1)
		return this;
	Tab* tb = new Tab(w,k);
	tb->t = t;
	n--;
	return tb;
}


//..............................Mref.......................
Matrix::Mref::operator double() const{
	return m.read(w,k);
}
Matrix::Mref& Matrix::Mref::operator= (double d){
	m.write(w,k,d);
	return *this;
}

Matrix::Mref& Matrix::Mref::operator= (const Mref& ref){
	return operator=((double)ref);
}

