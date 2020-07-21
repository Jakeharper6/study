unsigned set(unsigned x, int pos)
{
    unsigned mask = (1u << pos);
    x = (mask | x);
    return x;
}