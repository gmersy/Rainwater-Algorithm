#include <iostream>
#include <cmath>

using namespace std;

double rightHeight(double arr[], int ind);
double leftHeight(double arr[], int ind);
double waterHeight(double arr[], int ind);

int main()
{
	double arr[10];
	double height;
	cout << "Input 10 heights: ";
	// Filling array with user input tower heights
	int i;
	for(i = 0; i < 10; i++)
	{
		cin >> height;
		if(height <= 0)
		{        
			cout << "Invalid heights!";
			
			return 0;
		}
		arr[i] = height;
	}
	// Computing total water
	double watTot = 0.0;
	for(i = 0; i < 10; i++)
	{
		double waterLevel = waterHeight(arr, i);		
		if(waterLevel > 0)
		{
			watTot += (waterLevel-arr[i]);
		}
	
	}
	cout << "Amount of water: " << watTot;
}

// Finds height to the right of the index argument
double rightHeight(double arr[], int ind)
{
	double temp[10];
	int i;
	for(i = 0; i < 10; i++)
	{
		temp[i] = arr[i];
	}
	double max = temp[ind+1];
	if(ind == 9)
	{
		max = 0.0; 
		return max;
	}
	for(i = ind+1; i < 10; i++)
	{
		
		if(temp[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
// Finds height to the left of the index argument
double leftHeight(double arr[], int ind)
{
	double temp[10];
	int i;
	for(i = 0; i < 10; i++)
	{
		temp[i] = arr[i];
	}
	
	double max = temp[ind-1];
	if(ind == 0)
	{
		max = 0.0;
		return max;
	}
	// here 
	for(i = ind-1; i >= 0; i--)
	{
		if(temp[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

// Computes water level at each index 
double waterHeight(double arr[], int ind)
{
	double waterLevel;
	double temp[10];
	int i;
	for(i = 0; i < 10; i++)
	{
		temp[i] = arr[i];
	}
	int indParam = ind;
	waterLevel = min(rightHeight(temp, indParam), leftHeight(temp, indParam));
	if(waterLevel <= temp[indParam])
	{
		waterLevel = 0.0;
	}
	else 
	{
		waterLevel = waterLevel;
	}
	
	return waterLevel;
}
