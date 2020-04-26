//Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
//cannot use additional data structures?

//The idea is to check the string for a characters duplicates
//If the string hasn't a duplicate - true, otherwise - false.

//Could be applied for arbitrary alphabet
bool IsStrHasAllUnuqueChars(string input_str)
{ //O(n*log(n))

    map<int, char> buff;

    for (auto v : input_str)
    { //O(input_str.size())

        int ascii_key = v - '0'; // for arbitrary alphabet should be change to the better cash function

        if (!buff.count(ascii_key)) //log(buff.size())
            buff.emplace(ascii_key, v);
        else
            return false;
    }
    return true;

    //without using by map container
    //just checking each characted one by one with others for O(n^2) runtime
}