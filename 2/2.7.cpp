//Intersection : Given two (singly) linked lists, determine if the two lists intersect. Return the inter-
//secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
//node of the first linked list is the exact same node (by reference) as the jth node of the second
//linked list, then they are intersecting.

//The intersection means shared node for bouth of LLs looks like tree:
//       a->b->c->d->e                     
//                   |
//          l->k->f->g->h->u->z          ///the owners of g node are bouth of LLs



struct Node
{
    int value;
    Node* next;
};

//Simplest solution with set container:
//just traverse throught bouth LLs, remind each node and check if we traverse this node before or not.
//O(N1+N2) runtime with O(N) space
Node* AreIntersect(Node* header1, Node* header2){

Node* cur_node1=header1->next;
Node* cur_node2=header2->next;

set<Node*> buff;

while(cur_node1!=nullptr || cur_node2!=nullptr){

buff.emplace(cur_node1);

if(buff.count(cur_node2)) return cur_node2;
else buff.emplace(cur_node2);

if(cur_node1!=nullptr)
cur_node1=cur_node1->next;

if(cur_node2!=nullptr)
cur_node2=cur_node2->next;

}

return nullptr;

}
//Of course we could define the legth of LLs, then skip different nodes - alignment and than iterates consicuetly trought LL's
//until shared node not reached. - this approach with O(1) space, but wit O( 2(N1+N2) ) runtime