#include <bits/stdc++.h>

using namespace std;

typedef struct LinkListNode{
    int data;
    struct LinkListNode *next;
}*nodePtr;

nodePtr head = NULL, currentNode;

void InsertData(int data){
    nodePtr newNode = new LinkListNode;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        currentNode->next = newNode;
    }
    currentNode = newNode;
}

void DisplayLinkedList(){
       nodePtr ptr;
       ptr = head;
       if(ptr == NULL){
        cout << "List is Empty!!!" << endl;
       }
       else{
        cout << "Linked List: ";
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
       }
}

void SearchListItem(int item){
      nodePtr ptr = head;
      if(ptr == NULL){
        cout << "List is Empty!!!" << endl;
      }
      while(ptr->next != NULL && ptr->data != item){
         ptr = ptr->next;
      }
      if(ptr->data == item){
        cout << "Linked List Data Found: " << item << endl;
      }
      else{
        cout << "Data not found in Linked List" << endl;
      }

}

void InsertBegin(int item){
         nodePtr newNode = new LinkListNode;
         newNode->data = item;
         newNode->next = head;
         head = newNode;
}

void InsertAnyWereList(int item, int des){
          nodePtr ptr = head;
          nodePtr newNode = new LinkListNode;
          newNode->data = item;
          while(ptr->next != NULL && ptr->data != des){
            ptr = ptr->next;
          }
          if(ptr->data == des && ptr->next != NULL){
            newNode->next = ptr->next;
            ptr->next = newNode;
          }
          else{
            cout << "Insert in middle was not successful!!!." << endl;
          }
}

void DeleteFirstElement(){
         nodePtr ptr = head, deletePtr;
         deletePtr = ptr;
         head = ptr->next;
         delete(deletePtr);
}

void DeleteLastElement(){
           nodePtr ptr = head, deletePtr;
           while(ptr->next->next != NULL){
            ptr = ptr->next;
           }
           deletePtr = ptr->next;
           ptr->next = NULL;
           delete(deletePtr);

}

void DeleteMiddle(int item){
         nodePtr ptr = head, deletePtr;
         while(ptr->next->data != item && ptr->next->next != NULL){
            ptr = ptr->next;
         }
         if(ptr->next->data == item && ptr->next->next != NULL){
            deletePtr = ptr->next;
            ptr->next = ptr->next->next;
            delete(deletePtr);
         }
         else{
            cout << "Desired Data is not a middle item." << endl;
         }
}

int main()
{
    int choice;

    do{
        cout << "Enter 1 add to the linkedList." << endl;
        cout << "Enter 2 to add first of the linkedList." << endl;
        cout << "Enter 3 to add Middle of the linkedList." << endl;
        cout << "Enter 4 delete first element." << endl;
        cout << "Enter 5 to delete last element." << endl;
        cout << "Enter 6 to delete from middle element of the linkedList." << endl;
        cout << "Enter 7 to search a linkedList element." << endl;
        cout << "Enter 8 to display the Linked List." << endl;
        cout << "Enter 9 to exit the program." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
               int listData;
               cout << "Enter Data to insert in linked list:" ;
               cin >> listData;
               InsertData(listData);
               break;
            }
            case 2:{
              int insertFirst;
              cout << "Enter data to insert at first of the list:";
              cin >> insertFirst;
              InsertBegin(insertFirst);
              break;
            }
            case 3:{
              int insertAnywhere, des;
              cout << "Enter to insert anywhere in list: ";
              cin >> insertAnywhere;
              cout << "Enter desired destination: ";
              cin >> des;
              InsertAnyWereList(insertAnywhere, des);
              break;
            }
            case 4:{
              DeleteFirstElement();
              break;
            }
            case 5:{
              DeleteLastElement();
              break;
            }
            case 6:{
              int deleteMid;
              cout << "Enter delete data:";
              cin >> deleteMid;
              DeleteMiddle(deleteMid);
              break;
            }
            case 7:{
              int item;
              cout << "Enter Item to search in list: ";
              cin >> item;
              SearchListItem(item);
              break;
            }
            case 8:{
              DisplayLinkedList();
              break;
            }
            case 9:{
              cout << "Program End." << endl;
              break;
            }
            default:{
              cout << "You Entered the wrong choice!!! Chose from listed numbers." << endl;
            }
        }

    }while(choice != 9);
    return 0;
}
