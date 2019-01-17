#include <iostream>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode *next;
    public:
        ListNode(){
            data=0;//the init data
            next=NULL;
        }
        ListNode(int item,ListNode *node=NULL){
            data=item;
            next=node;
        }
        ~ListNode(){
            next=NULL;
        }
        int getData(){
            return data;
        }
        ListNode* getNext(){
            return next;
        }
};
class LinkList{
    private:
        ListNode *head;//the head node
        int length;
    public:
        LinkList(){
            head=new ListNode();
            length=1;
        }
        LinkList(ListNode *node){
            head=node;
            length=1;
        }
        ~LinkList(){
            delete head;

        }
        //insertNode,
        //params:location:the location you want to insert 
        //       newData:the data
        bool insertNode(int location,int newData){
            ListNode *p=head;//p is just a cursor
            int j;
            for(j=1;j<=location-1;j++){
                p=p->next;
                if(p==NULL) break;
            }
            if(p==NULL && j<location-1){
                cout<<"false";
                return false;
            }
            ListNode *node=new ListNode(newData);
            node->next=p->next;
            p->next=node;
            length++;
            return true;
        }
        bool append(int data){
            ListNode *p=head;//cursor
            ListNode *node=new ListNode(data);
            if(node==NULL){
                return false;
            }
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=node;
            length++;
            return true;
        }
        bool removeNode(int location){
            if(location<0||location>=length){
                cout<<"the location is not illegal";
                return false;
            }
            ListNode *p=head;
            for (int i=0;i<location-1;i++){
                p=p->next;
            }
            ListNode *q=p->next;
            p->next=p->next->next;
            length--;
            delete q;
        }
        int findLocation(int value){
            ListNode *p=head;
            int i=0;
            int flag=0;
            while(p!=NULL){
                if (p->data==value){
                    flag=1;
                    break;
                } 
                i++;
                p=p->next;
            }
            if(flag==0) return -1;
            return i;
        }
        bool clearLink(){
            ListNode *p=head;
            while(head->next!=NULL){
                p=head->next;
                head->next=p->next;
                delete p;
            }
            length=1;
            return true;
        }
        int getNodeData(ListNode *node);
        int getLength(){
            return length;
        }
        void showList(){
            ListNode *p=head;
            while(p!=NULL){
                cout<<p->data<<",";
                p=p->next;
            }
            cout<<endl;
            delete p;
        }
};
int main(int argc, char const *argv[])
{
    //the head;
    ListNode *node=new ListNode(1);
    LinkList *list=new LinkList(node);
    list->append(3);
    list->append(4);
    list->showList();
    list->insertNode(0,5);
    list->showList();
    list->removeNode(3);
    list->showList();
    cout<<list->findLocation(3)<<endl;
    cout<<list->getLength()<<endl;
    list->clearLink();
    list->showList();
    return 0;
}
