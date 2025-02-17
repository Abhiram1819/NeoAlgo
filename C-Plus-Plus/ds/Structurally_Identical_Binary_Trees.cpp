/*
Introduction 
Given two Binary Trees , Check whether they are structurally identical or not.

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
*/

#include <bits/stdc++.h> 
using namespace std;

//Define Node as structure
struct Node 
{
    int key;
    Node* left;
    Node* right;
};
 
// Function to create a node with 'value' as the data stored in it. 
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to build tree with given input
struct Node* createTree(vector<int>v)
{
    int n=v.size();
    if(n==0) 
      return NULL;
    vector<struct Node* >a(n);
    //Create a vector of individual nodes with given node values
    for(int i=0;i<n;i++)  
    {
        //If the data is -1 , create a null node
        if(v[i]==-1)  
          a[i] = NULL;
        else 
          a[i] = newNode(v[i]);
    }
    //Interlink all created nodes to create a tree
    //Use two pointers using int to store indexes
    //One to keep track of parent node and one for children nodes
    for(int i=0,j=1;j<n;i++) 
    {
        //If the parent node is NULL , advance children pointer twice
        if(!a[i])
        {
          j=j+2;
          continue;
        } 
        //Connect the two children nodes to parent node
        //First left and then right nodes
        a[i]->left = a[j++];
        if(j<n) 
          a[i]->right = a[j++];
    }
    return a[0];
}

//Function to check whether given two binary trees are structurally identical or not
bool IsStructurallyIdentical(struct Node* root1, struct Node* root2)
{
    //If both are null nodes , return true
    if(!root1 && !root2)
      return true;
    
    //else if one of them is a null node , return false
    if(!root1 || !root2)
      return false;

    //else recursively find if their subtrees are structurally identical
    return IsStructurallyIdentical(root1->left,root2->left) && IsStructurallyIdentical(root1->right,root2->right);
}
                
// Driver code
int main()
{
    //Input of 1st Tree
    int n1;
    cout<<"Enter total no.of nodes of the 1st input Tree ( including NULL nodes ) : ";
    cin>>n1;

    vector<int>v1(n1);
    cout<<"Enter value of each node of the 1 st Tree  in level order ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>v1[i]; //store the input values in a vector
    }

    //create the tree using input node values  
    struct Node* root1=createTree(v1); 


    //Input of 2nd Tree
    int n2;
    cout<<"Enter total no.of nodes of the 2nd input Tree ( including NULL nodes ) : ";
    cin>>n2;

    vector<int>v2(n2);
    cout<<"Enter value of each node of the 2nd Tree  in level order ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>v2[i]; //store the input values in a vector
    }

    //create the tree using input node values  
    struct Node* root2=createTree(v2);

    //Call the function and print the result
    if(IsStructurallyIdentical(root1,root2))
      cout<<"Hence the given two trees are structurally identical";
    else
      cout<<"Hence the given two trees are structurally identical";
    
    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
if node is NULL , -1 is entered as it's key

Sample Test Case 1  
Input Binary Tree 1:                    Input Binary Tree 1: 
               1                                       10                          
           /         \                             /         \                   
         2              11                       22            3                  
     /       \        /   \                  /       \        /   \               
    3        NULL      NULL    13           13        NULL   NULL    1                        


Input Format : 
Example :
Enter total no.of nodes of the 1st input Tree ( including NULL nodes ) : 7
Enter value of each node of the 1 st Tree  in level order ( if a node is NULL , enter -1 ) with spaces
1 2 11 3 -1 -1 13
Enter total no.of nodes of the 2nd input Tree ( including NULL nodes ) : 7
Enter value of each node of the 2nd Tree  in level order ( if a node is NULL , enter -1 ) with spaces
10 22 3 13 -1 -1 1

Output Format :
Example : ( Output to the above input example ) 
Hence the given two trees are structurally identical

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the min of no.of nodes of two trees
Space Complexity : O(h) 
   Where h is the min of heights of the two trees
*/
