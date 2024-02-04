class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        word_length = len(word)

        for i in range(1, 10001):
            removed_chars = i * k
            remaining_part = word[removed_chars:]

            are_chars_equal = all(
                remaining_part[j] == word[j] for j in range(len(remaining_part))
            )

            if are_chars_equal:
                return i

        return 0
