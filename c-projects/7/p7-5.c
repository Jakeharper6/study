unsigned set_n(unsigned x, int pos, int n) {

    int i;
    for (i = 0; i < n - pos; i++) {
        unsigned mask = (1u << (pos + i));
        x = (mask | x);
    }
    return x;
}
