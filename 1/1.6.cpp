//String Compression: Implement a method to perform basic string compression using the counts
//of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
//"compressed" string would not become smaller than the original string, your method should return
//the original string. You can assume the string has only uppercase and lowercase letters (a - z).

//So, if string has only uppercase or lowercase letters we could just forming new string and calculate a forward duplicates of charecters.
//Approach is propagate a O(n) runtime.
string LetsCompress(string original_str)
{

     //if the string shouldn't sensetive to the upper/lowercases it could be added using by transform and tolower STL methods.

     string compress_str;
     compress_str.reserve(original_str); //reserve size

     compress_str.push_back(original_str[0]);
     compress_str.push_back('1');

     for (int i = 1; i < original_str.length(); ++i)
     {

          if (compress_str[compress_str.length() - 2] != original_str[i])
          {
               compress_str.push_back(original_str[i]);
               compress_str.push_back('1');
          }
          else
               compress_str[compress_str.length() - 1] = (compress_str[compress_str.length() - 1] - '0' + 1) + '0'; //trick to avoid concatenation problem
     }

     if (original_str.length() < compress_str.length())
          return original_str;

     return compress_str;
}