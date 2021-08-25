#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
	Node(int val){
		data=val;
		right=NULL;
		left=NULL;
	}
};

int maxSumofMaxPath(Node* root, int* height, int *ans, int *prevtotal){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		*height=1;
		*ans= root->data;
		return root->data;
	}

	int lh=0,rh=0,ansleft=0,ansright=0,dialeft=0,diaright=0;

	int left= maxSumofMaxPath(root->left, &lh, &ansleft, &dialeft);
	int right= maxSumofMaxPath(root->right, &rh, &ansright, &diaright);

	*prevtotal= lh+rh+1;
	*height= max(lh,rh)+1;

	if(lh==rh){
		*ans= max(ansleft+root->data, ansright+root->data);
	}
	else if(lh>rh){
		*ans= root->data+ansleft;
	}
	else if(rh>lh){
		*ans= root->data+ansright;
	}

	if(dialeft>diaright){
		if(dialeft>*prevtotal){
			return left;
		}
	}
	else if(diaright>dialeft){
		if(diaright>*prevtotal){
			return right;
		}
	}

	return root->data+ansleft+ansright;
}

int main(){
	Node* root= new Node(10);
	root->left= new Node(2);
	root->right= new Node(6);
	root->left->left= new Node(100);
	root->left->right= new Node(-4);
	root->right->left= new Node(7);
	root->right->right= new Node(5);
	root->left->right->left= new Node(7);

	int check=0,height=0,prevtotal=0;

	int ans= maxSumofMaxPath(root, &height, &check, &prevtotal);

	cout<<ans<<endl;
}