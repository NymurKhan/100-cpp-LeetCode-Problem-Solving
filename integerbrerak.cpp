class Solution {
    public int integerBreak(int n) {
        if (n <= 3) return n - 1; 
        
        int k = n / 3, r = n % 3; 
        if (r == 0) return (int) Math.pow(3, k); 
        else if (r == 1) return (int) Math.pow(3, k - 1) * 4;
        else return (int) Math.pow(3, k) * 2;
    }
}
