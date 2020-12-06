//Word Frequencies: Design a method to find the frequency of occurrences of any given word in a
//book. What if we were running this algorithm multiple times?

//We could solve it for O(N) runtime and O(1) space when N is number of words in the book.
//Or we could use a hashmap to store whole book for O(N) time + O(N) space and then have a O(1) time
//for gettin word frequency.

unordered_map<string, int> store_of_book_words;

void readBook(vector<string> &book)
{

    for (auto word : book)//O(N) read whole book 
    {
        if (store_of_book_words.contains(word)) //if word already in the bank
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower); //cast each word to lowercase 
            store_of_book_words[word]++; //add frequency
        }
        else
        {
            store_of_book_words.insert(word, 1); //if it's first time word add 
        }
    }
}

int getFrequency(string &word)
{
    return store_of_book_words.count(word); //return frequency
}