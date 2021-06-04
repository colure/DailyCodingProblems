//Given the root to a binary tree, implement serialize(root),
//which serializes the tree into a string, and deserialize(s),
//which deserializes the string back into the tree

import java.util.*;

/*TreeNode has key, left right children pointers*/
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class BinaryTree {
	TreeNode root;
	
	//encode tree to single string - serializes!
	public static String serialize(TreeNode root)
	{
		if (root == null) {
			return null;
		}
		Stack<TreeNode> s = new Stack<>(); //Stack is LIFO
		s.push(root);
		
		List<String> l = new ArrayList<>();
		while (!s.isEmpty()) {
			TreeNode t = s.pop(); //return element and remove
			if (t == null) {
				//store marker
				l.add("#");
			} else {
				//store current node and recur for child
				l.add("" + t.val);
				s.push(t.right);
				s.push(t.left);
			}
		}
		return String.join(",", l);
	}
	
	static int t;
	
	//Decode encoded data back to a tree
	public static TreeNode deserialize(String data)
	{
		if (data == null)
			return null;
		t = 0;
		String[] arr = data.split(",");
		return helper(arr);
	}
	
	public static TreeNode helper(String[] arr)
	{
		if (arr[t].equals("#"))
			return null;
		//create node with item and recur for child
		TreeNode root = new TreeNode(Integer.parseInt(arr[t]));
		t++;
		root.left = helper(arr);
		t++;
		root.right = helper(arr);
		return root;
	}
	
	//in order traverse for testing tree
	static void inorder(TreeNode root)
	{
		if (root != null) {
			inorder(root.left);
			System.out.print(root.val + " ");
			inorder(root.right);
		}
	}
	
	/*Driver to test*/
	public static void main(String args[])
	{
		BinaryTree tree = new BinaryTree();
		tree.root = new TreeNode(20);
		tree.root.left = new TreeNode(8);
		tree.root.right = new TreeNode(22);
		tree.root.left.left = new TreeNode(4);
		tree.root.left.right = new TreeNode(12);
		tree.root.left.right.left = new TreeNode(10);
		tree.root.left.right.right = new TreeNode(14);
		
		String serialized = serialize(tree.root);
		System.out.println("Serialized view of the tree:");
		System.out.println(serialized);
		System.out.println();
		
		//deserialize
		TreeNode t = deserialize(serialized);
		
		System.out.println("Inorder Traversal of tree constructed from serialized String");
		inorder(t);
	}
}
