import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class TreeNode {
    Coordy data;
    TreeNode left;
    TreeNode right;

    public TreeNode(Coordy data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BST {
    TreeNode root;

    public BST() {
        this.root = null;
    }

    public void preOrder(TreeNode node) {
        Solution.preOrderList.add(node.data.index);
        if (node.left != null) {
            preOrder(node.left);
        }
        if (node.right != null) {
            preOrder(node.right);
        }
    }

    public void postOrder(TreeNode node) {
        if (node.left != null) {
            postOrder(node.left);
        }
        if (node.right != null) {
            postOrder(node.right);
        }
        Solution.postOrderList.add(node.data.index);
    }

    public void insert(Coordy coordy) {
        TreeNode newNode = new TreeNode(coordy);
        if (root == null) {
            root = newNode;
            return;
        }
        TreeNode currentNode = root;
        TreeNode parentNode = null;
        while (true) {
            parentNode = currentNode;
            if (coordy.x < currentNode.data.x) {
                currentNode = currentNode.left;
                if (currentNode == null) {
                    parentNode.left = newNode;
                    return;
                }
            } else {
                currentNode = currentNode.right;
                if (currentNode == null) {
                    parentNode.right = newNode;
                    return;
                }
            }
        }
    }
}

class Coordy {
    int index;
    int x;
    int y;

    public Coordy(int x, int y, int index) {
        this.x = x;
        this.y = y;
        this.index = index;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

class Solution {
    List<Coordy> coordies = new ArrayList<>();
    public static List<Integer> preOrderList = new ArrayList<>();
    public static List<Integer> postOrderList = new ArrayList<>();

    public int[][] solution(int[][] nodeinfo) {
        int[][] answer = new int[2][];
        BST bst = new BST();
        for (int i = 0; i < nodeinfo.length; ++i) {
            coordies.add(new Coordy(nodeinfo[i][0], nodeinfo[i][1], i + 1));
        }
        coordies.sort(Comparator.comparing(Coordy::getY).reversed().thenComparing(Coordy::getX));
        for (Coordy coordy : coordies) {
            bst.insert(coordy);
        }
        bst.preOrder(bst.root);
        bst.postOrder(bst.root);
        answer[0] = this.convertIntegers(preOrderList);
        answer[1] = this.convertIntegers(postOrderList);
        return answer;
    }

    private int[] convertIntegers(List<Integer> integers) {
        int[] ret = new int[integers.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = integers.get(i).intValue();
        }
        return ret;
    }
}

public class Main {
    public static void main(String... args) {
        Solution solution = new Solution();
        String[] arg = {"go", "gone", "guild"};
        int[][] arg2 = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
        solution.solution(arg2);
    }
}