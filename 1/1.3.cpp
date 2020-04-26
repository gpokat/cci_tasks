//URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string
//has sufficient space at the end to hold the additional characters, and that you are given the "true"
//length of the string. (Note: If implementing in Java, please use a character array so that you can
//perform this operation in place.)

//The simple and ugly solution !!!
//But the task should have more specific information about behavior of the implemeting algorithm.
//BigO is O(n) becouse of loop. Just compare space to the current character, replace and control "true" length.
string ReplaceSpaces(string str, int true_length)
{

    string result = "";

    for (auto v : str)
    {
        if (true_length <= 0)
            break;

        if (v == ' ')
        {
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
            true_length--;
        }
        else
        {
            result.push_back(v);
            true_length--;
        }
    }

    return result;
}
//p.s. The solution for Java from book is worked only for pury cases like "Mr John Smith   ",
//but doesn't work for case like this " Mr John Smith   " or like like this "Mr  John  Smith   ".
//Thats why this task is worst for interview - so much special cases u have to predict.