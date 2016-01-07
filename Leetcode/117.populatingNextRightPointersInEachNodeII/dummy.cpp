void connect(TreeLinkNode *root) {
        TreeLinkNode* dummy = new TreeLinkNode(0);
        dummy -> next = root;
        while (dummy -> next) {
            TreeLinkNode* pre = dummy;
            TreeLinkNode* cur = dummy -> next;
            pre -> next = NULL;
            while (cur) {
                if (cur -> left) {
                    pre -> next = cur -> left;
                    pre = pre -> next;
                }
                if (cur -> right) {
                    pre -> next = cur -> right;
                    pre = pre -> next;
                }
                cur = cur -> next;
            }
        }
    }
