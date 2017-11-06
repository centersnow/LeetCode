import java.util.*;

class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words);
        Set<String> s = new HashSet<>();
        String res = new String();

        for (String t : words) {
            if (t.length() == 1 || s.contains(t.substring(0, t.length() - 1)) == true) {
                s.add(t);
                if (t.length() > res.length()) {
                    res = t;
                }
            }
        }

        return res;
    }
}
