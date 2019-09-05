class Trie {
    private Node root;
    public Trie() {
        this.root = new Node("");
    }

    private Node getNewNode(char c) {
        Node node = new Node(String.valueOf(c));
        node.setHasChild(false);
        return node;
    }

    public void insert(String key) {
        Node tempNode = root;

        for (int i = 0; i < key.length(); ++i) {
            char c = key.charAt(i);
            int index = c - 'a';

            if (tempNode.getChild(index) == null) {
                Node node = this.getNewNode(c);
                tempNode.setChild(index, node);
                tempNode = node;
            } else {
                tempNode = tempNode.getChild(index);
                tempNode.setHasChild(true);
            }
        }

    }

    public int search(String key) {
        Node trieNode = root;
        int depth = 0;
        for (; depth < key.length(); ++depth) {
            int index = key.charAt(depth) - 'a';
            trieNode = trieNode.getChild(index);
            if (!trieNode.isHasChild()) {
                return depth + 1;
            }
        }
        return depth;
    }
}

class Node {
    private String character;
    private Node[] child;
    private boolean hasChild;

    public Node(String character) {
        this.character = character;
        this.child = new Node[Solution.ALPHABET_SIZE];
    }

    public Node getChild(int index) {
        return child[index];
    }

    public void setChild(int index, Node node) {
        this.child[index] = node;
    }

    public String getCharacter() {
        return character;
    }

    public boolean isHasChild() {
        return hasChild;
    }

    public void setCharacter(String character) {
        this.character = character;
    }

    public void setHasChild(boolean hasChild) {
        this.hasChild = hasChild;
    }
}

class Solution {
    public static int ALPHABET_SIZE = 26;

    public int solution(String[] words) {
        Trie trie = new Trie();
        int answer = 0;

        for (int i = 0; i < words.length; ++i) {
            trie.insert(words[i]);
        }

        for (int i = 0; i < words.length; ++i) {
            answer += trie.search(words[i]);
        }

        return answer;
    }
}

public class Main {
    public static void main(String... args) {
        Solution solution = new Solution();
        String[] arg = {"go", "gone", "guild"};
        solution.solution(arg);
    }
}