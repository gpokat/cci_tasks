//Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin-
//drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
//is a rea rrangement of letters. The palindrome does not need to be limited to just dictionary words.

//optimize way for O(2n)
//We don't have to generate permutation coz enough to calculate calls of characters and compare it with length of string.
//Then if the length is even that is mean true palindrome must have only even calls of characters due to duplicates,
//if the length is odd that mean true palindrome must have only one odd call due to existing of only one unpair character.
bool IsStringAPalindrome(string str)
{

    //remove spaces
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); //or others specific delimeters if requared //O(n) at worst case

    map<int, int> table;

    for (int i = 0; i < str.length(); ++i)
    { //O(n)
        int askii_key = str[i] - '0';

        //change case
        if (askii_key < 96)
            askii_key = tolower(str[i]); //O(1)

        if (!table.count(askii_key)) //O(1)
            table.emplace(askii_key, 1);
        else
            table[askii_key]++;
    }

    int odd = 0;

    for (auto v : table) //O(n) at worst case
        if (v.second % 2 != 0)
            odd++;

    if (str.length() % 2 == 0 && odd == 0)
        return true;
    else if (str.length() % 2 != 0 && odd == 1)
        return true;
    else
        return false;
}

//straightward way for O(n!) runtime.
//We could generate all possible permutations of the string exclude specific characters like ' ', -, +, - etc. and lower/uppercases,
//then check if it is a palindrome.
bool IsStringAPalindrome(string str)
{

    //prepare string
    //set all characters to lowercase
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c) { return tolower(c); }); //O(n) at worst case

    //sort alphabetically for next_permutation
    sort(str.begin(), str.end()); //O(n*log(n))

    //remove spaces
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); //or others specific delimeters if requared //O(n) at worst case

    bool isPalindrome = true;
    do
    {

        isPalindrome = true;
        //check is it palindrome
        int j = str.length() - 1;
        for (int i = 0; i < str.length(); ++i, --j)
        { //O(n)
            int askii_key_forward = str[i] - '0';
            int askii_key_backward = str[j] - '0';

            if (askii_key_forward - askii_key_backward != 0)
            {
                isPalindrome = false;
                break;
            }
        }

    } while (next_permutation(str.begin(), str.end()) && !isPalindrome); //gener possible permutation //O(n!)

    return isPalindrome;
}
