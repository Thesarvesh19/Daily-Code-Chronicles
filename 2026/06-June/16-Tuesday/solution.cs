public class Solution {
    public string ProcessStr(string s) {
        List<char> res = new List<char>();

        foreach (char c in s) {
            if (char.IsLower(c)) {
                res.Add(c);
            }
            else if (c == '*') {
                if (res.Count > 0)
                    res.RemoveAt(res.Count - 1);
            }
            else if (c == '#') {
                res.AddRange(res.ToArray());
            }
            else { // '%'
                res.Reverse();
            }
        }

        return new string(res.ToArray());
    }
}
