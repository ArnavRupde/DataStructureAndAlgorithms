// link : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma
// struct Node{
// 	int data;
// 	struct Node * next;
// 	struct Node * bottom;
//
// 	Node(int x){
// 	    data = x;
// 	    next = NULL;
// 	    bottom = NULL;
// 	}
//
// };
Node* mergeTwoLists(Node* a, Node* b) {

    Node *temp = new Node(0);
    Node *res = temp;

    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if(a) temp->bottom = a;
    else temp->bottom = b;

    return res -> bottom;

}
Node *flatten(Node *root)
{

        if (root == NULL || root->next == NULL)
            return root;

        // recur for list on right
        root->next = flatten(root->next);

        // now merge
        root = mergeTwoLists(root, root->next);

        // return the root
        // it will be in turn merged with its left
        return root;
}
