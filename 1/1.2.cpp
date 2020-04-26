//Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

//The idea is to calculate sum of ASCII codes of the caracters for both of strings and than compare it.
//This hash is indepent of permutation and just link to the unique ASCII code if length is gurantee.
//BigO for that algorithm is O(2n)

//This approach could be used for arbitrary length with better hash function.
bool CheckPermuteStrings(string str1, string str2){

if(str1.length()!=str2.length()) return false;

unsigned int hash1=0, hash2=0;

for (auto v : str1) //O(n)
  hash1+=v-'0';

for (auto v : str2) //O(n)
  hash2+=v-'0';

if(hash1!=hash2) return false;

return true;

}
