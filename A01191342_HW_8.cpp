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
#include <vector>

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

int locationIndex(vector<string> &vLocs, string sLocation){
	for (int i = 0; i < vLocs.size(); ++i)
		if (vLocs[i] == sLocation)
			return i;

	vLocs.push_back(sLocation);//If no location was found, push new location to vector.

	return vLocs.size();//Return vLocs size for the last index.
}

void roadInput(int aGraph[100][100], vector<string> &vLocs, string sLocA, string sValue, string sLocB) {
	//Records the values and connections of the roads.
	//Cleanse string variables, sLocA, sValue, sLocB.
	//Function to return index of location or create a new one from vLocs.
	//Store in aGraph
}

int main () {

	//Problem 1
	//Variables
	int N = 0;//0 < N < 100
	int C = 0;//0 <= C < 1000
	int R = 0;//0 < R < 10000
	int aGraph[100][100] = {};//2D Array graph.

	string sLocation = "";//Location container.
	queue<string> qLocations;//Queue to attend car crashes as they where registered.
	vector<string> vLocations;//Vector for storing locations indexes.

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
				qLocations.push(sLocation);
			}

			string sLocA;
			string sValue;
			string sLocB;

			for (int i = 0; i < R; ++i)
			{
				cin >> sLocA; cin >> sValue; cin >> sLocB;
				roadInput(aGraph, vLocations, sLocA, sValue, sLocB);
			}

		} else {
			cout << "No Test Case" << endl;
		}
	} while(N != 0 && R != 0);

   return 0;
}