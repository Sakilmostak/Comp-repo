#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

/*Disjoint Set Union Method is better than Union Find algo in Kruskal's Algorithm.
  With the help of tree, Union Rank and Path Compression the complexity is reduced from O(E*V) 
  to O(E*log(V)) for Kruskals
*/

//Tree structure for DSN
class DSNode{
	public:
	int data;
	DSNode* parent;
	int rank;
};

class DisjointSet{
	private:
	map<int,DSNode*> hash;

	DSNode* searchInSetHelper(DSNode* node){
		if(node == node->parent){
			return node;
		}

		// Path Compression
		node->parent = searchInSetHelper(node->parent);
		return node->parent;
	}

	public:

	void initializeSet(int data){
		DSNode* node = new DSNode();
		node->data= data;
		node->parent= node;
		node->rank= 0;
		hash[data]= node;
	}

	void Union(int data1,int data2){
		DSNode* node1= hash[data1];
		DSNode* node2= hash[data2];

		DSNode* parent1= searchInSetHelper(node1);
		DSNode* parent2= searchInSetHelper(node2);

		//Union Ranking
		if(parent1->data==parent2->data){
			return;
		}

		if(parent1->rank>=parent2->rank){

			if(parent1->rank==parent2->rank){
				parent1->rank= parent2->rank+1;
			}
			
			parent2->parent=parent1;
		}
		else{
			parent1->parent=parent2;
		}
	}

	int searchInSet(int data){
		return searchInSetHelper(hash[data])->data;
	}
};

int main(){
	DisjointSet ds;
	ds.initializeSet(0);
	ds.initializeSet(1);
	ds.initializeSet(2);
	ds.initializeSet(3);
	ds.initializeSet(4);
	ds.initializeSet(5);
	ds.initializeSet(6);

	ds.Union(0,1);
	ds.Union(1,2);
	ds.Union(3,4);
	ds.Union(2,4);
	ds.Union(5,6);
	ds.Union(4,6);

	cout<<ds.searchInSet(0)<<endl;
	cout<<ds.searchInSet(1)<<endl;
	cout<<ds.searchInSet(2)<<endl;
	cout<<ds.searchInSet(3)<<endl;
	cout<<ds.searchInSet(4)<<endl;
	cout<<ds.searchInSet(5)<<endl;
	cout<<ds.searchInSet(6)<<endl;
}