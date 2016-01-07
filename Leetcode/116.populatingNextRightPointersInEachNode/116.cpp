//idea : Using two pointers for NEXT(pre) level and CUR(cur) level.
//when traverse current level, the next link on current level is already available from this iteraton
//It is trivial to link left node to right node. 
//To link right node to next one, it needs to get cur -> next -> LeftNode.


 void connect(TreeLinkNode *root)
  {
 	if (root == NULL) return;
 	TreeLinkNode* cur = root;
 	while (cur -> left)
 	{
 		TreeLinkNode* pre = cur -> left; 
 		while (cur){
 			cur -> left -> next = cur -> right;
 			if (cur -> next) 
 			    cur -> right -> next = cur -> next -> left;
 			cur = cur -> next;
 		}
 		cur = pre;
 	}
 }
