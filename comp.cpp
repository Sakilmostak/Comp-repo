#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int data){
        this->data= data;
        left=NULL;
        right=NULL;
    }
};

void preOrder(Tree* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void MorrisTraversal(Tree* root){
    Tree* cur= root;
     while(cur!=NULL){
        if(cur->left==NULL){
            cout<<cur->data<<" ";
            cur=cur->right;
        }
        else{
            Tree* rightMost= cur->left;
            while(rightMost->right && rightMost->right!=cur){
                rightMost=rightMost->right;
            }

            if(rightMost->right==NULL){
                rightMost->right=cur;
                cout<<cur->data<<" ";
                cur=cur->left;
            }
            if(rightMost->right==cur){
                rightMost->right=NULL;
                cur=cur->right;
            }
        }

        
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    //         1
    //        / \
    //       2   3
    //     / \  / \
    //    4  5 6  7

    Tree* root = new Tree(1);
    root->left= new Tree(2);
    root->right= new Tree(3);
    root->left->left= new Tree(4);
    root->left->right= new Tree(5);
    root->right->left= new Tree(6);
    root->right->right= new Tree(7);

    MorrisTraversal(root);

    return 0;
}