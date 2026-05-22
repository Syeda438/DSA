#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data =value;
        left=right=NULL;
    }
};
class BST{
    private:
    Node* root;
    public:
    BST(){
        root=NULL;
    }
    BST(int value){
        root=new Node(value);
        root->left=NULL;
        root->right=NULL;
    }
    void insert(int value){
        root = insert(root, value);
        }
    Node* insert(Node* root, int value){
        if(root==NULL){
            return new Node(value);
        }
        else{
            if(value<root->data){
                root->left=insert(root->left, value);
            }
            if(value>root->data){
                root->right=insert(root->right, value);
            }
        }
        return root;
    }
    Node* min(Node* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    void del(int value){
        root = del(root, value);
        }
    Node* del(Node* root, int key){
        if(root==NULL){
            return NULL;
        }
        if(key<root->data){
            root->left=del(root->left,key);
        }
        else if(key>root->data){
            root->right=del(root->right,key);
        }
        else if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp= min(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
        return root;
    }
    bool search(Node* root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data==key){
            return true;
        }
        if(key<root->data){
            return search(root->left, key);
        }
        if(key>root->data){
            return search(root->right, key);
        }
        return false;
    }
    void searching(int key){
        if(search(root,key)){
            cout<<key<<" found successfully\n";
        }else{
            cout<<key<<" not found in the tree\n";
        }
    }
    void display(){
        if(root==NULL){
            return;
        }
        else{
            cout<<"In order Traversal: ";
            inorder(root);
            cout<<endl;
            cout<<"Pre order Traversal: ";
            preorder(root);
            cout<<endl;
            cout<<"Post order Traversal: ";
            postorder(root);
            cout<<endl;
        }
    }
    void inorder(Node* root){
        if(root==NULL){
            return;
        }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
    }
    void preorder(Node* root){
        if(root==NULL){
            return;
        }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
    }
    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    
};
int main(){
    BST tree(40);
    tree.insert(20);
    tree.insert(50);
    tree.insert(30);
    tree.insert(45);
    tree.display();
    tree.insert(25);
    tree.insert(35);
    tree.insert(15);
    tree.insert(60);
    tree.display();
    tree.del(45);
    tree.display();
    tree.searching(20);
    tree.del(30);
    tree.display();
    tree.del(15);
    tree.display();
    tree.searching(35);
    return 0;
}