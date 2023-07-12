class Solution {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        return kthProduct(nums1, nums2, k);
    }
    public static long kthProduct(int[] nums1, int[] nums2, long k) {
        long si = -1000_00_00000l;
        long ei = 1000_00_00000l;
        long ans = 0;

        while (si <= ei) {
            long mi = (si + ei) / 2;
            if (countofproduct(nums1, nums2, mi) >= k) {
                ans = mi;
                ei = mi - 1;
            } else {
                si = mi + 1;
            }
        }

        return ans;
    }

    private static long countofproduct(int[] nums1, int[] nums2, long mi) {
        long ans = 0;
        for (int e1 : nums1) {
            if (e1 >= 0) {
                long count = 0;
                int lo = 0;
                int hi = nums2.length - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if ((long) (e1) * nums2[mid] <= mi) {
                        count = mid + 1;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                ans += count;
            } else {
                long count = 0;
                int lo = 0;
                int hi = nums2.length - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if ((long) (e1) * nums2[mid] <= mi) {
                        count = nums2.length - mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                ans += count;
            }
        }
        return ans;
    }
}