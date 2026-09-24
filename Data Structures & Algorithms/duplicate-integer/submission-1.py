class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        found_numbers = []
        for num in nums:
            for number in found_numbers:
                if num == number:
                    return True

            found_numbers.append(num)

        return False