/* This is similar to a challenge question I received while interviewing with Palantir. The question is hard, and therefore, 
I have only given what I belive to be the solution. Errors noticed and fixed are welcome. */

/* Question: Given a mXn matrix, that is full of elements, such that, for all x in mXn, x belongs to [0,1]. Please return the 
maximum number of rows where the row is either completely full or 0's or completely full of 1's, given that you can flip a column.
Fliping will allow you to convert the zeroes into ones and ones into zeroes for the corresponding column.
/* Ex:) 110
        001
Fliping column 1 yields - 010
                          101
Fliping column 2 yields - 100
                          011
*/

#include <map>
#include <iostream>
#include <string>

int main(){
        /* I plan on approaching this by reading in the matrix. As I'm doing that, I will concatenate each row as a string 
         into a key for a hashmap, where the frequency of each row entry will be stored. We will then realize that the row with the 
         maximum frequency of a particular entry added to the frequency of it's compliment entry (if there) is the amount of max.
         number of rows with all 0's and all 1's. This can be thought of very intuitively. We can flip 'n' columns, either alone or
         together in a combinatorial fashion. However, the maximum number of rows you can ever get to align to this codition is 
         independent of the number of times or ways in which you flip the columns (maybe you can flip in more than one way). However,
         the number of maximum rows that one can achieve through this is independent of that condition, simply because one can 
         assume that flipping the columns will be tailored to a greedy approach of maximizing the number of entries that are already existing
         */
         /* Example : In the matrix given above, as the hashmap will be {110:1, 001:1), and they are compliments, we return 2.
          This can be achieve by flipping column 3 once. :D :D */
         
        int m, n;
        int[500][500];
        int freq_one_columns[500];
        std::map<std::string, int> hashed;
        std::cin >> m, n;
        for (int i = 0; i < m; i++){
                string curr;
                for (int j = 0; j < n; j++){
                        int current;
                        std::cin >> current;
                        curr.append((char)current);
                }
                std::map<std::string, int>::iterator it = hashed.begin();
                it = hashed.find(current);
                if (it == hashed.end()){
                        hashed.insert(std::pair<std::string, int>(current, 1));
                }
                else{
                        it->second += 1;
                }
        }
        int max_normal = 0;
        string maximum;
        for (std::map<std::string, int> iterator it2 = hashed.begin(); it2 != hashed.end(); it2++){
                if (it2->second > max_normal){
                        string maximum = it2->first;
                        max_normal = it2->second;
                }
                else{
                        continue;
                }
        }
        string complement;
        int max_compliment = 0;
        for (std::string::iterator it3 = maximum.begin(); it3 != maximum.end(); it3++){
                if (*it3 == '0'){
                        complement.append('1');
                }
                else{
                        complement.append('0');
                }
        }
        if (hashed.find(complement) != hashed.end()){
                max_complement = (hashed.find(complement))->second;
        }
        int max_output = max_normal + max_compliment;
        std::cout << max_output;
}

/* - Juspreet */
