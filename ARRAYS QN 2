public class SimpleArrayRotator {    
    
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        int[] temp = new int[n];
        k %= n;  // if k>n 
        
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }        
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
public static void main(String[] args) {
        SimpleArrayRotator rotator = new SimpleArrayRotator();
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;

        System.out.println("Original array:");
        printArray(nums);

        rotator.rotate(nums, k);

        System.out.println("\nArray after rotating by " + k + " steps:");
        printArray(nums);
    }
public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
