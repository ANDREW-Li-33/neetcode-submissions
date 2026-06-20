class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.replace(" ", "").lower()
        new_s = ""

        for char in s:
            if char.isalnum():
                new_s += char

        l_ptr = 0
        r_ptr = len(new_s) - 1

        mid_index = len(new_s) // 2
        
        while l_ptr <= r_ptr:
            if new_s[l_ptr] != new_s[r_ptr]:
                return False
            l_ptr += 1
            r_ptr -= 1
                
        return True
            