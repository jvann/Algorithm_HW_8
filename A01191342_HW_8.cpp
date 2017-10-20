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

void fillMatrix(int aGraph[100][100], int N) {
	//Fills 2D array with "Infinite" (No connection), also cleanses the matrix for new use.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			aGraph[i][j] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j)
				aGraph[i][j] = 999;
}

bool validateValues(int N, int C, int R) {
	//Validates the range of values.
	//Validate 0 < N < 100, 0 <= C < 1000, 0 < R < 10000

	if (0 < N && N < 100)
		if (0 < R && R < 10000)
			if (0 <= C && C < 1000)
				return true;
	return false;
}

int lIndex(vector<string> &vLocs, string sLocation){
	//LocationIndex.
	//Gets the index of the location given, if not found, it is added to the vector list.
	for (int i = 0; i < vLocs.size(); ++i)
		if (vLocs[i] == sLocation)
			return i;

	vLocs.push_back(sLocation);//If no location was found, push new location to vector.

	return vLocs.size()-1;//Return vLocs size for the last index.
}

void roadInput(int aGraph[100][100], vector<string> &vLocs, string sLocA, string sValue, string sLocB) {
	//Records the values and connections of the roads.
	//Auxiliar variables for connection.
	int iValue;//Distance measured.

	string sAux1;//Direction 1.
	string sAux2;//Direction 2.

	//Cleanse string variable sValue.
	sAux1 = sValue.front();//Access first element.
	sAux2 = sValue.back();//Access last element.

	//Clear string for conversion.
	sValue.erase(0,2);//Clears first 2 characters from string.
	sValue.erase(sValue.length()-2,2);//Clears last two characters from string.

	//Convert string to int value(Distance).
	iValue = stoi(sValue);

	//Check locations.
	lIndex(vLocs, sLocA);//For sLocA.
	lIndex(vLocs, sLocB);//For sLocB.

	//Store value(Distance) in aGraph.
	if (sAux1 == "<")
		aGraph[lIndex(vLocs, sLocB)][lIndex(vLocs, sLocA)] = iValue;
	if (sAux2 == ">")
		aGraph[lIndex(vLocs, sLocA)][lIndex(vLocs, sLocB)] = iValue;
}

// Algoritmo de Floyd
int min(int a, int b)
{
 if(a<b)
  return(a);
 return(b);
}

void floyd(int aGraph[100][100], int N)
{
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				aGraph[i][j]=min(aGraph[i][j],aGraph[i][k]+aGraph[k][j]);
}

int getDistanceRoute(int aGraph[100][100], queue<string> qLocations, vector<string> &vLocs)
{
	int iSumDistance = 0;//Distance tarveled acumulation.
	string sAux; //Auxiliar variable to hold starting point.

	while(!qLocations.empty())
	{
		sAux = qLocations.front();
		qLocations.pop();

		iSumDistance += aGraph[lIndex(vLocs, sAux)][lIndex(vLocs, qLocations.front())];
	}

	return iSumDistance;
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

	//One or more test cases.
	do 
	{
		//New test case. 0, 0, 0 == no more test cases.
		cin >> N; cin >> C; cin >> R;

		if (validateValues(N, C, R))
		{
			fillMatrix(aGraph, N);//For cleaning and initializing.

			//First place/input is the agency base.
			cin >> sLocation;
			qLocations.push(sLocation);
			vLocations.push_back(sLocation);

			//Next car queues
			for (int i = 0; i < C; i++)
			{	
				cin >> sLocation;
				qLocations.push(sLocation);
			}

			qLocations.push(qLocations.front());//Needs to return to agency base, so we add the last point as the base.

			//Auxiliar variables
			string sLocA;
			string sValue;
			string sLocB;

			for (int i = 0; i < R; ++i)
			{
				cin >> sLocA; cin >> sValue; cin >> sLocB;
				roadInput(aGraph, vLocations, sLocA, sValue, sLocB);
			}

			floyd(aGraph, N);//Apply floyd for shortest paths.

			cout << getDistanceRoute(aGraph, qLocations, vLocations) << endl;//Gets the total travel distance.
		}

	} while(N != 0 && C != 0 && R != 0);

   return 0;
}