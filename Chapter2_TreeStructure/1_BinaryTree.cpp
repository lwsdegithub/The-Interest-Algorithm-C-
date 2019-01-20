#include<iostream>
#include "../Chapter1_BaseDataStructure/4_Queue.cpp"//use to BFS
using namespace std;
/*******We use the structure of link to express a node*******/
class BinaryTreeNode{
private:
    int data;
    BinaryTreeNode *lChild;
    BinaryTreeNode *rChild;
public:
    friend class BinaryTree;
    BinaryTreeNode(){
        data=0;
        lChild=NULL;
        rChild=NULL;
    }
    BinaryTreeNode(int m_data){
        data=m_data;
        lChild=rChild=NULL;
    }
    void setData(int m_data){
        data=m_data;
    }
    void setLeftNode(BinaryTreeNode* node){
        lChild=node;
    }
    void setRightNode(BinaryTreeNode* node){
        rChild=node;
    }
    int getData(){
        return data;
    }
    BinaryTreeNode* getLeftNode(){
        return lChild;
    }
    BinaryTreeNode* getRightNode(){
        return rChild;
    }
};
/******the definition of the BinaryTree******/
class BinaryTree{
private:
    BinaryTreeNode *root;
public:
    BinaryTree(){
        root=new BinaryTreeNode();
    }
    BinaryTree(int data){
        root=new BinaryTreeNode(data);
        root->lChild=NULL;
        root->rChild=NULL;
    }
    ~BinaryTree(){
        delete root;
    }
    BinaryTreeNode* getRoot(){
        if(!root)
        return root;
        return NULL;
    }
    /*****The traverse of the BinaryTree******/
    //前序遍历
    void preOrder(BinaryTreeNode *node){
        if(!node){
            cout<<node->getData()<<","<<endl;
            preOrder(node->getLeftNode());
            preOrder(node->getRightNode());
        }
    }
    //中序遍历
    void inOrder(BinaryTreeNode *node){
        if(!node){
            inOrder(node->getLeftNode());
            cout<<node->getData()<<","<<endl;
            inOrder(node->getRightNode());
        }
    }
    //后序遍历
    void postOrder(BinaryTreeNode* node){
        if(!node){
            postOrder(node->getLeftNode());
            postOrder(node->getRightNode());
            cout<<node->getData()<<","<<endl;
        }
    }
    /***a traverse algorithm of BFS(广度优先遍历),And it will use my Queue****/
    void BFS(BinaryTreeNode *node){
        Queue<BinaryTreeNode*> queue=Queue<BinaryTreeNode*>(50);//use the size of 50
        BinaryTreeNode* currentNode;
        if(!node){
            queue.insert(node);
            while(queue.getCount()!=0){
                currentNode=queue.delElement();
                cout<<currentNode->getData()<<endl;
                if(!currentNode->getLeftNode()){//the currentNode has left child node
                    queue.insert(currentNode->getLeftNode());
                }
                if(!currentNode->getRightNode()){
                    queue.insert(currentNode->getRightNode());
                }
            }
        }
    }
    /*********get the parent of a node,we ca use the BFS**********/
    BinaryTreeNode* getParentNode(BinaryTreeNode* node){
        if(node==NULL||node==root) return NULL;
        Queue<BinaryTreeNode*> queue=Queue<BinaryTreeNode*>(50);
        BinaryTreeNode *current,*child;
        queue.insert(node);
        while(queue.getCount()!=0){
            current=queue.delElement();
            if(!current->getLeftNode()){
                child=current->getLeftNode();
                if(child==current->getLeftNode()) return current;
                queue.insert(child);
            }
            if(!current->getRightNode()){
                child=current->getRightNode();
                if(child==current->getRightNode()) return current;
                queue.insert(child);
            }
        }
    }
    /*******get the left brother node or right brother node********/
    BinaryTreeNode* getBrotherNode(BinaryTreeNode* node){
        if (node==NULL) return NULL;
        BinaryTreeNode *parent=getParentNode(node);
        if(parent==NULL) return NULL;
        if(parent->getLeftNode()==node) return parent->getRightNode();
        if(parent->getRightNode()==node) return parent->getLeftNode();
    }
    /******get the max depth of the tree*******/
    int getDepth(int numberOfNodes){
        BinaryTreeNode* nodeStack[numberOfNodes];
        int depthStack[numberOfNodes];
        int currentDepth,maxDepth=0;
        int top=-1;
        BinaryTreeNode* node=root;
        if(node!=NULL){
            currentDepth=1;
            do{
                while(node!=NULL){
                    nodeStack[++top]=node;
                    depthStack[top]=currentDepth;
                    node=node->lChild;
                    currentDepth++;
                }
                node=nodeStack[top];
                currentDepth=depthStack[top--];
                if(node->lChild==NULL && node->rChild==NULL){
                    if (currentDepth>maxDepth) maxDepth=currentDepth;
                }
                node=node->rChild;
                currentDepth++;
            }while(!(node==NULL && top==-1));
        }
        return maxDepth;
    }
    /***删除节点的左右子树****/
    //删除所有结点,delete all the node 
    void deleteNodes(BinaryTreeNode *node){
        if(node!=NULL){
            deleteNodes(node->lChild);
            deleteNodes(node->rChild);
            delete node;
        }
    }
    //delete the sub tree,i is the choice,i=1 means delete the left sub tree,i=2 means delete the right sub tree,i=3.means all;
    bool deleteSubTree(BinaryTreeNode *node,int i){
        if(node==NULL) return false;
        BinaryTreeNode *p=NULL;
        switch(i){
            case 1:
                p=node->lChild;
                deleteNodes(p);
                node->lChild=NULL;
                return true;
            case 2: 
                p=node->rChild;
                deleteNodes(p);
                node->rChild=NULL;
                return true;
            case 3:
                p=node->lChild;
                deleteNodes(p);
                node->lChild=NULL;
                p=node->rChild;
                deleteNodes(p);
                node->rChild=NULL;
                return true;
        }
        return false;   
    }
    /*****destroy a BinaryTree*****/
    void destroyBT(BinaryTreeNode *node){
        if(node!=NULL){
            destroyBT(node->lChild);
            destroyBT(node->rChild);
            delete node;
        }
        root=NULL;
    }
    //判断两颗树是否是相等的
    bool compareTree(BinaryTreeNode *tree1,BinaryTreeNode*tree2){
        if((tree1==NULL)!=(tree2==NULL)){
            return false;
        }
        if((tree1==NULL)&&(tree2==NULL)) return true;
        if(tree1->data!=tree2->data) return false;
        return ((compareTree(tree1->lChild,tree2->lChild)&&compareTree(tree1->rChild,tree2->rChild))||
                    (compareTree(tree1->lChild,tree2->rChild)&&compareTree(tree1->rChild,tree2->lChild)));
    }
};

int main(){
    BinaryTree *tree=new BinaryTree(6);
    tree->preOrder(tree->getRoot());
}
