//Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
//different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order
//of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following
//constraints:
//(1) Only one disk can be moved at a time.
//(2) A disk is slid off the top of one tower onto another tower.
//(3) A disk cannot be placed on top of a smaller disk.
//Write a program to move the disks from the first tower to the last using stacks


//The recursive function to moving disks from one to another tower based on discovered pattern
//from manual 2&3&4 cases solving with optimal numbers of steps.
//The runtime is to O(2^N) due to 2 recursive branches and space is O(N) due to stack storage.

typedef stack<int> tower;

void move_disk(tower &from, tower &to) //moving disk using by stack storage
{ 
    to.push(from.top());
    from.pop();
}

void HanoiRecursiveSolver(int count, tower &source_tower, tower &buffer_tower, tower &result_tower)
{
    if (count == 1) //top or smallest disk (counted from bottom to top)
    {
        move_disk(source_tower, result_tower); //if it smallest disk, just transfer it (i.e. smallet could be placed anywere)
        return;
    }
    HanoiRecursiveSolver(count - 1, source_tower, result_tower, buffer_tower); //make move from 1st tower to 2nd tower (hold disk in buffer)
    move_disk(source_tower, result_tower); //transfer disk from 1st tower to buffer
    HanoiRecursiveSolver(count - 1, buffer_tower, source_tower, result_tower); //going up & transver highest disk from 2nd tower to 3nd (last) tower
    return;//just reminding about tower mixing i.e. source->buffer; result->source; ----> and reverse
}