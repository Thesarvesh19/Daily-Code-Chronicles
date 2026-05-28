import java.util.*;

class Solution {

    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        int idx = -1;
        int length = Integer.MAX_VALUE;
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {

        TrieNode root = new TrieNode();

        for (int i = 0; i < wordsContainer.length; i++) {
            String word = wordsContainer[i];

            TrieNode node = root;
            update(node, i, word.length());

            for (int j = word.length() - 1; j >= 0; j--) {
                char ch = word.charAt(j);

                node.children.putIfAbsent(ch, new TrieNode());
                node = node.children.get(ch);

                update(node, i, word.length());
            }
        }

        int[] ans = new int[wordsQuery.length];

        for (int i = 0; i < wordsQuery.length; i++) {
            String word = wordsQuery[i];

            TrieNode node = root;

            for (int j = word.length() - 1; j >= 0; j--) {
                char ch = word.charAt(j);

                if (!node.children.containsKey(ch))
                    break;

                node = node.children.get(ch);
            }

            ans[i] = node.idx;
        }

        return ans;
    }

    private void update(TrieNode node, int idx, int len) {
        if (len < node.length) {
            node.length = len;
            node.idx = idx;
        }
    }
}
