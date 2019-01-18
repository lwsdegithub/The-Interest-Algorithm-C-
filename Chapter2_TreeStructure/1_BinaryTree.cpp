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
    //ǰ�����
    void preOrder(BinaryTreeNode *node){
        if(!node){
            cout<<node->getData()<<","<<endl;
            preOrder(node->getLeftNode());
            preOrder(node->getRightNode());
        }
    }
    //�������
    void inOrder(BinaryTreeNode *node){
        if(!node){
            inOrder(node->getLeftNode());
            cout<<node->getData()<<","<<endl;
            inOrder(node->getRightNode());
        }
    }
    //�������
    void postOrder(BinaryTreeNode* node){
        if(!node){
            postOrder(node->getLeftNode());
            postOrder(node->getRightNode());
            cout<<node->getData()<<","<<endl;
        }
    }
    /***a traverse algorithm of BFS(������ȱ���),And it will use my Queue****/
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
};
int main(){
    BinaryTree *tree=new BinaryTree(6);
    tree->preOrder(tree->getRoot());
}
