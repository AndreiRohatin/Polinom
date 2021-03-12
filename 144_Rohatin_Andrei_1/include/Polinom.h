#ifndef Polinom_H
#define Polinom_H

#include <vector>
#include <cmath>
#include <iostream>
class Polinom
{
private:
	unsigned length;
	std::vector<double> coef;
public:

	//Constructors
	Polinom();
	Polinom(std::vector<double> coef);
	Polinom(Polinom &x);
	Polinom(Polinom const &x);
	Polinom(Polinom &&x);

	//Destructors
	~Polinom();

	//Methods
	double GetSum(double point);

	//Operators
	Polinom operator+(Polinom x);
	Polinom operator-(Polinom x);
	Polinom operator*(Polinom x);
	Polinom& operator=(const Polinom &x);
	Polinom operator^(int pow);
	double& operator[](unsigned x);
	bool operator!();
	bool operator==(Polinom x);
	bool operator!=(Polinom x);
	friend std::ostream& operator<<(std::ostream& os,const Polinom& x);
	friend std::istream& operator>>(std::istream& is, Polinom& x);


	//Getters
	std::vector<double> getCoef();
	unsigned getLength();
	//Setters
	void setCoef(std::vector<double> coef);
	void setLength(unsigned length);


};
#endif

