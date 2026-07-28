class Solution:
    def smallestPalindrome(self, s: str) -> str:
        # Array to store character frequencies
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord('a')] += 1
            
        left_half = []
        middle = ""
        
        # Build the left half of the palindrome in lexicographical order
        for i in range(26):
            if freq[i] > 0:
                char = chr(i + ord('a'))
                
                # Append half of the occurrences
                left_half.append(char * (freq[i] // 2))
                
                # Check for the middle character (odd frequency)
                if freq[i] % 2 == 1:
                    middle = char
                    
        # Join the list into a string
        left_str = "".join(left_half)
        
        # Return left half + middle + reversed left half
        return left_str + middle + left_str[::-1]
