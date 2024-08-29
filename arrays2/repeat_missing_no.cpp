//approach 1 : for every element(1 to n) run an inner loop and if same element is found increment freq, if at any time we find cnt == 2 we update repeating no and if we find cnt == 0 we update missing no 
//if at any time we get repeating != -1 and missing != -1 then we break loop
//TC : O(n^2) SC : O(1)

//approach 2 : freq arr
//TC : O(2n) SC : O(n)

//approach 3 : math
//sum of number - sum of first n numbers => x-y
//sum of square of numbers - sum of sq of first n numbers => x2-y2
// x is repeating no, y is missing no
//TC : O(n) SC : O(n)
vector<int>findMissingNumber(vector<int>a){
int n = a.size();
    long long sn = (n*(n+1))/2;
    long long sn2 = (n*(n+1)*(2*n+1))/6;
    long long s = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = s - sn;
    long long val2 = s2 - sn2;;
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return ({(int)x, (int)y});
}

//approach 3 : xor
// even no of elements xor together give 0 and 0^no = no
//we seperate the nos based on given differentiating bit
//TC : O(n) SC : O(1)
vector<int>findMissingNumber(vector<int>a){
    //long long mei le skte h size
    int n = a.size();
    int xr = 0;
    for(int i = 0; i < n; i++) {
        xr ^= a[i] ^ (i+1);
    }
    int bit = 0;
    while(true) {
        if((xr & (1<<bit))) {
            break;
        }
        else bit++;
    }

    int zero = 0, one = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] & (1<<bit)) {
            one ^= a[i];
        }
        else {
            zero ^= a[i];
        }
        if((i+1) & (1<<bit)) {
            one ^= i;
        }
        else {
            zero ^= i;
        }
        
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return ({zero, one});
    return ({one, zero});
}