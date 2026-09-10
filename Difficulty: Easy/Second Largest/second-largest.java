class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        
        for(int x: arr) {
            if(x > largest) {
                secondLargest = largest;
                largest = x;
            }
            else if(x > secondLargest && x!=largest) {
                secondLargest = x;
            }
        }
        
        if(secondLargest == Integer.MIN_VALUE) return -1;
        
        return secondLargest;
    }
}