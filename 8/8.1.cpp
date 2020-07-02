//Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
//steps at a time. Implement a method to count how many possible ways the child can run up the
//stairs.


const int N = 6;
//Brute-force solution
//straightforward way to calculate recursevly for O(3^n) runtime and O(1) space complexity.
int RunUp(int n)
{
if(n<0) return 0; //return 0 if we overstepped of N
else if(n==0)
return 1; //return 1 way if we traversed all N
else return RunUp(n-1)+RunUp(n-2)+RunUp(n-3);   //going deepere by N creating on each n three branches
}
