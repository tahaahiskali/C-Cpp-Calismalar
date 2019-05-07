#include <iostream>


template < typename T > 

T maximum ( T value1, T value2, T value3 )  //   OR     auto maximum ( T value1, T value2, T value3 ) -> T
{
	T maximumValue = value1;
	
	if ( value2 > maximumValue )
		maximumValue = value2;
	
	if ( value3 > maximumValue )
		maximumValue = value3;
		
	return maximumValue;
	
 } 
 
 
 using namespace std;
 
 int main()
 {
 	
	int int1 = 0;
	int int2 = 0;
	int int3 = 0;
	
	cout << "Input three integer values : ";
	cin >> int1 >> int2 >> int3;
	
	cout << "integer maximum  = " << maximum(int1, int2, int3) << endl;
	
	double double1 = 0.0;
	double double2 = 0.0;
	double double3 = 0.0;
	
	cout << "Input three double values : ";
	cin >> double1 >> double2 >> double3;
	
	cout << "double maximum  = " << maximum(double1, double2, double3);
 	
 }
