#include<iostream>
using namespace std;
template<typename DataType> class ThreadBTNode{
private:
    //friend class ThreadBT;
    ThreadBTNode<DataType> *lChild,*rChild;
    int lFlag,rFlag;
    DataType data;
public:
    ThreadBTNode(DataType data){
        lFlag=rFlag=0;
        this->data=data;
        lChild=rChild=NULL;
    }
    ThreadBTNode(){
        lFlag=rFlag=0;
        lChild=rChild=NULL;
    }
};
/******以中序线索二叉树为例*******/
template<typename DataType> class ThreadBT{
private:
    ThreadBTNode<DataType> *root;
public: 
    ThreadBT(){
        root=NULL;
    }
    ThreadBT(DataType data){
        root=new ThreadBTNode<DataType>(data);
    }
    /****find the pre node****///左子树中最右边的结点
    ThreadBTNode<DataType>* prior(ThreadBTNode<DataType> *node){
        ThreadBTNode<DataType> *s;
        s=node->lChild;
        if(node->lFlag==1){
            while(s->rFlag==1){
                s=s->rChild;
            }
        }
        return s;
    }
    /*****find the after node 后继结点*****///右子树中最左边的结点
    ThreadBTNode<DataType>* succ(ThreadBTNode<DataType> *node){
        ThreadBTNode<DataType> *s;
        s=node->rChild;
        if(node->rFlag==1){
            while(s->lFlag==1){
                s=s->lChild;
            }
        }
        return s;
    }
    /*****inOder****///中序遍历线索二叉树
    void inOrder(){
        if(root!=NULL){
            ThreadBTNode<DataType> *s;
            s=root;
            while(prior(s)!=NULL){
                s=prior(s);
            }
            while(succ(s)!=NULL){
                cout<<s->data<<endl;
                s=succ(s);
            }
        }
    }
};