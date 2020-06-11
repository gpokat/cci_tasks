//BST Sequences: A binary search tree was created by traversing through an array from left to right
//and inserting each element. Given a binary search tree with distinct elements, print all possible
//arrays that could have led to this tree.
//EXAMPLE
/*          2
           / \
          1   3
        */
//Output: {2, 1, 3} , {2, 3, 1}

//straithward way (non-efficient)
//Shuffle initial array i.e. make all possible permutations than try to build BST from this new array by rule frome task description then
//compare new BST with initial pattern. If both are equal, then reminde permutation (sequance) otherwise continue.
//The runtime is O(N!) due to permutations.

//The backtracking solution located here https://coliru.stacked-crooked.com/a/ad69f44617748795
//Another similar approach is desribed using by SWIFT laguage: https://gist.github.com/kean/40a1e592a608154b117a0dac48baf25f
//And another is at Reddit using by Java: https://www.reddit.com/r/algorithms/comments/3q96r5/print_all_possible_sequences_that_could_have/

struct Node
{

  Node *left_child = nullptr;
  Node *right_child = nullptr;

  int data;

  Node(int d) : data(d)
  {
  }
};

//The backtrack approach:
//suffle initial seeds using by backtrack in reverse order then build an array from this seeds.
//Runtime is O(2^N)
//Space is O(N) due to we have to reminde a node in vector before print. 
vector<vector<Node *>> possible_initial_arrays;
void GenerateAllSequance(deque<Node *> *seeds_to_sequance, vector<Node *> *new_sequance)
{
count++;
  if (seeds_to_sequance->empty())
  { //store here or just print w/o store
    /*for(auto v : new_sequance){
cout<<v->data<<" ";
}*/
    possible_initial_arrays.push_back(*new_sequance);
    return;
  }

  deque<Node *> seeds = (*seeds_to_sequance);
  for (int i = 0; i < seeds_to_sequance->size(); ++i) //must to be a safe-index manner i.e. we shuld travers trought all input indexes
  {
    Node *seed = seeds.front();
    seeds.pop_front();

    if (seed->left_child != nullptr)  seeds.push_back(seed->left_child);
    if (seed->right_child != nullptr) seeds.push_back(seed->right_child);

    new_sequance->push_back(seed);

    GenerateAllSequance(&seeds, new_sequance);
    //backtrack & shuffle initial seeds in reverse order
    new_sequance->pop_back();
    if (seed->left_child != nullptr) seeds.pop_back();
    if (seed->right_child != nullptr) seeds.pop_back();
    seeds.push_back(seed);
  }

  return;
}

void GenerateAllSequance(Node *root)
{
  deque<Node *> *sq = new deque<Node *>();
  sq->push_front(root);

  vector<Node *> *hh = new vector<Node *>();
  GenerateAllSequance(sq, hh);

  cout << "print possible sequances: " << endl;
  for (auto v : possible_initial_arrays)
  {
    for (auto v2 : v)
    {

      cout << v2->data << " ";
    }
    cout << "\n";
  }
}