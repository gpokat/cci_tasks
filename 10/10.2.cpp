//Group Anagrams: Write a method to sort an array of strings so that all the anagrams are next to each other.



//The approach based on sum of characters aka 'hash' using ASCII mappring.
//In this case it is working well becouse the ANAGRAMS strings must have the same length.
//Just in case if the array will be more complicated it could be cover using by additional constrains in lambda expression of sort algo.

//The runtime is O(N*log(N)), the space is O(1)

vector<string> arr={"man","bac","god", "abc", "dog", "cab"};

void SortedArr(vector<string>& arr){

sort(arr.begin(),arr.end(),[](const string& A, const string& B){
    if(accumulate(A.begin(),A.end(),0)<=accumulate(B.begin(),B.end(),0)) return true;
});

}
