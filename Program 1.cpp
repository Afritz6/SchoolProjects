#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num1,den1, num2, den2;
	cout << endl << "FRACTION 1" << endl;
	cout << "Input Numerator:   ";
	cin >> num1;
	cout << "Input Denominator: ";
	cin >> den1;
	
	cout <<endl <<  "FRACTION 2" << endl;
	cout << "Input Numerator:   ";
	cin >> num2;
	cout << "Input Denominator: ";
	cin >> den2;

	cout << endl << "RESULTS" << endl;
	float times1 = num1 * num2;
	float times2 = den1 * den2;
	cout << num1 << "/" << den1 << " times " << num2 << "/" << den2 << " = " << times1 << "/" << times2 << endl; //multiplication
	float divid1 = num1 * den2;
	float divid2 = num2 * den1;
	cout << num1 << "/" << den1 << " divided " << num2 << "/" << den2 << " = " << divid1 << "/" << divid2 << endl;//divid
	float add1 = num1 * den2;
	float comden = den1 * den2;
	float add3 = num2 * den1;
	float plus1 = add1 + add3;
	cout << num1 << "/" << den1 << " plus " << num2 << "/" << den2 << " = " << plus1 << "/" << comden << endl;//plus
	return 0;
}