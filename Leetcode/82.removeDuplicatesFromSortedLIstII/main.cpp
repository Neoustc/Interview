  ListNode * deleteDuplicates(ListNode* head){  
      if(head==NULL)return head;
      ListNode *helper=new ListNode(0); 
      helper->next=head;
      ListNode *cur=head;
      ListNode *tail=helper;
      while(cur){
      while(cur->next&&cur->val==cur->next->val){
        cur=cur->next;
       }
       if(tail->next==cur){
       	tail=tail->next;
       }
       else{
       	tail->next=cur->next;
       }
       return helper->next;
    }
