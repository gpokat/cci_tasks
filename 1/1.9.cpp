//String Rotation: Assume you have a method isSubstring which checks if one word is a substring
//of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
//call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").

//pre-existing method
bool isSubstring(string str1, string str2){
    ...
}

//The idea is to doubled inital string itself(using by concatination) and than
//using method isSubstring to check containing already rotated string inside
//a doubled initial string which contain all possbile variants of rotation.
//Runtime is O(n^2) * O(isSubstring) approximatly is around O(n^3)
bool isStringRotate(string str1, string str2){

string AllPossibleRotations=str1+str1; //it's a combinatorial trick

if(isSubstring(str2,AllPossibleRotations)) return true;

return false;

}

//The other way looks like a brute-force -
//just generate a possible rotation and check - anyway it is required
//several comparisons between strings and not a one calls the isSubstring =)