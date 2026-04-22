# Words Within Two Edits of Dictionary

class Solution:
    def twoEditWords(self, queries, dictionary):
        
        answer = []
        
        for word in queries:
            for target in dictionary:
                mismatch = 0 
                
                for a, b in zip(word, target):
                    if a != b:
                        mismatch += 1
                        if mismatch > 2:
                            break
                
                if mismatch <= 2:
                    answer.append(word)
                    break
        
        return answer
