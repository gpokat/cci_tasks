//Three in One: Describe how you could use a single array to implement three stacks.

//stack is a data structure which based on a FILO principle - First Input, Last Output
//support a fast modifying for O(1) runtime for the top element (which is insert to stack as last)

//stacks could be implemented with fixed sizes by dividing initial array by 3 parts.
//For efficient memory using I wrapping data to extended double linked list -
//it approach allow to use memory more flexible for three stacks(in general for kStacks), but requared a little bit more memory
//due to DLL allocation (flexible index array processing)

//general k stacks class for array allocation efficient
class kStack
{
private:
  struct Node
  {
    int index;
    Node *next;
    Node *prev;
    Node *prev_in_stack;
    bool isFree;
    Node(int i = -1,
         Node *n = nullptr,
         Node *p = nullptr,
         Node *ps = nullptr,
         bool isF = true) : index(i),
                            next(n),
                            prev(p),
                            prev_in_stack(ps),
                            isFree(isF){

                            };
  };

  int *arr;
  Node *first;
  Node *last;
  Node *top_nodes[3]; //could be a k size for kStacks

public:
  kStack(int *ap, int N) : arr(ap) //init double linked list for the array
  {
    Node *prev = new Node(N - 1);
    last = prev;
    for (int i = N - 2; i >= 0; --i)
    {
      Node *nprev = new Node(i, prev);
      prev = nprev;
    }
    first = prev;

    prev = prev->next;
    Node *c_prev = first;
    while (prev != nullptr)
    {
      prev->prev = c_prev;
      prev = prev->next;
      c_prev = c_prev->next;
    }

    top_nodes[0] = nullptr;
    top_nodes[1] = nullptr;
    top_nodes[2] = nullptr;
  }

  void push(int data, int stack_id = 0)
  {

    int idx = first->index;
    //  assert();TODO out of bound
    if (!first->isFree)
    {
      cout << "out of bound !" << endl;
      return;
    }
    arr[idx] = data; //store data at array

    first->isFree = false;
    switch (stack_id)
    {
    case 0:
      first->prev_in_stack = top_nodes[0];
      top_nodes[0] = first;
      break;
    case 1:
      first->prev_in_stack = top_nodes[1];
      top_nodes[1] = first;
      break;
    case 2:
      first->prev_in_stack = top_nodes[2];
      top_nodes[2] = first;
      break;
    }

    Node *next_first = first->next;
    first->next = nullptr;
    first->prev = last;
    last->next = first;
    last = first;
    first = next_first;
    first->prev = nullptr;
  }

  void pop(int stack_id = 0)
  {
    Node *top_node;
    switch (stack_id)
    {
    case 0:
    {
      top_node = top_nodes[0];
      top_nodes[0] = top_node->prev_in_stack;
      break;
    }
    case 1:
    {
      top_node = top_nodes[1];
      top_nodes[1] = top_node->prev_in_stack;
      break;
    }
    case 2:
    {
      top_node = top_nodes[2];
      top_nodes[2] = top_node->prev_in_stack;
      break;
    }
    }
    //arr[top_idx]=-999; //destroy or
    if (top_node->next != nullptr)
    {
      top_node->next->prev = top_node->prev;
      top_node->prev->next = top_node->next;
    }
    top_node->isFree = true;
    top_node->next = first;
    top_node->prev->next = nullptr;
    first->prev = top_node;
    top_node->prev = nullptr;
    first = top_node;
  }

  int &top(int stack_id = 0)
  {
    switch (stack_id)
    {
    case 0:
      return arr[top_nodes[0]->index];
    case 1:
      return arr[top_nodes[1]->index];
    case 2:
      return arr[top_nodes[2]->index];
    }
  }
};

//straightward way w/o additional data structure but with wage of unused space inside of stacks.
//reserve space in the array for 3 blocks and just looking for 3 indexes - simple, fast and ugly.
class ThreeStacks
{

private:
  int *arr;
  int begin_idx[3];
  int top_idx[3];
  int N;

public:
  ThreeStacks(int *ap, int n) : arr(ap), N(n)
  { //ctor
    begin_idx[0] = -1;
    begin_idx[1] = floor(N / 3) - 1;
    begin_idx[2] = (N - 1) - begin_idx[1] - 1;

    top_idx[0] = begin_idx[0];
    top_idx[1] = begin_idx[1];
    top_idx[2] = begin_idx[2];
  }

  void push(int data, int stack_id = 0)
  {
    switch (stack_id)
    {
    case 0:
      if (top_idx[0] <= begin_idx[1])
        arr[++top_idx[0]] = data;
      break;
    case 1:
      if (top_idx[1] <= begin_idx[2])
        arr[++top_idx[1]] = data;
      break;
    case 2:
      if (top_idx[2] <= N)
        arr[++top_idx[2]] = data;
      break;
    }
  }

  void pop(int stack_id = 0)
  {
    switch (stack_id)
    {
    case 0:
      if (top_idx[0] > 0)
        --top_idx[0];
      break;
    case 1:
      if (top_idx[1] >= begin_idx[1])
        --top_idx[1];
      break;
    case 2:
      if (top_idx[2] >= begin_idx[2])
        --top_idx[2];
      break;
    }
  }

  int &top(int stack_id = 0)
  {

    switch (stack_id)
    {
    case 0:
      return arr[top_idx[0]];
      break;
    case 1:
      return arr[top_idx[1]];
      break;
    case 2:
      return arr[top_idx[2]];
      break;
    }
  }
};
