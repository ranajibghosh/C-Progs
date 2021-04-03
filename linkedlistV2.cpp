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
        cout<<"-----------------------------------------------------------------------------No elements in the list-----------------------------------------------------------"<<endl;
        }else{
        		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Elements in list are :"<<endl;
            for(p=head;p!=NULL;p=p->next){
                 cout<<"[<"<<p->x<<">/"<<&(*p)<<"("<<&(*(p->next))<<")]";
            }
            cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        }
}


////-----------------------------Double link list---------------------------------------------------------------
struct dnode{
         int x;
         struct dnode *next;
         struct dnode *prev;
    };
    struct dnode *dhead=NULL;
isEmptyDouble(){
    if(dhead==NULL)
        return 1;
    return 0;
}
struct dnode * createNodeDouble(){
        return (new dnode);
}
void insertEndDouble(int val){
    struct dnode * p;
    struct dnode *temp = createNodeDouble();
    temp->x=val;
    temp->next = NULL;
    temp->prev = NULL;
    if(isEmptyDouble()){
       dhead=temp;
       }else{
    		for(p=dhead;p->next!=NULL;p=p->next);
    			p->next=temp;
            temp->prev = p;
         }
}
void insertFrontDouble(int val){
    struct dnode *temp = createNodeDouble();
    temp->x=val;
    temp->next = dhead;
    temp->prev = NULL;
    if(dhead!=NULL){
       dhead->prev = temp;
    }
    dhead=temp;
}
void insertAfterBeforeDouble(int afterBeforeWhich,char afterOrBefore  , int newVal){
    struct dnode *p;
    struct dnode *temp = createNodeDouble();
    temp->x=newVal;
    for(p=dhead;p!=NULL&&p->x!=afterBeforeWhich ;p=p->next);
    if(p==NULL)
        cout<<"The value is not in the list"<<endl;
    else{
    		if(afterOrBefore=='B'){
         	if(p==dhead){
               temp->next = p;
               temp->prev = NULL;
               dhead->prev = temp;
    				dhead=temp;
            }else{
            temp->next = p;
            temp->prev = p->prev->next;
            p->prev->next=temp;
            p->prev = temp;

           }
         } else{
        		 temp->next = p->next;
             temp->prev = p;
             if(p->next!=NULL)
                p->next->prev = temp;
       		 p->next=temp;
        }
    }
}

int delFrontDouble(){
int delVal;
struct dnode * p;
 if(isEmptyDouble()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
      p=dhead;
      delVal = p->x;
      dhead=p->next;
      if(p->next!=NULL)
      	p->next->prev = NULL;
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
 }
 return  delVal;
}

int delBackDouble(){
int delVal=0;
struct dnode *p;
 if(isEmptyDouble()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
 		for(p=dhead;p!=NULL&&p->next!=NULL ;p=p->next);
      delVal = p->x;
      if(p==dhead) {
       dhead=NULL;
      }else{
      p->prev->next = p->next;
      }
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
 }
 return  delVal;
}

int delMiddleDouble(int val){
int delVal;
struct dnode *p;
 if(isEmptyDouble()){
      cout<<" No elements in the list to delete "<<endl;
 }else{
 		for(p=dhead;p!=NULL&&p->x!=val ;p=p->next);
      if(p==NULL){
        cout<<" Element not found in the list "<<endl;
      }else{
      delVal = p->x;
      if(p==dhead) {
       dhead=p->next;
      if(p->next!=NULL)
      	p->next->prev = NULL;
      }else{
      if(p->next!=NULL){
      	p->next->prev = p->prev;
      }
      p->prev->next = p->next;
      }
      cout<<delVal<<" is deleted from the list."<<endl;
      delete p;
     }
 }
 return  delVal;
}


void displayDouble(){
    struct dnode * p;
     if(isEmptyDouble()){
        cout<<"-----No elements in the list-----"<<endl;
        }else{
        		cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Elements in list are :"<<endl;
            for(p=dhead;p!=NULL;p=p->next){
                  cout<<"["<<"("<<&(*(p->prev))<<")<"<<p->x<<">/"<<&(*p)<<"("<<&(*(p->next))<<")]"<<endl;
            }
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        }
}



////-------------------------------------------------------------------------------------------------------------
int main() {
    int option;
    do{
    cout<<"------------------------------ Linked List Programme-------------------------------------------"<<endl;
    cout<<"Which kind of Linked List Do you want ? "<<endl;
    cout<<"Single Linked List: [1] | Double Linked List: [2] | Quit: [0] || Enter your option : ";
    cin>>option;
    switch(option){
    // outer switch
    case 1:
          int choiceSingleList;
      do{
          cout<<"-----------------------------------------------------------------------Single Linked List-------------------------------------------------------------------------"<<endl;
          cout<<"Add at END: [1] |  at FRONT: [2] | at MIDDLE: [3] || Delete from FRONT: [4] |  from END: [5] | Desire Element: [6] || DISPLAY: [7] || Quit: [0] || Enter your option : ";
          cin>>choiceSingleList;
          switch(choiceSingleList){
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
                  cout<<"Add after "<<afterBefore<<": [1] | Before "<<afterBefore<<": [2] ||  Enter your choice :";
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

        }while(choiceSingleList);

      break;
    case 2:
        int choiceDoubleList;
      do{
          cout<<"------------------------------------------------------------------Double Linked List-------------------------------------------------------------------------------"<<endl;
          cout<<"Add at END: [1] |  at FRONT: [2] | at MIDDLE: [3] || Delete from FRONT: [4] |  from END: [5] | Desire Element: [6] || DISPLAY: [7] || Quit: [0] || Enter your option : ";
          cin>>choiceDoubleList;
          switch(choiceDoubleList){
          	int doubleval, afterBeforeDouble, afterBeforeDoubleChoice;
           case 1:
           			cout<<"Enter the value to add at the end of the list : ";
           			cin>>doubleval;
                  insertEndDouble(doubleval);
                  displayDouble();
            break;
            case 2:
           			cout<<"Enter the value to add at the front of the list : ";
           			cin>>doubleval;
                  insertFrontDouble(doubleval);
                  displayDouble();
            break;
            case 3:
           			cout<<"Enter the value to add at the middle of the list : ";
           			cin>>doubleval;
                  cout<<"Enter after/before which you want to add :";
                  cin>>afterBeforeDouble;
                  cout<<"Add after "<<afterBeforeDouble<<": [1] | Before "<<afterBeforeDouble<<": [2] ||  Enter your choice :";
                  cin>>afterBeforeDoubleChoice;
                  switch(afterBeforeDoubleChoice){
                  	case 1:
                            insertAfterBeforeDouble(afterBeforeDouble, 'A',doubleval);
                            break;
                     case 2:
                            insertAfterBeforeDouble(afterBeforeDouble, 'B' ,doubleval);
                            break;
                     default: cout<<"No such options."<<endl;break;

                  }
                  displayDouble();
            break;
            case 4:
           			delFrontDouble();
                  displayDouble();
            break;
            case 5:
           			delBackDouble();
                  displayDouble();
            break;
            case 6:
            		int delvalDouble;
            		cout<<"Enter the value which you want to delete from the existing list :";
                  cin>>delvalDouble;
           			delMiddleDouble(delvalDouble);
                  displayDouble();
            break;
            case 7:

                  displayDouble();
            break;


          case 0:  cout<<"------------------------------------- "<<endl;break;
          default: cout<<"No such options."<<endl;break;
          }

        }while(choiceDoubleList);


       break;
    case 0:  cout<<"------------------------------------- "<<endl;break;
    default: cout<<"No such options. "<<endl;break;
    }

}while(option);

	return 0;
}

