class Solution {
    public boolean isPalindrome(String s) {

        String temp = "";

        for(char ch: s.toCharArray()) {
            if(Character.isLetterOrDigit(ch)) {
                temp += Character.toLowerCase(ch);
            }
        }
        int i = 0;
        int j = temp.length()-1;

        while(i <= j) {
            if(temp.charAt(i) == temp.charAt(j)) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        
        return true;
    }
}