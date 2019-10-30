//Tracy Albers
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

vector<int> makePrimeList(int number); //this will be my list of prime numbers to use for checking
bool isPrime(int num); //function for checking primes
void test(); //a test function so I don't have to enter as many numbers when testing

int main()
{
	cout << "Enter number greater than 1 to check for Primeness: ";  //request input
	int number= 0; //declare variable
	while (number < 2) //check input
	{
	cin >> number; //receive input
	}
	bool answer = isPrime(number); //create a bool and immediately populate it with the return of the function
	if (answer == true) //state the results
		cout << number << " is prime.\n";
	else
		cout << number << " is composite.\n";
	//test(); //runs the test function, randomly generates numbers and then checks them for primeness
	system("Pause");
	return 0;
}

bool isPrime(int num)
{
	int limit = floor(sqrt(num)); //let the limit of checking to the floor of the square root of the input number
	int i = 0; //create a counter for going through the list of vectors
	bool prime = true; //set prime to true
	vector<int> primeList = makePrimeList(num); //populate the list of primes, creates more than necessary
	while ((primeList[i] <= limit) && (prime == true)) //continue the loop while the prime number is less limit
	{ //checks if a factor has been found by checking if prime flag is still true
		if (num%primeList[i] == 0) //if the number mod prime = 0, then the number is not prime
			prime = false; //set flag to false
		else
			i++; //otherwise, increment the counter to check next prime number within the limits
	}
	return prime; //return the boolean value
}
vector<int> makePrimeList(int number) //Using the Sieve of Eratosthenes Method
{
	vector<int> primeList;//create a vector for storing numbers
	for (int i = 2; i <= number; i++) //populate the list with all numbers between 2 and number desired
	{
		primeList.push_back(i); //put all numbers in the vector
	}
	int seive = 0;
	while (seive < (number / 2))
	{
	for (int k = 0; k < primeList.size(); k++) //start with 2 and increment until halfway through the list
	{ //the number will not be divisible by a number greater than half it's value
		seive = primeList[k]; //go through the remaining integers that are in the seive
			bool repeatOccurance = false; //set repeat occurance to false
			for (int j = 0; j < primeList.size(); j++) //check through all values on the primeList
			{
				if (primeList[j] % seive == 0) //if that number is divisible by i, further evaluate
				{
					if (repeatOccurance == true) //if this is not the first occurance, delete the number from the list
						primeList.erase(primeList.begin() + j);
					else //first occurance, don't delete but note additional occurances are repeats
						repeatOccurance = true;
				}
			}
		}
	}
	cout << "The primes from 1 to " << number << " are :"; //for fun, print the primes found
	for (int i = 0; i < primeList.size(); i++)
	{
		cout << primeList[i] << ' ';//incremenent through the list and print the primes 
	}
	cout << endl;
	return primeList; //return the prime list for use in other functions
}
void test() //a test function
{  //randomly generates 10 integers from 2 to 1000 and checks for primeness
	int size = 10; //set size
	srand((unsigned)time(0)); //prepare random number seed
	for (int i = 1; i <= size; i++) //increment 10 times
	{
		int limit = floor(pow(2, i)); //I wanted results from a variate of ranges, it'll go from 1-2, to 1-2^9)
		int nums = 2 + rand() % limit + 1; //generate random number
		bool answer = isPrime(nums); //check if that number is prime
		if (answer == true) //output result
			cout << nums << " is prime.\n";
		else
			cout << nums << " is composite.\n";
	}
}