#include <iostream>

//using namespace std;
struct node{
         int x;
         struct node *next;
    };
    struct node *head=NULL;
isEmpty(){
    if(head==NULL)
        return 1;
    return 0;
}
struct node * createNode(){
        return (new node);
    }
void insertEnd(int val){
    struct node * p;
    struct node *temp = createNode();
    temp->x=val;
    temp->next = NULL;
    if(isEmpty())
       head=temp;
       else{
    		for(p=head;p->next!=NULL;p=p->next);
    		p->next=temp;
         }
}
void insertFront(int val){
    struct node *temp = createNode();
    temp->x=val;
    temp->next = head;
    head=temp;

}
void insertAfterBefore(int afterBeforeWhich,char afterOrBefore  , int newVal){
    struct node * p, *q;
    struct node *temp = createNode();
    temp->x=newVal;
    for(p=head;p!=NULL&&p->x!=afterBeforeWhich ;p=p->next);
    if(p==NULL)
        cout<<"The value is not in the list"<<endl;
    else{
    		if(afterOrBefore=='B'){
         	if(p==head){
               temp->next = p;
    				head=temp;
            }else{
           for(q=head;q!=NULL&&q->next!=p ;q=q->next);
            temp->next = q->next;
            q->next=temp;
           }
         } else{
        		 temp->next = p->next;
       		 p->next=temp;
        }
    }
}


int delFront(){
int delVal;
struct node * p;
 if(isEmpty()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
      p=head;
      delVal = p->x;
      head=p->next;
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
 }
 return  delVal;
}

int delBack(){
int delVal=0;
struct node *p,*q;
 if(isEmpty()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
 		for(p=head;p!=NULL&&p->next!=NULL ;p=p->next);
      for(q=head;q!=p&&q->next!=p ;q=q->next);
      if(p==q) {
       head=NULL;
      }
      delVal = p->x;
      q->next=p->next;
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
 }
 return  delVal;
}

int delMiddle(int val){
int delVal;
struct node *p,*q;
 if(isEmpty()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
 		for(p=head;p!=NULL&&p->x!=val ;p=p->next);
      if(p==NULL){
        cout<<" Element not found in the list "<<endl;
      }else{
      for(q=head;q!=p&&q->next!=p ;q=q->next);
      if(p==q) {
       head=NULL;
      }
      delVal = p->x;
      q->next=p->next;
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
     }
 }
 return  delVal;
}


void display(){
    struct node * p;
     if(isEmpty()){
        cout<<"-----No elements in the list-----"<<endl;
        }else{
        		cout<<"--------------------------------"<<endl;
            cout<<"Elements in list are :"<<endl;
            for(p=head;p!=NULL;p=p->next){
                 cout<<p->x<<endl;
            }
            cout<<"--------------------------------"<<endl;
        }
}
int main() {
    int option;
    do{
    cout<<"------ Linked List Programme--------------"<<endl;
    cout<<"Which kind of Linked List Do you want ? "<<endl;
    cout<<"Enter 1 for Single Linked List "<<endl;
    cout<<"Enter 2 for Double Linked List "<<endl;
    cout<<"Enter 0 to quit "<<endl;
    cout<<"Enter your option : ";
    cin>>option;
    switch(option){

    case 1:
          int choice;
      do{

          cout<<"--------Single Linked List----------"<<endl;
          cout<<"Enter 1 to add at end "<<endl;
          cout<<"Enter 2 to add at front "<<endl;
          cout<<"Enter 3 to add at middle "<<endl;
          cout<<"Enter 4 to delete from front "<<endl;
          cout<<"Enter 5 to delete from end "<<endl;
          cout<<"Enter 6 to delete desire one "<<endl;
          cout<<"Enter 7 to Display the list "<<endl;
          cout<<"Enter 0 to quit "<<endl;
          cout<<"Enter your choice : ";
          cin>>choice;

          switch(choice){
          	int val, afterBefore,afterBeforeChoice;
           case 1:
           			cout<<"Enter the value to add at the end of the list : ";
           			cin>>val;
                  insertEnd(val);
                  display();
            break;
            case 2:
           			cout<<"Enter the value to add at the front of the list : ";
           			cin>>val;
                  insertFront(val);
                  display();
            break;
            case 3:
           			cout<<"Enter the value to add at the middle of the list : ";
           			cin>>val;
                  cout<<"Enter after/before which you want to add :";
                  cin>>afterBefore;
                  cout<<"Enter 1 to add after "<<afterBefore<<endl;
                  cout<<"Enter 2 to add before "<<afterBefore<<endl;
                  cout<<"Enter your choice : ";
                  cin>>afterBeforeChoice;
                  switch(afterBeforeChoice){
                  	case 1:
                            insertAfterBefore(afterBefore, 'A'  , val);
                            break;
                     case 2:
                            insertAfterBefore(afterBefore, 'B'  , val);
                            break;
                     default: cout<<"No such options."<<endl;break;

                  }
                  display();
            break;
            case 4:
           			delFront();
                  display();
            break;
            case 5:
           			delBack();
                  display();
            break;
            case 6:
            		int delval;
            		cout<<"Enter the value which you want to delete from the existing list :";
                  cin>>delval;
           			delMiddle(delval);
                  display();
            break;
            case 7:
           		
                  display();
            break;
            

          case 0:  cout<<"------------------------------------- "<<endl;break;
          default: cout<<"No such options."<<endl;break;
          }

        }while(choice);

      break;
    case 2:
       cout<<"--------Double Linked List----------"<<endl;

       break;
    case 0:  cout<<"------------------------------------- "<<endl;break;
    default: cout<<"No such options. "<<endl;break;
    }

}while(option);

	return 0;
}

