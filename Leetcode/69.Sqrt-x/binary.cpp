 int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int l = 1, r = x;
        while (l < r - 1)
        {
            int m = l + ((r - l) >> 1);
            if (m < x / m) l = m;
            else if (m > x / m) r = m - 1;
            else return m;
        }
        if (r <= x / r) return r;
        return l;
    }
