/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next)
      return;
      //檢查輸入是否為空或只有一個節點
    ListNode* mid = findMid(head);     //找到list的中間節點 mid
    ListNode* reversed = reverse(mid);     //反轉從mid開始的後半部分list
    merge(head, reversed);     //將前半部分和反轉後的後半部分合併
  }

 private:
  ListNode* findMid(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    //low和fast用來找到中間節點
    //prev用來保存中間節點的前一個節點
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;     //每次移動一步
      fast = fast->next->next;     //每次移動兩步
      //fast到達末尾時，slow 則到達中間
    }
    prev->next = nullptr;
    //將前半部分list和後半部分鏈表斷開
    return slow;
    //回傳後半部分list的頭節點 
  }

  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    //prev用來保存反轉後list的前一個節點
    //curr用來遍歷list
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      //每次將curr的next指針指向prev
      //向前移動prev和curr
    }
    return prev;
    //回傳反轉後的新頭節點 prev
  }

  void merge(ListNode* l1, ListNode* l2) {
    while (l2) {
      ListNode* next = l1->next;
      l1->next = l2;
      l1 = l2;
      l2 = next;
      //將l1的next指向l2
      //然後移動l1和l2
    }
  }
};