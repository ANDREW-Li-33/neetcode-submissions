class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # to make sure we have no duplicates, we can use a set
        answer_set = set()

        nums.sort()

        # -nums[i] = nums[left_ptr] + num[right_ptr]

        # [-4, -1, -1, 0, 1, 2]

        for i in range(len(nums)):
            target = -nums[i]

            l_ptr = i + 1
            r_ptr = len(nums) - 1


            while l_ptr < r_ptr:
                ptr_sum = nums[l_ptr] + nums[r_ptr]

                if ptr_sum == target:
                    answer_set.add(tuple(sorted((nums[l_ptr], nums[r_ptr], nums[i]))))
                    l_ptr += 1
                    r_ptr -= 1
                elif ptr_sum < target:
                    l_ptr += 1
                else:
                    r_ptr -= 1

        results = []
        for answer in answer_set:
            results.append(answer)

        return results
                    
                



