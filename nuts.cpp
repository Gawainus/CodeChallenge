/*
Problem: given N bolts and N nuts.
	Bolts cannot be compared to nuts and nuts cannot be compared to nuts.
	The only way to compare is to fit bolts into nuts.
	Find the matching nut of each bolt. They are one to one mapped.
*/
/*
 The obvious way is to do a n^2 search. A better way is a binary search, that would be n*log(n). 
 The best way is to hash to bolts in a hashmap. Then, we see which one matches, and finish that. 2n ~ O(n).
 However, I am a little unclear on what this question means ? - How do we find that a nut 'fits' a bolt ? 
 - Juspreet 
 */
 

int main() {
	
}
