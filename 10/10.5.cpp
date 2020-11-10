//Sparse Search: Given a sorted array of strings that is interspersed with empty strings, write a
//method to find the location of a given string.
//EXAMPLE
//Input: ball, {"at","", "", "", "ball","" , "" , "car","","" ,"dad","",""}
//Output: 4

//Classic binary search but with strings. For the skipping empty slots using brute-force approach to 
//find closest non-empty string as mid.

//The runtime is O(log(N)) or O(N) at worst case with O(1) space.


vector<string> strings{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

int binarySearchString(vector<string> &strs, int l, int r, string v)
{

    if (r >= l && strs.size() > 0 && v != "")
    {

        int mid = l + (r - l) / 2;

        if (strs[mid] == "")
        {
            int new_mid_left = mid - 1;
            int new_mid_right = mid + 1;
            while (true)
            {
                if (new_mid_left < l || new_mid_right > r)
                    return -1;

                if (strs[new_mid_left] != "")
                {
                    mid = new_mid_left;
                    break;
                }
                else if (strs[new_mid_right] != "")
                {
                    mid = new_mid_right;
                    break;
                }
                new_mid_left--;
                new_mid_right++;
            }
        }

        if (strs[mid] == v)
        {
            return mid;
        }

        if (strs[mid].compare(v) > 0)
        {
            return binarySearchString(strs, l, mid - 1, v);
        }
        return binarySearchString(strs, mid + 1, r, v);
    }
    return -1;
}
