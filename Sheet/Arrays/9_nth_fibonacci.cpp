
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    int fib_n_2 = 0;
    int fib_n_1 = 1;
    int fib_n;
    for (int i = 2; i <= n; i++)
    {
        fib_n = fib_n_1 + fib_n_2;

        fib_n_2 = fib_n_1;
        fib_n_1 = fib_n;
    }
    return fib_n;
}