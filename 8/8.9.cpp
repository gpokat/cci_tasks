//Parens: Implement an algorithm to print all valid (i.e. properly opened and closed) combinations of n pairs of parentheses.
//EXAMPLE
//Input: 3
//Output: ((())), (()()), (())(), ()(()), ()()()

//The runtime is O(2^N), space is O(N*2)

//will be initialize once not in heap, but in special memory block
//should be initilize with parens_num*2 symbols
static string gen_res; //shared trought recursion stack

void PrintParens(int pos, int parens_num, int open_count, int close_count) {

    if (parens_num<=0) {//not valid case
        return;
    }
    //it could be here if you want =)
    //static string gen_res="000000"; //should be initilize with parens_num*2 symbols

    if (close_count == parens_num) { //print generated case 
        cout<<gen_res<<endl;           //if count of close braket equals to number of parens (i.e. generated all brackets)
        return;
    }

    if (open_count>close_count) { //if count of open brakets larger than count of close brakets then add close braket to string
        gen_res[pos]=')';
        PrintParens(pos+1, parens_num, open_count, close_count+1);
    }

    if (open_count < parens_num) { //if count of close brakets less then count of parens then add open braket to string
        gen_res[pos]='(';
        PrintParens(pos+1, parens_num, open_count+1, close_count);
    }


}
