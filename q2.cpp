#include <iostream>
#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(0) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2){
        ListNode *returnNode = 0, *currentNode = 0, *newNode;
        int moveUp = 0, sum = 0, counter = 0;

        while(counter < 10 && (L1 || L2)){
            counter++;
            int left = L1 ? (*L1).val : 0;
            int right = L2 ? (*L2).val : 0;
//std::cout << L1 << ", " << L2 << "\n";
            sum = (left + right) % 10 + moveUp;
            moveUp = (left + right) >= 10 ? 1 : 0;
            newNode = new ListNode(sum);
std::cout << "new node @: " << newNode << "\n";
            // new node becomes current, or current.next
            if(currentNode){
                (*currentNode).next = newNode;
                currentNode = newNode;
            }else{
                currentNode = newNode;
            }
std::cout << "current node @: " << currentNode << "\n";
            // assign current to return if return is empty
            // only need this once
            if(returnNode){
                //(*returnNode).next = currentNode;
            }else{
                returnNode = currentNode;
            }

            // advance input lists
            L1 = L1 && (*L1).next ? (*L1).next : 0;
            L2 = L2 && (*L2).next ? (*L2).next : 0;
std::cout << "sum, r: " << sum << ", " << moveUp << " @ " << &newNode << "\n";
        }

        return returnNode;
    }
};

int main(){

    ListNode l11 = ListNode(2);
    ListNode l12 = ListNode(4);
    ListNode l13 = ListNode(9);
    ListNode l14 = ListNode(1);
    l11.next = &l12;
    l12.next = &l13;
    l13.next = &l14;

    ListNode l21 = ListNode(5);
    ListNode l22 = ListNode(6);
    ListNode l23 = ListNode(9);
    l21.next = &l22;
    l22.next = &l23;

    Solution foo = Solution();
    ListNode* rl = foo.addTwoNumbers(&l11, &l21);

std::cout << "rl: " << rl << '\n';

    while(rl){
        std::cout << "rl val: " << (*rl).val << ' ';
        rl = (*rl).next;
    }
    std::cout << "\n";

    return 0;
}