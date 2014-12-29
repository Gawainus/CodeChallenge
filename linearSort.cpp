//write an algorithm to sort an int[] in linear time
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> * sort(vector<int> * unsorted) {
    
    int min= unsorted[0];
    int max= unsorted[0];

    int N = unsorted->size();

    for(int i=0;i < N; i++) {
        if(unsorted[i] > max) {
            max = unsorted[i];
        }
        if(unsorted[i] < min) {
            min = unsorted[i];
        }
    }

    int offset = -min;

    vector<int> * temp = new vector<int>(max-min,0);

    for(int i = 0; i < N; i++) {
        temp->at(unsorted->at(i)+offset) += 1;
    }

    for(int i = 0, j = 0; i < N; i++) {
        while(temp->at(i) > 0) {
             unsorted->at(j) = i - offset;
             temp->at(i)--;
             j++;
        }
    }

    return unsorted; //now its sorted
}
