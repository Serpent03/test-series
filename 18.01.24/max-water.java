class Solution {
  public int maxArea(int[] height) {
    // water = area = height * (x1 - x0)
    int maxWater = 0;
    int lp = 0;
    int rp = height.length - 1;

    while (lp < rp) {
      maxWater = Math.max(((height[lp] < height[rp]) ? height[lp] : height[rp]) * (rp - lp), maxWater);
      if (height[lp] > height[rp]) {
        rp--;
      } else {
        lp++;
      }
    }
    return maxWater;
  }
}