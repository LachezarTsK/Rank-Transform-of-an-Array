
/**
 * @param {number[]} input
 * @return {number[]}
 */
var arrayRankTransform = function (input) {
    if (input.length === 0) {
        return [];
    }
    const clonedInput = Array.from(input);
    clonedInput.sort((x, y) => x - y);

    let rank = 0;
    const valueToRank = new Map();
    for (let num of clonedInput) {
        if (!valueToRank.has(num)) {
            valueToRank.set(num, ++rank);
        }
    }

    const ranks = new Array(input.length);
    for (let i = 0; i < input.length; ++i) {
        ranks[i] = valueToRank.get(input[i]);
    }

    return ranks;
};
