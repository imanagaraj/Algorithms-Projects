/*CS 303 Assignment 2 C++ Maximum Subsequence Program
 Aparna Nagaraj
 Febrary 27th 2017
 */

#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;

/* Description: This program uses 4 different algorithms to compute the maximum subsequence of a given array of size up to 2500. The algorithms use varying strategies to compute the max subsequence and have time complexities O(n), O(n log n), O(n^2), and O(n^3). The program returns the max subsequnce found by every algorithm and the run time of every algorithm. 
 */


double maxSubSum1(int a[], int arrSize)
{
	clock_t start;
	clock_t end;
	double time;

	int maxSum = 0;

	start = clock();
	end = 0;

	for(int i = 0; i < arrSize; ++ i)
		
		for(int j = i; j < arrSize; ++j)
		{
			int thisSum = 0;
			for( int k = i; k <= j; ++k)
				thisSum += a[k];

			if(thisSum > maxSum)
				maxSum = thisSum;
		}

	end = clock();

	time = end - start;

	time = time/CLOCKS_PER_SEC* 1000000;

	cout<<"Algorithm 1: "<< maxSum << "\n";
	return time; 
}


double maxSubSum2(int a[], int arrSize)
{
	clock_t start;
	clock_t end;
	double time;

	int maxSum  = 0;

	start = clock();
	end = 0;
	
	for(int i = 0; i < arrSize; ++i)
	{

		int thisSum = 0;

		for(int j = i; j < arrSize; ++j)
		{
			thisSum+= a [j];

			if(thisSum > maxSum)
				maxSum = thisSum;

		}

	}

	end = clock();

	time = end - start;

	time = time/CLOCKS_PER_SEC * 1000000;

	cout<<"Algorithm 2: "<< maxSum << "\n";
	return time;
}

int maximum(int x, int y, int z) {
	int max = x;

	if (y > max) {
		max = y;
	} 

	if (z > max) { 
		max = z;
	} 

	return max; 
} 

int maxSumRec(int a[], int left, int right) //getting jacked up bc of array size
{
	if (left == right){

		if(a[left] > 0){
			return a[left];
		}
		
		else{
			return 0;
		}

	} // base case


	int center = (left+right)/2; //median
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center+1, right);

	int maxLeftBorderSum = 0;
	int leftBorderSum = 0;
	for(int i = center; i>= left; i--)
	{
		leftBorderSum += a[i];
		if(leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0;
	int rightBS = 0;
	for(int j = center + 1; j<= right; ++j)
	{
		rightBS += a[j];
		if(rightBS > maxRightBorderSum)
			maxRightBorderSum = rightBS;
	}
	
	int borderSum = maxLeftBorderSum + maxRightBorderSum;
	
	return maximum(maxLeftSum, maxRightSum, borderSum);
	
}

double maxSubSum3(int a[], int arrSize)
{
	clock_t cStart;
	clock_t cEnd;
	double time;
	
	cStart = clock();
	cEnd = 0;
	
	int maxSum = maxSumRec(a, 0 , arrSize - 1);

	cEnd = clock();

	time = cEnd - cStart;

	time = time/CLOCKS_PER_SEC * 1000000;
	cout<<"Algorithm 3: "<< maxSum << "\n"; //////////////
	return time;

}


double maxSubSum4(int a[], int arrSize)
{
	clock_t start;
	clock_t end;
	double time;

	int maxSum = 0, thisSum = 0;

	start = clock();
	end = 0;

	for ( int j = 0; j < arrSize; ++j)
	{
		thisSum += a[j];

		if(thisSum > maxSum)
			maxSum = thisSum;
		else if( thisSum < 0)
			thisSum = 0;
	}

	end = clock();

	time = end - start;
	time = time/CLOCKS_PER_SEC * 1000000;

	cout<<"Algorithm 4: "<< maxSum << "\n";
	return time;
	
}
int main(){

	int i=0;
	int array[2500] = {};  //initialize array max sixe 2500
	string arr;

	cout<<"Please enter sequence integers: "<<"\n";
    cin>>arr;//manual input of sequence integers
    
	while(cin >> array[i]){    // populate array with numbers from file or user input
		i++;
	}

	int arrSize = i;
    
	double alg1 = maxSubSum1(array, arrSize);  //call each function for the array and its size
	double alg2 = maxSubSum2(array, arrSize);  //results are printed from each function
	double alg3 = maxSubSum3(array, arrSize);
	double alg4 = maxSubSum4(array, arrSize);

	cout << "Final Results" << "\n";

	cout<<"\t"<< "Algorithm 1 O(n^3):    " << fixed<<std::setprecision(0) << alg1 << "ms"<< "\n";  // print the run time of each function
	cout<<"\t"<< "Algorithm 2 O(n^2):    " << fixed<<std::setprecision(0)<< alg2 <<"ms"<< "\n";
	cout<<"\t"<< "Algorithm 3 O(n lg n): " << fixed<<std::setprecision(0)<< alg3 <<"ms"<< "\n"; 
	cout<<"\t"<< "Algorithm 4 O(n):      " << fixed<<setprecision(0)<< alg4 <<"ms"<< "\n";
	
	


}
