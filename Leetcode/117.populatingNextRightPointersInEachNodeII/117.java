 //https://leetcode.com/discuss/3339/o-1-space-o-n-complexity-iterative-solution
 public class Solution {
        public static void connect(TreeLinkNode root) {
            TreeLinkNode nextHead = new TreeLinkNode(0);
            nextHead.next = root;
            while(nextHead.next != null){
                TreeLinkNode tail = nextHead;
                TreeLinkNode n = nextHead.next;
                nextHead.next = null;
                for(; n != null; n = n.next){
                    if(n.left != null){
                        tail.next = n.left;
                        tail = tail.next;//tail and nexthead are not same now
                    }

                    if(n.right != null){
                        tail.next = n.right; 
                        tail = tail.next;
                    }
                }
            }
        }
    }
