
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public int[] arrayRankTransform(int[] input) {
        if (input.length == 0) {
            return new int[0];
        }
        int[] clonedInput = Arrays.copyOf(input, input.length);
        Arrays.sort(clonedInput);

        int rank = 0;
        Map<Integer, Integer> valueToRank = new HashMap<>();
        for (int num : clonedInput) {
            if (!valueToRank.containsKey(num)) {
                valueToRank.put(num, ++rank);
            }
        }

        int[] ranks = new int[input.length];
        for (int i = 0; i < input.length; ++i) {
            ranks[i] = valueToRank.get(input[i]);
        }

        return ranks;
    }
}
