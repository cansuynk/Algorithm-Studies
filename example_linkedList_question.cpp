/******************************************************************************


*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//https://leetcode.com/problems/add-two-numbers/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* tempAns = NULL;
    ListNode* headAns = NULL;
    int sum = 0;
    int carry = 0;
    
    //2 4 5 , 5 6 4
    //[9,9,9,9,9,9,9], l2 = [9,9,9,9]
    while(temp1 && temp2){
        sum = (temp1->val + temp2->val + carry)%10; //7
        carry = (temp1->val + temp2->val + carry)/10;
        ListNode *ans = new ListNode(sum);
        if(tempAns){
            tempAns->next = ans;
        }else{
            headAns = ans;
        }
        tempAns = ans;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1){
        while(temp1){
            sum = (temp1->val + carry)%10;
            carry = (temp1->val + carry)/10;
            ListNode *ans = new ListNode(sum);
            tempAns->next = ans;
            tempAns = ans;
            temp1 = temp1->next;
        }
    }
    else if(temp2){
        while(temp2){
            sum = (temp2->val + carry)%10;
            carry = (temp2->val + carry)/10;
            ListNode *ans = new ListNode(sum);
            tempAns->next = ans;
            tempAns = ans;
            temp2 = temp2->next;
        }        
    }
    
    if(carry>0){
        ListNode *ans = new ListNode(carry);
        tempAns->next = ans;
        tempAns = ans;        
    }
    
    return headAns;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}


int main()
{
    //Example linked list
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    
    node1 ->next = node2;
    node2 ->next = node3;
    
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);
    
    node4 ->next = node5;
    node5 ->next = node6;
    
    ListNode *ans = addTwoNumbers(node1, node4);
    
    printLinkedList(ans);
    
    return 0;
}
