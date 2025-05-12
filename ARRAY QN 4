public class SingleNumberFinder {
    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR each number with result
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {4, 1, 2, 1, 2};
        int single = singleNumber(nums);
        System.out.println("The number that appears only once is: " + single);
    }
}
