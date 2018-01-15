//HW5  AVL Tree
//Due: Saturday (Nov. 18) at 11:59PM
#include <iostream> //to use cout
#include <algorithm> //to use max function such as  i = max(a, b);
using namespace std;

//You need to use the following node class for each node of the AVL tree
class node {
public:
    int value;
    int height;
    int child;//0: this node is a left child of its parent; 1: right child; -1 this node is the tree root
    node* parent;
    node* l_child;
    node* r_child;
    node() {}
    node(int i) { value = i; height = 1; parent = l_child = r_child = nullptr; }
};

class avl_tree {
public:
    node * root;
    avl_tree() {
        root = nullptr;
    }

    void add_node(int i)//You need to implement this.
    {
        node *next = nullptr;
        node *last = nullptr;

        //Initialize root
        node *temp = new node();
        temp->value = 0;
        temp->height = 1;
        root = temp;

        next = root;//next will be different according to value
        int count = 0;
        next->value = 0;
        next->height = 1;
        //Traversing to the end and updating
        while( next != nullptr )
        {
            count ++;
            if( i == next->value )
            {
            		next = next->l_child;
            }

            if( i < next->value )
            {
                next = next->l_child;
                next->height += 1;
            }

            else if( i > next->value )
            {
                next = next->r_child;
                next->height += 1;
            }
            last = next;
        }

        cout << last << next << root << endl;
        cout << last->value << last->height << endl;

        if( i < last->value )
        {
            last->l_child->value = i;
        }

        if( i > last->value )
        {
            last->r_child->value = i;
        }

        //Check if balanced

        int balance = 0;
        // Left Left Case
        if (balance > 1 && i < last->l_child->value)

        // Right Right Case
        if (balance < -1 && i > last->r_child->value)

        // Left Right Case
        if (balance > 1 && i > last->l_child->value)
        {
        		;
        }

        // Right Left Case
        if (balance < -1 && i < last->r_child->value)
        {
        		;
        }


    }

    void in_order_traversal(node *p);//provided.

    node * height_adjustment(node *p, int &pattern)//Returning Null means not im-balanced
    //Invoke this function one more time after rotations are done
    {
        //Invoke L_Rotate and R_Rotate
        return nullptr;

    }
    //Pattern is a local variable used inside add_node or remove_node for invoking height_adjustment.

    void L_Rotate(node *p)//You need to implement this.
    {
    		node *right = p;
    		while( right != nullptr )
    		{
    	        right = p->r_child;//P is the root
    	        node *left = right->l_child;

    	        //Perform rotation
    	        right->l_child = p;
    	        p->r_child = left;

    	        //Update heights
    	        p->height = max(p->l_child->height , p->r_child->height) - 1;
    	        right->height = max( right->l_child->height, right->r_child->height) - 1;
    		}
    }

    void R_Rotate(node *p)//You need to implement this.
    {
    		node *left = p;
    		while( left != nullptr )
    		{
    	        //node *left = p->l_child;//p is the root
    			left = p->l_child;//p is the root
    	        node *right = left->r_child;//

    	        //Perform Rotation
    	        left->r_child = p;
    	        p->l_child = right;

    	        //Update heights
    	        p->height = max( p->l_child->height,p->r_child->height ) - 1;
    	        left->height = max( left->l_child->height, left->r_child->height ) - 1;
    		}
    }

    void remove_node(int i)//Invoke node* replace
    {
    		;
    }

    node * replace(node * p1)
    {
        return nullptr;
    }

};


void avl_tree::in_order_traversal(node * p) {
    if (p == nullptr)  return;
    in_order_traversal(p->l_child);
    cout << "value = " << p->value << " " << "height = " << p->height << "   ";
    in_order_traversal(p->r_child);
}

int main(){
	avl_tree t1;
	t1.add_node(45);
	t1.in_order_traversal(t1.root);
	t1.remove_node(45);
	t1.in_order_traversal(t1.root);
	t1.add_node(50);
	t1.add_node(47);
	t1.add_node(30);
	t1.add_node(35);
	t1.in_order_traversal(t1.root);
	t1.remove_node(47);
	t1.in_order_traversal(t1.root);
	getchar();
	getchar();
	return 0;
}
