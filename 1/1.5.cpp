//One Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character. Given two strings, write a function to check if they are
//one edit (or zero edits) away.

//In this task we have a 2 cases:
//1st for equal strings  - check for one or less possible edits used to ASCII differences between strings
//2nd for strings with different length - bruteforce possible solutions throught like erase one character (the insertion for smaller string equivalents the removing for bigger string).
bool OneAway(string str1, string str2)
{

    if (abs(str1.length() - str2.length()) > 1)
        return false;

    if (str1.length() == str2.length())
    { //O(n)
        int edit_seed = 0;
        for (int i = 0; i < str1.length(); ++i)
        {

            int askii_key1 = str1[i] - '0';
            int askii_key2 = str2[i] - '0';

            if (askii_key1 - askii_key2 != 0)
                edit_seed++;
        }

        if (edit_seed > 1)
            return false;
        else
            return true;
    }
    else
    {

        string bigger_str = (str1.length() > str2.length()) ? str1 : str2;
        string smaller_str = (str1.length() > str2.length()) ? str2 : str1;

        for (int i = 0; i < bigger_str.length(); ++i)
        { //O(n)+-
            string stmp = bigger_str;
            string::iterator it = stmp.begin() + i;
            stmp.erase(it);

            if (stmp == smaller_str)
                return true;
        }

        return false;
    }
}
