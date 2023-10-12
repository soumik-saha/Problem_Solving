/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int size = arr.length();

        // Find Peek
        int low = 0, high = size-2;
        while(low!=high) {
            int ind = low + (high-low)/2;
            if(arr.get(ind) < arr.get(ind+1)) {
                low = ind+1;
            }
            else {
                high = ind;
            }
        } 
        int peek = high;

        // Check in increasing part
        low = 0;
        high = peek;
        while(low!=high) {
            int ind = low + (high-low)/2;
            if(arr.get(ind) < target) {
                low = ind+1;
            }
            else {
                high = ind;
            }
        }
        if(arr.get(low)==target) {
            return low;
        }

        // Check in decreasing part
        low = peek+1;
        high = size-1;
        while(low!=high) {
            int ind = low + (high-low)/2;
            if(arr.get(ind) > target) {
                low = ind + 1;
            }
            else {
                high = ind;
            }
        }
        if(arr.get(low)==target) {
            return low;
        }

        return -1;
    }
};
