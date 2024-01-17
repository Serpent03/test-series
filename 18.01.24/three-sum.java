import java.util.*;

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    if (nums.length < 3) {
      return new ArrayList<List<Integer>>();
    }
    Set<List<Integer>> tVal = new HashSet<>();
    Arrays.sort(nums);
    // switch to hashmap based approaches?
    for (int i = 0; i < nums.length; i++) {
      int l = i + 1;
      int r = nums.length - 1;
      int ans = -1;

      while (l < r) {
        ans = nums[i] + nums[l] + nums[r];
        if (ans == 0) {
          tVal.add(Arrays.asList(nums[i], nums[l++], nums[r--]));
        }
        if (ans < 0) {
          l++;
        }
        if (ans > 0) {
          r--;
        }
      }
    }
    return new ArrayList<List<Integer>>(tVal);
  }
}