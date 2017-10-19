/*
 * Jorge Ivan Diaz Sanchez 
 * A01191342
 * Clase: Algorithms
 * Maestro: Roman Mtz
 * Fecha creacion: 19/10/2017
 * Fecha ultima modificacion: 19/10/2017
 * Nombre del programa: Homework 8
 * Descripcion del programa: Solve both problems from the PDF file Homework 8
 * Firma: 私は正直です。
*/

#include <iostream>
#include <queue>

using namespace std;

bool validateValues(int N, int C, int R) {
	//Validates the range of values.
	//Validate 0 < N < 100, 0 <= C < 1000, 0 < R < 10000

	if (0 < N && N < 100)
		if (0 < R && R < 10000)
			if (0 <= C && C < 1000)
				return true;
	return false;
}

void roadInput(queue &aGraph, string sLocA, string sValue, string sLocB) {
	//Records the values and connections of the roads.
	
}

int main () {

	//Problem 1
	//Variables
	int N = 0;//0 < N < 100
	int C = 0;//0 <= C < 1000
	int R = 0;//0 < R < 10000
	string sLocation = "";
	int aGraph[100][100] = {};
	queue<string> vLocations;

	//Fills 2D array with "Infinite" (No connection)
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (i != j)
				aGraph[i][j] = 999;

	//One or more test cases.
	do {

		//New test case. 0, 0, 0 == no more test cases.
		cin >> N; cin >> C; cin >> R;

		if (validateValues(N, C, R))
		{
			for (int i = 0; i <= C; i++)
			{	
				cin >> sLocation;
				vLocations.push(sLocation);
			}

			string sLocA;
			string sValue;
			string sLocB;

			for (int i = 0; i < R; ++i)
			{
				cin sLocA; cin >> sValue; cin >> sLocB;
				roadInput(aGraph, sLocA, sValue, sLocB);
			}

		} else {
			cout << "No Test Case" << endl;
		}
	} while(N != 0 && R != 0);

   return 0;
}