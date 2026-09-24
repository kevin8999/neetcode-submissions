class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphabet = ""

        for char in s:
            if char.isalnum():
                alphabet += char.lower()
        
        return alphabet == alphabet[::-1]