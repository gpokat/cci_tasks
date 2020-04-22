//The answer is O(b) or O(n).
//The recursive is expand into b-1, (b-1)-1, ... b-1)-1)-1...-1 and the number of recursion calls is equal to (b) argument.

int power(int a, int b){
    if(b<0){
        return 0;
    } else if(b==0){
        return 1;
    } else {
        return a*power(a,b-1);
    }
}