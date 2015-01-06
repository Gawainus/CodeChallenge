/*
For string str0 = "YumenTsao", a rotation of it would be str1 = "TsaoYumen".
Given a isSubStr(string a, string b) function which returns whether a is a substring of b,
find out wheater str1 is a rotation of str0.
*/
/* We can put the main string in a hashmap, and then iterate through the given other string to check whether each of it's 
 characters are in the hashmap 
 Yumen, TsaoYumen is NOT a substring of YumenTsao. Please read the definition of a substring. Here:
 http://en.wikipedia.org/wiki/Substring#Substring
 */
 
#include <iostream>
#include <string>
#include <map>
int main() {
	string a;
	string b;
	if (a.length() > b.length()){
		std::cout<<"False";
	}
	else{
		std::map<char,int> tester;
		int placer = 0;
		for (std::string::iterator it = a.begin(); it != a.end(); it++){
			tester.insert(std::pair<char, int>((*it), placer));
			placer++;
		}
		int printed = 0;
		int count = 0;
		for (std::string::iterator it2 = b.begin(); it2 != b.end(); it2++){
			if (tester.find(*it2) != tester.end()){
				int curr = tester.get(*it2);
				if (curr - count > 1){
					printed = 1;
					std::cout<<"False";
					break;
				}
				else{
					count = curr;
				}
			}
			else{
				printed = 1;
				std::cout<<"False";
				break;
			}
		}
		if (printed != 1){
			std::cout<<"True";
		}
	}
	//sudo code is fine, this is an easy one
}
/* - Juspreet */
