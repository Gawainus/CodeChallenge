/*
	Problem: Find the subarr with the biggest sum in an arr of int
		the array has lat least 1 positive num.

	Originally Solved by Yumen

	Note, this solution find all the legit sums can push them to the solnVec.
	If you need the largest one, just compare their soln->sum
*/

# include <iostream>
# include <vector>

using namespace std;

typedef struct soln_t {
	unsigned int start;
	unsigned int end;
	long long sum;
} soln;

int main() {

	int arr[] = { -1, 10, 8, -7, 1, 2, 10, 11, -60, 102, 2, -1, -2, -100, 200};
	vector<int> * input = new vector<int>( arr, arr + sizeof(arr) / sizeof(int) );

	vector<soln_t *> solnVec; //soln vector
	soln_t* soln = new soln_t();
	soln->start = 0;
	soln->end = 0;
	soln->sum = 0;

	long long currSum = 0;
	unsigned int N = input->size();

	for( unsigned int i = 0; i < N; i++)
	{
		int curr = input->at(i);
		cout <<"Curr: " << curr << " currSum: " << currSum << " Soln Sum: " << soln->sum << endl;
		
		if( curr <= 0 && soln->start == 0) { // skip all non-positives in the beginning
			cout << endl;
			continue;
		}

		if( soln->start == 0 ) { // start with the first non-negative
			soln->start = i;
		}

		if( curr <= 0 && currSum > soln->sum ) {
			// detected a negative. record a checkpoint
			soln->end = i-1;
			soln->sum = currSum;
		}

		currSum += curr;

		if( i == N-1 ) {
			if( currSum > soln->sum) {
				soln->end = N-1;
				soln->sum = currSum;
			}

			solnVec.push_back(soln);

			cout << endl;
			break;
		}

		if( currSum <= 0) {
			solnVec.push_back(soln);

			//reset
			soln = new soln_t();
			soln->start = 0;
			soln->end = 0;
			soln->sum = 0;
			currSum = 0;

			cout << endl;
			continue;
		}
	}
	delete input;

	cout << "Solns:" << endl;
	for ( int i = 0; i < solnVec.size(); i++ )
	{
		cout<< solnVec[i]->start << " " << solnVec[i]->end << " " << solnVec[i]->sum << endl;
		delete solnVec[i];
	}
}
