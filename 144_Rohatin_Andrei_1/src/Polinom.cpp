#include "Polinom.h"

// Constructors
Polinom::Polinom(){
	this->length = 0;
	this->coef = std::vector<double>(0,0);
}
Polinom::Polinom(std::vector<double>coef){
	this->coef = coef;
	this->length = coef.size();
}
Polinom::Polinom(Polinom& x) {
	this->coef = x.coef;
	this->length = x.length;
}
Polinom::Polinom(Polinom const &x){
	this->coef = x.coef;
	this->length = x.length;
}
Polinom::Polinom(Polinom &&x){
	this->coef = x.coef;
	this->length = x.length;
}

//Destructors
Polinom::~Polinom(){
	delete &coef;
	delete &length;
}
//Methods
double Polinom::GetSum(double point) {
	double ret_obj = 0;
	//used to calculate point^power of n-th polynom element
	int index = 0;
	for (auto elm = this->coef.cbegin(); elm != coef.cend(); elm++, index++)
		ret_obj += pow(point, index) * (*elm);
	return ret_obj;
}

//Operators
Polinom Polinom::operator+(Polinom x) {
	Polinom ret_obj;
	//return the polynom which is higher in grade
	ret_obj.length = this->length > x.length ? this->length : x.length;

	//iterators for both vectors
	auto x_elm = x.coef.cbegin();
	auto this_elm = this->coef.cbegin();

	//iterate both vectors at the same time
	for (; x_elm != x.coef.cend() && this_elm != this->coef.cend(); x_elm++, this_elm++)
		ret_obj.coef.push_back((*x_elm) + (*this_elm));

	//treat the case where polynom x is higher in grade than polynom from context
	for (; x_elm != x.coef.cend(); x_elm++)
		ret_obj.coef.push_back(*x_elm);

	//treat the case where polynom from context is higher in grade than polynom x
	for (; x_elm != x.coef.cend(); x_elm++)
		ret_obj.coef.push_back(*x_elm);

	return ret_obj;
}
Polinom Polinom::operator-(Polinom x){
	Polinom ret_obj;
	//return the polynom which is higher in grade
	ret_obj.length = this->length > x.length ? this->length : x.length;

	//iterators for both vectors
	auto x_elm = x.coef.cbegin();
	auto this_elm = this->coef.cbegin();

	//iterate both vectors at the same time
	for (; x_elm != x.coef.cend() && this_elm != this->coef.cend(); x_elm++, this_elm++)
		ret_obj.coef.push_back((*x_elm) - (*this_elm));

	//treat the case where polynom x is higher in grade than polynom from context
	for (; x_elm != x.coef.cend(); x_elm++)
		ret_obj.coef.push_back(-(*x_elm));

	//treat the case where polynom from context is higher in grade than polynom x
	for (; x_elm != x.coef.cend(); x_elm++)
		ret_obj.coef.push_back(-(*x_elm));

	return ret_obj;
}
Polinom Polinom::operator*(Polinom x) {
	Polinom ret_obj;
	ret_obj.length = x.length + this->length-1;
	//initialize vector
	ret_obj.coef = std::vector<double>(ret_obj.length, 0);
	for (unsigned i = 0; i < this->length; i++)
		for (unsigned j = 0; j < x.length; j++) {
			ret_obj.coef[i + j] += this->coef[i] * x.coef[j];
		}

	return ret_obj;
}
Polinom Polinom::operator^(int pow) {
	Polinom ret_obj;
	ret_obj.coef = this->coef;
	ret_obj.length = this->length;
	--pow;
	while (pow) {
		ret_obj = ret_obj * ret_obj;
	}
	return ret_obj;
}
double& Polinom::operator[](unsigned pos) {
	return this->coef[pos];
}
bool Polinom::operator==(Polinom x) {
	if (this->length != x.length)
		return false;
	for (; x.length > 0; x.length--)
		if (this->coef[x.length-1] != x.coef[x.length])
			return false;
	return true;
}
bool Polinom::operator!=(Polinom x) {
	if (this->length != x.length)
		return true;
	if (this->length == x.length) {
		//if count equals length of polynom ===> they are equal
		int count = 0;
		for (; x.length > 0; x.length--)
			if (this->coef[x.length-1] != x.coef[x.length])
				count++;
		if (this->length == count)
			return false;
	}
	return true;


}
bool Polinom::operator!() {
	if (this->length == 0)
		return true;
	bool ok = true;
	for (double x : this->coef)
		if (x)
			ok = false;
	return ok;
}
Polinom& Polinom::operator=(const Polinom &x){
    this->length=x.length;
    this->coef=x.coef;
    return *this;
}
//Getters
std::vector<double> Polinom::getCoef() {
	return this->coef;
}
unsigned Polinom::getLength() {
	return this->coef.size();
}
//Setters
void Polinom::setLength(unsigned length){
    this->length=length;
}
void Polinom::setCoef(std::vector<double> coef){
    this->coef=coef;
}
