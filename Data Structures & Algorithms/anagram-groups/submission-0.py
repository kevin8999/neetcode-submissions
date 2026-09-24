class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_table: dict[str, List[str]] = {}
        for word in strs:
            alphabetized = "".join(sorted(word))

            if alphabetized in hash_table:
                hash_table[alphabetized].append(word)
            else:
                hash_table[alphabetized] = [word]
        
        strs_list: List[List[str]] = []

        for key, value in hash_table.items():
            strs_list.append(value)
        
        return strs_list