//Number Swapper: Write a function to swap a number in place (that is, without temporary variables).


//If we could overload +/- operators for the class, the in-place swap could be done with simple operations.
//Runtime is O(1), space is O(1)
void swap(int& a, int& b){

b=a+b; //add a to b i.e. store a with b in the same place
a=b-a; //to calculate a we have to substract from b=(a+b) a => a=(a+b)-a => a=b
b=b-a;//backward step to get b. b=(a+b)-b from previouse step.

}