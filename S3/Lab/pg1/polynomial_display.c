void print_terms(int n, struct term sum[]) 
{
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (sum[i].coef == 0)
            continue;
        first && sum[i].coef>0 ? printf("%d",sum[i].coef) : printf("%+d",sum[i].coef);
        sum[i].exp == 0 ? printf(" ") :(sum[i].exp== 1 ? printf("x ") :printf("x^%d ", sum[i].exp));
        first = 0;
    }
}

void print_terms(int n, struct term sum[]) 
{
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (sum[i].coef == 0)
            continue;
        !first && sum[i].coef > 0 ? printf("+ ") : 0;
        printf("%d", sum[i].coef);
        sum[i].exp == 1 ? printf("x ") : (sum[i].exp > 1 ? printf("x^%d ", sum[i].exp) : printf(" "));
        first = 0;
    }
}