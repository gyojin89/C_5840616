#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { long long n, d; } Fraction;

static long long gcd_ll(long long a, long long b) {
    if (a<0) a=-a; if (b<0) b=-b;
    while (b) { long long t=b; b=a%b; a=t; }
    return a? a:1;
}
static Fraction norm(Fraction f) {
    if (f.d==0) { fprintf(stderr,"Denominator = 0\n"); exit(1); }
    if (f.d<0) { f.n=-f.n; f.d=-f.d; }
    long long g=gcd_ll(f.n,f.d);
    f.n/=g; f.d/=g;
    return f;
}
static Fraction parse_frac(const char *s) {
    const char *slash=strchr(s,'/');
    if (!slash) { fprintf(stderr,"Bad format: %s\n",s); exit(1); }
    char num[32]={0}, den[32]={0};
    strncpy(num,s,slash-s);
    strcpy(den,slash+1);
    return norm((Fraction){ atoll(num), atoll(den) });
}

static Fraction add(Fraction a,Fraction b){return norm((Fraction){a.n*b.d+b.n*a.d,a.d*b.d});}
static Fraction mul(Fraction a,Fraction b){return norm((Fraction){a.n*b.n,a.d*b.d});}

static Fraction perimeter(Fraction w,Fraction h){ return mul((Fraction){2,1}, add(w,h)); }
static Fraction area(Fraction w,Fraction h){ return mul(w,h); }

int main(int argc,char **argv){
    if(argc!=3){
        fprintf(stderr,"Usage: %s <width A/B> <height C/D>\n",argv[0]);
        return 1;
    }
    Fraction w=parse_frac(argv[1]), h=parse_frac(argv[2]);
    Fraction p=perimeter(w,h), a=area(w,h);
    printf("Perimeter: %lld/%lld, Area: %lld/%lld\n",
           p.n,p.d, a.n,a.d);
    return 0;
}