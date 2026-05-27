import java.util.*;

class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character> lower = new HashSet<>();
        Set<Character> upper = new HashSet<>();

        for(char ch : word.toCharArray()) {
            if(Character.isLowerCase(ch))
                lower.add(ch);
            else
                upper.add(Character.toLowerCase(ch));
        }

        lower.retainAll(upper);
        return lower.size();
    }
}
