import java.util.HashSet;

public class DuplicateChecker {

    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();

        for (int num : nums) {
            if (seen.contains(num)) {
                return true; // Duplicate found
            }
            seen.add(num);
        }

        return false; // No duplicates
    }

    public static void main(String[] args) {
        DuplicateChecker checker = new DuplicateChecker();

        int[] nums1 = {1, 2, 3, 4, 5};         // No duplicates
        int[] nums2 = {1, 2, 3, 1};            // Contains duplicate

        System.out.println(checker.containsDuplicate(nums1)); // false
        System.out.println(checker.containsDuplicate(nums2)); // true
    }
}
