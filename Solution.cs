
using System;
using System.Collections.Generic;

public class Solution
{
    public int[] ArrayRankTransform(int[] input)
    {
        if (input.Length == 0)
        {
            return new int[0];
        }
        int[] clonedInput = new int[input.Length];
        Array.Copy(input, clonedInput, input.Length);
        Array.Sort(clonedInput);

        int rank = 0;
        Dictionary<int, int> valueToRank = new Dictionary<int, int>();
        foreach (var num in clonedInput)
        {
            if (!valueToRank.ContainsKey(num))
            {
                valueToRank.Add(num, ++rank);
            }
        }

        int[] ranks = new int[input.Length];
        for (int i = 0; i < input.Length; ++i)
        {
            ranks[i] = valueToRank[input[i]];
        }

        return ranks;
    }
}
