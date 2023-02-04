#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int digitCount(int n){
    int count =0;
    while (n){
        count += 1;
        n /=10;
    }
    return count;
}

int findMax(int k, int l){
    if (k>l){
        return k;
    }
    else{
        return l;
    }
}

int power(int b, int e){
    int value =1;
    while(e){
        value *= b;
        e--;
    }
    return value;
}

long int karatsuba(int x, int y){
    long int sol;
    if((x<10) && (y<10))
        return x*y;
    else{
        int n, nby2;
        n = findMax(digitCount(x),digitCount(y));
        nby2 = ceil((float)n/2);
        
        int a,b,c,d;
        a = x/power(10,nby2);
        b = x%power(10,nby2);
        c = y/power(10,nby2);
        d = y%power(10,nby2);

        int s1,s2,s3,s4;
        s1 = karatsuba(a,c);
        s2 = karatsuba(b,d);
        s3 = karatsuba(a+b,c+d);
        s4 = s3 - s2 - s1;

        sol = ((s1*power(10,n))+(s4*power(10,nby2)) + s2);

        return sol;
    }
}

int main()
{
    int x,y;
    x=1234;
    y=5678;
    long int sol = karatsuba(x,y);

    printf("%d * %d = %d", x,y,sol);

}
