// Find Out the Morris Inorder Traversal For The Given Tree

// Look For Reference In the Book On Pg No 126-127


public class morrisInordalTraversal{
    public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int v){
            val = v;
            left = null;
            right = null;
        }
    }

    public static void morris_inorder_traversal(TreeNode root){
        System.out.print("[");
        while(root!=null){
            if(root.left==null){
                System.out.print(root.val);
                root = root.right;
                if(root!=null){
                    System.out.print(", ");
                }
            }
            else{
                TreeNode predecessor = root.left;
                while(predecessor.right!=null&&predecessor.right!=root){
                    predecessor = predecessor.right;
                }
                if(predecessor.right == null){
                    predecessor.right = root;
                    root = root.left;
                }
                else{
                    predecessor.right = null;
                    System.out.print(root.val);
                    root = root.right;
                    if(root!=null){
                        System.out.print(", ");
                    }
                }
            }
        }
        System.out.print("]");
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        morris_inorder_traversal(root);
    }
}