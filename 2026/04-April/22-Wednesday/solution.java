// Words Within Two Edits of Dictionary

import java.util.*;

class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> res = new LinkedList<>();
        
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            
            for (String d : dictionary) {
                if (check(q, d)) {
                    res.add(q);
                    break; 
                }
            }
        }
        
        return res;
    }
    
    private boolean check(String a, String b) {
        int changes = 0;
        
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                changes++;
            }
            if (changes > 2) return false;
        }
        
        return true;
    }
}
