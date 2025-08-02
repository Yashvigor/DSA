// User function Template for C
//  Function to find moves
int towerOfHanoi(int n, int from, int to, int aux) {
    // code here
    if (n == 0)
        return 0;
    return 1 + 2 * towerOfHanoi(n - 1, from, aux, to);


}
    
