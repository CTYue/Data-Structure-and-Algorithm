//Implement the following three member functions for the class my_matrix:
//add_node, operator+, operator*
//Do not change the main function and the my_matrix::print function
#include <iostream>
#include <vector>
using namespace std;

class node {
public:
 int value;
 int r_position;
 int c_position;
 node * r_next;
 node * c_next;
 node() { value = -9999; r_position = c_position = -1; r_next = c_next = nullptr; }
 node(int v, int r, int c) { value = v; r_position = r; c_position = c; r_next = c_next = nullptr; }
};
class my_matrix 
{
public:
    int num_rows;
    int num_cols;
    vector<node*> r_vec;
    vector<node*> c_vec;
    my_matrix() {}
    my_matrix(int r, int c);
    //Initialize a matrix of rows and c cols.
    my_matrix(int r, int c, int n, int k);
    //Initializa a matrix of r rows, c cols, n nodes, with values randomly in - (k-1) ... (k-1);
    void print(); //print value, r_position, and c_position of all matrix elements in row-oriented manner
    //Implement the following three member functions:
    void add_node(int v, int r, int c);
    //Create a new node with value v at row r and col c.
    //If there already exists an element at this position, then just update the node
    //value at this position to v, and do not create a new node.
    int at(int r, int c) const;
    my_matrix operator+(my_matrix M); //matrix addition
    my_matrix operator*(my_matrix M); //matrix multiplication
};
my_matrix::my_matrix(int r, int c)
{
    num_rows = r;
    num_cols = c;
    r_vec.resize(r, nullptr);
    c_vec.resize(c, nullptr);
}
my_matrix::my_matrix(int r, int c, int n, int k)
{
    num_rows = r;
    num_cols = c;
    r_vec.resize(r, nullptr);
    c_vec.resize(c, nullptr);
    for (int i = 0; i < n; i++) {
        int vv = rand() % (2 * k - 1) - (k - 1);
        int rr = rand() % r;
        int cc = rand() % c;
        add_node(vv, rr, cc);
    }
}
void my_matrix::add_node(int v, int r, int c)
{
    node* r_p = r_vec[r];
    node* c_p = c_vec[c];
    if (r_p != nullptr) {
        while (r_p->r_next != nullptr && r_p->r_next->c_position < c)
        {
            r_p = r_p->r_next;
        }
    }
    if (c_p != nullptr) {
        while (c_p->c_next != nullptr && c_p->c_next->r_position < r)
        {
            c_p = c_p->c_next;
        }
    }
    if (r_p != nullptr && r_p->r_next != nullptr && r_p->r_next->c_position == c)
     {
        node* p = r_p->r_next;
        if (v == 0) {
            r_p->r_next = p->r_next;
            c_p->c_next = p->c_next;
            delete p;
        } else {
            p->value = v;
        }
        return;
    }
    if (v == 0)
        return;
    node *p = new node(v, r, c);
    if (r_vec[r] == nullptr)
    {
        r_vec[r] = p;
    }
    else if (r_vec[r]->c_position > c)
     {
        p->r_next = r_vec[r];
        r_vec[r] = p;
    }
    else if (r_p->r_next == nullptr)
    {
        r_p->r_next = p;
    }
    else
    {
        p->r_next = r_p->r_next;
        r_p->r_next = p;
    }
    if (c_vec[c] == nullptr)
    {
        c_p = p;
        c_vec[c] = p;
    }
    else if (c_vec[c]->r_position > r)
    {
        p->c_next = c_vec[c];
        c_vec[c] = p;
    }
    else if (c_p->c_next == nullptr)
    {
        c_p->c_next = p;
    }
    else
    {
        p->c_next = c_p->c_next;
        c_p->c_next = p;
    }
}
int my_matrix::at(int r, int c) const
{
    node* r_p = r_vec[r];
    while (r_p != nullptr && r_p->c_position < c)
    {
        r_p = r_p->r_next;
    }
    if (r_p != nullptr && r_p->c_position == c)
        return r_p->value;
    else
        return 0;
}
void my_matrix::print()
{
    cout << endl;
    for (int i = 0; i < num_rows; i++) {
        node* p = r_vec[i];
        cout << endl;
        while (p != nullptr) {
            cout << p->value << " " << p->r_position << " " << p->c_position << "  ";
            p = p->r_next;
        }
    }
}
my_matrix my_matrix::operator+(my_matrix M)
{
    my_matrix result(M.num_rows, M.num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++)
            result.add_node(at(i, j) + M.at(i, j), i, j);
    }
    return result;
}
my_matrix my_matrix::operator*(my_matrix M)
{
  int sum = 0;
  my_matrix result(num_rows, M.num_cols);
  for (int i=0; i<num_rows; i++)
  {
    for (int j=0; j<M.num_cols;j++)
    {
      sum = 0;
      for (int k=0; k<num_cols;k++)
        sum += at(i,k)*M.at(k,j);
      result.add_node(sum,i,j);
    }
  }
  return result;
}
int main()
{
    my_matrix M1(7, 5, 11, 8), M2(7, 5, 10, 8), M3(7, 5), M4(5, 6, 13, 9), M5(7, 6);
    M1.print();
    M2.print();
    M3 = M1 + M2;
    M3.print();
    M1.print();
    M4.print();
    M5 = M1 * M4;
    M5.print();
    getchar();
    getchar();
    return 0;
}
