#include <iostream>

#include <cstdlib>//system("cls");
#include <time.h>

using namespace std;

struct element{
int number;
element* next;
};

struct single_list{
    element* head;
    element* tail;
    int counter;
};
///////////////Adding///////////////////////////
void add_tail(single_list &l,int value){
    element* el=new element;
    el->number=value;
    el->next=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;//counter increase
}


void add_head(single_list& l, int value){
    element* el= new element;
    el->number=value;
    el->next=l.head;
    l.head=el;
    if(l.tail==nullptr){
        l.tail=el;
    }
    l.counter++;//counter increase
}

void add_position(single_list& l,int value, int position){
    element* el=new element;
    el->number=value;
    element* tmp=l.head;
    int i=1;
    while(i<position-1){
            tmp=tmp->next;
            i++;
    }
    el->next=tmp->next;
    tmp->next=el;
    l.counter++;//counter increase
}

/////////////Delete///////////////////////////
void delete_tail(single_list& l){
    element* tmp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        element* bef_tmp=l.head;
        int i=1;
        while(i<l.counter-1){
            bef_tmp=bef_tmp->next;
            i+=1;
        }
        l.tail=bef_tmp;
        l.tail->next=nullptr;
    }
    delete tmp;
    l.counter--;//counter decrease
}

void delete_head(single_list& l){
    element* tmp=l.head;
    l.head=l.head->next;
    if(l.counter==1){
        l.tail=nullptr;
    }
    delete tmp;
    l.counter--;//counter decrease
}

void delete_position(single_list& l, int position){
    element* prev=l.head;
    int i=1;
    while(i<position-1){
        prev=prev->next;
        i+=1;
    }
    element* tmp=prev->next;
    prev->next=tmp->next;
    delete tmp;
    l.counter--;//counter decrease
}

////////////Display///////////////////////
void show(single_list l){
    int i=1;
    element* tmp=l.head;
    while(i<=l.counter){
        tmp->number;
        tmp=tmp->next;
        i+=1;
    }
}

void first(single_list l){
    cout<<l.head->number;
}
void last(single_list l){
    cout<<l.tail->number;
}
///////////Is empty//////////////////////
bool isEmpty(single_list l){
    if(l.head==nullptr){
        return true;
    }
    else{
        return false;
    }
}
////////////////////////////////
float listAvg(single_list l){
    int i=1;
    int sum=0;
    element* tmp=l.head;
    while(i<=l.counter){
        sum+=tmp->number;
        tmp=tmp->next;
        i++;
    }
    return (float)sum/l.counter;
}

void listMax(single_list l){
    int i=1;
    int maxIndex=1;
    element* tmp=l.head;
    int max=tmp->number;
    while(i<=l.counter){
        if(max<tmp->number){
                max=tmp->number;
                maxIndex=i;
        }
        tmp=tmp->next;
        i++;
    }
    cout<<"MAximal element: "<<max<<" is on position:"<<maxIndex<<endl;
}

void listShow(single_list l){
    int i=1;
    element* tmp=l.head;
    while(i<=l.counter){
        cout<<tmp->number<<endl;
        tmp=tmp->next;
        i++;
    }
}
////////////////Menu///////////////////////
void line(){
cout<<"--------------------------------------------------\n";
}

void menu(int& choice){
line();
cout<<"Menu:"<<endl;
cout<<"1.check if list is empty."<<endl;
cout<<"2.add element to the end of the list."<<endl;
cout<<"3.add element to the start of the list."<<endl;
cout<<"4.add element at the specified position."<<endl;
cout<<"5.drop element from the end of the list."<<endl;
cout<<"6.drop element from start of the list."<<endl;
cout<<"7.drop element from specified position."<<endl;
cout<<"8.display first element from the list"<<endl;
cout<<"9.display last element from the list"<<endl;
cout<<"10.display last element from the list"<<endl;
cout<<"11.calculate average from elements in the list"<<endl;
cout<<"12.search maximal element in the list (display position)"<<endl;
cout<<"13.display all list"<<endl;
cout<<"14.drop all list and memory release"<<endl;
cout<<"15.program exit"<<endl;
line();
cout<<"Choose:";
cin>>choice;
system("cls");
}
//////////////////////MAIN//////////////////////////
int main()
{
    srand (time(NULL));//random number generation

    single_list l;
    l.head=nullptr;
    l.tail=nullptr;
    l.counter=0;

    int index;

    int a;
    menu(a);
    while(a>0 && a<15){
        switch(a){
    case 1:
        cout<<"Is empty:"<<endl;
        if(isEmpty(l)){
            cout<<"Yes"<<endl;
        }
        menu(a);
        break;
    case 2:
        add_tail(l,rand()%50+1);
        menu(a);
        break;
    case 3:
        add_head(l,rand()%50+1);
        menu(a);
        break;
    case 4:
        //add element at the specified position
        cout<<"Input position in which you want add number:";
        cin>>index;
        if(index<=1){
            cout<<"index too small - adding element at the start"<<endl;
            add_head(l,rand()%50+1);
        }
        else if(index>1 && index<l.counter){
            add_position(l,rand()%50+1,index);
            cout<<"Added element at the position:"<<index<<endl;
        }
        else{
            cout<<"index too big - adding element to the end"<<endl;
            add_tail(l,rand()%50+1);
        }
        menu(a);
        break;
    case 5:
        if(!isEmpty(l)){
        delete_tail(l);
        }
        menu(a);
        break;
    case 6:
        if(!isEmpty(l)){
            delete_head(l);
        }
        menu(a);
        break;
    case 7:
        if(!isEmpty(l)){
        cout<<"Input position you want to delete:";
        cin>>index;
        if(index<=1){
            cout<<"index too small - deleting element at the start"<<endl;
            delete_head(l);
        }
        else if(index>1 && index<l.counter){
            delete_position(l,index);
            cout<<"Dropped element at position:"<<index<<endl;
        }
        else{
            cout<<"index too big - deleting element to the end"<<endl;
            delete_tail(l);
        }}else{
        cout<<"Cannot delete empty list"<<endl;
        }
        menu(a);
        break;
    case 8:
        if(!isEmpty(l)){
            first(l);
            cout<<endl;
        }
        else{
            cout<<"Cannot display empty list"<<endl;
        }
        menu(a);
        break;
    case 9:
        if(!isEmpty(l)){
            first(l);
            cout<<endl;
        }
        else{
            cout<<"Cannot display empty list"<<endl;
        }
        menu(a);
        break;
    case 10:
        if(!isEmpty(l)){
            last(l);
            cout<<endl;
        }
        else{
            cout<<"Cannot display empty list"<<endl;
        }
        menu(a);
        break;
    case 11:
        cout<<"Average:"<<listAvg(l)<<endl;
        menu(a);
        break;
    case 12:
        if(!isEmpty(l)){
        listMax(l);
        }
        menu(a);
        break;
    case 13:
        if(!isEmpty(l)){
            listShow(l);
        }
        menu(a);
        break;
    case 14:
        while(!isEmpty(l)){
            delete_head(l);
        }
        menu(a);
        break;
    case 15:
        a=16;
        break;
        }
    }


    cout << "End of the program" << endl;
    return 0;
}
